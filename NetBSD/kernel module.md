##開発

*  [module(7) - NetBSD Manual Pages](http://netbsd.gw.com/cgi-bin/man-cgi?module+7+NetBSD-current)
*  [module(9) - NetBSD Manual Pages](http://netbsd.gw.com/cgi-bin/man-cgi?module+9+NetBSD-current)
*  [modstat - NetBSD Manual Pages](http://netbsd.gw.com/cgi-bin/man-cgi?modstat++NetBSD-current)
*  [modload(8) - NetBSD Manual Pages](http://netbsd.gw.com/cgi-bin/man-cgi?modload+8+NetBSD-current)
*  [Re: Kernel modules - documentation?](http://mail-index.netbsd.org/tech-kern/2010/05/23/msg008216.html)

src/sys/modules/example/example.c を見ろ

*  http://cvsweb.netbsd.org/bsdweb.cgi/src/sys/modules/example/example.c?only_with_tag=MAIN
*  http://cvsweb.netbsd.org/bsdweb.cgi/src/sys/sys/module.h?only_with_tag=MAIN


exampleをビルド

    % cd /usr/src/sys/modules/example

    % make
    #   compile  example/example.o
    /usr/src/obj/tooldir.NetBSD-6.0-i386/bin/i486--netbsdelf-gcc -O2 -std=gnu99  -Wall -Wstrict-prototypes -Wmissing-prototypes -Wpointer-arith -Wno-sign-compare  -Wno-traditional  -Wa,--fatal-warnings -Wreturn-type -Wswitch -Wshadow -Wcast-qual -Wwrite-strings -Wextra -Wno-unused-parameter -Wno-sign-compare -Werror   -ffreestanding  -fno-strict-aliasing -Wno-pointer-sign  -I/usr/src/common/include --sysroot=/  -nostdinc -I. -I/usr/src/sys/modules/example -isystem /usr/src/sys -isystem /usr/src/sys/arch -isystem /usr/src/sys/../common/include -D_KERNEL -D_LKM -D_MODULE -DSYSCTL_INCLUDE_DESCR -c    example.c
    #      link  example/example.kmod
    /usr/src/obj/tooldir.NetBSD-6.0-i386/bin/i486--netbsdelf-gcc  --sysroot=/ -nostdlib -r -Wl,-T,/usr/src/sys/../sys/modules/xldscripts/kmodule,-d  -o example.kmod example.o

kmod が生成される。

    % ll
    total 14
    drwxr-xr-x 2 root wheel  512 Oct 13 15:54 CVS/
    -rw-r--r-- 1 root wheel  115 May  2  2008 Makefile
    -rw-r--r-- 1 root wheel 2818 Oct 26  2010 example.c
    -rw-r--r-- 1 root wheel 1916 Dec 27 19:58 example.kmod
    -rw-r--r-- 1 root wheel 2076 Dec 27 19:58 example.o
    lrwxr-xr-x 1 root wheel   30 Dec 27 19:58 i386 -> /usr/src/sys/arch/i386/include/
    lrwxr-xr-x 1 root wheel   30 Dec 27 19:58 machine -> /usr/src/sys/arch/i386/include/
    lrwxr-xr-x 1 root wheel   29 Dec 27 19:58 x86 -> /usr/src/sys/arch/x86/include/

インストール

    % make install
    #   install  /stand/i386/6.0/modules/example/example.kmod
    dirs=/stand/i386\ /stand/i386/6.0\ /stand/i386/6.0/modules;  for d in $dirs; do  /usr/src/obj/tooldir.NetBSD-6.0-i386/bin/i486--netbsdelf-install  -N /usr/src/etc -d $d;  done
    /usr/src/obj/tooldir.NetBSD-6.0-i386/bin/i486--netbsdelf-install  -N /usr/src/etc -d /stand/i386/6.0/modules/example
    /usr/src/obj/tooldir.NetBSD-6.0-i386/bin/i486--netbsdelf-install  -N /usr/src/etc -c  -r -o root -g wheel -m 444  example.kmod /stand/i386/6.0/modules/example/example.kmod

まだ無い。

    % modstat | grep example

ロードする

    % modload /stand/i386/6.0/modules/example/example.kmod

    % modstat | grep example
    example          misc       filesys    0     599      -

メッセージ

    % tail /var/log/messages
    Dec 27 20:00:19 mogu /netbsd: Example module loaded.
    Dec 27 20:00:19 mogu /netbsd: The 'msg' property was not given.


## 利用

*  [Updating an existing system from a current snapshot](http://www.netbsd.org/docs/current/#updating-from-snapshot)
*  [Chapter 33 Updating an existing system from sources](http://www.netbsd.org/docs/guide/en/chap-updating.html)
*  [33.1.5. Summary](http://www.netbsd.org/docs/guide/en/chap-updating.html#updating-summary) 手順概要

最初に ./build.sh distribution すると ./build.sh install=/ したときに怒られるし、中途半端にやるとカーネルパニックするので install するまでやらないこと。

###summary

    # cd /usr/src
    # ./build.sh -O ../obj -T ../tools -D ../destdir tools
    # ./build.sh -O ../obj -T ../tools -D ../destdir modules
    # ./build.sh -O ../obj -T ../tools -D ../destdir kernel=MYKERNEL
    # cd /usr/obj/sys/arch/i386/compile/MYKERNEL/
    # make install
    # reboot

    # ./build.sh -O ../obj -T ../tools -D ../destdir distribution
    # ./build.sh -O ../obj -T ../tools -D ../destdir install=/

###detail

モジュールビルド

    # ./build.sh modules
     :
    ===> Successful build of kernel modules for NetBSD/i386 5.99.39
    ===> build.sh ended:      Fri Oct 22 21:58:37 JST 2010
    ===> Summary of results:
             build.sh command:    ./build.sh modules
             build.sh started:    Fri Oct 22 21:49:54 JST 2010
             NetBSD version:      5.99.39
             MACHINE:             i386
             MACHINE_ARCH:        i386
             Build platform:      NetBSD 5.0.1 i386
             HOST_SH:             /bin/sh
             TOOLDIR path:        /usr/src/obj/tooldir.NetBSD-5.0.1-i386
             DESTDIR path:        /usr/src/obj/destdir.i386
             RELEASEDIR path:     /usr/src/obj/releasedir
             Updated makewrapper: /usr/src/obj/tooldir.NetBSD-5.0.1-i386/bin/nbmake-i386
             Building modules without building new tools
             Building kernel modules for NetBSD/i386 5.99.39
             Successful build of kernel modules for NetBSD/i386 5.99.39
             build.sh ended:      Fri Oct 22 21:58:37 JST 2010
    ===> .

カーネルビルド

    # ./build.sh kernel=MYKERNEL
    # cd /usr/obj/sys/arch/i386/compile/MYKERNEL
    # make install


FFS を確認

    # dumpfs /dev/rwd0a | head -3
    file system: /dev/rwd0a
    endian  little-endian
    magic   11954 (UFS1)    time    Fri Oct 22 21:20:13 2010

bootloader 書き換え

    # cp /usr/destdir/usr/mdec/boot /
    # installboot -v /dev/rwd0a /usr/destdir/usr/mdec/bootxx_ffsv1

    # mkdir /stand/i386/5.99.39
    # cp -r /usr/obj/sys/modules /stand/i386/5.99.39
    # reboot


    # cd /usr/src
    # ./build.sh distribution
    # ./build.sh install=/
     
     :
    postinstall checks passed: bluetooth ddbonpanic dhcpcd envsys fontconfig hosts iscsi motd pam pf ssh wscons x11 varrwho
    postinstall checks failed: defaults gid makedev mtree named periodic rc xkb uid obsolete
    To fix, run:
        /usr/src/usr.sbin/postinstall/postinstall -s '/usr/src' -d // fix defaults gid makedev mtree named periodic rc xkb uid obsolete
    Note that this may overwrite local changes.
       ================================
    make installworld started at:  Sat Oct 23 13:01:07 JST 2010
    make installworld finished at: Sat Oct 23 13:04:57 JST 2010
    ===> Successful installworld to /
    ===> build.sh ended:      Sat Oct 23 13:04:58 JST 2010
    ===> Summary of results:
             build.sh command:    ./build.sh install=/
             build.sh started:    Sat Oct 23 13:01:04 JST 2010
             NetBSD version:      5.99.39
             MACHINE:             i386
             MACHINE_ARCH:        i386
             Build platform:      NetBSD 5.99.39 i386
             HOST_SH:             /bin/sh
             TOOLDIR path:        /usr/src/obj/tooldir.NetBSD-5.99.39-i386
             DESTDIR path:        /usr/src/obj/destdir.i386
             RELEASEDIR path:     /usr/src/obj/releasedir
             Updated makewrapper: /usr/src/obj/tooldir.NetBSD-5.99.39-i386/bin/nbmake-i386
             Successful installworld to /
             build.sh ended:      Sat Oct 23 13:04:58 JST 2010
    ===> .


    # /usr/src/usr.sbin/postinstall/postinstall -s '/usr/src' -d // fix defaults gid makedev mtree named periodic rc xkb uid obsolete
    # reboot

おｋ

    % uname -a
    NetBSD hitomi.area51.gr.jp 5.99.39 NetBSD 5.99.39 (MYKERNEL) #2: Fri Oct 22 20:58:00 JST 2010  root@hitomi.area51.gr.jp:/usr/obj/sys/arch/i386/compile/MYKERNEL i386
