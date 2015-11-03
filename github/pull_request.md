pull request

[github初心者がPull Requestを送ってみた時の手順](http://blog.mogmet.com/github-abecedarian-send-pull-request/ "github初心者がPull Requestを送ってみた時の手順")

Fork式 をmackerel-agent https://github.com/mackerelio/mackerel-agent で実践してみた。

# githubにあるリポジトリを自分のリポジトリにfork

github リポジトリ https://github.com/mackerelio/mackerel-agent の右上の Fork ボタンを押す。

Fork される。

# forkリポジトリにコミットする

fork したリポジトリを clone する

    % mkdir product
    % cd product
    % git clone https://github.com/miwarin/mackerel-agent.git
    % cd mackerel-agent

作業用にブランチを作成する。

    % git checkout -b add_netbsd

ブランチが出来てか確認する。

    % git branch -v
    * add_netbsd 5aba7fe Merge pull request #154 from mackerelio/gotestcover
      master     5aba7fe Merge pull request #154 from mackerelio/gotestcover

ここでファイルを編集する。

ファイルを編集したらファイルの状態を確認する。

    % git status
    On branch add_netbsd
    Changes not staged for commit:
      (use "git add <file>..." to update what will be committed)
      (use "git checkout -- <file>..." to discard changes in working directory)
    
            modified:   Makefile
            modified:   command/command_unix_test.go
            modified:   metrics/plugin_test.go
            modified:   pid.go
            modified:   pid_test.go
            modified:   util/filesystem.go
            modified:   util/filesystem_test.go
            modified:   util/util.go
            modified:   util/util_test.go
    
    Untracked files:
      (use "git add <file>..." to include in what will be committed)
    
            command/command_netbsd.go
            config/config_netbsd.go
            metrics/netbsd/
            spec/netbsd/
    
    no changes added to commit (use "git add" and/or "git commit -a")

NetBSD 用にファイルを新規作成(といっても FreeBSD からコピーしたものを変更しただけだが )したので add する( [git add -A と git add . と git add -u の違い - Qiita](http://qiita.com/YusukeHigaki/items/06e38eec96387d408780 "git add -A と git add . と git add -u の違い - Qiita") )

    % git add .


ファイルの状態を確認すると new になっている。

    % git status
    On branch add_netbsd
    Changes to be committed:
      (use "git reset HEAD <file>..." to unstage)
    
            modified:   Makefile
            new file:   command/command_netbsd.go
            modified:   command/command_unix_test.go
            new file:   config/config_netbsd.go
            new file:   metrics/netbsd/cpuusage.go
            new file:   metrics/netbsd/cpuusage_test.go
            new file:   metrics/netbsd/filesystem.go
            new file:   metrics/netbsd/filesystem_test.go
            new file:   metrics/netbsd/loadavg5.go
            new file:   metrics/netbsd/memory.go
            new file:   metrics/netbsd/memory_test.go
            modified:   metrics/plugin_test.go
            modified:   pid.go
            modified:   pid_test.go
            new file:   spec/netbsd/cpu.go
            new file:   spec/netbsd/cpu_test.go
            new file:   spec/netbsd/filesystem.go
            new file:   spec/netbsd/interface.go
            new file:   spec/netbsd/kernel.go
            new file:   spec/netbsd/kernel_test.go
            new file:   spec/netbsd/memory.go
            new file:   spec/netbsd/memory_test.go
            modified:   util/filesystem.go
            modified:   util/filesystem_test.go
            modified:   util/util.go
            modified:   util/util_test.go

コミットする。コメントは 1 行目に概要、改行をあけて 3 行目から詳細らしい？ 詳細といってもほとんど書くことないけど。

    % git commit -a

エディタ ( 環境変数 EDITOR で登録してあるやつ ) が起動する。コメント書いたら保存して終了する( vim なので :x する )

      1 add NetBSD support
      2
      3 It was diverted FreeBSD.
      4
      5 # Please enter the commit message for your changes. Lines starting
      6 # with '#' will be ignored, and an empty message aborts the commit.
      7 # On branch add_netbsd
      8 # Changes to be committed:
      9 #>modified:   Makefile
     10 #>new file:   command/command_netbsd.go
     11 #>modified:   command/command_unix_test.go
     12 #>new file:   config/config_netbsd.go
     13 #>new file:   metrics/netbsd/cpuusage.go
     14 #>new file:   metrics/netbsd/cpuusage_test.go
     15 #>new file:   metrics/netbsd/filesystem.go
     16 #>new file:   metrics/netbsd/filesystem_test.go
     17 #>new file:   metrics/netbsd/loadavg5.go
     18 #>new file:   metrics/netbsd/memory.go
     19 #>new file:   metrics/netbsd/memory_test.go
     20 #>modified:   metrics/plugin_test.go
     21 #>modified:   pid.go
     22 #>modified:   pid_test.go
     23 #>new file:   spec/netbsd/cpu.go
     24 #>new file:   spec/netbsd/cpu_test.go
     25 #>new file:   spec/netbsd/filesystem.go
     26 #>new file:   spec/netbsd/interface.go
     27 #>new file:   spec/netbsd/kernel.go
     28 #>new file:   spec/netbsd/kernel_test.go
     29 #>new file:   spec/netbsd/memory.go
     30 #>new file:   spec/netbsd/memory_test.go
     31 #>modified:   util/filesystem.go
     32 #>modified:   util/filesystem_test.go
     33 #>modified:   util/util.go
     34 #>modified:   util/util_test.go
     35 #

push する先を確認する。

    % git remote -v
    origin  https://github.com/miwarin/mackerel-agent.git (fetch)
    origin  https://github.com/miwarin/mackerel-agent.git (push)

コミットした内容をリポジトリへ push する。

    % git push origin add_netbsd
    Username for 'https://github.com':
    Password for 'https://miwarin@github.com':
    Counting objects: 35, done.
    Compressing objects: 100% (35/35), done.
    Writing objects: 100% (35/35), 10.85 KiB | 0 bytes/s, done.
    Total 35 (delta 13), reused 0 (delta 0)
    To https://github.com/miwarin/mackerel-agent.git
     * [new branch]      add_netbsd -> add_netbsd

# pull requestを送る

fork 元のリポジトリ https://github.com/mackerelio/mackerel-agent に「Compare & pull request」が出来てるので押す。

コメントを書いて「Send pull request」を押す。コメントは先ほど commit 時に書いた文章と同じでよかろう。

マージされるのを寝て待つ。

