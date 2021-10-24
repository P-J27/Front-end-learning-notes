

#### 1.边框圆角（border-radius）

**语法：border-radius: n1,n2,n3,n4;**

- n1-n4 四个值的顺序是：左上角，右上角，右下角，左下角。

#### 2.过渡（transition）

**语法：transition： CSS 属性，持续时间，效果曲线(默认 ease)，延迟时间(默认 0)**

**示例**

```css
/*宽度从原始值到制定值的一个过渡，运动曲线ease,运动时间0.5秒，0.2秒后执行过渡*/
transition：width,.5s,ease,.2s

/*所有属性从原始值到制定值的一个过渡，运动曲线ease,运动时间0.5秒*/
transition：all,.5s

// 也可以分开写各个属性
transition-property: width;
transition-duration: 1s;
transition-timing-function: linear;
transition-delay: 2s;
```

#### 3.动画（animation）

**语法：animation：动画名称，一个周期花费时间，运动曲线（默认 ease），动画延迟（默认 0），播放次数（默认 1），是否反向播放动画（默认 normal），是否暂停动画（默认 running）**

示例

```css
animation：动画名称，一个周期花费时间，运动曲线（默认ease），动画延迟（默认0），播放次数（默认1），是否反向播放动画（默认normal），是否暂停动画（默认running）
```



#### 4.阴影（box-shadow）

**语法：box-shadow: 水平阴影的位置 垂直阴影的位置 模糊距离 阴影的大小 阴影的颜色 阴影开始方向（默认是从里往外，设置 inset 就是从外往里）**

```css
box-shadow: 5px 5px 10px 2px rgba(0, 0, 0, 0.71);
```

效果如下：

> 实用拓展 ：可运用阴影创造很多设计感十足的效果 比如阴影边框 立体感 光晕效果等等

#### 5.背景大小（background-size）

**语法：background-size: length|percentage|cover|contain**

```css
background-size: cover;
```

效果如下：

> 实用拓展：background-size 还可以设置具体的宽高 px 或者百分比 用来在项目里更加合适的展示背景图

#### 6.文本溢出（text-overflow）

**语法：text-overflow：clip|ellipsis|string**

```css
text-overflow: ellipsis;
```

> 实用拓展：一般用作于单行省略

#### 7.渐变

语法：

- CSS3 线性渐变

```css
<linear-gradient>：linear-gradient([ <point>,]? <color-stop>[, <color-stop>]+);
<point>：[ left | right ]? [ top | bottom ]? || <angle>?
<color-stop>：<color> [ <length> | <percentage> ]?
```

- CSS3 径向渐变

```css
<radial-gradient>：radial-gradient([ <position>,]? [ [ <shape> || <size> ] | <shape-size>{2},]? <color-stop>[, <color-stop>]+);
<position>：[ <length>① | <percentage>① | left | center① | right ]? [ <length>② | <percentage>② | top | center② | bottom ]?

<shape>：circle | ellipse

<size>：closest-side | closest-corner | farthest-side | farthest-corner | contain | cover

<shape-size>：<length> | <percentage>

<color-stop>：<color> [ <length> | <percentage> ]?

```

示例

```css
   <!-- 直线渐变 -->
    <div class="toRight"></div>
    <!-- 径向渐变 -->
    <div class="radial-gradient"></div>
   /* 直线渐变*/
    .toRight {
        margin-top: 100px;
        width: 100%;
        height: 200px;
        background-image: -webkit-linear-gradient(to right,
                rgba(255, 0, 0, 0) 0%,
                rgba(255, 0, 0, 0.8) 7%,
                rgba(255, 0, 0, 1) 11%,
                rgba(255, 0, 0, 1) 12%,
                rgba(255, 252, 0, 1) 28%,
                rgba(1, 180, 7, 1) 45%,
                rgba(0, 234, 255, 1) 60%,
                rgba(0, 3, 144, 1) 75%,
                rgba(255, 0, 198, 1) 88%,
                rgba(255, 0, 198, 0.8) 93%,
                rgba(255, 0, 198, 0) 100%);
        background-image: linear-gradient(to right,
                rgba(255, 0, 0, 0) 0%,
                rgba(255, 0, 0, 0.8) 7%,
                rgba(255, 0, 0, 1) 11%,
                rgba(255, 0, 0, 1) 12%,
                rgba(255, 252, 0, 1) 28%,
                rgba(1, 180, 7, 1) 45%,
                rgba(0, 234, 255, 1) 60%,
                rgba(0, 3, 144, 1) 75%,
                rgba(255, 0, 198, 1) 88%,
                rgba(255, 0, 198, 0.8) 93%,
                rgba(255, 0, 198, 0) 100%);
    }

    /*径向渐变 */
    .radial-gradient {
        margin: 20px auto;
        width: 200px;
        height: 200px;
        border-radius: 100%;
        background-image: -wekbit-radial-gradient(red 20%, green 50%, blue 80%);
        background-image: radial-gradient(red 20%, green 50%, blue 80%);
    }
```

> 实用拓展：这个在实际项目可以用来做彩虹特效  同时模拟太阳光线以及地球地壳分层等

#### 8.滤镜（Filter）

**语法：filter: none | blur() | brightness() | contrast() | drop-shadow() | grayscale() | hue-rotate() | invert() | opacity() | saturate() | sepia() | url();**

```css
filter: grayscale(100%)  blur(2px) opacity(50%);
```

> 实用拓展：对图片置灰 背景图高斯模糊视觉优化  图片透明度调整等等

#### 9.字体（font-face）

语法：

```
<style> 
    @font-face
    {
     font-family: myFirstFont;
     src: url(sansation_light.woff);
    }
    div
    {
     font-family:myFirstFont;
    }
</style>
```

> 实用拓展：为项目配置特殊字体 引用iconfont字体图标

#### 10.媒体查询

语法：

```
@media mediatype and|not|only (media feature) {
    CSS-Code;
} 
```

示例：背景色根据屏幕尺寸变化

```
   @media screen and (max-width: 780px) {
        body {
            background-color: lightblue;
        }
    }
    @media screen and (min-width: 780px) and (max-width:1200px) {
        body {
            background-color: pink;
        }
    }
```

> 实用拓展：移动端适配的解决方案之一 可以个性化定制pc端和移动端样式

#### 11、形状变换

语法：

- transform:适用于2D或3D转换的元素
- transform-origin：转换元素的位置（围绕那个点进行转换）。默认(x,y,z)：(50%,50%,0)

示例：

```css
transform:rotate(30deg);旋转
transform:translate(30px,30px);平移
transform:scale(.8); 放缩
transform: skew(10deg,10deg); 
transform:rotateX(180deg);
transform:rotateY(180deg);
transform:rotate3d(10,10,10,90deg);
```

