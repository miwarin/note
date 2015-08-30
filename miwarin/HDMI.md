#概要

[R&S UPP Audio Analyzer with HDMI HDMI 1.4a Overview](http://www.rohde-schwarz-av.com/_pdf/Application%20Notes/HDMI/HDMI-Overview.pdf)

HDMI 物理インターフェース

*  TMDS (映像そのもの、音声そのもの)
       *  AV_DATA
           *  Video Formats
           *  Audio Formats
       *  HDMI Signalling
       *  Info Frames (どういう映像なのか、どういう音声なのか)
           *  Audio Info Frame
           *  AVI Info Frame
           *  VSIF
*  HEAC (知らん)
       *  HEC
       *  ARC
*  DDC
       *  EDID (通信相手の諸元)
           *  Capabilities of Sink
           *  Video Support
           *  Audio Support
           *  Vendor Specific Info
       *  HDCP (知らん)
*  CEC (Consumer Electronics Control)
       *  Remote Control (機器制御)
           *  Standby
           *  Power Up
           *  Power Down
           *  Volume
           *  One touch record
           *  OSD

#実装する？

*  [FPGAマガジン No.1](http://shop.cqpub.co.jp/hanbai/books/46/46111.html)
*  [fpga4fun.com - HDMI](http://www.fpga4fun.com/HDMI.html)
*  [Implementing a TMDS Video Interface in the Spartan-6 FPGA](http://www.xilinx.com/support/documentation/application_notes/xapp495_S6TMDS_Video_Interface.pdf)
*  [Spartan 6 1080p - Hamsterworks Wiki!](http://hamsterworks.co.nz/mediawiki/index.php/Spartan_6_1080p)
*  [FPGA - 休日くらい技術者っぽいことしてみたい](http://www.airy.org/blog/eng/?cat=10)
*  [廉価FPGAでHDMI(DVI)出力 - sa89a.net](http://sa89a.net/mp.cgi/ele/fpga_hdmi.htm)
*  [特電Spartan-6ボードでHDMI出力に成功: なひたふJTAG日記](http://nahitafu.cocolog-nifty.com/nahitafu/2013/08/spartan-6hdmi-a.html)


#HDMI まとめ(予定地)

*  Why: 技術が出てきた背景
*  What: 技術の仕組み、特徴
*  How: 技術の使い方
*  Where: 技術がどこで使われているのか 
