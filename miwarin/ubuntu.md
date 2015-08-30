#バージョン確認

ubuntu のバージョン

    % lsb_release -a
    No LSB modules are available.
    Distributor ID:	Ubuntu
    Description:	Ubuntu 12.04.1 LTS
    Release:	12.04
    Codename:	precise

Linux のバージョン

    % uname -a
    Linux ubuntu2 3.2.0-30-generic #48-Ubuntu SMP Fri Aug 24 16:54:40 UTC 2012 i686 i686 i386 GNU/Linux


#アプリのアップデートとか

    sudo aptitude update

    sudo aptitude upgrade


#システムアップデートとか

    sudo do-release-upgrade

または Unity ならばソフトウェア Update Manager を検索する

[Upgrade - Ubuntu](http://www.ubuntu.com/download/desktop/upgrade)

http://www.ubuntu.com/sites/www.ubuntu.com/files/active/02_ubuntu/update-1.png

#samba

インストール

    % sudo aptitude install samba

編集

    % sudo vim /etc/samba/smb.conf

    [global]
    dos charset = CP932
    display charset = UTF-8
    server string = Samba %v (%h)
    hosts allow = 192.168.0., 127.
    
    [homes]
    comment = Home Directories
    browseable = no
    read only = no
    valid users = %S

再起動

    % sudo service smbd restart

ユーザー追加
    % sudo pdbedit -a rin
    new password:            ← パスワード設定
    retype new password:

Windows から以下のようにアクセスできる。

    \\ubuntu2\rin
