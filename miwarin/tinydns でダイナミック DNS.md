#tinydns でダイナミック DNS

tinydns (djbdns) はRFC 2136 未対応なのでちゃんとしたダイナミック DNS ではないので、それっぽいふうに運用してみる。なんちゃってダイナミックDNSである。

#環境

*  NetBSD
*  pkgsrc/net/djbdns-run
*  ドメイン area51.gr.jp

area51.gr.jp は設定済みとする。

#手段

[tinydns で Dynamic DNS (not RFC )](http://www.bugbearr.jp/?tinydns)

> 要は、A レコードを追加/更新して data.cdb を再生成させれば成功である。

1.  レコードごとに設定ファイルを一時ファイルで受け取る。
1.  受け取った後にディレクトリに移動する。(古い設定ファイルは上書きする。)
1.  すべての設定ファイルを結合して data ファイルを作る。
1.  data.cdb を作成する。

ここのやり方そのまま。

IP アドレスはログイン時の SSH_CLIENT を利用する。

#更新方法

ダイナミック DNS の IP アドレス更新を連絡する手段としては以下の手段がよくあるみたいだ。

*  メール
*  ウェブ
*  FTP

しかし、これらは利用者が自らの IP アドレスを知る必要があるし、IP アドレスを知るための手段としていろいろあるみたいだけど、利用者としては面倒くさいので却下した。SSH_CLIENT を使うだけならば追加投資がないし、むしろ実績があるので採用した( [ssh の接続元 IP アドレス - ヨタの日々(2011-12-26)](http://www.area51.gr.jp/~rin/diary/?date=20111226#p04) )

#準備

##data

/usr/pkg/etc/tinydns の下に user-data というディレクトリを作成し、そこに data を格納する。たとえばこう

    -rw-r--r-- 1 root     users 498 Jun 23 00:17 data         ← 全部結合した data
    -rw-r--r-- 1 root     users 430 Jun 16 17:21 data.area51  ← area51.gr.jp の data
    -rw-r--r-- 1 AAAA     users  36 Jun 23 00:15 data.aaaa    ← ドメイン aaaa の data
    -rw-r--r-- 1 BBBB     users  32 Jun 23 00:05 data.bbbb    ← ドメイン bbbb の data
    -rwxr--r-- 1 root     users 548 Jun 16 17:19 record.sh*   ← Aレコード更新スクリプト(後述)

chmod を忘れずに。

    chmod g+w user-data

##A レコード更新

スクリプト(record.sh) で利用者の A レコードを追加/更新する。引数にサブドメイン名を指定する。

    #!/bin/sh
    
    usage()
    {
      echo "usage:"
      echo "  record.sh <domain>"
      echo ""
    }
    
    check()
    {
      if [ -z $1 ]; then
        usage
        exit
      fi
    }
    
    setup()
    {
      addr=$(echo $SSH_CLIENT | awk '{print $1}')
      user=${USER}
      base_dir=/usr/pkg/etc/tinydns/user-data
      file=${base_dir}/data.${user}
      domain=$1
      record="+${domain}.area51.gr.jp:${addr}"
    
      echo "your address   => " ${addr}
      echo "your data file => " ${file}
      echo "your domain    => " ${domain}
    }
    
    record()
    {
      echo ${record} > ${file}
    }
    
    main()
    {
      check $@
      setup $@
      record $@
    }
    
    main $@


SSH ログインしたときに実行したいので、${HOME}/.ssh/rc に書いておく。

    #!/bin/sh
    
    sh /usr/pkg/etc/tinydns/user-data/record.sh aaaa

こんな感じに更新される。

    cat /usr/pkg/etc/tinydns/user-data/data.aaaa
    +aaaa.area51.gr.jp:xxx.xxx.xxx.xxx

##data.cdb 更新

スクリプト(build.sh) を /usr/pkg/etc/tinydns に設置しておく。data が変更されたときのみ tinydns で reload する( /etc/rc.d/tinydns cdb )。

    #!/bin/sh
    
    base_dir=/usr/pkg/etc/tinydns
    data_dir=${base_dir}/user-data
    data=./data
    
    cd ${data_dir}
    cat data.* > ${data}
    
    diff ${base_dir}/${data} ${data_dir}/${data}
    
    if [ $? -eq 1 ]; then
      cp ${data_dir}/${data} ${base_dir}/
      /etc/rc.d/tinydns cdb
    fi

build.sh を crontab に登録しておく。とりあえず daily で

    @daily /usr/pkg/etc/tinydns/build.sh

tinydns cdb したあとだいたい 12 時間くらいで名前解決できるようになった。けどまあこれはいろいろな要因が重なるのでなんとも言えんか。
