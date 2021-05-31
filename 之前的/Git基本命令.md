#### 一：创建仓库

##### 	Git设置标识

​		git config --global user.name "用户名"

​		git config --global user.email "邮箱"

​		PS:pwd	显示当前目录

##### 	初始化仓库

​		git init

##### 	提交文件入版本库中

​		git add 文件名（批量添加 git add .）

​		git commit -m "提交的注释"

​		PS:git status	查看当前未被提交的修改

​		PS:git diff 文件名	查看文件到底更改了什么内容

##### 	提交修改同提交文件

#### 二：版本回退

​	git log	查看历史记录

​	git log --pretty=oneline	简略格式查看历史记录

​	git reset --hard HEAD^	回退到上一个版本（几个^就回退到上几个版本）

​	git reset --hard HEAD~100	回退到上*100个版本

​	git reflog	获取之前所有版本号和操作信息

​	git reset --hard 版本号	通过版本号回退

​	

#### 四：撤销修改和删除文件

​	git checkout --文件名	丢弃工作区的修改

​		1.修改后没有放到暂存区，撤销修改就回到和版本库一样的状态

​		2.修改后放到暂存区，但又进行修改，撤销后就回到添加暂存区的状态

​	rm 文件名	删除文件（未提交前可以通过git checkout --文件名恢复）



#### 五：远程仓库

​	ssh-keygen -t rsa -C "email"	创建ssh公钥

​	cat ~/.ssh/id_rsa.pub 	查看自己的公钥

​	ssh -T git@gitee.com	进行连接



#### 六：Clone项目

​	git clone "SSH地址"（clone下来的项目需要初始化）

​	git remote add origin https/ss（添加远程仓库地址）

​	git pull --rebase origin master（将远程仓库和本地仓库合并）

#### 七：git 控制仓库

​	1.git clone git@github.com:github名称/项目仓库		克隆仓库

​	2.修改

​	3.git remote add origin https://gitee.com/yachunli123/liyadang.git		连接远程仓库

​	4.git push origin master			提交修改





​	git branch -a 先查看当前远端分支情况

​	git  checkout origin/xxx  选择远端xxx分支

​	git branch xxx  创建本地xxx分支

​	git checkout xxx  选择新创建的分支就可以了。

​	git push origin dev2将更改添加到新建分支上





​	git status （查看本地分支文件信息，确保更新时不产生冲突） 

​	git branch（查看当前分支情况） 

​	 git checkout remote branch (若分支为本地分支，则需切换到服务器的远程分支) 

 	git pull 





​	git branch 看看分支
​	git chechout aaa 切换分支aaa
​	git branck aaa 创建aaa分支
​	git chechout -b aaa 本地创建 aaa分支，同时切换到aaa分支。只有提交的时候才会在服务端上创建一个分支 



 ####  六：创建与合并分支

git checkout -b dev		 创建dev分支，然后切换到dev分支上 

git branch			查看当前分支

git merge dev			合并分支



查看分支：git branch

创建分支：git branch name

切换分支：git checkout name

创建+切换分支：git checkout –b name

合并某分支到当前分支：git merge name

删除分支：git branch –d name

