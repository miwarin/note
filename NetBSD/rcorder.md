* [Chapter 7 - The rc.d System](http://www.netbsd.org/docs/guide/en/chap-rc.html) 本家
* [rcorder - NetBSD Manual Pages](http://netbsd.gw.com/cgi-bin/man-cgi?rcorder++NetBSD-current) マニュアル
* BSD Magazine 2001 年 9 号 特集1 システム管理者虎の巻 NetBSD 1.5 以降の起動と停止の処理
* [A Daemon-Writer's Guide To NetBSD's Rc.d System](http://www.bsdatwork.com/2004/01/15/guide_to_netbsd_rc_d/) 実装説明
* [The Design and Implementation of the NetBSD rc.d system](http://www.usenix.org/events/usenix01/freenix01/full_papers/mewburn/mewburn_html/index.html) 実装説明
       * [4.2. The technical details](http://www.usenix.org/events/usenix01/freenix01/full_papers/mewburn/mewburn_html/index.html#pgfId-106476)

,/etc/rc,System start-up script.
,/etc/rc.shutdown,System shutdown script.
,/etc/rc.d/*,Individual start-up scripts.
,/etc/rc.subr,Common shell code used by various scripts.
,/etc/defaults/rc.conf,Default system configuration.
,/etc/rc.conf,System configuration file.
,/etc/rc.conf.d/*,Per service configuration file.
