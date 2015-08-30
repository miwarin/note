Linux でいう busy box みたいなもの。

[NetBSD on L-Card+ 16M](http://arhc.org/lcard/)

> runch binary方式によって小さなフットプリントで多くの機能を組 み込めます。crunch binaryとは全ての実行プログラムとそれらが必 要とするライブラリ関数を一つの実行形式に束ねてしまう技術です。 static linkのようにライブラリ関数が実行プログラム毎に重複して 存在することがありません。shared libraryのように、使用しないラ イブラリ関数がROMに含まれてしまうこともありません。crunch  binaryは、必要なライブラリ関数のコピーをただ一つだけリンクしま す。そのため、最終的なフットプリントは最小になります。NetBSDは crunch binaryをビルドするためのフレームワークを整備しており、 簡単な設定を行うだけで自動的にcrunch binaryを構築できます。

http://www.cam.hi-ho.ne.jp/wyal/weekly_news/nbsd_mdroot.txt

crunch binaryをつくる手順とか設定とか

[TECH I シリーズ Vol.5 技術者のためのUNIX系OS入門](http://www.cqpub.co.jp/hanbai/books/33/33161.htm)

> 14.3 crunch binary

[crunchgen-internal](http://sakurai.sumomo.ne.jp/page/crunchgen-internal)
