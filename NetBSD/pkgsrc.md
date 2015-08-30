#pkgsrc を使う

*  [Chapter 2 Where to get pkgsrc and how to keep it up-to-date](http://www.netbsd.org/docs/pkgsrc/getting.html)
*  [NetBSD パッケージシステムに関するドキュメンテーション](http://www.jp.netbsd.org/ja/docs/pkgsrc/index.html)
*  [pkgsrcめも - isihara＠つなぐねっとのぺーじ](http://www.tunagu.gr.jp/cgi-bin/fswiki/wiki.cgi/isihara?page=pkgsrc%A4%E1%A4%E2) オプションとかたくさん説明がある
*  [NetBSD wiki - pkgsrc](http://wiki.netbsd.org/pkgsrc/)

##FTP

古い /usr/pkgsrc は全て削除しておくこと

ftp://ftp.netbsd.org/pub/pkgsrc/ から取得

    cd /usr
    wget ftp://ftp.netbsd.org/pub/pkgsrc/pkgsrc-2013Q1/pkgsrc-2013Q1.tar.gz
    tar xzf pkgsrc-2013Q1.tar.gz

##CVS

csh系

    setenv CVSROOT anoncvs@anoncvs.NetBSD.org:/cvsroot
    setenv CVS_RSH ssh

または sh 系

    export CVSROOT="anoncvs@anoncvs.NetBSD.org:/cvsroot"
    export CVS_RSH="ssh"

取得

    cd /usr
    cvs checkout -P pkgsrc

アップデート

    cd /usr/pkgsrc
    cvs update -dP

##different version xxxx already installed

なにかのパッケージを make install している途中で

    different version xxxx already installed

などと言われたら

    % cd /usr/pkgsrc/pkgtools/pkg_tarup/
    % make install clean clean-depends

その後 怒られたパッケージのディレクトリへ移動し

    % make replace

その後 元々インストールしようとしていたパッケージへ戻り make install

[obache](https://twitter.com/obache/statuses/235726030663458816)

> @miwarin pkg_admin rebuild=YES pkg1 pkg2... したのち、pkgtools/pkg_rolling-replace 入れて、pkg_rolling-replace すれば放置可能。

#バイナリパッケージをインストールする

[Chapter&#160;4.&#160;Using pkgsrc - 4.1.2. Installing binary packages](http://www.netbsd.org/docs/pkgsrc/using.html#installing-binary-packages)

NetBSD 6.1.2 / i386 とする

配布元 http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/

たとえばここ:

http://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/i386/6.1.2/All/

設定

    PATH="/usr/pkg/sbin:$PATH"
    PKG_PATH="ftp://ftp.netbsd.org/pub/pkgsrc/packages/NetBSD/i386/6.1.2/All/"
    export PATH PKG_PATH

インストール

    pkg_add gimp-2.8.10
    pkg_add mng-2.0.2

#ruby 1.9 未対応

(2012-08-16)

    rin@mogu[/usr/pkgsrc]% grep -r "RUBY_VERSION_SUPPORTED.*18.*" *
    audio/amarok-kde3/Makefile:RUBY_VERSION_SUPPORTED=      18
    converters/ruby-uconv/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-debug/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-debug-base/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-debug-extra/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-debug-ide/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-eet/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-linecache/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-rbx-require-relative/Makefile:RUBY_VERSION_SUPPORTED= 18
    devel/ruby-rcov/Makefile:RUBY_VERSION_SUPPORTED=        18
    graphics/ruby-clutter/Makefile:RUBY_VERSION_SUPPORTED= 18
    graphics/ruby-clutter-cairo/Makefile:RUBY_VERSION_SUPPORTED= 18
    graphics/ruby-clutter-core/Makefile:RUBY_VERSION_SUPPORTED= 18
    graphics/ruby-clutter-gtk/Makefile:RUBY_VERSION_SUPPORTED= 18
    inputmethod/prime/Makefile:RUBY_VERSION_SUPPORTED= 18
    inputmethod/prime-el/Makefile:RUBY_VERSION_SUPPORTED= 18
    inputmethod/scim-prime/Makefile:RUBY_VERSION_SUPPORTED= 18
    lang/ruby/rubyversion.mk:RUBY_VERSION_SUPPORTED?= 18 192 193
    lang/ruby18/Makefile:RUBY_VERSION_SUPPORTED=    18
    lang/ruby18-base/Makefile:RUBY_VERSION_SUPPORTED=       18
    misc/howm/Makefile:RUBY_VERSION_SUPPORTED= 18
    multimedia/ruby-clutter-gst/Makefile:RUBY_VERSION_SUPPORTED= 18
    net/dnsdoctor/Makefile:RUBY_VERSION_SUPPORTED=  18
    textproc/ruby-eruby/Makefile:RUBY_VERSION_SUPPORTED= 18
    textproc/xhtmldiff/Makefile:RUBY_VERSION_SUPPORTED= 18
    www/ap-ruby/Makefile:RUBY_VERSION_SUPPORTED= 18
    x11/kdebindings-ruby/Makefile:RUBY_VERSION_SUPPORTED= 18



#パッケージを作る

##参考

*  [Part II.The pkgsrc developer's guide](http://www.netbsd.org/docs/pkgsrc/developers-guide.html) 本家
*  [The pkgsrc guide](http://www.jp.netbsd.org/ja/docs/pkgsrc/index.html) なぜか日本語文書がある

あと mail/postfix とか www/apache22 とか devel/ruby* とか先人たちによるパッケージも眺める。

##はじめに

pkgsrc でパッケージを作るには 2 通りの方法がある。

*  url2pkg を使う: 1 から作る場合 ref. [Chapter 10. Creating a new pkgsrc package from scratch](http://www.netbsd.org/docs/pkgsrc/creating.html)
*  port2pkg を使う: FreeBSD ports に存在する場合 ref. [port2pkgを試してみる - isihara＠つなぐねっとのぺーじ](http://www.tunagu.gr.jp/cgi-bin/fswiki/wiki.cgi/isihara?page=port2pkg%A4%F2%BB%EE%A4%B7%A4%C6%A4%DF%A4%EB) 本家に文書が無いのか

##quickml パッケージを作ってみる

url2pkg を使ってみた

最終的にはこう

Makefile


    # $NetBSD$
    #
    
    DISTNAME=       quickml-0.7
    CATEGORIES=     mail
    MASTER_SITES=   http://0xcc.net/quickml/
    
    MAINTAINER=     pkgsrc-users@NetBSD.org
    HOMEPAGE=       http://0xcc.net/quickml/
    COMMENT=        Easy-to-use mailing list system
    LICENSE=        gnu-gpl-v2
    
    QUICKML_USER=   quickml
    QUICKML_GROUP=  quickml
    PKG_GROUPS=     ${QUICKML_GROUP}
    PKG_USERS=      ${QUICKML_USER}:${QUICKML_GROUP}
    USERGROUP_PHASE=        configure
    
    #PKG_DESTDIR_SUPPORT=   user-destdir
    
    GNU_CONFIGURE=  yes
    USE_LANGUAGES=  # none
    
    RCD_SCRIPTS+=   quickml
    
    QUICKML_DATA_DIR=       ${PREFIX}/var/quickml
    
    .include "options.mk"
    
    .include "../../lang/ruby/buildlink3.mk"
    
    CONFIGURE_ARGS+=        --datadir=${QUICKML_DATA_DIR}
    CONFIGURE_ARGS+=        --with-ruby=${RUBY}
    CONFIGURE_ARGS+=        --with-user=${QUICKML_USER}
    CONFIGURE_ARGS+=        --with-group=${QUICKML_GROUP}
    CONFIGURE_ARGS+=        --with-rubydir=${RUBY_SITELIB}
    
    
    post-install:
            ${MKDIR} ${QUICKML_DATA_DIR}
            ${INSTALL_DATA} ${WRKSRC}/messages.ja ${QUICKML_DATA_DIR}
    
    
    
    .include "../../mk/bsd.pkg.mk"


DESCR


    quickml server is a very-easy-to-use mailing list system. quickml
    server provides very-easy-to-use mailing list service.
    
    - Yuichiro AIZAWA
    yaizawa@mdbl.sfc.keio.ac.jp


PLIST

    bin/quickml-analog
    etc/quickmlrc.sample
    sbin/quickml
    sbin/quickml-ctl
    share/examples/rc.d/quickml
    var/quickml/messages.ja


files/quickml.sh  ( /etc/rc.d/quickml として設置する。quickml-ctl があるのでそれを呼び出してるだけ )

    #!/bin/sh
    #
    # $FreeBSD: ports/mail/quickml/files/quickml.in,v 1.2 2010/02/13 21:17:42 dougb Exp $
    #
    
    # PROVIDE: quickml
    # REQUIRE: LOGIN
    #
    # Add the following lines to /etc/rc.conf.local or /etc/rc.conf
    # to enable this service:
    #
    # quickml=YES
    
    name="quickml"
    command="/usr/pkg/sbin/${name}-ctl"
    $command "$1"

options.mk


    PKG_OPTIONS_VAR=        PKG_OPTIONS.quickml
    PKG_SUPPORTED_OPTIONS+= limit analog
    
    
    .include "../../mk/bsd.options.mk"
    
    
    .if !empty(PKG_OPTIONS:Mlimit)
    LIMIT_PATCH=  quickml-0.7-limited.patch
    PATCHFILES+=            ${LIMIT_PATCH}
    #SITES.${LIMIT_PATCH}=        http://linux.matchy.net/view.xcg?c=plugin;plugin=attach_download;p=QuickMLLimited;file_name=
    SITES.${LIMIT_PATCH}=        http://matchy.s28.xrea.com/hiki.xcg?c=plugin;plugin=attach_download;p=QuickMLLimited;file_name=
    PATCH_DIST_STRIP.${LIMIT_PATCH}=     -p1
    .endif
    
    
    .if !empty(PKG_OPTIONS:Manalog)
    .include "../../graphics/ImageMagick/buildlink3.mk"
    DEPENDS+=      gnuplot>=3.7:../../graphics/gnuplot
    .endif

#パッケージを提出する

*  [Chapter&#160;21.&#160;提出およびコミット](http://www.jp.netbsd.org/ja/docs/pkgsrc/submit.html)

tar gz して uuencode し、[send-pr](http://www.netbsd.org/support/send-pr.html) する。

    % tar czf quickml.tgz quickml
    % uuencode quickml.tgz < quickml.tgz > quickml.tgz.uuencode

#デバッグ的な何か

##変数の値を確認

    % make -V WRKSRC
    ${WRKDIR}/${DISTNAME}

#pkgsrc クロスコンパイル

*  [Obache Watching:pkgsrc の cross-build](http://www.lins.jp/~obata/diary/200803242.html)
*  [pkgsrc/doc/HOWTO-crosscompile - view - 1.2](http://cvsweb.netbsd.org/bsdweb.cgi/pkgsrc/doc/HOWTO-crosscompile?rev=HEAD&content-type=text/x-cvsweb-markup)

#バルクビルド

wiki のとおりにやればよい

*  [Chapter 7. Creating binary packages for everything in pkgsrc (bulk builds)](http://www.netbsd.org/docs/pkgsrc/bulk.html)
*  [Chapter&#160;7.&#160;pkgsrc のバイナリーパッケージを全部作成する (バルクビルド)](http://www.jp.netbsd.org/ja/docs/pkgsrc/bulk.html)
*  [pbulk](http://wiki.netbsd.org/tutorials/pkgsrc/pbulk/)
