##apache

pkgsrc の www/apache22 ではデフォルトで webdav が組み込まれている

    % httpd -M | grep dav
    Syntax OK
     dav_module (shared)
     dav_fs_module (shared)
     dav_lock_module (shared)
    
##参考

* [＠IT：Apache 2.0でWebDAV（1/2）](http://www.atmarkit.co.jp/flinux/special/webdav03/webdav01a.html)
* [麗の小屋 - WebDAV Client CarotDAV -](http://www.rei.to/carotdav.html) Windowsクライアント
