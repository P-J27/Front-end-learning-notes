1、定义

```
<meta> 标签提供关于 HTML 文档的元数据。它不会显示在页面上，但是对于机器是可读的。可用于浏览器（如何显示内容或重新加载页面），搜索引擎（关键词），或其他 web 服务。
```

2、作用
meta里的数据是供机器解读的，告诉机器该如何解析这个页面，还有一个用途是可以添加服务器发送到浏览器的http头部内容，例如我们为页面中添加如下meta标签：

```
<meta http-equiv="charset" content="iso-8859-1">
<meta http-equiv="expires" content="31 Dec 2008">
浏览器的头部就会包括这些:
charset:iso-8859-1
expires:31 Dec 2008
```


只有浏览器可以接受这些附加的头部字段，并能以适当的方式使用它们时，这些字段才有意义。

3、meta的必需属性和可选属性
meta的必需属性是content，当然并不是说meta标签里一定要有content，而是当有http-equiv或name属性的时候，一定要有content属性对其进行说明。例如：

必需属性
<meta name="keywords" content="HTML,ASP,PHP,SQL">
这里面content里的属性就是对keywords进行的说明，所以呢也可以理解成一个键值对吧，就是{keywords:"HTML,ASP,PHP,SQL"}。

可选属性
在W3school中，对于meta的可选属性说到了三个，分别是http-equiv、name和scheme。考虑到scheme不是很常用，所以就只说下前两个属性吧。

http-equiv

http-equiv属性是添加http头部内容，对一些自定义的，或者需要额外添加的http头部内容，需要发送到浏览器中，我们就可以是使用这个属性。在上面的meta作用中也有简单的说明，那么现在再举个例子。例如我们不想使用js来重定向，用http头部内容控制，那么就可以这样控制：

<meta http-equiv="Refresh" content="5;url=http://blog.yangchen123h.cn" />

在页面中加入这个后，5秒钟后就会跳转到指定页面啦，效果可看W3school的例子

name

第二个可选属性是name，这个属性是供浏览器进行解析，对于一些浏览器兼容性问题，name属性是最常用的，当然有个前提就是浏览器能够解析你写进去的name属性才可以，不然就是没有意义的。还是举个例子吧:

<meta name="renderer" content="webkit">

这个meta标签的意思就是告诉浏览器，用webkit内核进行解析，当然前提是浏览器有webkit内核才可以，不然就是没有意义的啦。当然看到这个你可能会有疑问，这个renderer是从哪里冒出来的，我要怎么知道呢？这个就是在对应的浏览器的开发文档里就会有表明的，例如这个renderer是在360浏览器里说明的。360浏览器内核控制Meta标签说明文档

常用meta标签大总结
接下来就是常用的meta标签大总结啦，我会尽可能的做到全

charset
charset是声明文档使用的字符编码，解决乱码问题主要用的就是它，值得一提的是，这个charset一定要写第一行，不然就可能会产生乱码了。

charset有两种写法

<meta charset="utf-8">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">

两个都是等效的。

百度禁止转码
百度会自动对网页进行转码，这个标签是禁止百度的自动转码

<meta http-equiv="Cache-Control" content="no-siteapp" />
SEO 优化部分
<!-- 页面标题<title>标签(head 头部必须) -->
<title>your title</title>
<!-- 页面关键词 keywords -->
<meta name="keywords" content="your keywords">
<!-- 页面描述内容 description -->
<meta name="description" content="your description">
<!-- 定义网页作者 author -->
<meta name="author" content="author,email address">
<!-- 定义网页搜索引擎索引方式，robotterms 是一组使用英文逗号「,」分割的值，通常有如下几种取值：none，noindex，nofollow，all，index和follow。 -->
<meta name="robots" content="index,follow">
viewport
viewport主要是影响移动端页面布局的，例如：

<meta name="viewport" content="width=device-width, initial-scale=1.0">

content 参数：

width viewport 宽度(数值/device-width)
height viewport 高度(数值/device-height)
initial-scale 初始缩放比例
maximum-scale 最大缩放比例
minimum-scale 最小缩放比例
user-scalable 是否允许用户缩放(yes/no)
各浏览器平台
Microsoft Internet Explorer

<!-- 优先使用最新的ie版本 -->
<meta http-equiv="x-ua-compatible" content="ie=edge">
<!-- 是否开启cleartype显示效果 -->
<meta http-equiv="cleartype" content="on">
<meta name="skype_toolbar" content="skype_toolbar_parser_compatible">
 

<!-- Pinned Site -->
<!-- IE 10 / Windows 8 -->
<meta name="msapplication-TileImage" content="pinned-tile-144.png">
<meta name="msapplication-TileColor" content="#009900">
<!-- IE 11 / Windows 9.1 -->
<meta name="msapplication-config" content="ieconfig.xml">
Google Chrome

<!-- 优先使用最新的chrome版本 -->
<meta http-equiv="X-UA-Compatible" content="chrome=1" />
<!-- 禁止自动翻译 -->
<meta name="google" value="notranslate">
360浏览器

<!-- 选择使用的浏览器解析内核 -->
<meta name="renderer" content="webkit|ie-comp|ie-stand">
UC手机浏览器

UCBrowser_U3_API

QQ手机浏览器

<!-- 锁定屏幕在特定方向 -->
<meta name="x5-orientation" content="landscape/portrait">
<!-- 全屏显示 -->
<meta name="x5-fullscreen" content="true">
<!-- 页面将以应用模式显示 -->
<meta name="x5-page-mode" content="app">
Apple iOS

<!-- Smart App Banner -->
<meta name="apple-itunes-app" content="app-id=APP_ID,affiliate-data=AFFILIATE_ID,app-argument=SOME_TEXT">
 

<!-- 禁止自动探测并格式化手机号码 -->
<meta name="format-detection" content="telephone=no">
 

<!-- Add to Home Screen添加到主屏 -->
<!-- 是否启用 WebApp 全屏模式 -->
<meta name="apple-mobile-web-app-capable" content="yes">
<!-- 设置状态栏的背景颜色,只有在 “apple-mobile-web-app-capable” content=”yes” 时生效 -->
<meta name="apple-mobile-web-app-status-bar-style" content="black">
<!-- 添加到主屏后的标题 -->
<meta name="apple-mobile-web-app-title" content="App Title">
Google Android

<meta name="theme-color" content="#E64545">
<!-- 添加到主屏 -->
<meta name="mobile-web-app-capable" content="yes">
<!-- More info: https://developer.chrome.com/multidevice/android/installtohomescreen -->
App Links

<!-- iOS -->
<meta property="al:ios:url" content="applinks://docs">
<meta property="al:ios:app_store_id" content="12345">
<meta property="al:ios:app_name" content="App Links">
<!-- Android -->
<meta property="al:android:url" content="applinks://docs">
<meta property="al:android:app_name" content="App Links">
<meta property="al:android:package" content="org.applinks">
<!-- Web Fallback -->
<meta property="al:web:url" content="http://applinks.org/documentation">
<!-- More info: http://applinks.org/documentation/ -->
最后——移动端常用的meta
<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
<meta name="apple-mobile-web-app-capable" content="yes" />
<meta name="apple-mobile-web-app-status-bar-style" content="black" />
<meta name="format-detection"content="telephone=no, email=no" />
<meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no" />
<meta name="apple-mobile-web-app-capable" content="yes" /><!-- 删除苹果默认的工具栏和菜单栏 -->
<meta name="apple-mobile-web-app-status-bar-style" content="black" /><!-- 设置苹果工具栏颜色 -->
<meta name="format-detection" content="telphone=no, email=no" /><!-- 忽略页面中的数字识别为电话，忽略email识别 -->
<!-- 启用360浏览器的极速模式(webkit) -->
<meta name="renderer" content="webkit">
<!-- 避免IE使用兼容模式 -->
<meta http-equiv="X-UA-Compatible" content="IE=edge">
<!-- 针对手持设备优化，主要是针对一些老的不识别viewport的浏览器，比如黑莓 -->
<meta name="HandheldFriendly" content="true">
<!-- 微软的老式浏览器 -->
<meta name="MobileOptimized" content="320">
<!-- uc强制竖屏 -->
<meta name="screen-orientation" content="portrait">
<!-- QQ强制竖屏 -->
<meta name="x5-orientation" content="portrait">
<!-- UC强制全屏 -->
<meta name="full-screen" content="yes">
<!-- QQ强制全屏 -->
<meta name="x5-fullscreen" content="true">
<!-- UC应用模式 -->
<meta name="browsermode" content="application">
<!-- QQ应用模式 -->
<meta name="x5-page-mode" content="app">
<!-- windows phone 点击无高光 -->
<meta name="msapplication-tap-highlight" content="no">
<!-- 适应移动端end -->

 