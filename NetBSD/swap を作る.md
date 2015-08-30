[NetBSD Documentation: Other FAQs and HOWTOs - Adding more swap to a running system](http://www.netbsd.org/docs/misc/#adding-swap)


作成前

    % swapctl -lh
    Device      Size     Used    Avail Capacity  Priority
    /dev/wd0b   128M       0B     128M     0%    0
    /home/swap  2.0G       0B     2.0G     0%    1
    Total       2.1G       0B     2.1G     0%

作成


    % dd if=/dev/zero bs=1m count=256 of=/home/swap2
    % chmod 600 /home/swap2
    % swapctl -a -p 1 /home/swap2

作成後

    % swapctl -lh
    Device      Size     Used    Avail Capacity  Priority
    /dev/wd0b   128M       0B     128M     0%    0
    /home/swap  2.0G       0B     2.0G     0%    1
    /home/swap2 256M       0B     256M     0%    1         <====
    Total       2.3G       0B     2.3G     0%
