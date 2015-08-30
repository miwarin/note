[How to use FUSE in NetBSD - NetBSD Wiki](http://wiki.netbsd.se/index.php/How_to_use_FUSE_in_NetBSD)

[Filesystems in userspace: puffs, refuse, FUSE, and more](http://www.netbsd.org/docs/puffs/)

有効にする。

    /etc/mk.conf:
    MKPUFFS=yes
    
    kernel config:
    file-system PUFFS
    OR
    /etc/lkm.conf:
    # change BEFOREMOUNT to BEFORENET if /var or /usr is puffs
    puffs.o -s - - - BEFOREMOUNT

/dev/puffs を作る。

==(cd /dev ; sh MAKEDEV puffs)==

    (cd /dev ; sh MAKEDEV putter)

putter も要る。

    # Pass-to-Userspace Transporter
    pseudo-device   putter

puffs sshfs

    mount_psshfs host.name.tld:/directory /puffs

pkgsrc & FUSE → [pkgsrc/filesystems](ftp://ftp.netbsd.org/pub/pkgsrc/current/pkgsrc/filesystems/README.html)
