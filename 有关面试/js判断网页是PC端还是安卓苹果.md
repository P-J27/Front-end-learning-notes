#### 前言

> 今天看到一道面试题，JS判断是否是苹果系统(ios)和安卓系统(Android)客户端，一下就涉及到自己的知识盲区，赶紧亡羊补牢一下。顺便在拓展一下是pc还是移动端？pc端的话，又是在什么浏览器运行？



#### JS判断是否是苹果系统(ios)和安卓系统(Android)客户端？

```html
<--!通过判断浏览器的userAgent，用正则来判断是否是ios和Android客户端。代码如下-->
 
<script type="text/javascript">
    var u = navigator.userAgent;
    var isAndroid = u.indexOf('Android') > -1 || u.indexOf('Adr') > -1; //android终端
    var isiOS = !!u.match(/\(i[^;]+;( U;)? CPU.+Mac OS X/); //ios终端
    alert('是否是Android：'+isAndroid);
    alert('是否是iOS：'+isiOS);
    
    //或者直接用正则，i是忽略大小写
    checkPlatform(){
	if(/android/i.test(navigator.userAgent)){
		console.log("Android");//Android
	}
	if(/(iPhone|iPad|iPod|iOS)/i.test(navigator.userAgent)){
		console.log("iOS");//iOS
	}
}

</script>
```



#### js判断客户端是PC端还是移动端访问

```js
//方法1
function IsPC(){  
     var userAgentInfo = navigator.userAgent;
     var Agents = new Array("Android", "iPhone", "SymbianOS", "Windows Phone", "iPad", "iPod");  
     var flag = true;  
     for (var v = 0; v < Agents.length; v++) {  
         if (userAgentInfo.indexOf(Agents[v]) > 0) { flag = false; break; }  
     }  
     return flag;  
  }


//方法2
if (/(iPhone|iPad|iPod|iOS)/i.test(navigator.userAgent)) {
    //alert(navigator.userAgent);  
    window.location.href ="iPhone.html";
} else if (/(Android)/i.test(navigator.userAgent)) {
    //alert(navigator.userAgent); 
    window.location.href ="Android.html";
} else {
    window.location.href ="pc.html";
};


```

#### js判断用什么浏览器运行

```js
var browser={
    versions:function(){ 
           var u = navigator.userAgent, app = navigator.appVersion; 
           return {//移动终端浏览器版本信息 
                trident: u.indexOf('Trident') > -1, //IE内核
                presto: u.indexOf('Presto') > -1, //opera内核
                webKit: u.indexOf('AppleWebKit') > -1, //苹果、谷歌内核
                gecko: u.indexOf('Gecko') > -1 && u.indexOf('KHTML') == -1, //火狐内核
                mobile: !!u.match(/AppleWebKit.*Mobile.*/), //是否为移动终端
                ios: !!u.match(/\(i[^;]+;( U;)? CPU.+Mac OS X/), //ios终端
                android: u.indexOf('Android') > -1 || u.indexOf('Linux') > -1, //android终端或者uc浏览器
                iPhone: u.indexOf('iPhone') > -1 , //是否为iPhone或者QQHD浏览器
                iPad: u.indexOf('iPad') > -1, //是否iPad  
                webApp: u.indexOf('Safari') == -1, //是否web应该程序，没有头部与底部
                weixin: u.indexOf('MicroMessenger') > -1, //是否微信 
                qq: u.match(/\sQQ/i) == " qq" //是否QQ
            };
         }(),
         language:(navigator.browserLanguage || navigator.language).toLowerCase()
} 
 
  if(browser.versions.mobile || browser.versions.ios || browser.versions.android || 
  	browser.versions.iPhone || browser.versions.iPad){  	
   		window.location = "http://m.zhaizhainv.com";	
  }

```

