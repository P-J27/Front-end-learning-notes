#### 前言

一直都在使用Typora写个人笔记，但是markdown里面经常有很多配图，之前采用本地存储的方式，但是这样很容易丢，而且上blog的时候很多平台因为防盗链的原因，体验很不好，以前就知道图床，但是没有自己用过。今天特意写一篇关于建立图床的。这里采用Typora+PicGo+Gitee,全白嫖，之所以选择gitee，因为github太慢了，而且还经常被墙。难受😭。



#### 一. 环境准备

- Typora : 好用的Markdown编辑器
- Gitee账户 : 创建图床仓库
- PicGo ：自动上传图片并返回markdown格式的图片url，这是自动上传的，也就是在Typora中插入图片就自动帮你上传替换图片的url，对于我们用户是透明的，十分舒服。
- node.js : PicGo 安装 Gitee 插件需要 node.js（这个就不用说了吧，一般早就装好了）



#### 二. 正式开始

#### Gitee

1. 如果没有Gitee账号，请先注册，若已有直接登录。

2. 创建仓库（也可以用已有仓库）

   ![image-20210522203704451](https://gitee.com/p_pj/picgo/raw/master/img/20210522203704.png)

   ![image-20210522203824861](https://gitee.com/p_pj/picgo/raw/master/img/20210522203825.png)

3. 仓库分支可以直接是单分支（默认master），可以在分支下再创建个img文件夹，专门存放图床图片

   ![image-20210522203852587](https://gitee.com/p_pj/picgo/raw/master/img/20210522203852.png)

4. 进入生成私人令牌（token），后面配置PicGo时使用

   ![image-20210522203904365](https://gitee.com/p_pj/picgo/raw/master/img/20210522203904.png)

5. 
   点击生成新令牌，可以只选择下面两项，注意：生成的令牌（token）一定要记下来，只显示一次

   ![image-20210522203947664](https://gitee.com/p_pj/picgo/raw/master/img/20210522203947.png)

6. 至此，Gitee部分已经完成



#### PicGo

1. 下载后直接安装，一路next，没什么可说的（安装路径可改可不改）

2. 由于PicGo在GitHub上，一些同学可能下的慢。这里给上的我的百度云

   ```
   链接：https://pan.baidu.com/s/1odMQs9Ue9RtrXFcTruNRbA 
   提取码：1111 
   复制这段内容后打开百度网盘手机App，操作更方便哦
   ```

3. 打开PicGo，安装Gitee图床插件，安装gitee-uploader

   ![image-20210522204154519](https://gitee.com/p_pj/picgo/raw/master/img/20210522204154.png)

4. 安装完成后，再图床设置里面会多出一个Gitee图床

   ![image-20210522204221585](https://gitee.com/p_pj/picgo/raw/master/img/20210522204221.png)

5. 配置Gitee图床说明

![](https://gitee.com/p_pj/picgo/raw/master/img/20210522204534.png)

  - `repo`写入码云建的仓库地址，注意，如果红色框里你的含有中文，你就复制https地址

    如https://gitee.com/p_pj/pig.git，去掉前面的https://gitee.com/和最后的.git 剩下的就是。

![在这里插入图片描述](https://gitee.com/p_pj/picgo/raw/master/img/20210522205704.png)

  - `token`写入前面生成的私人令牌

```css
 repo：gitee用户名/仓库名  //不要用带中文的，你会撞墙的
 branch：master
 token：上面生成的私人令牌
 path：img  
 customPath：默认即可，不用填写
 customUrl：默认即可，不用填写
```





#### Typora

1. 打开Typora，在文件中选择**偏好设置**，点击图像，按照如下选择设置上传规则，其中PicGo路径，选择自己PicGo的安装目录。

![image-20210522205013358](https://gitee.com/p_pj/picgo/raw/master/img/20210522205013.png)

配置好之后，点击**验证图片上传选**项按钮，  验证成功如下：

![image-20210522205051714](https://gitee.com/p_pj/picgo/raw/master/img/20210522205051.png)

这样就成功了，你可以自己试着截张图放进typora里面，不过这样只会在图床上有一份。

如果你想本地和图床都有，你可以改一下这里

![image-20210522205249064](https://gitee.com/p_pj/picgo/raw/master/img/20210522205249.png)

插入时保存在本地，插入成功后右键图片上传就行，也可以。不过感觉必要不大。

