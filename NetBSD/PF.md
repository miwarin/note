##参考

* [PF: The OpenBSD Packet Filter](http://www.openbsd.org/faq/pf/index.html)
* [PF: OpenBSD パケットフィルター](http://gd.tuwien.ac.at/.vhost/www.openbsd.org/xxx/faq/pf/ja/index.html)
* [NetBSD Packet Filter information](http://www.netbsd.org/docs/network/pf.html)
* [NetBSD Packet Filter 情報](http://www.na.rim.or.jp/~kano/tmp/docs/network/pf.html)
* [FreeBSDでPacketFilter(pf)を使う](http://www.daily-labo.com/content_22.html)

##手順

/usr/src/sys/arch/i386/conf/MYKERNEL を編集

     :
    options         PFIL_HOOKS      # pfil(9) packet filter hooks
     :
    pseudo-device   pf                      # PF packet filter
    pseudo-device   pflog                   # PF log if


    cd /usr/src
    ./build.sh kernel=MYKERNEL
    cd /usr/obj/sys/arch/i386/compile/MYKERNEL/
    make install
    reboot

デバイス作成

    % /dev/MAKEDEV bpf

    % ifconfig pflog0 up


/etc/rc.conf

    pf=yes
    pflogd=yes


/etc/pf.conf

    # macros
    lo_if = "lo0"
    
    ext_if  = "pcn0"
    tcp_services = "{ ssh, www, smtp, domain, munin, netbios-ssn, microsoft-ds }"
    udp_services = "{ domain, netbios-ns, netbios-dgm }"
    
    #ext_if  = "wm0"
    #tcp_services = "{ ssh, www, smtp, domain, munin }"
    #udp_services = "{ domain }"
    priv_nets = "{ 192.168.0.0/16, 172.16.0.0/12, 10.0.0.0/8 }"
    localhost="127.0.0.1"
    
    
    # options
    set block-policy return
    set loginterface $ext_if
    
    
    # scrub incoming packets
    scrub in all
    
    
    # setup a default deny policy
    block in all
    block out all
    
    
    # see. Address Allocation for Private Internets
    # http://www.nic.ad.jp/ja/translation/rfc/1918.html
    block drop in  on $ext_if from $priv_nets to any
    block drop out on $ext_if from any to $priv_nets
    
    
    ## pass traffic on the loopback interface in either direction
    pass in quick on $lo_if all
    
    ## anti TCP SYN flood
    pass in on $ext_if proto tcp from any to any port $tcp_services flags S/SA synproxy state
    
    
    # IP Source Address Spoofing
    antispoof quick for $ext_if inet
    
    # for quickml
    pass in on $lo_if inet proto tcp from any to $localhost port 10025
    pass out on $lo_if inet proto tcp from $localhost to any
    pass out on $ext_if inet proto tcp from $localhost to any
    
    
    # pass tcp, udp, and icmp out on the external (Internet) interface.
    # keep state on udp and icmp and modulate state on tcp.
    pass out on $ext_if proto tcp all modulate state flags S/SA
    pass out on $ext_if proto { udp, icmp } all keep state
    
    
    pass in on $ext_if inet proto tcp from any to ($ext_if) port $tcp_services flags S/SA keep state
    pass in on $ext_if inet proto udp from any to ($ext_if) port $udp_services
    

起動

    /etc/rc.d/pflogd start
    /etc/rc.d/pf start
