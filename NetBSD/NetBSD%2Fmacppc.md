* [NetBSD/macppc の設置](http://www.ki.nu/OHP/macppc/index.html)
* [NetBSD/macppcを入れてみる](http://homepage2.nifty.com/pinetop/imac/imac05.html)
* [NetBSD/macppc パーティショニング HOW-TO](http://www.jp.netbsd.org/ja/Ports/macppc/partitioning.html)
* [NetBSD/macppc/index](http://www.ki.nu/software/macppc2/index.html)
* [INSTALL - Installation procedure for NetBSD/macppc.](ftp://ftp.netbsd.org/pub/NetBSD/NetBSD-3.0.1/macppc/INSTALL.html)
* [NetBSD/macppc Model Support - Apple Mac mini](http://www.jp.netbsd.org/ja/Ports/macppc/models.html#macmini)
* [NetBSD/macppc よくある質問](http://www.jp.netbsd.org/ja/Ports/macppc/faq.html)
* [[BSD小僧の日記] - 2005/06c Diary - Mac mini|http://www.tokuda.net/diary.gns/200506c.html#2102]
* [[BSD小僧の日記] Mac OS XでNetBSDをbuildする|http://www.tokuda.net/diary.gns/200605b.html#1702]
* [[BSD小僧の日記] Mac OS XでNetBSDをbuildする( 二日目 )|http://www.tokuda.net/diary.gns/200605b.html#1803]
* [[BSD小僧の日記] Mac OS XでNetBSDをbuildする( 三日目 )|http://www.tokuda.net/diary.gns/200605b.html#1902]

    sudo ./build.sh -a powerpc -m evbppc release

* [[netbsd,01054] Re: How make boot HDD NetBSD/Aplha|http://www.unixmagic.org/ml/netbsd/199612/msg00003.html]  installboot の説明

1. first-stage boot program (bootxx) を元に, ffs 上にある 	second-stage boot program (boot) の物理的位置 (block numebr) を埋め込んだ image をつくる.
1. その image を, hard disk 上の所定の位置に書き込む.

* [NetBSD/macppc](http://www.ki.nu/software/NetBSD/macppc/booting/installboot.html)

> OF 1/2 の機械で disk から起動する時には bootxx がまず動く。その bootxx は sector 0 に書いてある。そうして、それは、 /boot という名前で書いてある ofwboot を呼出す。とは言うものの filesystem はまだ利用出来ない時点で /boot の位置を知る必要がある。
> このため、 bootxx に /boot の位置を (sector 数で表して) 埋込んでおいて sector 0 に書くのが installboot である。 macppc の場合、1.5ZC くらいまでは /usr/mdec/installboot に置いてあったが、 1.6 からは /usr/sbin/installboot に移っている。 
