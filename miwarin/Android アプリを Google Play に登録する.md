Android アプリを Google Play に登録する

#Android アプリ公開手順

手順は 2 通りある。

*  Google Play デベロッパーアカウントにてアプリを公開する
*  アカウント所有者に追加ユーザーとして招待してもらいアプリを公開する

[アカウント ユーザーの追加と権限の管理 - Android デベロッパー ヘルプ](https://support.google.com/googleplay/android-developer/answer/2528691?hl=ja&ref_topic=16285)

> Google Play デベロッパー コンソールには、「アカウント所有者」と「ユーザー」の 2 つのアクセスレベルがあります。

> アカウント所有者とは、Google Play デベロッパー コンソールに最初に登録したアカウントです。アカウント所有者は、ユーザーの追加、各権限の管理、ユーザー アクセスの削除を行うことができます。また、アカウント所有者は、アクティビティ ログを使ってデベロッパー コンソールに加えられた変更を確認できます。

> ユーザーは、デベロッパー コンソールにアクセスするのにデベロッパー登録料（25 ドル）を支払う必要はありません。ユーザーがアカウント所有者のデベロッパー登録料を支払うことはできません。

> 注: Google Play でアプリを販売する場合、ユーザーの権限はデベロッパー コンソールと Google ウォレット Merchant Center との間で同期されません。デベロッパー コンソールにユーザーを追加しても、Google ウォレット Merchant Center アカウントへのユーザー アクセスは付与されません。Google ウォレット Merchant Center の権限の追加は別途行うことができます。 

*  アカウント所有者
       *  デベロッパー コンソールにフルアクセスできる
       *  新しいユーザーの招待、ユーザーのデベロッパー コンソールへのアクセスの取り消し、各ユーザーの権限の設定を行うことができる
       *  有料アプリを販売するため、関連付けられた Google ウォレット Merchant アカウントを所有できる（アカウント所有者のみ）
*  ユーザー 	
       *  デベロッパー コンソールにさまざまなレベルでアクセスできる
       *  すべてまたは指定のアプリにアクセスできる
       *  新しいユーザーの招待やユーザーの権限の編集はできない

# Android アプリ販売手順

支払い金額の受け取りは Google Play デベロッパーアカウントではなく Google ウォレットアカウント でおこなう。

1.  アプリを Google Play デベロッパーコンソールにて登録する
1.  アプリの値段を設定する [有料アプリの価格の設定と変更](https://support.google.com/googleplay/android-developer/answer/138412?hl=ja&ref_topic=6075663)
1.  [Google ウォレット Merchant Center](https://wallet.google.com/merchant) にアカウントを登録する
1.  銀行口座を設定などする

詳細はこちら [販売者向けのガイドライン - 注文と支払い - お支払いに関するよくある質問 - Android デベロッパー ヘルプ](https://support.google.com/googleplay/android-developer/answer/173779?hl=ja&ref_topic=6075727)

# Android アプリで広告を表示する

AdMob を使う

[アカウントの登録 - AdMob ヘルプ](https://support.google.com/admob/v2/topic/2784574?hl=ja&ref_topic=3049640)

AdSense と AdWords に登録する必要がある

## AdMob にアカウントを作る

1.  [Google アカウントで登録](https://apps.admob.com/admob/signup)
1.  AdSense を設定する
1.  AdWords を設定する

[AdMob が使えるようになる](https://apps.admob.com/#home)

## Android アプリを AdMob に登録する

[新しいアプリの収益化](https://apps.admob.com/#monetize/adunit:create)

1.  アプリを選択
1.  広告フォーマットの選択と広告ユニット名の設定
1.  表示の設定方法

登録したら AdMob SDK で広告を表示するだけ。たぶん
