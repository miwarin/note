* [公式のSamba 3.2.x HOWTOとリファレンスガイド - Chapter&#160;2.&#160;手軽な始め方: 短気な方への手引き](http://www.samba.gr.jp/project/translation/Samba3-HOWTO/FastStart.html)
* [How to set up a Samba Server - NetBSD Wiki](https://wiki.netbsd.org/tutorials/how_to_set_up_a_samba_server/)

そのまま


インストール

    % cd /usr/pkgsrc/net/samba4
    % sudo make install clean clean-depends

コピー

    % sudo cp /usr/pkg/share/examples/rc.d/smbd /etc/rc.d
    % sudo cp /usr/pkg/share/examples/rc.d/nmbd /etc/rc.d
    % sudo cp /usr/pkg/share/examples/rc.d/samba /etc/rc.d

/etc/rc.conf に書く

    smbd=yes
    nmbd=yes
    samba=yes

/usr/pkg/etc/samba/smb.conf に書く

    % testparm
     :
    [global]
            dos charset = CP932
            unix charset = UTF8
            server string = Samba %v (%h)
            hosts allow = 192.168.0., 127.
    
    [homes]
            comment = Home Directories
            valid users = %S
            read only = No
            browseable = No


ユーザー追加。sambaをインストールしたホスト(NetBSD)にユーザー rin が居て且つ /home/rin にはユーザー rin としてアクセスしたい場合。

    % sudo pdbedit -a rin

共有フォルダ( usr )にアクセスさせたい場合。samba においてゲストアカウントはデフォルトで nobody なので、追加しておく。sambaホスト(NetBSD)にユーザー nodoby が居る必要がある(つまり /etc/passowd に nodoby が居る必要がある)。pdedit でも nobody を追加しておく。パスワードはカラッポでかまわんでしょ(家庭内で使ってるのでテキトー)

    [usr]
            path = /usr
            read only = No
            guest only = Yes
            guest ok = Yes

ユーザー追加。

    % sudo pdbedit -a nobody

開始

    % sudo /etc/rc.d/samba start

こんな

    % smbclient -L localhost -U%
    Domain=[WORKGROUP] OS=[Unix] Server=[Samba 3.5.8]
    
            Sharename       Type      Comment
            ---------       ----      -------
            IPC$            IPC       IPC Service (Samba 3.5.8 (yukina))
    Domain=[WORKGROUP] OS=[Unix] Server=[Samba 3.5.8]
    
            Server               Comment
            ---------            -------
    
            Workgroup            Master
            ---------            -------
