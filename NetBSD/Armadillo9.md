##参考

* [Armadillo-9 - TOKUDA.NET WIKI](http://www.tokuda.net/cgi-bin/fswiki/wiki.cgi?page=Armadillo%2D9)
* [Install NetBSD/evbarm in Armadillo-9 (MicroDrive)](http://www.tokuda.net/NetBSD/Armadillo9/install_md4g.html)
* [BSD小僧の日記 NetBSD/evbarm (9)](http://www.tokuda.net/diary.gns/2006_ca.html#W_%4E%65%74%42%53%44%2F%65%76%62%61%72%6D)
* [Re: panic: pmap_map_chunk: no L2 table for VA 0xc0400000](http://mail-index.netbsd.org/port-arm/2008/05/07/msg000190.html)

##作業前

    armadillo9:~# fdisk /dev/hdc
    
    The number of cylinders for this disk is set to 7936.
    There is nothing wrong with that, but this is larger than 1024,
    and could in certain setups cause problems with:
    1) software that runs at boot time (e.g., old versions of LILO)
    2) booting and partitioning software from other OSs
       (e.g., DOS FDISK, OS/2 FDISK)
    
    Command (m for help): u
    Changing display/entry units to cylinders
    
    Command (m for help): p
    
    Disk /dev/hdc: 4095 MB, 4095737856 bytes
    16 heads, 63 sectors/track, 7936 cylinders
    Units = cylinders of 1008 * 512 = 516096 bytes
    
       Device Boot      Start         End      Blocks   Id  System
    /dev/hdc1               1          13        6520+  83  Linux    ← Linux の区画は 1024 cylinder 内に収まってる
    /dev/hdc2              14        7936     3993192   a9  NetBSD
    /dev/hdc3               1           1           0    0  Empty
    Partition 3 does not end on cylinder boundary.

[Large Disk HOWTO: ブート](http://www.linux.or.jp/JF/JFdocs/Large-Disk-HOWTO-5.html)

> BIOS がアクセス可能なディスク - おそらく一台目か二台目のディスク - の最初の 1024 シリンダ内に完全に収まるパーティションに、カーネル(と、LILO のマップファイルのようにもしかしたらブートアップの最中に使用されるかもしれない他のファイル) を配置すればいいのです。したがって、カーネル用の領域として 10 MB くらいの小さなパーティションを、一台目か二台目のディスクの先頭から 1024 シリンダ内に完全に収まるように作成してください。これを /boot としてマウントし、 LILO がここにカーネルを置くようにしてください。 

##ファイル準備

via [BSD小僧の日記](http://www.tokuda.net/diary.gns/200602b.html#1902)

/usr/src/sys/arch/evbarm/conf/ARMADILLO9 の netbsd カーネルを作るようにする。

    config netbsd root on ? type ?
    config netbsd-epe0 root on epe0 type nfs
    config netbsd-wd0 root on wd0 type ffs
    config netbsd-sd0 root on sd0 type ffs

/usr/src/sys/arch/evbarm/conf/ARMADILLO9_INSTALL を作る

    #      $NetBSD$
    #
    #      ARMADILLO9_INSTALL -- ARMADILLO9 kernel with installation-sized
    #      ramdisk
    #
    
    include "arch/evbarm/conf/ARMADILLO9"
    include "arch/evbarm/conf/INSTALL"

/usr/src/etc/etc.evbarm/Makefile.inc を変更する

    .if ${MACHINE_ARCH} == "arm"
    # Little endian platforms
    EVBARM_BOARDS=         ARMADILLO9 ADI_BRH INTEGRATOR IQ80310 IQ80321 SMDK2410 SMDK2800 \
                           TEAMASA_NPWR TS7200 TWINTAIL

##ビルド

    ./build.sh -m evbarm -O /usr/src/evbarm.obj -T /usr/src/evbarm.tools -D /usr/src/evbarm.destdir -R /usr/src/evbarm.release tools | tee evbarm.tools.log

    ./build.sh -m evbarm -O /usr/src/evbarm.obj -T /usr/src/evbarm.tools -D /usr/src/evbarm.destdir -R /usr/src/evbarm.release kernel=ARMADILLO9 release | tee evbarm.release.log

    ===> Summary of results:
             build.sh command: ./build.sh -m evbarm -O /usr/src/evbarm.obj -T /usr/src/evbarm.tools -D /usr/src/evbarm.destdir -R /usr/src/evbarm.release kernel=ARMADILLO9 release
             build.sh started: Wed Jun 18 20:04:41 JST 2008
             NetBSD version:   4.99.65
             MACHINE:          evbarm
             MACHINE_ARCH:     arm
             Build platform:   NetBSD 4.99.64 i386
             HOST_SH:          /bin/sh
             TOOLDIR path:     /usr/src/evbarm.tools
             DESTDIR path:     /usr/src/evbarm.destdir
             RELEASEDIR path:  /usr/src/evbarm.release
             makewrapper:      /usr/src/evbarm.tools/bin/nbmake-evbarm
             Updated /usr/src/evbarm.tools/bin/nbmake-evbarm
             Building kernel without building new tools
             Building kernel:  ARMADILLO9
             Build directory:  /usr/src/evbarm.obj/sys/arch/evbarm/compile/ARMADILLO9
             Kernels built from ARMADILLO9:
              /usr/src/evbarm.obj/sys/arch/evbarm/compile/ARMADILLO9/netbsd
              /usr/src/evbarm.obj/sys/arch/evbarm/compile/ARMADILLO9/netbsd-epe0
              /usr/src/evbarm.obj/sys/arch/evbarm/compile/ARMADILLO9/netbsd-wd0
              /usr/src/evbarm.obj/sys/arch/evbarm/compile/ARMADILLO9/netbsd-sd0
             Successful make release
             build.sh ended:   Thu Jun 19 00:58:48 JST 2008
    ===> .

##PCを使ったNetBSD/evbarmのインストール

[Install NetBSD/evbarm in Armadillo-9 (MicroDrive)](http://www.tokuda.net/NetBSD/Armadillo9/install_md4g.html) のまま作業する。

    newfs -O 2 /dev/rsd0a
    mount -t ext2fs /dev/sd0f /mnt
    cp /usr/src/evbarm.release/evbarm/binary/kernel/netbsd-wd0.bin-ARMADILLO9.gz /mnt/boot/Image.gz
    umount /mnt

    mount -t ffs /dev/sd0a /mnt
    mkdir /mnt/sets
    cd /usr/src/evbarm.release/evbarm/binary/sets
    cp base.tgz comp.tgz etc.tgz games.tgz man.tgz misc.tgz text.tgz kern-ARMADILLO9.tgz /mnt/sets
    cd /mnt
    foreach i (/mnt/sets/*.tgz)
    foreach> pax -rzpe -f $i
    foreach> end

    cd dev
    ./MAKEDEV all

fstab を書く

    cd /mnt/etc/
    cat > fstab
    /dev/wd0a / ffs rw,softdep 1 1
    /dev/wd0b none swap sw 0 0

/mnt/etc/rc.conf を書く

    rc_configured=YES
    
    # Add local overrides below
    #
    defaultroute="192.168.0.1"
    hostname=sakura.area51.gr.jp
    wscons=YES
    sshd=YES
    ntpd=yes

/mnt/etc/ifconfig.epe0 を書く

    up
    192.168.0.20 netmask 255.255.255.0 media autoselect

/mnt/etc/resolv.conf を書く

    nameserver 218.45.16.73


    cd /
    sync
    umount /mnt

##起動

NetBSD version:   4.99.55 で試した。ジャンパを**刺して** 電源を入れた。起動した。途中で止まった。

    Hermit-At v1.0.0 (armadillo9) compiled at 18:43:28, Sep 26 2005
    Disk drive detected: HMS360604D5CF00 DP4OC40D       DNP450B4VL6ABA 
    /dev/hdc1: start=0x0000003f, size=0x000032f1
    Image.gz is found.
    Copying        kernel.......done.
    Uncompressing  kernel................................................................................................done.
    Doing noinitrd
    Doing root=/dev/hdc
    Doing mtdparts=armadillo9-nor:0x10000(bootloader)ro,0x170000(kernel),0x670000(userland),-(config)
    
    NetBSD/Armadillo-9 booting ...
    Copyright (c) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,
        2006, 2007, 2008
        The NetBSD Foundation, Inc.  All rights reserved.
    Copyright (c) 1982, 1986, 1989, 1991, 1993
        The Regents of the University of California.  All rights reserved.
    
    NetBSD 4.99.55 (ARMADILLO9) #4: Mon Mar 10 21:38:16 JST 2008
    	rin@yukina.area51.gr.jp:/usr/obj/sys/arch/evbarm/compile/ARMADILLO9
    total memory = 65536 KB
    avail memory = 60292 KB
    mainbus0 (root)
    cpu0 at mainbus0: ARM920T rev 0 (ARM9TDMI core)
    cpu0: DC enabled IC enabled WB enabled EABT
    cpu0: 16KB/32B 64-way Instruction cache
    cpu0: 16KB/32B 64-way write-back-locking-A Data cache
    epsoc0 at mainbus0: Cirrus Logic EP93xx SoC rev E0
    epsoc0: fclk 200.02 MHz hclk 100.01 MHz pclk 50.00 MHz
    epclk0 at epsoc0 addr 0x80810000-0x8081008f intr 4
    epgpio0 at epsoc0 addr 0x80840000-0x808400cb intr 59
    gpio0 at epgpio0: port A: 8 pins
    gpio1 at epgpio0: port B: 8 pins
    gpio2 at epgpio0: port C: 8 pins
    gpio3 at epgpio0: port D: 8 pins
    gpio4 at epgpio0: port E: 8 pins
    gpio5 at epgpio0: port F: 8 pins
    gpio6 at epgpio0: port G: 8 pins
    gpio7 at epgpio0: port H: 8 pins
    epled0 at epgpio0: port E bit1 0 bit2 1
    armadillo9iic0 at epgpio0: port B bit1 4 bit2 5
    iic0 at armadillo9iic0: I2C bus
    seeprom0 at iic0 addr 0x50: AT24Cxx EEPROM


NetBSD version: 4.99.65 で試した。L2 が見つからない。

    Hermit-At v1.0.0 (armadillo9) compiled at 18:43:28, Sep 26 2005
    Disk drive detected: HMS360604D5CF00 DP4OC40D       DNP450B4VL6ABA
    /dev/hdc1: start=0x0000003f, size=0x000032f1
    Image.gz is found.
    Copying        kernel.......done.
    Uncompressing  kernel.................................................................................................done.
    Doing noinitrd
    Doing root=/dev/hdc
    Doing mtdparts=armadillo9-nor:0x10000(bootloader)ro,0x170000(kernel),0x670000(userland),-(config)
    
    NetBSD/Armadillo-9 booting ...
    panic: pmap_map_chunk: no L2 table for VA 0xc0400000
    
NetBSD 4.0 RELEASE で試した。起動した。

    Hermit-At v1.0.0 (armadillo9) compiled at 18:43:28, Sep 26 2005
    Disk drive detected: HMS360604D5CF00 DP4OC40D       DNP450B4VL6ABA 
    /dev/hdc1: start=0x0000003f, size=0x000032f1
    Image.gz is found.
    Copying        kernel.......done.
    Uncompressing  kernel............................................................................................done.
    Doing noinitrd
    Doing root=/dev/hdc
    Doing mtdparts=armadillo9-nor:0x10000(bootloader)ro,0x170000(kernel),0x670000(userland),-(config)
    NetBSD/Armadillo-9 booting ...
    Copyright (c) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,
        2006, 2007
        The NetBSD Foundation, Inc.  All rights reserved.
    Copyright (c) 1982, 1986, 1989, 1991, 1993
        The Regents of the University of California.  All rights reserved.
    
    NetBSD 4.0 (ARMADILLO9) #1: Mon Jun 23 22:51:22 JST 2008
    rin@megumi.area51.gr.jp:/usr/src/evbarm.obj/sys/arch/evbarm/compile/ARMADILLO9
    total memory = 65536 KB
    avail memory = 60540 KB
    mainbus0 (root)
    cpu0 at mainbus0: ARM920T rev 0 (ARM9TDMI core)
    cpu0: DC enabled IC enabled WB enabled EABT
    cpu0: 16KB/32B 64-way Instruction cache
    cpu0: 16KB/32B 64-way write-back-locking-A Data cache
    epsoc0 at mainbus0: Cirrus Logic EP93xx SoC rev E0
    epsoc0: fclk 200.02 MHz hclk 100.01 MHz pclk 50.00 MHz
    epclk0 at epsoc0 addr 0x80810000-0x8081008f intr 4
    epgpio0 at epsoc0 addr 0x80840000-0x808400cb intr 59
    gpio0 at epgpio0: port A: 8 pins
    gpio1 at epgpio0: port B: 8 pins
    gpio2 at epgpio0: port C: 8 pins
    gpio3 at epgpio0: port D: 8 pins
    gpio4 at epgpio0: port E: 8 pins
    gpio5 at epgpio0: port F: 8 pins
    gpio6 at epgpio0: port G: 8 pins
    gpio7 at epgpio0: port H: 8 pins
    epled0 at epgpio0: port E bit1 0 bit2 1
    armadillo9iic0 at epgpio0: port B bit1 4 bit2 5
    iic0 at armadillo9iic0: I2C bus
    seeprom0 at iic0 addr 0x50: AT24Cxx EEPROM
    ohci0 at epsoc0 addr 0x80020000-0x80020fff intr 56
    epe0 at epsoc0 addr 0x80010000-0x8001ffff intr 39
    epe0: MAC address 00:11:0c:02:07:61
    lxtphy0 at epe0 phy 0: LXT971/2 10/100 media interface, rev. 2
    lxtphy0: 10baseT, 10baseT-FDX, 100baseTX, 100baseTX-FDX, auto
    epcom0 at epsoc0 addr 0x808c0000-0x808c0fff intr 52
    epcom0: console
    epcom1 at epsoc0 addr 0x808d0000-0x808d0fff intr 54
    epwdog0 at epsoc0 addr 0x80940000-0x80940007 intr 36
    eppcic0 at epsoc0 addr 0x80080020-0x80080043 intr 49
    pcmcia0 at eppcic0
    eprtc0 at epsoc0 addr 0x80920000-0x8092010b intr 37
    ohci0: OHCI version 1.0
    usb0 at ohci0: USB revision 1.0
    uhub0 at usb0
    uhub0: Cirrus Logic OHCI root hub, class 9/0, rev 1.00/1.00, addr 1
    uhub0: 3 ports with 3 removable, self powered
    wdc0 at pcmcia0 function 0: <HITACHI, microdrive>
    wdc0: i/o mapped mode
    atabus0 at wdc0 channel 0
    wd0 at atabus0 drive 0: <HMS360604D5CF00>
    wd0: drive supports 32-sector PIO transfers, LBA addressing
    wd0: 3906 MB, 7936 cyl, 16 head, 63 sec, 512 bytes/sect x 7999488 sectors
    wd0: drive supports PIO mode 4
    boot device: <unknown>
    root on wd0a dumps on wd0b
    WARNING: preposterous TOD clock time
    WARNING: using filesystem time
    WARNING: CHECK AND RESET THE DATE!
    Wed Jun 25 10:22:05 UTC 2008
    swapctl: adding /dev/wd0b as swap device at priority 0
    Checking for botched superblock upgrades: done.
    Starting file system checks:
    /dev/rwd0a: file system is clean; not checking
    Setting tty flags.
    Setting sysctl variables:
    Starting network.
    Hostname: sakura.area51.gr.jp
    IPv6 mode: host
    Configuring network interfaces: epe0.
    add net default: gateway 192.168.0.1
    Adding interface aliases:
    Building databases...
    wsconscfg: Cannot open `/dev/ttyEcfg': Device not configured
    wsconscfg: Cannot open `/dev/ttyEcfg': Device not configured
    wsconscfg: Cannot open `/dev/ttyEcfg': Device not configured
    wsconscfg: Cannot open `/dev/ttyEcfg': Device not configured
    Starting syslogd.
    Checking for core dump...
    savecore: no core dump
    Mounting all filesystems...
    Clearing /tmp.
    Creating a.out runtime link editor directory cache.
    Checking quotas: done.
    Setting securelevel: kern.securelevel: 0 -> 1
    Starting virecover.
    Starting local daemons:.
    Updating motd.
    Starting ntpd.
    Starting sshd.
    postfix/postfix-script: starting the Postfix mail system
    Starting inetd.
    Starting cron.
    Wed Jun 25 10:22:22 UTC 2008
    
    NetBSD/evbarm (sakura.area51.gr.jp) (console)
    
    login: root

uname

    sakura# unmame -a
    NetBSD sakura.area51.gr.jp 4.0 NetBSD 4.0 (ARMADILLO9) #1: Mon Jun 23 22:51:22 JST 2008  rin@megumi.area51.gr.jp:/usr/src/evbarm.obj/sys/arch/evbarm/compile/ARMADILLO9 evbarm
