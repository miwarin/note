pull request

[github���S�҂�Pull Request�𑗂��Ă݂����̎菇](http://blog.mogmet.com/github-abecedarian-send-pull-request/ "github���S�҂�Pull Request�𑗂��Ă݂����̎菇")

Fork�� ��mackerel-agent https://github.com/mackerelio/mackerel-agent �Ŏ��H���Ă݂��B

# github�ɂ��郊�|�W�g���������̃��|�W�g����fork

github ���|�W�g�� https://github.com/mackerelio/mackerel-agent �̉E��� Fork �{�^���������B

Fork �����B

# fork���|�W�g���ɃR�~�b�g����

fork �������|�W�g���� clone ����

    % mkdir product
    % cd product
    % git clone https://github.com/miwarin/mackerel-agent.git
    % cd mackerel-agent

��Ɨp�Ƀu�����`���쐬����B

    % git checkout -b add_netbsd

�u�����`���o���Ă��m�F����B

    % git branch -v
    * add_netbsd 5aba7fe Merge pull request #154 from mackerelio/gotestcover
      master     5aba7fe Merge pull request #154 from mackerelio/gotestcover

�����Ńt�@�C����ҏW����B

�t�@�C����ҏW������t�@�C���̏�Ԃ��m�F����B

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

NetBSD �p�Ƀt�@�C����V�K�쐬(�Ƃ����Ă� FreeBSD ����R�s�[�������̂�ύX������������ )�����̂� add ����( [git add -A �� git add . �� git add -u �̈Ⴂ - Qiita](http://qiita.com/YusukeHigaki/items/06e38eec96387d408780 "git add -A �� git add . �� git add -u �̈Ⴂ - Qiita") )

    % git add .


�t�@�C���̏�Ԃ��m�F����� new �ɂȂ��Ă���B

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

�R�~�b�g����B�R�����g�� 1 �s�ڂɊT�v�A���s�������� 3 �s�ڂ���ڍׂ炵���H �ڍׂƂ����Ă��قƂ�Ǐ������ƂȂ����ǁB

    % git commit -a

�G�f�B�^ ( ���ϐ� EDITOR �œo�^���Ă����� ) ���N������B�R�����g��������ۑ����ďI������( vim �Ȃ̂� :x ���� )

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

push �������m�F����B

    % git remote -v
    origin  https://github.com/miwarin/mackerel-agent.git (fetch)
    origin  https://github.com/miwarin/mackerel-agent.git (push)

�R�~�b�g�������e�����|�W�g���� push ����B

    % git push origin add_netbsd
    Username for 'https://github.com':
    Password for 'https://miwarin@github.com':
    Counting objects: 35, done.
    Compressing objects: 100% (35/35), done.
    Writing objects: 100% (35/35), 10.85 KiB | 0 bytes/s, done.
    Total 35 (delta 13), reused 0 (delta 0)
    To https://github.com/miwarin/mackerel-agent.git
     * [new branch]      add_netbsd -> add_netbsd

# pull request�𑗂�

fork ���̃��|�W�g�� https://github.com/mackerelio/mackerel-agent �ɁuCompare & pull request�v���o���Ă�̂ŉ����B

�R�����g�������āuSend pull request�v�������B�R�����g�͐�ق� commit ���ɏ��������͂Ɠ����ł悩�낤�B

�}�[�W�����̂�Q�đ҂B

