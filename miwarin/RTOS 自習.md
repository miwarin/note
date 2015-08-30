RTOS 自習

RTOS とくに μiTRON準拠の OS を使い学習する。

教材は何があるか。

#TOPPERS

μiTRON といえば TOPPERS

TOPPERS はターゲットによってはメンテナンスされていないものもある( H8 とか )

##[TOPPERSプロジェクト／ASPカーネル](https://www.toppers.jp/asp-e-download.html)

*  STBEE（Strawberry Linux）簡易パッケージ
       *  よくメンテナンスされている
       *  [STM32マイコンボード『STBee』(72MHz, 512K+64KB) - STBEE(STM32F103VE) - ネット販売](https://strawberry-linux.com/catalog/items?code=32103)
       *  ここ以外では買えず。銀行振込

*  AKI-H8/3069F（秋月電子通商）簡易パッケージ 
       *  もはやメンテナンスされてない。10年くらい前の環境

##[TOPPERSプロジェクト／SSPカーネル](https://www.toppers.jp/ssp-kernel.html)

*  Interface誌付属FM3基板用簡易パッケージ 
       *  **以下の情報は CodeSourcery Lite 使用を前提としているが CodeSourcery Lite はもはや ARM をサポートしていないため、これらの手順ではダメ**
       *  [付属FM3マイコン基板特設ページ｜Interface](http://www.kumikomi.net/interface/contents/fm3.php)
       *  [Interface 2012年6月号 特集 ARMコア搭載FM3マイコンではじめる組み込み開発](http://shop.cqpub.co.jp/hanbai/books/MIF/MIF201206.html)
       *  [7月号掲載FM3マイコン基板向けTOPPERS/ASPのビルド方法の詳細手順について｜Interface編集部ブログ](http://www.kumikomi.net/interface/editors/2012/06/7fm3toppersasp.php)
       *  [さわってみようTOPPERS/SSP](http://www.slideshare.net/NSaitoNmiri/toppers-ssp-34024303?related=1)

*  Interface誌附属RX62Nボード用簡易パッケージ
       *  うーん
       *  開発環境が HEW 試用は制限あり
       *  [2011年 9月号 付属RXマイコン基板でリアルタイムOSを動かす（前編）](http://www.kumikomi.net/interface/contents/201109.php) 品切れ。amazonは高い
       *  [RX62N上で動作するTOPPERS/ASPをいじる - Wunderkerze](http://ladybug-micon.main.jp/weblog/2013/11/rx62ntoppersasp.html)
       *  [ダウンロード](http://www.tokudenkairo.co.jp/rx62n/download.html) gcc か？

#その他

*  [世界の定番ARMマイコン 超入門キット STM32ディスカバリ](http://toragi.cqpub.co.jp/tabid/530/Default.aspx)
       *  CPU は STM32F100RBT6B だが TOPPERS 移植は公式にはない

*  [マイコン徹底入門:RTOS編:フリーのリアルタイムOS活用法](http://miqn.net/rtos/index.html) FreeRTOS を使うようだ
       *  [2.1.1. 本書で設定ファイルを提供しているマイコンボード](http://miqn.net/introduction/16.html) 

#Interface誌付属FM3基板用簡易パッケージ 

http://www.keil.com/arm/mdk.asp

    To install the MDK-ARM Software...
    
        Right-click on MDK_513.EXE and save it to your computer.
        PDF files may be opened with Acrobat Reader.
        ZIP files may be opened with PKZIP or WINZIP.


Interface 2012-06 号 サンプルプログラム [6月号　ARMコア搭載FM3マイコンではじめる組み込み開発](http://www.cqpub.co.jp/interface/download/contents.htm#FM3_201206)

サンプルプロジェクトを読み込む

プロジェクトが MDK5 以前のものなのでどうするか聞かれる

*  Migrate to Device Pack (いまどきのCortex-MデバイスはSoftware Packsに対応してるからこっちがオススメ)
*  Install Legacy Support (MDK5 で古いバージョンのプロジェクトを扱いたいときはこっち)

http://www2.keil.com/mdk5/legacy/

USB DIRECT Programmer はこっちに移転された

[FLASH USB DIRECT Programmer ダウンロード](http://www.spansion.com/JP/Support/microcontrollers/development-environment/pages/downloads-flash-usb-direct-download.aspx)

Interface 2012年6月号 FM3 付属基板用追加部品セット一式

若松通商の eマートと電子部品の 2 箇所ある。どちらも同じ。支払いはゆうぱっく又は銀行振込

*  [元祖秋葉原！通販・若松通商ｅマート](http://www.wakamatsu.ne.jp/cgi-bin/shop/shop.cgi?order=41164,,:1&class=all&keyword=Interface&FF=&price_sort=&mode=p_wide&id=41164&superkey=1)
*  [wakamatsu 若松通商](http://www.wakamatsu-net.com/cgibin/biz/pageshousai.cgi?code=38310028&CATE=3831)
