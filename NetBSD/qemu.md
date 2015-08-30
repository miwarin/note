#参考

*  [オープンギャラリー：QEMU on NetBSD(FreeBSDの実行)](http://www.os-museum.com/qemuonbsd/qemunetbsd4/qemunetbsd4.htm)
*  [オープンギャラリー：QEMUブリッジネットワーク接続環境](http://www.os-museum.com/qemubridgenet/qemubridgenet.htm)
*  [QEMU CPUエミュレータユーザードキュメント](http://www.h7.dion.ne.jp/~qemu-win/qemu-doc-ja.html)
*  [qemu - osdev-j (MMA)](http://wiki.osdev.info/index.php?qemu)
*  [QEMU Emulator User Documentation](http://qemu.weilnetz.de/qemu-doc.html)
*  [QEMU/Images - Wikibooks, open books for an open world](http://en.wikibooks.org/wiki/QEMU/Images)
*  [QEMU/FreeDOS - Wikibooks, open books for an open world](http://en.wikibooks.org/wiki/QEMU/FreeDOS) ここを手本にしてみる

ディスクイメージ作成

    % /usr/pkg/bin/qemu-img create -f raw /home/freebsd8qemu.img 20G

    % ls -lh /home/freebsd8qemu.img
    -rw-r--r-- 1 root wheel 20G May 24 22:39 /home/freebsd8qemu.img

起動

    % qemu-system-x86_6 -m 256 -localtime /home/freebsd8qemu.img -cdrom FreeBSD-8.3-RELEASE-i386-disc1.iso


#ネットワーク

*  [networking qemu virtual bsd systems](http://bsdwiki.reedmedia.net/wiki/networking_qemu_virtual_bsd_systems.html)
*  [Sa.In.Ag.: NetBSD/sparc 5.0.2 を pkgsrc に収録の qemu-0.12.4 on NetBSD/i386 上で動かして、tap を使ってネットワークに接続する](http://sainag.blogspot.jp/2010/09/netbsdsparc-502-pkgsrc-qemu-0124-tap.html)
*  [HowTo: Qemu networking on NetBSD | dornea.nu](http://dornea.nu/articles/2010/03/01/howto-qemu-networking-netbsd)
*  [How to use Network](http://www.h7.dion.ne.jp/~qemu-win/HowToNetwork-ja.html)
