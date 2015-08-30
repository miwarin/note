( 無線LAN )

Panasonic Let's CF-R4G は Intel(R) PRO/Wireless 2915ABG Network Connection

wi0 とか？

* BSD magazine No.4 神戸隆博, NetBSD のモバイル状況
* [Using WaveLAN IEEE under NetBSD](http://www.netbsd.org/docs/network/wavelan.html)
* [NetBSD Blog - Introducing dhcpcd-dbus and dhcpcd-gtk](http://blog.netbsd.org/tnf/entry/introducing_dhcpcd_gtk)


sys/arch/*/conf/GENERIC を見る [Configuring the kernel](http://www.netbsd.org/docs/network/wavelan.html#configuring-the-kernel)

設定は見るだけにしておけ [Using the network](http://www.netbsd.org/docs/network/wavelan.html#using-the-network)

"ifconfig -m wi0" で確認できる。

その他 [Other WaveLAN tricks](http://www.netbsd.org/docs/network/wavelan.html#other-tricks)

    ifconfig ath0 powersave で有効
    ifconfig ath0 -powersave で無効

via [Nabble - Re: How can I scan for available ssid's?](http://www.nabble.com/Re%3A-How-can-I-scan-for-available-ssid%27s--p18514405.html)

    ifconfig [wireless device] up
    wiconfig [wireless device] -D 


*  [NetBSD Blog - Switching between wired and wireless automatically](http://blog.netbsd.org/tnf/entry/switching_between_wired_and_wireless)

> Comments:
> dhcpcd-4.99 in pkgsrc does this automatically - no need to script anything. Just Install and Go (TM) :) 


* [hubertf's NetBSD blog - Network auto-detection scripts](http://www.feyrer.de/NetBSD/bx/blosxom.cgi/nb_20070816_1133.html)
* [ymir_lin - NetBSD で wireless lan](http://my.opera.com/ymirlin/blog/2010/11/04/netbsd-wireless-lan)
* [wpa_supplicant](http://space.geocities.jp/wireless_defence/html/30wpa_supplicant.htm)

> wpa_supplicantとはIEEE802.1X/WPAを無線LANクライアントに提供するツールです。Linux以外にもWindowsやMacOS Xでも使用可能です。簡単にいうとLinuxでWPA-PSKを設定したい場合はこのツールを使用します。また802.1Xを使用する際に必要なクライアントのサプリカント機能もサポートしています
