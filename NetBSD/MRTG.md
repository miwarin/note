MRTG

* [[FreeBSD]MRTGの導入・利用 | ごった煮 - tips about programming and building a server](http://park1.wakwak.com/~ima/freebsd_mrtg.html "[FreeBSD]MRTGの導入・利用 | ごった煮 - tips about programming and building a server")

インストール

    % cd /usr/pkgsrc/net/mrtg
    % make install clean clean-depends

/usr/pkg/etc/mrtg.conf に作業ディレクトリが書いてあるので

    WorkDir: /usr/pkg/share/httpd/htdocs/mrtg
    Refresh: 300
    Interval: 5
    WriteExpires: Yes

ディレクトリを作る。

    % mkdir /usr/pkg/share/httpd/htdocs/mrtg

MRTG 用の index.html を作る。

    % cd /usr/pkg/share/httpd/htdocs/mrtg
    % /usr/pkg/bin/indexmaker /usr/pkg/etc/mrtg.conf > ./index.html

テキトーに crontab に書く。

    @hourly /usr/pkg/bin/mrtg  /usr/pkg/etc/mrtg.conf


## 変更

ただしインストールしただけだと実行時に怒られる。envstat にはもはや -n は無いため。

    % /usr/pkg/bin/mrtg  /usr/pkg/etc/mrtg.conf
    envstat: unknown option -- n
    Usage: envstat [-DfIklrSTx] [-c file] [-d device] [-i interval] [-s device:sensor,...] [-w width]

とりあえず変更しておく

    # diff -u /usr/pkg/libexec/envstat2mrtg.orig /usr/pkg/libexec/envstat2mrtg
    --- /usr/pkg/libexec/envstat2mrtg.orig  2015-10-21 21:24:08.000000000 +0900
    +++ /usr/pkg/libexec/envstat2mrtg       2015-10-21 21:24:30.000000000 +0900
    @@ -3,7 +3,7 @@
    
     if (@ARGV == 1)
     {
    -       open(CMDOUT, "envstat -n0 -s '@ARGV[0]'|");
    +       open(CMDOUT, "envstat -s '@ARGV[0]'|");
            $line = <CMDOUT>;
            chop $line;
            if ($line =~ m|^[\s\t]+(\w+)$|)
    @@ -25,7 +25,7 @@
    
     if (@ARGV == 2)
     {
    -       open(CMDOUT, "envstat -n0 -s '@ARGV[0],@ARGV[1]'|");
    +       open(CMDOUT, "envstat -s '@ARGV[0],@ARGV[1]'|");
            $line = <CMDOUT>;
            if ($line =~ m|^[\s\t]+(\w+)[\s\t]+(\w+)$|)
            {

* [ENVSTAT(8)](http://man.netbsd.org/7.0/usr/share/man/html8/envstat.html "ENVSTAT(8)")
* [modman.unixdev.net - Page: envstat(8) in [NetBSD-2.0]](http://modman.unixdev.net/?sektion=8&amp;page=envstat&amp;manpath=NetBSD-2.0 "modman.unixdev.net - Page: envstat(8) in [NetBSD-2.0]")
* [src/usr.sbin/envstat/envstat.c - diff - 1.25](http://cvsweb.netbsd.org/cgi-bin/cvsweb.cgi/src/usr.sbin/envstat/envstat.c.diff?r1=1.24&amp;r2=1.25&amp;f=h "src/usr.sbin/envstat/envstat.c - diff - 1.25")

