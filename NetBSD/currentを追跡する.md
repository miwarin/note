[Tracking NetBSD-current](http://www.netbsd.org/docs/current/index.html)

anoncvs を準備( [Using anoncvs](http://www.netbsd.org/docs/current/index.html#using-anoncvs-pserver) )

    setenv CVSROOT :pserver:anoncvs@anoncvs.NetBSD.org:/cvsroot

または

    CVSROOT=:pserver:anoncvs@anoncvs.NetBSD.org:/cvsroot; export CVSROOT

    cd /usr
    cvs login

パスワードは "anoncvs"

anoncvs で current を追跡( [Tracking NetBSD-current with anoncvs](http://www.netbsd.org/docs/current/index.html#using-anoncvs) )

準備

    mkdir /usr/obj
    mkdir /usr/tools

    cd /usr
    cvs checkout -P src

リリースブランチを取得する場合はこう

    cvs co -r netbsd-5-1-RELEASE -P src

アップデート

    cd /usr/src
    cvs update -dP

既存システムをアップデート( [Chapter&#160;33.&#160;Updating an existing system from sources](http://www.netbsd.org/docs/guide/en/chap-updating.html) )

From the root of the source tree:

    cd /usr/src

Build the toolchain:

    ./build.sh -O ../obj -T ../tools -D ../destdir tools | tee tools.log

Build the distribution:

    ./build.sh -O ../obj -T ../tools -D ../destdir distribution | tee distribution.log

Build the kernel:

    ./build.sh -O ../obj -T ../tools -D ../destdir kernel=MYKERNEL | tee kernel.log

Install the kernel:

    cd /usr/src/obj/sys/arch/i386/compile/MYKERNEL
    make install
    reboot

Install the new userland:

    cd /usr/src
    ./build.sh -O ../obj -T ../tools -D ../destdir install=/ | tee userland.log

Follow the instruction in the output for fixing obsolete files, for example:

    /usr/src/usr.sbin/postinstall/postinstall -s /usr/src -d // fix defaults mtree obsolete

Update /etc:

    /usr/sbin/etcupdate -s /usr/src

Optionally reboot to ensure all running services are using the new binaries:

    reboot


##忙しい人のための

[How to build NetBSD-current - NetBSD Wiki](http://wiki-static.aydogan.net/How_to_build_NetBSD-current)

    ./build.sh -O ../obj -T ../tools -D ../destdir tools distribution kernel=MYKERNEL


##参考

* [rr.homeunix.net - NetBSDメモ](http://www.rr.homeunix.net/netbsd/)
       * [NetBSD-current の追いかけ方](http://www.rr.homeunix.net/netbsd/current.html)
* [Appendix B. sysinst を使わないインストール](http://nobug.tukusi.ne.jp/netbsd-guide/trans/ap-inst.html)
* [current を追っかけるときの注意点](http://tack.fukui-med.ac.jp/NetBSD/ja/Note_for_Current.html)
* [NetBSD - Anonymous CVS server](http://www.jp.netbsd.org/ja/JP/Documentation/anoncvs.html)
* [NetBSD を 新しくする](http://www.takemaru.com/microserver/technote/netbsd_update.txt)
