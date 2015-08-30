##参考

* [NetBSDでサポートされている USB ハードウェア](http://www.netbsd.org/ja/support/hardware/usb.html)
* [USB Hardware Supported by NetBSD](http://www.netbsd.org/support/hardware/usb.html)
* [『*BSDでのUSBデバイスドライバーの実装』 2003年10月18日 OFUG勉強会資料](http://www.ofug.net/~yamajun/presentation/2003/usb.html)
* [BSD USB-driver Notes](http://www.ht.sfc.keio.ac.jp/move/memodoc/usbdriver/)
* [Fun for FreeBSD - USBカメラ](http://qml.610t.org/FreeBSD/USBcamera.html)
* [NetBSD Page](http://www.medias.ne.jp/~takam/bsd/NetBSD.html)
* [hwhack: ugenでラピッドプロトタイピング(*BSDでUSB）](http://hwhack.blogspot.com/2008/01/ugenbsdusb.html)
* [[bsd-usb:403] ugenの使い方|http://www.clave.gr.jp/ml/bsd-usb/200101/msg00018.html]

##sysutils/usbutil

    % cd /usr/pkgsrc/sysutils/usbutil
    % sudo make install clean-depends
     :
    install usbctl usbdebug usbstats usbgen /usr/pkg/sbin

##ウェブカメラ

* [Logicool ウェブカメラ  Qcam S7500 with Headset](http://www.logicool.co.jp/index.cfm/webcam_communications/webcams/devices/4765&cl=jp,ja)

おもむろに刺す

    uaudio0 at uhub1 port 1 configuration 1 interface 2: vendor 0x046d product 0x09a2, rev 2.00/0.08, addr 2
    uaudio0: audio rev 1.00
    audio2 at uaudio0: full duplex, independent

##graphics/qcamview

[Logicool Qcam Express](http://www.medias.ne.jp/~takam/bsd/NetBSD.html#qcam)

    % cd /usr/pkgsrc/graphics/qcamview
    % sudo make install clean-depneds
