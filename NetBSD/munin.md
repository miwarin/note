# [NetBSD][munin]munin を入れてみた

NetBSD で pkgsrc でヒャッハー

##munin って？

[Munin - Trac](http://munin-monitoring.org/)

> Munin is a networked resource monitoring tool that can help analyze resource trends and "what just happened to kill our performance?" problems. It is designed to be very plug and play. A default installation provides a lot of graphs with almost no work.

ネットワーク経由で計算機のリソース( CPU とかメモリとかファイルシステムとかいろいろ)をグラフなどにいい感じに出力などしてくれるツール。

##munin-doc

    % cd /usr/pkgsrc/sysutils/munin-doc
    % make install clean clean-depends

##munin-server


    % cd /usr/pkgsrc/sysutils/munin-server
    % make install clean clean-depends
    
    :
    
    ===========================================================================
    $NetBSD: MESSAGE,v 1.3 2006/06/09 13:25:22 he Exp $
    
    You can start the collection of statistics and production of graphs by
    installing a crontab for the munin user of the form
    
    */5 * * * * /usr/pkg/bin/munin-cron
    
    You may need to give munin a valid shell to do so.
    
    
    You may also want to add lines like
    
    /var/log/munin/munin-graph.log  munin:munin 644 7 *    24   Z
    /var/log/munin/munin-html.log   munin:munin 644 7 *    24   Z
    /var/log/munin/munin-limits.log munin:munin 644 7 *    24   Z
    /var/log/munin/munin-update.log munin:munin 644 7 *    24   Z
    
    to your /etc/newsyslog.conf file to have the logs rotated.
    
    ===========================================================================

言われたとおりに作業する

cron に↑を追加

    % crontab -u munin -e

    */5 * * * * /usr/pkg/bin/munin-cron

/etc/newsyslog.conf に↑を追加

    /var/log/munin/munin-graph.log  munin:munin 644 7 *    24   Z
    /var/log/munin/munin-html.log   munin:munin 644 7 *    24   Z
    /var/log/munin/munin-limits.log munin:munin 644 7 *    24   Z
    /var/log/munin/munin-update.log munin:munin 644 7 *    24   Z


/usr/pkg/etc/munin/munin.conf を編集

    % vim /usr/pkg/etc/munin/munin.conf

デフォルトのまま

    dbdir   /var/munin
    htmldir /usr/pkg/www/munin/data
    logdir  /var/log/munin
    rundir  /var/run/munin
    tmpldir /usr/pkg/etc/munin/templates
    
    [mogu.area51.gr.jp]
        address 127.0.0.1
        use_node_name yes


##apache

httpd の設定を追加

    % sudo vim /usr/pkg/etc/httpd/httpd.conf

    include etc/httpd/httpd-munin.conf

    % sudo vim /usr/pkg/etc/httpd/httpd-munin.conf


    ScriptAlias /munin/cgi/  /usr/pkg/www/munin/data/cgi/
    Alias /munin/ /usr/pkg/www/munin/data/
    
    <Directory "/usr/pkg/www/munin/data">
        Options ExecCGI
        Order allow,deny
        Allow from all
    </Directory>



    Forbidden
    You don't have permission to access /munin/ on this server.

と怒られたら Directory の設定してないとかなんとか

##munin-node

    % cd /usr/pkgsrc/sysutils/munin-node
    % make install clean clean-depends
    
    :
    
    ===========================================================================
    The following files should be created for munin-node-1.3.2nb9:
    
            /etc/rc.d/munin-node (m=0755)
                [/usr/pkg/share/examples/rc.d/munin-node]
    
    ===========================================================================
    ===========================================================================
    $NetBSD: MESSAGE,v 1.3 2006/12/05 14:53:32 xtraeme Exp $
    
    Plugins can be auto-configured with "munin-node-configure --shell | sh"
    
    You may also want to add an entry such as
    
    /var/log/munin/munin-node.log   munin:munin 644 7 *    24   Z
    
    to /etc/newsyslog.conf to have the node log rotated.
    
    ===========================================================================

rc ファイルをコピー

    % cp /usr/pkg/share/examples/rc.d/munin-node /etc/rc.d/

/etc/newsyslog.conf に↑を追加

    /var/log/munin/munin-node.log   munin:munin 644 7 *    24   Z


/etc/rc.conf に追加

    munin_node=yes

設定を実行

    % munin-node-configure --shell | sh
    :
    Could not open "/usr/pkg/etc/munin/plugins" for reading: No such file or directory at /usr/pkg/sbin/munin-node-configure line 348.

怒られたので作っておく


    % mkdir /usr/pkg/etc/munin/plugins

もう一回

    % munin-node-configure --shell | sh

デフォルトだとこんなのが作られる。


    % ls -l /usr/pkg/etc/munin/plugins
    lrwxr-xr-x 1 root wheel 30 Sep 26 20:49 cpu -> /usr/pkg/lib/munin/plugins/cpu*
    lrwxr-xr-x 1 root wheel 29 Sep 26 20:49 df -> /usr/pkg/lib/munin/plugins/df*
    lrwxr-xr-x 1 root wheel 32 Sep 26 20:49 forks -> /usr/pkg/lib/munin/plugins/forks*
    lrwxr-xr-x 1 root wheel 38 Sep 26 20:49 if_errcoll_pcn0 -> /usr/pkg/lib/munin/plugins/if_errcoll_*
    lrwxr-xr-x 1 root wheel 30 Sep 26 20:49 if_pcn0 -> /usr/pkg/lib/munin/plugins/if_*
    lrwxr-xr-x 1 root wheel 37 Sep 26 20:49 interrupts -> /usr/pkg/lib/munin/plugins/interrupts*
    lrwxr-xr-x 1 root wheel 33 Sep 26 20:49 iostat -> /usr/pkg/lib/munin/plugins/iostat*
    lrwxr-xr-x 1 root wheel 37 Sep 26 20:49 iostat_ops -> /usr/pkg/lib/munin/plugins/iostat_ops*
    lrwxr-xr-x 1 root wheel 35 Sep 26 20:49 irqstats -> /usr/pkg/lib/munin/plugins/irqstats*
    lrwxr-xr-x 1 root wheel 31 Sep 26 20:49 load -> /usr/pkg/lib/munin/plugins/load*
    lrwxr-xr-x 1 root wheel 33 Sep 26 20:49 memory -> /usr/pkg/lib/munin/plugins/memory*
    lrwxr-xr-x 1 root wheel 39 Sep 26 20:49 memory_pools -> /usr/pkg/lib/munin/plugins/memory_pools*
    lrwxr-xr-x 1 root wheel 39 Sep 26 20:49 memory_types -> /usr/pkg/lib/munin/plugins/memory_types*
    lrwxr-xr-x 1 root wheel 34 Sep 26 20:49 netstat -> /usr/pkg/lib/munin/plugins/netstat*
    lrwxr-xr-x 1 root wheel 37 Sep 26 20:49 nfs_client -> /usr/pkg/lib/munin/plugins/nfs_client*
    lrwxr-xr-x 1 root wheel 31 Sep 26 20:49 nfsd -> /usr/pkg/lib/munin/plugins/nfsd*
    lrwxr-xr-x 1 root wheel 37 Sep 26 20:49 open_files -> /usr/pkg/lib/munin/plugins/open_files*
    lrwxr-xr-x 1 root wheel 44 Sep 26 20:49 postfix_mailqueue -> /usr/pkg/lib/munin/plugins/postfix_mailqueue*
    lrwxr-xr-x 1 root wheel 36 Sep 26 20:49 processes -> /usr/pkg/lib/munin/plugins/processes*
    lrwxr-xr-x 1 root wheel 31 Sep 26 20:49 swap -> /usr/pkg/lib/munin/plugins/swap*
    lrwxr-xr-x 1 root wheel 36 Sep 26 20:49 swap_size -> /usr/pkg/lib/munin/plugins/swap_size*
    lrwxr-xr-x 1 root wheel 33 Sep 26 20:49 uptime -> /usr/pkg/lib/munin/plugins/uptime*
    lrwxr-xr-x 1 root wheel 33 Sep 26 20:49 vmstat -> /usr/pkg/lib/munin/plugins/vmstat*


##動作確認

起動

    % /etc/rc.d/munin-node start

telnet してみる

    % telnet localhost 4949
    Trying ::1...
    telnet: connect to address ::1: Connection refused
    Trying 127.0.0.1...
    Connected to localhost.
    Escape character is '^]'.

しゃべってみる

    # munin node at mogu.area51.gr.jp
    list
    irqstats processes postfix_mailqueue if_errcoll_pcn0 memory_types swap_size memory_pools df netstat interrupts uptime swap load nfsd cpu if_pcn0 iostat forks open_files memory vmstat iostat_ops nfs_client


##TLS Error: Could not enable TLS

ログ /var/log/munin/munin-node.log にこんなのがあった。

    2011/12/22-22:00:00 [3491] TLS Notice: No key file "/usr/pkg/etc/munin/munin-node.pem". Continuing without private key.
    2011/12/22-22:00:00 [3491] TLS Notice: No certificate file "/usr/pkg/etc/munin/munin-node.pem". Continuing without certificate.
    Use of uninitialized value $msg in concatenation (.) or string at /usr/pkg/lib/perl5/vendor_perl/5.12.0/i386-netbsd-thread-multi/Net/SSLeay.pm line 693, <STDIN> line 1.
    2011/12/22-22:00:00 [3491] TLS Error: Could not enable TLS:  3491: 1 - error:14077410:SSL routines:SSL23_GET_SERVER_HELLO:sslv3 alert handshake failure
    Dec 22 22:00:51 mogu newsyslog[7894]: log file turned over

ググる

[うーたんの小部屋 &#187; Blog Archive &#187; Munin障害（対応）](http://kaju.jp/2008/06/post-929.php)

/usr/pkg/etc/munin/munin-node.conf に以下を追加

    tls disabled

再起動

    % /etc/rc.d/munin-node restart

##見る

http://example.org/munin/ にアクセスする。


#参考

* [muninでいろいろモニタリング - yellowback's blog](http://blog.yellowback.net/archives/162-20070927.html)
* [MUNIN ほほほのほ](http://www.seirios.org/~seirios/dokuwiki/doku.php?id=os:netbsd:pkgsrc:packages:munin)
* [(っ´∀｀)っ ゃー &#187; munin 動的IPアドレスの監視サーバから外部のサーバを監視する](http://nullpopopo.blogcube.info/2008/05/munin-ip.html)
* [webプログラマーのメモ &#187; CentOS 5.4 に munin(サーバー監視ツール) をインストール MRTG/cacti](http://blog.96q.org/2010/02/23/centos-munin-install-mrtg-cacti/)
