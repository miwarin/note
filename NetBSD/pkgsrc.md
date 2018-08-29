# pkgsrc を使う

*  [Chapter 2 Where to get pkgsrc and how to keep it up-to-date](http://www.netbsd.org/docs/pkgsrc/getting.html)
*  [NetBSD パッケージシステムに関するドキュメンテーション](http://www.jp.netbsd.org/ja/docs/pkgsrc/index.html)
*  [pkgsrcめも - isihara＠つなぐねっとのぺーじ](http://www.tunagu.gr.jp/cgi-bin/fswiki/wiki.cgi/isihara?page=pkgsrc%A4%E1%A4%E2) オプションとかたくさん説明がある
*  [NetBSD wiki - pkgsrc](http://wiki.netbsd.org/pkgsrc/)

## FTP

古い /usr/pkgsrc は全て削除しておくこと

ftp://ftp.netbsd.org/pub/pkgsrc/ から取得

    cd /usr
    wget ftp://ftp.netbsd.org/pub/pkgsrc/pkgsrc-2013Q1/pkgsrc-2013Q1.tar.gz
    tar xzf pkgsrc-2013Q1.tar.gz

## CVS

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

## different version xxxx already installed

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

# バイナリパッケージをインストールする

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

# ruby 1.9 未対応

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

# パッケージを作る

## 参考

*  [Part II.The pkgsrc developer's guide](http://www.netbsd.org/docs/pkgsrc/developers-guide.html) 本家
*  [The pkgsrc guide](http://www.jp.netbsd.org/ja/docs/pkgsrc/index.html) なぜか日本語文書がある

あと mail/postfix とか www/apache22 とか devel/ruby* とか先人たちによるパッケージも眺める。

## はじめに

pkgsrc でパッケージを作るには 2 通りの方法がある。

*  url2pkg を使う: 1 から作る場合 ref. [Chapter 10. Creating a new pkgsrc package from scratch](http://www.netbsd.org/docs/pkgsrc/creating.html)
*  port2pkg を使う: FreeBSD ports に存在する場合 ref. [port2pkgを試してみる - isihara＠つなぐねっとのぺーじ](http://www.tunagu.gr.jp/cgi-bin/fswiki/wiki.cgi/isihara?page=port2pkg%A4%F2%BB%EE%A4%B7%A4%C6%A4%DF%A4%EB) 本家に文書が無いのか

## quickml パッケージを作ってみる

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

# パッケージを提出する

*  [Chapter&#160;21.&#160;提出およびコミット](http://www.jp.netbsd.org/ja/docs/pkgsrc/submit.html)

tar gz して uuencode し、[send-pr](http://www.netbsd.org/support/send-pr.html) する。

    % tar czf quickml.tgz quickml
    % uuencode quickml.tgz < quickml.tgz > quickml.tgz.uuencode

# デバッグ的な何か

## 変数の値を確認

    % make -V WRKSRC
    ${WRKDIR}/${DISTNAME}

## すべての変数の値を確認

    % make show-all

こういうもの(mk/misc/show.mk)

```
# show-all:
#	Prints a list of (hopefully) all pkgsrc variables that are visible
#	to the user or the package developer. It is intended to give
#	interested parties a better insight into the inner workings of
#	pkgsrc. Each variable name is prefixed with a "category":
#
#		* "usr" for user-settable variables,
#		* "pkg" for package-settable variables,
#		* "sys" for system-defined variables.
```

# pkgsrc クロスコンパイル

*  [Obache Watching:pkgsrc の cross-build](http://www.lins.jp/~obata/diary/200803242.html)
*  [pkgsrc/doc/HOWTO-crosscompile - view - 1.2](http://cvsweb.netbsd.org/bsdweb.cgi/pkgsrc/doc/HOWTO-crosscompile?rev=HEAD&content-type=text/x-cvsweb-markup)

# バルクビルド

この手順どおり

https://wiki.netbsd.org/tutorials/pkgsrc/pbulk/

chroot 環境を作る。chroot 環境で作業しないと /var/pkg/db 等がぶっ壊されて分けわからなくなる。

mksandbox で作る。インストールする。

    % cd /usr/pkgsrc/pkgtools/mksandbox/
    % make install clean clean-depends

実行

    % mksandbox --without-x /home/bulk
    WARNING: LOCALPATCHES directory does not exist - ignoring
    Copying the kernel
    Checking package hierarchy in /usr/pkg and package database in /var/db/pkg exist
    Make and populate /home/bulk/dev
    Make and populate /home/bulk/etc
    Make empty dirs upon which to mount the null mounts
    Making /tmp in /home/bulk
    Making /var/games in /home/bulk
    Making /var/run in /home/bulk
    Making /var/log in /home/bulk
    Making /var/spool/lock in /home/bulk
    Making /var/run/utmp in /home/bulk
    Making /var/run/utmpx in /home/bulk
    Making /var/log/wtmp in /home/bulk
    Making /var/log/wtmpx in /home/bulk
    Making /var/log/lastlog in /home/bulk
    Making /var/log/lastlogx in /home/bulk
    Mount /usr/src from /home/bulk
    Mount /usr/pkgsrc from /home/bulk
    Mounting /usr/pkgsrc/packages and /usr/pkgsrc/distfiles from /home/bulk
    Sandbox creation is now complete

mount はこんな感じ。

    % mount
    /dev/wd0a on / type ffs (local)
    /dev/wd0f on /var type ffs (local)
    /dev/wd0e on /usr type ffs (local)
    /dev/wd0g on /home type ffs (local)
    kernfs on /kern type kernfs (local)
    ptyfs on /dev/pts type ptyfs (local)
    procfs on /proc type procfs (local)
    tmpfs on /var/shm type tmpfs (local)
    /bin on /home/bulk/bin type null (read-only, local)
    /sbin on /home/bulk/sbin type null (read-only, local)
    /lib on /home/bulk/lib type null (read-only, local)
    /libexec on /home/bulk/libexec type null (read-only, local)
    /usr/bin on /home/bulk/usr/bin type null (read-only, local)
    /usr/games on /home/bulk/usr/games type null (read-only, local)
    /usr/include on /home/bulk/usr/include type null (read-only, local)
    /usr/lib on /home/bulk/usr/lib type null (read-only, local)
    /usr/libdata on /home/bulk/usr/libdata type null (read-only, local)
    /usr/libexec on /home/bulk/usr/libexec type null (read-only, local)
    /usr/share on /home/bulk/usr/share type null (read-only, local)
    /usr/sbin on /home/bulk/usr/sbin type null (read-only, local)
    /var/mail on /home/bulk/var/mail type null (read-only, local)
    /usr/src on /home/bulk/usr/src type null (read-only, local)
    /usr/pkgsrc on /home/bulk/usr/pkgsrc type null (local)
    /usr/pkgsrc/packages on /home/bulk/usr/pkgsrc/packages type null (local)
    /usr/pkgsrc/distfiles on /home/bulk/usr/pkgsrc/distfiles type null (local)

pbulk 環境を作る

    % /home/bulk/sandbox mount

    % /home/bulk/sandbox

mount はこんな感じ。

    % mount
    /bin on /bin type null (read-only, local)
    /sbin on /sbin type null (read-only, local)
    /lib on /lib type null (read-only, local)
    /libexec on /libexec type null (read-only, local)
    /usr/bin on /usr/bin type null (read-only, local)
    /usr/games on /usr/games type null (read-only, local)
    /usr/include on /usr/include type null (read-only, local)
    /usr/lib on /usr/lib type null (read-only, local)
    /usr/libdata on /usr/libdata type null (read-only, local)
    /usr/libexec on /usr/libexec type null (read-only, local)
    /usr/share on /usr/share type null (read-only, local)
    /usr/sbin on /usr/sbin type null (read-only, local)
    /var/mail on /var/mail type null (read-only, local)
    /usr/src on /usr/src type null (read-only, local)
    /usr/pkgsrc on /usr/pkgsrc type null (local)
    /usr/pkgsrc/packages on /usr/pkgsrc/packages type null (local)
    /usr/pkgsrc/distfiles on /usr/pkgsrc/distfiles type null (local)
    /dev/wd0g on / type ffs (local)

シェルは補完が効かないので on にする。

    % set -o tabcomplete
    % set -o emacs

mk.conf.frag を作る。

    % cd /
    % vi mk.conf.frag

内容

    SKIP_LICENSE_CHECK=             yes
    ALLOW_VULNERABLE_PACKAGES=      yes
    PKG_DEVELOPER?=         yes

pbulk.sh でえいやっと。

    % sh /usr/pkgsrc/mk/pbulk/pbulk.sh -n -l -c mk.conf.frag

pbulk.sh で limited_list を指定し忘れた場合は /usr/pbulk/etc/pbulk.conf を編集する。

    limited_list=/usr/pbulk/etc/pbulk.list

pbulk.list は <カテゴリ>/<パッケージ名> を書く。/usr/pkgsrc からの相対 PATH です。wip も書ける。

    devel/git
    lang/ruby
    wip/mackerel-agent

pbulk.conf を編集。ユーザー pbulk で実行されるらしく /usr/pkgsrc 以下にディレクトリとか作れないので root にする。(どこかに pbulk ユーザーで mount する手段があるのか？)

    #unprivileged_user=pbulk
    unprivileged_user=root

mk.conf.frag を指定し忘れた場合は /usr/pbulk/etc/mk.conf を編集する。

プロキシがある場合は環境変数を設定しておくこと。パッケージが fetch できないぞ。

    % env | grep proxy
    ftp_proxy=http://example.jp:8080
    no_proxy=localhost,127.0.0.1,10.1.5.0/24,192.168.100.0/24
    https_proxy=http://example.jp:8080
    rsync_proxy=http://example.jp:8080
    http_proxy=http://example.jp:8080

ビルドする

    % /usr/pbulk/bin/bulkbuild

レポートは /mnt/bulklog/meta/report.txt に出来る。

何かエラーがあったら /mnt/bulklog/meta 以下に bulkduild のフェーズごとのログがあるのでエラーを特定して解決して再度ビルドしよう。


# パッケージを全部アップグレードする

    % cd /usr/pkgsrc
    % pkg_rolling-replace -rsuv

* [how to upgrade packages](https://wiki.netbsd.org/pkgsrc/how_to_upgrade_packages/ "how to upgrade packages")

# pkgsrc-wip を使う

[The pkgsrc-wip project](https://pkgsrc.org/wip/ "The pkgsrc-wip project")

## ユーザーとして使う

wip/<パッケージ> は相対ディレクトリとして mk を include するので pkgsrc/wip にあることが前提。

    % cd /usr/pkgsrc/
    % git clone git://wip.pkgsrc.org/pkgsrc-wip.git wip

あとは普通に

    % cd wip/<パッケージ>
    % make install 

## 開発者として使う

ようするに git でコミットできるようにする。

git 利用するのが一般ユーザーであり、root ではないことを前提とする。wip 自体は一般ユーザーの ~/wip といった場所に clone する

* git で操作するときは一般ユーザーで ~/wip 以下で作業する
* パッケージをビルドするときは /usr/pkgsrc/wip/<パッケージ> で make する

という使い方とする。pkgsrc を一般ユーザーの ~/ 以下に置いて make すればいいんだろうけど習慣として /usr/pkgsrc にしとく。

### コミット権を申請する

git で wip にアクセスできるようにコミット権を貰う。手順は [committer access](https://pkgsrc.org/wip/users/ "committer access") にあるとおりに作業する。鍵を生成し、公開鍵を Thomas Klausner へ送付する。

そのとき「○○というパッケージを wip に追加したいんだけど」等と書いておくと「いいよ！バシバシやってくれよ！」といったように気軽にコミット権をくれます。

### 作業

git の操作については上記ページに書いてあるとおりにやる。

wip をビルドするときに union mount しておくと便利。

    % cd ~/
    % git clone username@wip.pkgsrc.org:/pkgsrc-wip.git wip
    % sudo mkdir /usr/pkgsrc/wip
    % sudo mount_union /home/rin/wip /usr/pkgsrc/wip

ビルドするときはこう

    % cd /usr/pkgsrc/wip/パッケージ
    % make install

パッケージを git 操作するときは ~/wip で作業する。

    % cd ~/wip
    % git commit
    % git push

# よく使うオプション

/etc/mk.conf はだいたいこんな

    ACCEPTABLE_LICENSES+=postfix-license
    ACCEPTABLE_LICENSES+=vim-license
    ACCEPTABLE_LICENSES+=gnu-agpl-v3
    X11_TYPE=modular           # システムのX11(/usr/X11R6, /usr/openwin, ...)を使わない場合。/usr/pkgsrc/x11/modular-xorg-server が使われるようになる。らしい
    PKG_OPTIONS.ImageMagick=-x11 -jasper
    PKG_OPTIONS.scmgit=-scmgit-gui
    ALLOW_VULNERABLE_PACKAGES=1
    PKG_OPTIONS.emacs=-dbus -gtk -svg -x11 -xft2 -xaw -motif -nextstep


# SSL ルート証明書をインストールする

    % cd /usr/pkgsrc/security/mozilla-rootcerts
    % make install clean clean-depends
    % mozilla-rootcerts install

ここに入る

    /etc/ssl/certs/ca-certificates.crt

# git で SSL エラーになる場合

ありがちなエラー

    % git clone https://github.com/motemen/go-cli 
    Cloning into 'go-cli'...
    fatal: unable to access 'https://github.com/motemen/go-cli/': SSL certificate problem: unable to get local issuer certificate

暫定回避策

    % git config --global http.sslVerify false

ちゃんと対策する場合は ~/.gitconfig に書く

    [http]
    sslCAinfo = /etc/ssl/certs/ca-certificates.crt

