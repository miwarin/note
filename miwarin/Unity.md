#よちよち.unity

##公式

*  [Unity - Tutorial - 2D Shooting Game](http://japan.unity3d.com/developer/document/tutorial/2d-shooting-game/)
*  [Unity - Developer - はじめての Unity - 第1回 世界の「骨格」をつくろう](http://japan.unity3d.com/developer/document/tutorial/my-first-unity/01.html)
*  [ニコニコ動画](http://japan.unity3d.com/developer/document/tutorial/2d-shooting-game/nikoniko.html)

##入門

*  [iPhoneゲームを20分間で作る【メダルプッシャー編】 - ニコニコ動画:GINZA](http://www.nicovideo.jp/watch/sm12948504)
*  [個人でゲームを作りたい人に是非読んで欲しい！スマホ用RPG「ダンジョン999F」のメイキングが公開。素材作成やバランス調整など - テラシュールブログ](http://tsubakit1.hateblo.jp/entry/2015/05/25/001728)
*  [ダンジョン999F - 開発ノート on Behance](https://www.behance.net/gallery/26408595/999F)
*  [「ゲーム　作り方」 - テラシュールブログ](http://tsubakit1.hateblo.jp/entry/20140218/1392651856)
*  [Unity4.6のチュートリアルをやってみる(翻訳完了) - Qiita](http://qiita.com/yando/items/64dcb415a6bc9168ae78)
*  [【Unity2D】Unityで2Dミニゲームを作るチュートリアル（第１回） - Qiita](http://qiita.com/2dgames_jp/items/11bb76167fb44bb5af5f)
*  [「ゲーム開発初心者のためのUnity入門」最新記事一覧 - ITmedia Keywords](http://www.atmarkit.co.jp/ait/kw/unity4_nyumon.html)
*  [Unity本まとめメモ　2015/4/15時点 - Qiita](http://qiita.com/hiroyuki_hon/items/6781cd3e7dbca66d8fda)
*  [これから始めるUnity入門 ｜ シリーズ ｜ Developers.IO](http://dev.classmethod.jp/series/%E3%81%93%E3%82%8C%E3%81%8B%E3%82%89%E5%A7%8B%E3%82%81%E3%82%8Bunity%E5%85%A5%E9%96%80/)
*  [ダイスふる制作レポート　Unityでアプリ個人開発](http://www.slideshare.net/RyoheiTokimura/ss-23565450)
*  [【Unity】ゲーム会社でスマホ向けゲームを開発して得た知識 コーディング編 - Qiita](http://qiita.com/baba_s/items/f2ad850dd7fc84165e96)
*  [非エンジニアが知ってると得するUnityの知識｜1 pixel｜サイバーエージェント公式クリエイターズブログ](http://ameblo.jp/ca-1pixel/entry-11718229785.html) 「ウチの姫さまがいちばんカワイイ」

#遭遇したアレコレ

##UIText の Text にテキストを設定する

めんどくさ

    using UnityEngine.UI;
    
    Text msg = GameObject.Find("Canvas/msg").GetComponent<Text>();
    msg.color = Color.red;
    msg.text = "COMPLETE!";


[【Unity】【C#】【JavaScript】4.6.x の Canvas〜UI Text のテキストをコードで変更する - ヽ｜∵｜ゝ(Fantom) の 開発blog？](http://fantom1x.blog130.fc2.com/blog-entry-158.html)

##MonoDevelop C#のアセンブリロードできてない

    オブジェクト参照がオブジェクトインスタンスに設定されていません。

プロジェクトクリック - メニュー - Reload


[独り言日記（2013/11） - FreeStyleWiki](http://ft-lab.ne.jp/cgi-bin/wiki.cgi?page=%C6%C8%A4%EA%B8%C0%C6%FC%B5%AD%A1%CA2013%2F11%A1%CB#p3)

##MonoDevelop 改行コードの警告

    The file "C:\home\rin\work\Unity\medal0\Assets\Score.cs" has line endings which differ from the policy settings.
    Do you want to convert the line endings?

MonoDevelop の Project - Solution Options - Source Code - Code Formating - C# source code - Line encoding を Unix か Microsoft Windows に経洸

[Throw the warped code out: MonoDevelopで”~has line endings which differ from the policy settings.”の警告を黙らす](http://ttwco.blogspot.jp/2013/02/monodevelophas-line-endings-which.html)
