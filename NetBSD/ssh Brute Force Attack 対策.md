ブルートフォースアタック対策として [DenyHosts](http://denyhosts.sourceforge.net/) を使ってみる。


    % cd /usr/pkgsrc/security/py-denyhosts
    % sudo make install clean clean-depends
    :
    ===> Install binary package of py26-denyhosts-2.6nb2
    py26-denyhosts-2.6nb2: copying /usr/pkg/share/denyhosts/denyhosts.cfg-dist to /usr/pkg/etc/denyhosts.conf
    ===========================================================================
    The following files should be created for py26-denyhosts-2.6nb2:
    
            /etc/rc.d/denyhosts (m=0755)
                [/usr/pkg/share/examples/rc.d/denyhosts]
    
    ===========================================================================
    ===> Cleaning for py26-denyhosts-2.6nb2
    ===> Cleaning for digest-20080510
    ===> Cleaning for checkperms-1.11
    ===> Cleaning for f2c-20100903
    ===> Cleaning for libtool-base-2.2.6bnb5
    ===> Cleaning for pkg-config-0.25nb1
    ===> Cleaning for libffi-3.0.9nb1
    ===> Cleaning for readline-6.2
    ===> Cleaning for python26-2.6.7

    % cp /usr/pkg/share/examples/rc.d/denyhosts /etc/rc.d/

/etc/rc.d/denyhosts は /usr/pkg/bin/denyhosts.py をデーモンモードで実行させる。

/etc/rc.conf に以下を追加

    denyhosts=yes

起動

    % /etc/rc.d/denyhosts start


##参考

* [DenyHosts で ssh ブルートフォースアタック対策 - maruko2 Note.](http://www.maruko2.com/mw/DenyHosts_%E3%81%A7_ssh_%E3%83%96%E3%83%AB%E3%83%BC%E3%83%88%E3%83%95%E3%82%A9%E3%83%BC%E3%82%B9%E3%82%A2%E3%82%BF%E3%83%83%E3%82%AF%E5%AF%BE%E7%AD%96)
