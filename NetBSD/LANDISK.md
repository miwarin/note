#GigaLANDISK

##HDL-GX

* [NetBSD Documentation: Porting NetBSD to a new ARM SoC - Supporting the ARM926EJ-S Variant](http://www.netbsd.org/docs/kernel/porting_netbsd_arm_soc.html#id1136302)
* [NetBSD/evbarm](http://www.netbsd.org/ports/evbarm/) NetBSD 本家
* [NetBSD-current/src/sys/arch/evbarm/conf/ の一覧](ftp://ftp6.jp.netbsd.org/pub/NetBSD/NetBSD-current/src/sys/arch/evbarm/conf/)
* [INSTALL - Installation procedure for NetBSD/evbarm.](ftp://ftp2.jp.netbsd.org/pub/NetBSD/NetBSD-4.0_RC5/evbarm/INSTALL.html)
* [HDL-GX, HDL-Fシリーズ](http://www.freeml.com/netbsd-landisk/42/latest)

    とくだです
    
    あたらしい LANDISK シリーズの HDL-GX, HDL-Fシリーズですがどうなんでしょうか。
    (GX なのか G6 なのかよくわからん IO-DATA の Web ページ)
    
    IO-DATA にソースくれと言えば貰えるようですね。
    
    [参考] 某掲示版より HDL-GX のスペック
    
    CPU: Marvell 88F5181 (ARM926 コア)
    GbE: Marvell 88E1111
    SATA: Marvell 88SX7042
    USB: NEC D720101F1
    RTC: RICOH 5c372A
    PHY: Marvell 88E1111
    Flash: MX 29LV400CBTC-90G
    RAM: SAMSUNG K4T51163QC-ZC05
    
    その他
    ・JTAG、UART[12] 用のスルーホールが存在する。
    ・シリアルコンソールは UART1 で、設定は 115200bps、Parity: None、Data: 8bit、Stop bit: 1bit。

* [LANDISK - Wikipedia](http://ja.wikipedia.org/wiki/LANDISK) HDL-GX/GXRシリーズ
       * CPUもIntelからMarvell 88F5181に変更
       * USBコントローラはNEC製のチップ
       * SATAコントローラはMarvell 88SX7042
       * UARTが二本LAN Tankと同じピンアサインのスルーホール
       * 片方はシリアルコンソールとして機能する。

* [I-O Hack - wiki@nothing](http://wiki.nothing.sh/835.html) Giga LANDISK (HDL-GXxxx) : 160GB, 250GB, 300GB, 400GB, 500GB，750GB
       *  コア ARM系
       *  HDL-Gの後継機
       *  メモリ、動作クロックなどは据え置き
       *  WoLの廃止、USBポートの削減、LED輝度調整の廃止、eSATAポートの追加、内部のインターフェイス パラレルATAから、シリアルATAへと変更
       *  eSATAポートは、内蔵ドライブとのミラーリングでの運用も可能になっており、内蔵ドライブのクラッシュ時には、外付けからの起動も起動可能となっている。
       *  また、スケジュールパトロールリード機能、スポットリペア機能等、保守に力が入った。

###CONF

* [status for Marvell Orion support](http://mail-index.netbsd.org/current-users/2008/11/09/msg005790.html)
* [FreeBSD/arm for Marvell Orion, Kirkwood and Discovery systems-on-chip](http://wiki.freebsd.org/FreeBSDMarvell)
       * 88F5181, 88F5182, 88F5281 
* [CVS log for src/sys/arm/conf/DB-88F5XXX](http://www.jp.freebsd.org/cgi/cvsweb.cgi/src/sys/arm/conf/DB-88F5XXX)
* [Porting FreeBSD/arm to Marvell SoC](http://www.bsdcan.org/2008/schedule/attachments/50_2008_marvell_freebsd.pdf)(PDF)


###シリアルコンソール

* [HDL-GXのシリアルコンソール (musicsys)](http://musicsys.ddo.jp/dosblog/2007/10/hdlgx_2.html)

> HDL-Gシリーズの回路をそのまま刺せば大丈夫です

* [I-O Hack/シリアルコンソール - wiki@nothing](http://wiki.nothing.sh/page/I-O%20Hack/%A5%B7%A5%EA%A5%A2%A5%EB%A5%B3%A5%F3%A5%BD%A1%BC%A5%EB) HDL-G/GW/GZ/LAN Tank/GLAN Tank
* [LANDISK/serial-console - mizore Wiki](http://www.mizore.jp/wiki/index.php?LANDISK%2Fserial-console)
* [yahho - B-Wiki - LANDISK HDL-G 編](http://yahho.ii2.cc/modules/bwiki/index.php?LANDISK%20HDL-G%20%CA%D4)
* [SERIAL-KIT - SOME TANKS](http://iohack.sourceforge.jp/tanks/index.php?SERIAL-KIT)


##HDL-G

* [noname - NetBSD/gigalandisk への道](http://d.hatena.ne.jp/nonakap/20050719#p2)
* [noname - NetBSD/gigalandisk への道 最終回](http://d.hatena.ne.jp/nonakap/20050720#p1)
→i80219 or IQ80321 か？
* [私的日常非日常記録 - gigalandisk](http://www.yagoto-urayama.jp/~oshimaya/d/?200507c&to=200507213S1#200507213S1)
* [NetBSD/gigalandisk](http://diary.clarestudio.org/dd/2005-11.html) を gigalandisk で grep
       *  ベースは NetBSD/evbarm
       *  プロセッサは Intel i80219
       *  メインメモリは 128MB
       *  ehci が生えてたり
       *  bootloader は RedHat の redboot。こいつが PC/AT compatible MBR を解釈して HDD から load and run するシカケ。
* [NetBSD/evbarm HDL-G](http://www.asahi-net.or.jp/~aw9k-nnk/n/gigalandisk.html)
* [NetBSD/gigalandisk のインストール](http://www.imou.to/~AoiMoe/column/gigalandisk/install.html)

#LANDISK

##HDL

* [NetBSD/landisk](http://www.netbsd.org/Ports/landisk/) NetBSD4.0 以降
* [Installing BSD on landisk](http://www.tumfatig.net/docs/00_tut/hardware/BSD%20-%20landisk.php)
* [私的日常非日常記録 - NetBSD update landisk](http://www.yagoto-urayama.jp/~oshimaya/d/?200507b&to=200507183S1#200507183S1)
* [LANDISK/serial-console](http://www.mizore.jp/wiki/index.php?LANDISK%2Fserial-console) シリアルコンソール
* [About NetBSD/landisk](http://www.nagoya.bug.gr.jp/~oshima/netbsd/landisk/)
* [BSD小僧の日記 NetBSD/landisk](http://www.tokuda.net/diary.gns/2006_ca.html#W_%4E%65%74%42%53%44%2F%6C%61%6E%64%69%73%6B)
* [BSD小僧の日記 - fdiskでNetBSDのパーティションを作成し、disklabelを書いて、newfsする](http://www.tokuda.net/diary.gns/200611a.html#0607)
* [ftp://ftp.netbsd.org/pub/NetBSD/misc/nonaka/snapshot/landisk/ の一覧](ftp://ftp.netbsd.org/pub/NetBSD/misc/nonaka/snapshot/landisk/)
* [LANDISK HACKING DIARY](http://landisk.kororo.jp/)
* [LinkStationでNetBSDを試す - isihara＠つなぐねっとのぺーじ](http://www.tunagu.gr.jp/cgi-bin/fswiki/wiki.cgi/isihara?page=LinkStation%A4%C7NetBSD%A4%F2%BB%EE%A4%B9)
* [BSD小僧の日記 - USL-5PにNetBSD/landiskをinstallする。](http://www.tokuda.net/diary.gns/200609b.html#1602)

手順

1. fdiskで様子を確認します。
1. disklabelも確認しておきます。
1. ddを使ってセクタの先頭を破壊し、MBRを書き込みます。
1. ddの結果をfdiskで確認します。
1. fdiskでNetBSDのパーティション(sysid 169)を作ります。
1. 作成した領域をアクティブにします。
1. disklabelを作成します
1. newfsします
1. installbootでbootxx_ffsv1をインストールします
1. bootを/にコピーします。
1. base.tgz, etc.tgz, kernelを展開します。
1. MAKEDEVします。
1. fstabを作成、rc.confを編集しマルチユーザモードで起動するよう設定します
1. umountします。
