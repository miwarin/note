quickml の ruby 1.9 対応

#quickml 機能テスト

[QuickML.COM: 使い方](http://quickml.com/usage.html)


##環境

*  テストメール1: miwarin+quickmltest01 at gmail.com
*  テストメール2: miwarin+quickmltest02 at gmail.com
*  テストメール3: miwarin+quickmltest03 at gmail.com

*  テストML: test00 at qml.area51.gr.jp

## メーリングリストの作成

ml_create

enkai@quickml.com のような好きなアドレスにメールを送れば、 新しいメーリングリストを作れます

*  準備: テストMLを削除しておく
*  実施: テストML へ テストメール1 からメールを投げる
*  確認: テストML が作成されていること。テストメール1 へメールが送信されること

    Subject: テスト メーリングリストの作成
    To:  テストML
    From: テストメール1
    
    メーリングリストの作成


## メーリングリストへ投稿

ml_submission

作成したメーリングリストのアドレスにメールを送れば投稿できま す。メンバー以外からのメールは受け付けません。 

*  準備: ml_create を実施しておく
*  実施: テストMLへテストメール1からメールを投げる
*  確認: テストMLメールが流れること。テストメール1へメールが送信されること


    Subject: テスト メーリングリストへ投稿
    To: テストML
    From: テストメール1
    
    メーリングリストへ投稿


## 新しいメンバーの追加

member_add

すでに参加しているメンバーは 新しいメンバーを Cc: で追加することができます。 

*  準備: ml_create を実施しておく
*  実施: テストML へ テストメール1 からメールを投げる。Cc: にテストメール2を指定
*  確認: テストMLメールが流れること。 テストメール1 へメールが送信されること。テストメール2 へメールが送信されること。


    Subject: テスト 新しいメンバーの追加
    To: テストML
    From: テストメール1
    Cc: テストメール2
    
    新しいメンバーの追加


## メーリングリストへ参加

ml_join

すでに参加しているメンバーを知っていれば、 そのメンバーを Cc: で指定すれば メーリングリストに参加できます。 

*  準備: ml_create を実施しておく
*  実施: テストML へ テストメール3 からメールを投げる。Cc: にテストメール1 を指定。
*  確認: テストMLメールが流れること。 テストメール3 へメールが送信されること。


    Subject: テスト メーリングリストへ参加
    To: テストML
    From: テストメール3
    Cc: テストメール1
    
    メーリングリストへ参加


## メーリングリストから退会

ml_leave

メーリングリストに空メールを送ると、メーリングリストから退会できます 

*  準備: ml_create を実施しておく
*  実施: テストML へ テストメール3 から空メールを投げる。
*  確認: テストMLからテストメール3 が削除されていること。

    Subject: テスト メーリングリストから退会
    To: テストML
    From: テストメール3
    
    

##メンバーの削除

member_delete

Cc: に削除したいアドレスを指定して メーリングリストに空メールを送ると、指定したアドレスをメーリングリストから削除できます。

*  準備: ml_create と member_add を実施しておく
*  実施: テストML へ テストメール1メールを投げる。Cc: にテストメール2 を指定
*  確認: テストMLからテストメール3 が削除されていること。


    Subject: テスト メンバーの削除
    To: テストML
    From: テストメール1
    Cc: テストメール2


##メーリングリストへ復帰

ml_comeback

退会したメーリングリストに再びメールを送ると、メーリ ングリストに復帰できます。 

*  準備: ml_create ml_join ml_leave を実施しておく
*  実施: テストML へ テストメール3 からメールを投げる。
*  確認: テストMLメールが流れること。 テストメール3 へメールが送信されること。

    Subject: テスト メーリングリストへ復帰
    To: テストML
    From: テストメール3
    
    メーリングリストへ復帰

##詳細

*  メーリングリストの作成
       *  to: test00@qml.area51.gr.jp
       *  from: miwarin@gmail.com
       *  cc: 
       *  subject: テスト メーリングリストの作成
       *  body: メーリングリストの作成
*  新しいメンバーの追加
       *  to: test00@qml.area51.gr.jp
       *  from: miwarin@gmail.com
       *  cc: riinn5511@yahoo.co.jp
       *  subject: テスト 新しいメンバーの追加
       *  body: 新しいメンバーの追加
*  メーリングリストへ投稿
       *  to: test00@qml.area51.gr.jp
       *  from: miwarin@gmail.com
       *  cc: 
       *  subject: テスト メーリングリストへ投稿
       *  body: メーリングリストへ投稿
*  メーリングリストから退会
       *  to: test00@qml.area51.gr.jp
       *  from: riinn5511@yahoo.co.jp
       *  cc:
       *  subject: テスト メーリングリストから退会
       *  body: 
*  メーリングリストへ復帰
       *  to: test00@qml.area51.gr.jp
       *  from: riinn5511@yahoo.co.jp
       *  cc:
       *  subject: テスト メーリングリストへ復帰
       *  body: メーリングリストへ復帰
*  メンバーの削除
       *  to: test00@qml.area51.gr.jp
       *  from: miwarin@gmail.com
       *  cc: riinn5511@yahoo.co.jp
       *  subject: テスト メンバーの削除
       *  body: 
*  メーリングリストへ参加
       *  to: test00@qml.area51.gr.jp
       *  from: riinn5511@yahoo.co.jp
       *  cc: miwarin@gmail.com
       *  subject: テスト メーリングリストへ参加
       *  body: メーリングリストへ参加

#デバッグ

起動

ruby 1.8 と ruby 1.9 での処理を見比べながら作業

    RUBYLIB=./quickml-0.7-ruby193/lib  ruby193 ./quickml-0.7-ruby193/quickml ./quickmlrc

    RUBYLIB=./quickml-0.7-ruby18/lib  ruby18 ./quickml-0.7-ruby18/quickml ./quickmlrc

擬似サーバー

貰う。

    #!/usr/pkg/bin/ruby -Ku
    
    # -*- coding: utf-8 -*-
    
    
    # Ruby で疑似メールサーバを作ってみた http://lab.tricorn.co.jp/suzuki/315
    
    require 'socket'
    require 'syslog'
    
    
    bind_address = "0.0.0.0"
    
    # port number
    port = 25
    
    # randmax 100 means => about 1 / 100
    randmax = 100
    
    gs = TCPServer.open(bind_address, port)
    addr = gs.addr
    addr.shift
    
    syslog = Syslog.open('dummy-smtpd', Syslog::LOG_PID | Syslog::LOG_USER)
    syslog.log(Syslog::LOG_INFO, sprintf("server is on %s", addr.join(":")))
    
    while true
      Thread.start(gs.accept) do |s|
    
        # greeting
        s.write("220 welcome to dummy smtp server\n")
    
        # DATA command flag
        dataflg = false
    
        while s.gets
          # request data
          original_request = $_.chomp
          request = original_request.upcase
    
          if dataflg == true
            # in DATA stream
            if /^\.$/ =~ request
              s.write("250 OK\n")
              dataflg = false
            end
          else
            # normal request
            case request
    
            when 'DATA'
              dataflg = true
              s.write("354 OK\n")
    
            when /^RCPT TO:/
              puts original_request + ' :OK'
              #syslog.log(Syslog::LOG_INFO, original_request + ' :OK')
              s.write("250 OK\n")
            when 'QUIT'
              s.write("221 OK\n")
              s.close
    
            else
              # ok ok ok !
              s.write("250 OK\n")
            end
          end
        end
      end
    end

擬似クライアント

mail と mail-iso-2022-jp を入れておく

[mail-iso-2022-jp | RubyGems.org | your community gem host](https://rubygems.org/gems/mail-iso-2022-jp)

    gem install mail
    gem install mail-iso-2022-jp

    # coding: utf-8
    
    require 'rubygems'
    require 'mail'
    require 'pp'
    
    options = { 
      :address => "127.0.0.1",
      :port    => 10025
    }
    
    Mail.defaults do
      delivery_method :smtp, options
    end
    
    mail = Mail.new
    mail.from = 'user1@example.jp'
    mail.to =  'ml00@ml.example.jp'
    mail.subject = '日本語タイトル' 
    mail.charset ='iso-2022-jp'
    mail.add_content_transfer_encoding
    mail.body  = '日本語本文'
    mail.deliver


#ruby 1.8 → ruby 1.9

## safe_unlink

ruby 1.9 で廃止されたものは置換。

    cd quickml-0.7-ruby193/lib/quickml
    perl -pi -e "s/File\.safe_unlink/FileUtils\.safe_unlink/g" *

## String::to_a

    def encode_field (field)
      field.toeuc.gsub(/[　-瑤]\S*\s*/) {|x|
        x.scan(/.{1,10}/).map {|y|
    -      "=?ISO-2022-JP?B?" + y.tojis.to_a.pack('m').chomp + "?="
    +      "=?ISO-2022-JP?B?" + [y.tojis].to_a.pack('m').chomp + "?="
        }.join("\n ")
      }
    end
    
##incompatible character encodings:

外部エンコーディングと内部エンコーディングが異なる問題。

gettext (message.ja などの設定によってメッセージを適切に変換する) の結果(外部エンコーディングと言えるか)と、core.rb などのテキスト(内部エンコーディング) を + しようとして怒られる。

メール受信して MTA へ送信後にエラー

     :
    2013-05-30T23:13:14: Closed: 127.0.0.1
    2013-05-30T23:13:14: Unknown Session Error: Encoding::CompatibilityError: incompatible character encodings: EUC-JP and ISO-2022-JP
    2013-05-30T23:13:14: ["/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:286:in `generate_footer'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:301:in `rewrite_body'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:334:in `_submit'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:454:in `submit'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:895:in `submit_article'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:960:in `submit'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:994:in `block in process_recipient'", "<internal:prelude>:10:in `synchronize'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:990:in `process_recipient'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:1010:in `block in process'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:1009:in `each'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/core.rb:1009:in `process'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/server.rb:249:in `process'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/server.rb:266:in `block in _start'", "/usr/pkg/lib/ruby/1.9.3/timeout.rb:68:in `timeout'", "/usr/pkg/lib/ruby/1.9.3/timeout.rb:99:in `timeout'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/server.rb:265:in `_start'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/server.rb:278:in `start'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/server.rb:316:in `process_session'", "/home/rin/usr/local/quickmltest/quickml-0.7-ruby193/lib/quickml/server.rb:298:in `block in accept'"]


    def generate_footer (member_list_p = false)
      footer = "\n--\n" + "ML: #{@address}\n" + 
      _("Info: %s\n", @config.info_url)          ← ここでエラー。gettext が _ に alias されてる

obata さんからメール貰った。

    2013/5/29 OBATA Akio <obache@netbsd.org>:
    I have no clear idea...but is it possible to modify gettext instead?
    force_encoding("ASCII-8BIT")?

gettext() で force_encoding("ASCII-8BIT") してみた。

とりあえずエラーにはならない。

    def gettext (text, *args)
      unless @catalog && @catalog.charset == @message_charset
        return sprintf(text, *args).force_encoding("ASCII-8BIT")
      end

      translated_message = @catalog.messages[text]    
      if translated_message
        codeconv(sprintf(translated_message, *args)).force_encoding("ASCII-8BIT")
      else
        sprintf(text, *args).force_encoding("ASCII-8BIT")
      end
    end
