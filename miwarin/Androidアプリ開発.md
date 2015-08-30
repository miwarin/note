#入門

*  [はじめてのAndroidアプリ開発！開発環境を構築する手順まとめ！ | PLUS](http://golog.plus.vc/android/4043/)
*  [逆引きAndroid入門](http://www.adakoda.com/android/)
*  [次のモバイルアプリはどのフレームワークで作る？（1/2） - ＠IT](http://www.atmarkit.co.jp/fwcr/design/ux/d89clip43/01.html)
*  [4Gamer.net — HTML5ベースのAVG＆ノベルゲームエンジン「Almight」が登...](http://www.4gamer.net/games/032/G003263/20120522016/)
*  [短期間でのスマホ向けWeb開発](http://www.slideshare.net/mauekusa/web-13331213)
*  [はてブiPhone・Androidアプリの開発プロセス - ninjinkun's diary](http://ninjinkun.hatenablog.com/entry/20110213/1297586340)
*  [O'Reilly Japan - Android Hacks](http://www.oreilly.co.jp/books/9784873114569/)
*  [Amazon.co.jp： Google Androidプログラミング入門](http://www.amazon.co.jp/dp/4048679562/)

*  [勉強会/ボタンをつくってみよう - 日本Androidの会（日本アンドロイドの会）](http://www.android-group.jp/index.php?%CA%D9%B6%AF%B2%F1%2F%A5%DC%A5%BF%A5%F3%A4%F2%A4%C4%A4%AF%A4%C3%A4%C6%A4%DF%A4%E8%A4%A6)
*  [blog lesson 01 - Javaのイベントリスナの書き方についての考察](http://team-pag.interprism.co.jp/member/okazawa/blog/?p=240)
*  [CallbackとListenerとObserverの違い - 前人未踏の領域へ](http://d.hatena.ne.jp/takeR/20111225/1324833885)

*  [イベント駆動によるModelとViewの分離 &#8211; Observer パターン](http://www.yukun.info/blog/2009/03/java-observe-event-model-view.html)
*  [とほほのJava入門](http://www.tohoho-web.com/java/index.htm)

#エミュレーター

*  [仮想環境へAndroidをインストールしてエミュレートを高速化する - 技術脳塗](https://sites.google.com/site/technoute/android/emulator/virtualbox)
*  [[Mtk's Blog: [Android] VmWare PlayerでAndroidをデバッグする|http://blog.fujiu.jp/2011/05/android-vmware-playerandroid.html]]
*  [VMWareでAndroidアプリをデバッグ - 明日はもっと幸せに](http://d.hatena.ne.jp/funatake/20100216/1266327967)

#録音

*  [AndroidでMediaRecorderとMediaPlayerを使って音声の録音と再生を行う &#187; tech-tec](http://tech-tec.com/archives/284)
*  [MediaRecorder - Android Developers](http://developer.android.com/reference/android/media/MediaRecorder.html)

実機を USB 接続して実行するとたまに

    /sdcard/ナントカ.wav が見つからない

などと怒られるときがある。これは本当に USB 接続してる最中に SD カードが認識されていないようだ。

一度ケーブルを引っこ抜いてから再度接続すると SD カードが認識される。意味わからん。

    package com.example.mediarecordertest1;
    
    import java.io.File;
    import java.io.IOException;
    
    import android.media.MediaRecorder;
    import android.os.Bundle;
    import android.os.Environment;
    import android.annotation.SuppressLint;
    import android.app.Activity;
    import android.util.Log;
    import android.view.Menu;
    import android.view.View;
    import android.view.View.OnClickListener;
    import android.widget.Button;
    
    public class MainActivity extends Activity implements OnClickListener{
        MediaRecorder recorder = null;
        Button btn = null;
        boolean bIsRecording = false;
        
        @Override
        public void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_main);
            btn = (Button)findViewById(R.id.button1);
            btn.setOnClickListener(this);
    
            recorder = new MediaRecorder();
            File sampleDir = Environment.getExternalStorageDirectory();
            String path = sampleDir.getAbsolutePath() + "/tanaka.wav";
            recorder.setOutputFile(path);
        
        }
    
        @Override
        public boolean onCreateOptionsMenu(Menu menu) {
            getMenuInflater().inflate(R.menu.activity_main, menu);
            return true;
        }
    
        @Override
        public void onClick(View arg0) {
            // TODO Auto-generated method stub
            // TODO Auto-generated method stub
            if (arg0 == btn) {
              if (!bIsRecording) {
                recorder.setAudioSource(MediaRecorder.AudioSource.MIC);
                recorder.setOutputFormat(MediaRecorder.OutputFormat.THREE_GPP);
                recorder.setAudioEncoder(MediaRecorder.AudioEncoder.AMR_NB);
                try {
                  recorder.prepare();
                } catch (IllegalStateException e) {
                  e.printStackTrace();
                } catch (IOException e) {
                  e.printStackTrace();
                }
                // 録音開始
                recorder.start();
                btn.setText("録音停止");
                bIsRecording = true;
              }
              else {
                // 録音停止
                recorder.stop();
                recorder.reset();
                btn.setText("録音開始");
                bIsRecording = false;
              }
            }
        }
    }


#インテント

外部プロセスを呼び出す。みたいな

*  [勉強会/インテントを発行してみよう - 日本Androidの会（日本アンドロイドの会）](http://www.android-group.jp/index.php?%CA%D9%B6%AF%B2%F1%2F%A5%A4%A5%F3%A5%C6%A5%F3%A5%C8%A4%F2%C8%AF%B9%D4%A4%B7%A4%C6%A4%DF%A4%E8%A4%A6)
*  [Intent(インテント)連携をまとめてみる - コードを貼り付けながら。](http://d.hatena.ne.jp/unagi_brandnew/20100309/1268115942)
*  [Android インテント - Wiki](http://ee72078.moo.jp/chinsan/pc/MobileApp/index.php?Android%20%E3%82%A4%E3%83%B3%E3%83%86%E3%83%B3%E3%83%88)
*  [Androidメモ](http://www.saturn.dti.ne.jp/npaka/android/intent/index.html)

#ファイル保存というか

*  [Androidアプリで使えるJSONライブラリ比較](http://mstssk.blogspot.jp/2011/12/androidjson.html)
*  [Androidアプリのデータ保存方法の一つ「ローカルファイル」の使い方](http://android.roof-balcony.com/shori/strage/localfile-2/)

#テスト

*  [連載インデックス「Androidアプリ開発テスト入門」 - ＠IT](http://www.atmarkit.co.jp/fsmart/index/androidtest.html)
*  [o. テスト - ソフトウェア技術ドキュメントを勝手に翻訳](http://www.techdoctranslator.com/android/guide/testing)

#CI

*  [Getting started: Building Android apps with Hudson | Jenkins CI](http://jenkins-ci.org/content/getting-started-building-android-apps-hudson)
*  [JenkinsでCI（継続的インテグレーション）すればAndroidアプリ開発はもう怖くない（1/2） - ＠IT](http://www.atmarkit.co.jp/fsmart/articles/androidtest06/01.html)
*  [Android でも CI](http://www.slideshare.net/ussy/android-ci)
*  [Droid 君と Jenkins 氏の CI 3分クッキング](http://www.slideshare.net/tlync/droid-jenkins-ci-3-12149566)
*  [Jenkins と始める Android プロジェクトでの CI - Ant 基本編 - takuya's diary](http://tlync.hateblo.jp/entry/20120326/1332691894)

#UI

*  [NinePatchを使って簡単に吹き出しを作る](http://tomotomosnippet.blogspot.jp/2012/06/android-sdkninepatch.html)]

#音声認識

*  [大語彙連続音声認識を基盤技術とする実用指向音声インタフェースに関する研究](http://spalab.naist.jp/database/library/dthesis/0161030.pdf) (PDF)
*  [音声認識システム入門の入門](http://www.sematics.co.jp/mss/sm02-1.pdf) (PDF)
*  [大語彙連続音声認識エンジン Julius](http://julius.sourceforge.jp/index.php)
*  [日本語音声認識エンジン Julius for Android](https://github.com/tech-sketch/JuliusForAndroid)
*  [音声認識(RecognizerIntent)を使用するには - 逆引きAndroid入門](http://www.adakoda.com/android/000164.html)
*  [Android開発 - 音声認識サンプル](http://www.trusted-design.net/RecognizerIntent.html)
*  [AndroidにSiriのライバル登場—英True Knowledgeから音声認識アシスタントEviがローンチ](http://jp.techcrunch.com/archives/20120123evi-arrives-in-town-to-go-toe-to-toe-with-siri/)

> Eviは自然言語解析と知識ベースに関するTrue Knowledge独自の特許取得ずみテクノロジー [...] Eviは日常会話が対象にするようなあらゆる事物に関して何万というクラスのオントロジーを保有している。彼女は10億件もの機械処理可能な知識を保有している。TrueKnowledgeによれば彼女は必要に応じてこの知識を推論によって何兆件にも拡張可能だという。Eviはまた他の情報源も利用する。ローカル情報に関してはYelpを検索するし、その他モバイル環境に親和性が高いウェブサイト、API、通常の検索エンジンによる検索も利用する。

かなり強力らしい。

*  [Speech Recognition HOWTO](http://linuxjf.sourceforge.jp/JFdocs/Speech-Recognition-HOWTO/index.html)
*  [An Introduction to Speech Recognition](http://www.speech-recognition.de/pdf/introSR.pdf) (PDF)
*  [Speech Recognition: Theory and C++ Implementation](http://www.amazon.com/dp/0471977306)
*  [AndroidアプリでGoogleTTSを使った音声読み上げ（日本語編） - ぽろりのニコ生放送用メモページ](https://sites.google.com/site/pororinicochu/android-googletts-jp)

#人工無脳

*  [人工無脳のアーキテクチャ](http://www.ycf.nanet.co.jp/~skato/muno/5model/index.html)
*  [人工無脳レビュー](http://www.ycf.nanet.co.jp/~skato/muno/material/review.html)
*  [ししゃもを偲ぶ - xe-kdoo (2005-04-18)](http://yowaken.dip.jp/tdiary/20050418.html#p02)
*  [ミクさんでSiri対抗アプリを作ってみた - ブログなんだよもん](http://koduki.hatenablog.com/entry/2012/07/08/232836)


#日本語処理

*  [『ネガポ辞典』がiPhoneアプリに。ネガティブからポジティブになろう！](http://news.livedoor.com/article/detail/5439026/)]
*  [公開資源/日本語評価極性辞書 - 東北大学 乾・岡﨑研究室](http://www.cl.ecei.tohoku.ac.jp/index.php?%E5%85%AC%E9%96%8B%E8%B3%87%E6%BA%90%2F%E6%97%A5%E6%9C%AC%E8%AA%9E%E8%A9%95%E4%BE%A1%E6%A5%B5%E6%80%A7%E8%BE%9E%E6%9B%B8)
*  [日本の言語資源・ツールのカタログ](http://anlp.jp/NLP_Portal/lr-cat-j.html)
*  [[O] 3つの日本語評価極性辞書（岩波国語辞書見出し語、用言のみ、名詞のみ）|http://diary.overlasting.net/2012-08-28-1.html]
*  [Sanmoku: 省メモリな形態素解析器 - sileの日記](http://d.hatena.ne.jp/sile/20111106/1320575796)
*  [大規模データマイニング・機械学習 Mahout 活用に向けて読んでおきたい12のプレゼン資料 - hamadakoichi blog](http://d.hatena.ne.jp/hamadakoichi/20120504/p1)
*  [Social IMEの共有辞書を公開しました - nokunoの日記](http://d.hatena.ne.jp/nokuno/20111230/1325334850)
*  [大規模コーパスを無料で手に入れることのできるサイトまとめ - nokunoの日記](http://d.hatena.ne.jp/nokuno/20110621/1308608636)
*  [第3回さくさくテキストマイニング勉強会に参加しました #sakuTextMining - nokunoの日記](http://d.hatena.ne.jp/nokuno/20110604/1307178783)
*  [入力メソッドワークショップで発表しました〜「Social IMEの共有辞書をクリーニングしてみた」 - nokunoの日記](http://d.hatena.ne.jp/nokuno/20111229/1325174163)
*  [N-gram コーパス - 日本語ウェブコーパス 2010](http://s-yata.jp/corpus/nwc2010/ngrams/)
*  [中納言 コーパス検索アプリケーション](https://chunagon.ninjal.ac.jp/)
*  [KOTONOHA「現代日本語書き言葉均衡コーパス」　少納言](http://www.kotonoha.gr.jp/shonagon/)
*  [言語モデル配布ページ](http://plata.ar.media.kyoto-u.ac.jp/gologo/lm.html)
*  [LSIやLDAを手軽に試せるGensimを使った自然言語処理入門 - SELECT * FROM life;](http://yuku-tech.hatenablog.com/entry/20110623/1308810518)

#Android 開発入門

{{amazon 487311456X}}


##環境

Microsoft Windows 7 Proffesional 64bit

##手順

1.  Android SDK インストール
1.  Eclipse インストール

##Android SDK インストール

[Android SDK - Android Developers](http://developer.android.com/sdk/index.html) からダウンロードしてインストール。

    C:\Program Files (x86)\Android\android-sdk

SDK Manager.exe を実行して以下のようにエラーになった場合は SDK Manager.exe を管理者として実行してみるとよい。

    Preparing to install archives
    Downloading Android SDK Platform-tools, revision 11
    Failed to create directory C:\Program Files (x86)\Android\android-sdk\temp
    Downloading Documentation for Android SDK, API 15, revision 2
    Failed to create directory C:\Program Files (x86)\Android\android-sdk\temp
    Downloading SDK Platform Android 4.0.3, API 15, revision 3
    Failed to create directory C:\Program Files (x86)\Android\android-sdk\temp
    Downloading Samples for SDK API 15, revision 2
    Failed to create directory C:\Program Files (x86)\Android\android-sdk\temp
    Downloading Sources for Android SDK, API 15, revision 2
    Failed to create directory C:\Program Files (x86)\Android\android-sdk\temp
    Downloading Google USB Driver, revision 4
    Failed to create directory C:\Program Files (x86)\Android\android-sdk\temp
    Skipping 'Android SDK Tools, revision 19'; it depends on 'Android SDK Platform-tools, revision 11' which was not installed.
    Skipping 'ARM EABI v7a System Image, Android API 15, revision 2'; it depends on 'SDK Platform Android 4.0.3, API 15, revision 3' which was not installed.
    Skipping 'Google APIs, Android API 15, revision 2'; it depends on 'SDK Platform Android 4.0.3, API 15, revision 3' which was not installed.
    Done. Nothing was installed.


## Eclipse インストール

[Eclipse](http://www.eclipse.org/)

[Eclipse Downloads](http://www.eclipse.org/downloads/) からダウンロードしてインストールというか展開して以下のフォルダに設置。

    C:\eclipse

ADT インストール

eclipse 起動

    Name: ADT
    Location: https://dl-ssl.google.com/android/eclipse/

eclipse を使うときは管理者として起動すること。Android 用の何かをインストールするときなどに C:\Program Files (x86)\Android\android-sdk に書き込み出来る必要があるようだ。

日本語化

[nlpack - blanco Framework Wiki - SourceForge.JP](http://sourceforge.jp/projects/blancofw/wiki/nlpack) から eclipse のバージョンごとにファイルをダウンロード。展開して中にある eclipse をそのまま C:\eclipse\dropins に設置。

[Subclipseプラグイン - EclipseWiki](http://www.eclipsewiki.net/eclipse/?Subclipse%A5%D7%A5%E9%A5%B0%A5%A4%A5%F3)

#Android エミュレーター

##作成

AVD Manager.exe を使うと楽ちん。

対応 OS は Android 2.1 とする。

##起動

*  AVD Manager.exe から起動
*  eclipse のプロジェクトから起動

#Android アプリケーション

##作成

1.  eclipse 起動
1.  File → New → Project
1.  Android → Android Application
1.  あとはウィザードで適当に設定していく。対応 OS は Android 2.1 とする

##エミュレーターでデバッグ

eclipse のアプリケーションプロジェクトを右クリック → デバッグ → どの AVD から起動するか設定 → Start とか

##実機でデバッグ

Android デバイス側で 設定→アプリケーション→開発→USBデバッグをチェック。スリープモードにしない もチェック

Android デバイスを PC に接続。

eclipse プロジェクトを右クリック→ デバッグ → デバッグの構成 → Target タブ → Alwayz prompt to pick device を選択 → デバッグ

Choose a running Android device を選択 → さらにデバイスを選択 → OK

{{ref_image android_device_debug.PNG}}

#Android ライブラリ

*  [Androidでライブラリプロジェクトを作成する - iPhone/iPad/Androidアプリ開発ブログ](http://d.hatena.ne.jp/waochi/20101108/1289181917)
*  [Androidでライブラリプロジェクトを作成する際の考慮事項 - Develop with pleasure!](http://d.hatena.ne.jp/techmedia-think/20110622/1308740751)

jar で提供してはいけないらしい。

#テスト(testing)

ファイル→新規→プロジェクト→Android Test Project

Project Name: HelloTest

Location: テキトーに

]Select Test Target画面→An exsiting Android project: Hello

プロジェクトを作成したら、パッケージエクスプローラー上で

src/com.example.hello.test を右クリック→新規→JUnit テストケース

スーパークラス→参照→ActivityInstrumentationTestCase2を入力

どのメソッドスタブを作成しますか？

*  setUp
*  tearDown

テスト元クラス→参照→MainActivityを選択

ActivityInstrumentationTestCase2 を継承する。ActivityInstrumentationTestCase2 の型にテスト元クラスに指定したクラス名を書く。eclipse が名前空間が足りないなど言うので名前空間を追加する。その他テスト対象のメソッドがあれば選択しておく。

コンストラクターでテスト元クラス.class を super しておかないとテストが呼ばれないらしい。

    package com.example.hello.test;
    import com.example.hello.MainActivity;
    import android.test.ActivityInstrumentationTestCase2;
    import android.widget.TextView;
    
    public class HelloTest extends ActivityInstrumentationTestCase2<MainActivity> {
    
        private MainActivity mActivity;  // the activity under test
        private TextView mView;          // the activity's TextView (the only view)
        private String resourceString;
    
      public HelloTest() {
        super("Hello test", MainActivity.class);
      }
      
      protected void setUp() throws Exception {
        super.setUp();
            mActivity = this.getActivity();
            mView = (TextView) mActivity.findViewById(com.example.hello.R.id.txtHello);
            resourceString = mActivity.getString(com.example.hello.R.string.hello_world);  }
    
      protected void tearDown() throws Exception {
        super.tearDown();
      }
      
      public void testText() throws Exception {
         assertEquals(resourceString, (String)mView.getText());
      }
      
      public void testOnStart() {
        fail("まだ実装されていません"); // TODO
      }
    
      public void testOnRestart() {
        fail("まだ実装されていません"); // TODO
      }
    
      public void testOnResume() {
        fail("まだ実装されていません"); // TODO
      }
    
      public void testOnPause() {
        fail("まだ実装されていません"); // TODO
      }
    
      public void testOnStop() {
        fail("まだ実装されていません"); // TODO
      }
    
      public void testOnDestroy() {
        fail("まだ実装されていません"); // TODO
      }
    
      public void testOnCreateBundle() {
        fail("まだ実装されていません"); // TODO
      }
    
      public void testOnCreateOptionsMenuMenu() {
        fail("まだ実装されていません"); // TODO
      }
    
    }
