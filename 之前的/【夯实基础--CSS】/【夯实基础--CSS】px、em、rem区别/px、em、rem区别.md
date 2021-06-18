在css中单位长度用的最多的是px、em、rem，这三个的区别是：

1. px是固定的像素，一旦设置了就无法因为适应页面大小而改变。
2. em和rem相对于px更具有灵活性，他们是相对长度单位，意思是长度不是定死了的，更适用于响应式布局。
3. em是相对于其父元素来设置字体大小的，一般都是以`<body>` `font-size`为基准。这样就会存在一个问题，进行任何元素设置，都有可能需要知道他父元素的大小。而Rem是相对于根元素`<html>`，这样就意味着，我们只需要在根元素确定一个参考值。

总之：对于em和rem的区别一句话概括：**`em相对于父元素，rem相对于根元素。`**

#### 一、em

（一）子元素字体大小的em是`相对于父元素字体`大小

（二）元素的width/height/padding/margin用em的话是相对于该元素的font-size

```html
<div>
    父元素div
    <p>
       子元素p
        <span>孙元素span</span>
    </p>
</div>
```

```css
 div {
        font-size: 40px;
     /*
     即1em = 40px = font-size
     */
        width: 7.5em; /* 300px */
        height: 7.5em;
        border: solid 2px black;
    }
 p {
        font-size: 0.5em; /* 20px */
     /*
     上面的em以p的父亲的font-size为基准
     下面的em以p的font-size为基准
     */
        width: 7.5em; /* 150px */
        height: 7.5em;
        border: solid 2px blue ;
        color: blue;
    }span {
        font-size: 0.5em;
        width: 7em;
        height: 6em;
        border: solid 1px red;
        display: block;
        color: red;
    }
```

结果如图：

![img](https://gitee.com/p_pj/picgo/raw/master/img/20210618235740.png)

#### **二、rem**

rem是`全部的长度都相对于根元素`，根元素是谁？`<html>`元素。通常做法是给html元素设置一个字体大小，然后其他元素的长度单位就为rem。

上代码：

```html
<div>
    父元素div
    <p>
       子元素p
        <span>孙元素span</span>
    </p>
</div>
```

```css
   html {
        font-size: 10px;
    }
    div {
        font-size: 4rem; /* 40px */
        width: 20rem;  /* 200px */
        height: 20rem;
        border: solid 2px black;
    }
    p {
        font-size: 2rem; /* 20px */
        width: 10rem;
        height: 10rem;
        border: solid 1px blue;
        color:blue ;
    }
    span {
        font-size: 1.5rem;
        width: 7rem;
        height: 6rem;
        border: solid 2px red;
        display: block;
        color: red;
    }
```

结果如图：

![img](https://gitee.com/p_pj/picgo/raw/master/img/20210618235742.png)

**总结一**

在做项目的时候用什么单位长度取决于你的需求，我一般是这样的：

1、像素（px）：用于元素的边框或定位。

2、em/rem：用于做响应式页面，不过我更倾向于rem，因为em不同元素的参照物不一样（都是该元素父元素），所以在计算的时候不方便，相比之下rem就只有一个参照物（html元素），这样计算起来更清晰。

**总结二**

1、rem 和 em 单位是由浏览器基于你的设计中的字体大小计算得到的像素值。

2、em 单位基于使用他们的元素的字体大小。

3、rem 单位基于 html 元素的字体大小。

4、em 单位可能受任何继承的父元素字体大小影响

5、rem 单位可以从浏览器字体设置中继承字体大小。

6、使用 em 单位应根据组件的字体大小而不是根元素的字体大小。

7、在不需要使用em单位，并且需要根据浏览器的字体大小设置缩放的情况下使用rem。

8、使用rem单位，除非你确定你需要 em 单位，包括对字体大小。

9、媒体查询中使用 rem 单位

10、不要在多列布局中使用 em 或 rem -改用 %。

11、不要使用 em 或 rem，如果缩放会不可避免地导致要打破布局元素。

**需要注意的是：**

样式的reset中需先设置html字体的初始化大小为50px，这是为了防止js被禁用或者加载不到或者执行错误。

而做的兼容样式的reset中需先设置body字体的初始化大小为16px，这是为了让body内的字体大小不继承父级html元素的50px，而用系统默认的16px

#### px 与 rem 的选择？

对于只需要适配少部分手机设备，且分辨率对页面影响不大的，使用px即可 。

对于需要适配各种移动设备，使用rem，例如只需要适配iPhone和iPad等分辨率差别比较挺大的设备。

#### rpx

rpx 是微信小程序解决自适应屏幕尺寸的尺寸单位。`微信小程序规定屏幕的宽度为750rpx`。

无论是在iPhone6上面还是其他机型上面都是750rpx的屏幕宽度，拿iPhone6来讲，屏幕宽度为375px，把它分为750rpx后， 1rpx = 0.5px。

微信小程序同时也支持rem尺寸单位， rem 规定屏幕的宽度为20rem, 所以 1rem = (750/20)rpx = 37.5 rpx