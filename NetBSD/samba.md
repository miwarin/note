* [公式のSamba 3.2.x HOWTOとリファレンスガイド - Chapter&#160;2.&#160;手軽な始め方: 短気な方への手引き](http://www.samba.gr.jp/project/translation/Samba3-HOWTO/FastStart.html)
* [How to set up a Samba Server - NetBSD Wiki](http://wiki-static.aydogan.net/How_to_set_up_a_Samba_Server)

そのまま


インストール

    % cd /usr/pkgsrc/net/samba35
    % sudo make install clean clean-depends

コピー

    % sudo cp /usr/pkg/share/examples/rc.d/smbd /etc/rc.d
    % sudo cp /usr/pkg/share/examples/rc.d/nmbd /etc/rc.d
    % sudo cp /usr/pkg/share/examples/rc.d/winbindd /etc/rc.d/
    % sudo cp /usr/pkg/share/examples/rc.d/samba /etc/rc.d


/etc/inetd.conf に書いて再起動するか、または

    netbios-ssn stream tcp nowait root /usr/pkg/sbin/smbd
    netbios-ns dgram udp wait root /usr/pkg/sbin/nmbd

    % /etc/rc.d/inetd restart


/etc/rc.conf に書く

    smbd=yes
    nmbd=yes
    winbindd=yes
    samba=yes

/usr/pkg/etc/samba/smb.conf に書く

    % testparm
     :
    [global]
            dos charset = CP932
            display charset = UTF-8
            server string = Samba %v (%h)
            hosts allow = 192.168.0., 127.
    
    [homes]
            comment = Home Directories
            valid users = %S
            read only = No
            browseable = No

    [public]
            path = /usr
            read only = No
            guest only = Yes
            guest ok = Yes


ユーザー追加

    % sudo pdbedit -a rin

開始

    % sudo /etc/rc.d/samba start

こんな

    % smbclient -L localhost -U%
    Domain=[WORKGROUP] OS=[Unix] Server=[Samba 3.5.8]
    
            Sharename       Type      Comment
            ---------       ----      -------
            IPC$            IPC       IPC Service (Samba 3.5.8 (yukina))
    Domain=[WORKGROUP] OS=[Unix] Server=[Samba 3.5.8]
    
            Server               Comment
            ---------            -------
    
            Workgroup            Master
            ---------            -------
