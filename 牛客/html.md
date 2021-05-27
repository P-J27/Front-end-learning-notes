1.	浏览器页面有哪三层构成，分别是什么，作用是什么?

参考答案：

> 构成：结构层、表示层、行为层分别是：HTML、CSS、JavaScript
> 作用：HTML 实现页面结构，CSS 完成页面的表现与风格，JavaScript 实现一些客户端的功能与业务。

2.	HTML5 的优点与缺点？

参考答案： 

> 优点：
> a、网络标准统一、HTML5 本身是由 W3C 推荐出来的。b、多设备、跨平台
> c、即时更新。
> d、提高可用性和改进用户的友好体验；
>
>
> e、有几个新的标签，这将有助于开发人员定义重要的内容； f、可以给站点带来更多的多媒体元素(视频和音频)；
> g、可以很好的替代 Flash 和 Silverlight；
> h、涉及到网站的抓取和索引的时候，对于 SEO 很友好； i、被大量应用于移动应用程序和游戏。
>
> 缺点：
> a、安全：像之前 Firefox4 的 web socket 和透明代理的实现存在严重的安全问题，同时 web storage、web socket 这样的功能很容易被黑客利用，来盗取用户的信息和资料。
> b、完善性：许多特性各浏览器的支持程度也不一样。
> c、技术门槛：HTML5 简化开发者工作的同时代表了有许多新的属性和 API 需要开发者学习，像 web worker、web socket、web storage 等新特性，后台甚至浏览器原理的知识，机遇的同时也是巨大的挑战
> d、性能：某些平台上的引擎问题导致 HTML5 性能低下。
> e、浏览器兼容性：最大缺点，IE9 以下浏览器几乎全军覆没。

3. Doctype 作用? 严格模式与混杂模式如何区分？它们有何意义?
   参考答案：

    回答 1：
   （1）	声明位于文档中的最前面，处于标签之前。告知浏览器的解析器，用什么文档类型 规范来解析这个文档。
   （2）	严格模式的排版和 JS 运作模式是以该浏览器支持的最高标准运行。
   （3）	在混杂模式中，页面以宽松的向后兼容的方式显示。模拟老式浏览器的行为以防止站点无法工作。（4）	DOCTYPE 不存在或格式不正确会导致文档以混杂模式呈现。

   回答 2：
   doctype 声明指出阅读程序应该用什么规则集来解释文档中的标记。在 Web 文档的情况下，“阅读程序”通常是浏览器或者校验器这样的一个程序，“规则”则是 W3C 所发布的一个文档类型定义（DTD）中包含的规则。
   （1）	声明位于文档中的最前面的位置，处于标签之前。此标签可告知浏览器文档使用哪种 HTML 或 XHTML 规范。该标签可声明三种 DTD 类型，分别表示严格版本、过渡版本以及基于框架的 HTML 文档。
   （2）	所谓的标准模式是指，浏览器按 W3C 标准解析执行代码；怪异模式则是使用浏览器自己的方式解析执行代码，因为不同浏览器解析执行的方式不一样， 所以我们称之为怪异模式。 严格模式是浏览器根据 web 标准去解析页面，是一种要求严格的 DTD，不允许使用任何表现层的语法，如。严格模式的排版和 JS 运作模式是以该浏览器支持的最高标准运行混杂模式则是一种向后兼容的解析方法，说的透明点就是可以实现 IE5.5 以下版本浏览器的渲染模式。
   （3）	浏览器解析时到底使用标准模式还是怪异模式，与你网页中的 DTD 声明直接相关， DTD 声明定义了标准文档的类型（标准模式解析）文档类型，会使浏览器使用相应的方式加载网页并显示，忽略 DTD 声明 ,将使网页进入怪异模式。

4.	HTML5 有哪些新特性、移除了哪些元素？

参考答案：

> Html5 新增了 27 个元素，废弃了 16 个元素，根据现有的标准规范，把	HTML5 的元素按优先级定义为结构性属性、级块性元素、行内语义性元素和交互性元素4 大类。
>
> 结构性元素主要负责 web 上下文结构的定义：
> section：在	web	页面应用中，该元素也可以用于区域的章节描述。
>
>
> header：页面主体上的头部，	header	元素往往在一对	body	元素中。footer：页面的底部（页脚），通常会标出网站的相关信息。
> nav：专门用于菜单导航、链接导航的元素，是	navigator	的缩写。article：用于表现一篇文章的主体内容，一般为文字集中显示的区域。级块性元素主要完成 web 页面区域的划分，确保内容的有效分割。
> aside：用于表达注记、贴士、侧栏、摘要、插入的引用等作为补充主体的内容。figure：是对多个元素进行组合并展示的元素，通常与 ficaption 联合使用。code：表示一段代码块。
> dialog：用于表达人与人之间的对话，该元素包含 dt 和 dd 这两个组合元素， dt 用于表示说话者，而 dd 用来表示说话内容。
>
> 行内语义性元素主要完成 web 页面具体内容的引用和描述，是丰富内容展示的基础。
> meter：表示特定范围内的数值，可用于工资、数量、百分比等。time：表示时间值。
> progress：用来表示进度条，可通过对其	max	、 min	、 step	等属性进行控制，完成对进度的表示和监事。
> video：视频元素，用于支持和实现视频文件的直接播放，支持缓冲预载和多种视频媒体格式。
> audio：音频元素，用于支持和实现音频文件的直接播放，支持缓冲预载和多种音频媒体格式。
>
> 交互性元素主要用于功能性的内容表达，会有一定的内容和数据的关联，是各种事件的基础。
> details：用来表示一段具体的内容，但是内容默认可能不显示，通过某种手段
> （如单击）与	legend	交互才会显示出来。
> datagrid：用来控制客户端数据与显示，可以由动态脚本及时更新。
>
>
> menu：主要用于交互菜单（曾被废弃又被重新启用的元素）。command：用来处理命令按钮。

5. 你做的网页在哪些浏览器测试过,这些浏览器的内核分别 是什么?
   参考答案：

   > a、IE: trident 内核
   > b、Firefox：gecko 内核c、Safari: webkit 内核
   > d、Opera: 以前是 presto 内核，Opera 现已改用 Google Chrome 的 Blink 内核e、Chrome:Blink(基于 webkit，Google 与 Opera Software 共同开发	)

6. 每个 HTML 文件里开头都有个很重要的东西，Doctype，知道这是干什么的吗？
   参考答案：

   > 声明位于文档中的最前面的位置，处于标签之前。此标签可告知浏览器文档使用哪种 HTML 或 XHTML 规范。（重点：告诉浏览器按照何种规范解析页面）

7. 说说你对 HTML5 认识?（是什么,为什么）

参考答案： 是什么：
HTML5 指的是包括 HTML、CSS 和 JavaScript 在内的一套技术组合。它希望能够减少网页浏览器对于需要插件的丰富性网络应用服务（Plug-in-Based Rich Internet Application，RIA），例如：AdobeFlash	、Microsoft Silverlight 与 Oracle JavaFX 的需求，并且提供更多能有效加强网络应用的标准集。HTML5






是 HTML 最新版本，2014 年 10 月由万维网联盟（W3C）完成标准制定。目标是替换 1999 年所制定的 HTML4.01 和 XHTML 1.0 标准，以期能在互联网应用迅速发展的时候，使网络标准达到匹配当代的网络需求。
为什么：
HTML4 陈旧不能满足日益发展的互联网需要，特别是移动互联网。为了增强浏览器功能 Flash 被广泛使用，但安全与稳定堪忧，不适合在移动端使用（耗电、触摸、不开放）。
HTML5 增强了浏览器的原生功能，符合 HTML5 规范的浏览器功能将更加强大，减少了 Web 应用对插件的依赖，让用户体验更好，让开发更加方便，另外 W3C 从推出 HTML4.0 到 5.0 之间共经历了 17 年，HTML 的变化很小，这并不符合一个好产品的演进规则。

8.	对 WEB 标准以及 W3C 的理解与认识?

参考答案：

> 标签闭合、标签小写、不乱嵌套、提高搜索机器人搜索几率、使用外链 css 和js 脚本、结构行为表现的分离、文件下载与页面速度更快、内容能被更多的用户所访问、内容能被更广泛的设备所访问、更少的代码和组件，容易维护、改版方便，不需要变动页面内容、提供打印版本而不需要复制内容、提高网站易用性。

9.	HTML5 行内元素有哪些,块级元素有哪些, 空元素有哪些?

参考答案： 

* ```
  (1)行内元素a -	锚点
  abbr -	缩写acronym -	首字
  b -	粗体	(	不推荐	)
  
  bdo - bidi override big -	大字体
  br -	换行cite -		引用
  code -		计算机代码	(	在引用源码的时候需要	) dfn -	定义字段
  em -	强调
  font -	字体设定	(	不推荐	) i -	斜体
  img -	图片input -		输入框
  kbd -	定义键盘文本label -		表格标签
  q -	短引用
  s -	中划线	(	不推荐	) samp -	定义范例计算机代码select -		项目选择
  small -	小字体文本
  span -	常用内联容器，定义文本内区块strike -		中划线
  strong -	粗体强调sub -	下标
  sup -	上标
  textarea -	多行文本输入框tt -	电传文本
  u -	下划线
  var -	定义变量
  
  
  (2)	块元素	(block element)
  
  *	address -	地址
  *	blockquote -	块引用
  *	center - 居中对齐块
  *	dir -	目录列表
  *	div -	常用块级容易，也是	css layout	的主要标签
  *	dl -	定义列表
  *	fieldset - form 控制组
  *	form -	交互表单
  *	h1 -	大标题
  *	h2 -	副标题
  *	h3 - 3 级标题
  *	h4 - 4 级标题
  *	h5 - 5 级标题
  *	h6 - 6 级标题
  *	hr -	水平分隔线
  *	isindex - input prompt
  *	menu -	菜单列表
  *	noframes - frames 可选内容，（对于不支持	frame	的浏览器显示此区块内容
  *	noscript -	）可选脚本内容（对于不支持	script	的浏览器显示此内容）
  *	ol -	排序表单
  *	p -	段落
  *	pre -	格式化文本
  *	table -	表格ul -	非排序列表
  
  
  (3)	可变元素
  可变元素为根据上下文语境决定该元素为块元素或者内联元素。
  
  *	applet - java applet
  *	button -	按钮
  *	del -	删除文本
  *	iframe - inline frame
  *	ins -	插入的文本
  *	map -	图片区块	(map)
  *	object - object 对象
  *	script -	客户端脚本
  ```


```html
    (4)	空元素	(	在	HTML[1]	元素中，没有内容的	HTML	元素被称为空元素	)
    <br/> //换行
    <hr> //分隔线
    <input> //文本框等
    <img> //图片
    <link> <meta>
```

​    

11. 什么是 WebGL,它有什么优点?

参考答案：

> WebGL（全写 Web Graphics Library ）是一种 3D 绘图标准，这种绘图技术标准允许把 JavaScript 和 OpenGL ES 2.0 结合在一起，通过增加 OpenGL ES 2.0 的一个 JavaScript 绑定，WebGL 可以为 HTML5 Canvas 提供硬件 3D 加速渲染，这样 Web 开发人员就可以借助系统显卡来在浏览器里更流畅地展示 3D 场景和模型了，还能创建复杂的导航和数据视觉化。显然，WebGL 技术标准免去了开发网页专用渲染插件的麻烦，可被用于创建具有复杂 3D 结构的网站页面，甚至可以用来设计 3D 网页游戏等等。
> WebGL 完美地解决了现有的 Web 交互式三维动画的两个问题：
>
> 第一，它通过 HTML 脚本本身实现 Web 交互式三维动画的制作，无需任何浏览器插件支持 ;
> 第二，它利用底层的图形硬件加速功能进行的图形渲染，是通过统一的、标准的、跨平台的 OpenGL 接口实现的。
> 通俗说 WebGL 中 canvas 绘图中的 3D 版本。因为原生的 WebGL 很复杂，我们经常会使用一些三方的库，如 three.js 等，这些库多数用于 HTML5 游戏开发。



11.	请你描述一下 cookies，sessionStorage 和localStorage 的区别?
    参考答案: 

> 1）Cookie
> 每个域名存储量比较小（各浏览器不同，大致 4K ） 所有域名的存储量有限制（各浏览器不同，大致 4K ） 有个数限制（各浏览器不同）
> 会随请求发送到服务器
>
>
> 2）	LocalStorage 永久存储
> 单个域名存储量比较大（推荐 5MB ，各浏览器不同） 总体数量无限制
>
> 3）	SessionStorage 只在 Session 内有效
> 存储量更大（推荐没有限制，但是实际上各浏览器也不同）

12.	说说你对 HTML 语义化的理解?

参考答案：

(1)	什么是	HTML 语义化？
<基本上都是围绕着几个主要的标签，像标题（	H1~H6	）、列表（	li	）、强调（	strong	em	）等等


根据内容的结构化（内容语义化），选择合适的标签（代码语义化）便于开发者阅读和写出更优雅的代码的同时让浏览器的爬虫和机器很好地解析。

(2)	为什么要语义化？
为了在没有 CSS 的情况下，页面也能呈现出很好地内容结构、代码结构	:	为了裸奔时好看；
用户体验：例如 title、 alt	用于解释名词或解释图片信息、 label 标签的活用；
有利于 SEO：和搜索引擎建立良好沟通，有助于爬虫抓取更多的有效信息：爬虫依赖于标签来确定上下文和各个关键字的权重；
方便其他设备解析（如屏幕阅读器、盲人阅读器、移动设备）以意义的方式来渲染网页；
便于团队开发和维护，语义化更具可读性，是下一步网页的重要动向，遵循 W3C 标准的团队都遵循这个标准，可以减少差异化。

(3)	语义化标签

```html
<header></header>
<footer></footer>
<nav></nav>
<section></section>
<article></article>
```


14.	说说你对 SVG 理解?

参考答案：

> SVG 可缩放矢量图形（Scalable Vector Graphics）是基于可扩展标记语言（XML），用于描述二维矢量图形的一种图形格式。SVG 是 W3C('World Wide Web ConSortium'即'国际互联网标准织')在 2000 年 8 月制定的一种新的二维矢量图形格式，也是规范中的网络矢量图形标准。SVG 严格遵从 XML 语法，并用文本格式的描述性语言来描述图像内容，因此是一种和图像分辨率无关的矢量图形格 式。SVG 于 2003 年 1 月 14 日成为 W3C 推荐标准。
>
> 特点：
> (1)任意放缩
> 用户可以任意缩放图像显示，而不会破坏图像的清晰度、细节等。(2)文本独立
> SVG 图像中的文字独立于图像，文字保留可编辑和可搜寻的状态。也不会再有字体的限制，用户系统即使没有安装某一字体，也会看到和他们制作时完全相同的画面。
> (3)较小文件
> 总体来讲，SVG 文件比那些 GIF 和 JPEG 格式的文件要小很多，因而下载也很快。(4)超强显示效果
> SVG 图像在屏幕上总是边缘清晰，它的清晰度适合任何屏幕分辨率和打印分辨率。
> (5)	超级颜色控制
> SVG 图像提供一个 1600 万种颜色的调色板，支持 ICC 颜色描述文件标准、RGB、线 X 填充、渐变和蒙版。
>
>
> (6)	交互 X 和智能化。SVG 面临的主要问题一个是如何和已经占有重要市场份额的矢量图形格式 Flash 竞争的问题，另一个问题就是 SVG 的本地运行环境下的厂家支持程度。
>
> 浏览器支持：
> Internet Explorer9，火狐，谷歌 Chrome，Opera 和 Safari 都支持 SVG。IE8 和早期版本都需要一个插件-如 Adobe SVG 浏览器，这是免费提供的。

15.	HTML 全局属性(global attribute)有哪些?

参考答案：

```html
MDN: html global attribute 或者 W3C HTML global-attributes
accesskey:设置快捷键，提供快速访问元素如 aaa 在 windows 下的 firefox 中按alt + shift + a 可激活元素;
class:为元素设置类标识，多个类名用空格分开，CSS 和javascript 可通过class属性获取元素;
contenteditable: 指定元素内容是否可编辑;
contextmenu: 自定义鼠标右键弹出菜单内容 data-*: 为元素增加自定义属性; dir: 设置元素文本方向;
draggable: 设置元素是否可拖拽;
dropzone: 设置元素拖放类型： copy, move, link hidden: 表示一个元素是否与文档。样式上会导致元素不显示，但是不能用这个属性实现样式效果 id: 元素 id，文档内唯一;
lang: 元素内容的的语言 spellcheck: 是否启动拼写和语法检查style: 行内 css 样式
tabindex: 设置元素可以获得焦点，通过 tab 可以导航;
title: 元素相关的建议信息;
translate: 元素和子孙节点内容是否需要本地化;
```

16.	说说超链接 target 属性的取值和作用？

参考答案:

> target 这个属性指定所链接的页面在浏览器窗口中的打开方式。它的参数值主要有：
> a、_blank：在新浏览器窗口中打开链接文件；
> b、_parent	：将链接的文件载入含有该链接框架的父框架集或父窗口中。如果含有该链接的框架不是嵌套的，则在浏览器全屏窗口中载入链接的文件，就象
> _self 参数一；
> c、_self：在同一框架或窗口中打开所链接的文档。此参数为默认值，通常不用指定。但是我不太理解；
> d、_top：在当前的整个浏览器窗口中打开所链接的文档，因而会删除所有框架；

17.	`data-`属性的作用是什么？

参考答案:

> `data-`为 H5 新增的为前端开发者提供自定义的属性，这些属性集可以通过对象的`dataset`属性获取，不支持该属性的浏览器可以通过`getAttribute`方法获取，需要注意的是：`data-`之后的以连字符分割的多个单词组成的属性，获取的时候使用驼峰风格。所有主流浏览器都支持 data-* 属性。
> 即：当没有合适的属性和元素时，自定义的 data 属性是能够存储页面或 App 的私有的自定义数据。


18.	介绍一下你对浏览器内核的理解？

参考答案:

> 主要分成两部分：渲染引擎(layout engineer 或 Rendering Engine)和 JS 引擎。
> 渲染引擎：负责取得网页的内容（HTML、XML、图像等等）、整理讯息（例如加入 CSS 等），以及计算网页的显示方式，然后会输出至显示器或打印机。浏览器的内核的不同对于网页的语法解释会有不同，所以渲染的效果也不相同。所有网页浏览器、电子邮件客户端以及其它需要编辑、显示网络内容的应用程序都需要内核。
> JS 引擎：解析和执行 javascript 来实现网页的动态效果。
> 最开始渲染引擎和 JS 引擎并没有区分的很明确，后来 JS 引擎越来越独立，内核就倾向于只指渲染引擎。

19.	常见的浏览器内核有哪些？

参考答案:

> view sourceprint?
> Trident 内核：IE,MaxThon,TT,The World,360,	搜狗浏览器等。[又称 MSHTML] Gecko 内核：Netscape6 及以上版本，FF,MozillaSuite/SeaMonkey 等
> Presto 内核：Opera7 及以上。[Opera 内核原为：Presto，现为：Blink;] Webkit 内核：Safari,Chrome 等。 [ Chrome 的：Blink（WebKit 的分支）]

20.	iframe 有那些缺点？

参考答案:

> (1)	iframe 会阻塞主页面的 Onload 事件；
> (2)	搜索引擎的检索程序无法解读这种页面，不利于 SEO;
>
> (3)	iframe 和主页面共享连接池，而浏览器对相同域的连接有限制，所以会影响页面的并行加载。
> 使用 iframe 之前需要考虑这两个缺点。如果需要使用 iframe，最好是通过	javascript
> 动态给 iframe 添加	src	属性值，这样可以绕开以上两个问题。

21.	Label 的作用是什么，是怎么用的？

参考答案:

```html
//label 标签来定义表单控制间的关系	,	当用户选择该标签时，浏览器会自动将焦点转到和标签相关的表单控件上。
<label for='Name'>Number:</label>
<input type=“	text	“	name='Name' id='Name'/>
<label>Date:<input type='text' name='B'/></label>
注意:label 的 for 属性值要与后面对应的 input 标签 id 属性值相同
<label for='Name'>Number:</label>
<input type=“	text	“	name='Name' id='Name'/>
```

22.	如何实现浏览器内多个标签页之间的通信?

参考答案:

> WebSocket、SharedWorker；
> 也可以调用 localstorage、cookies 等本地存储方式；
> localstorage 另一个浏览上下文里被添加、修改或删除时，它都会触发一个事件，我们通过监听事件，控制它的值来进行页面信息通信；
> 注意 quirks：Safari 在无痕模式下设置 localstorge 值时会抛出QuotaExceededError 的异常；


23.	如何在页面上实现一个圆形的可点击区域？

参考答案:

> a、map+area 或者 svg b、border-radius
> c、纯 js 实现 需要求一个点在不在圆上简单算法、获取鼠标坐标等等

24.	title 与h3 的区别、b 与strong 的区别、i 与em 的区别？

参考答案:

```html
(1)	title 属性没有明确意义只表示是个标题，H1 则表示层次明确的标题，对页面信息的抓取也有很大的影响；
(2)	strong 是标明重点内容，有语气加强的含义，使用阅读设备阅读网时：
<strong>会重读，而<B>是展示强调内容。
(3)	i 内容展示为斜体，em 表示强调的文本； Physical Style Elements -- 自然样式标签b, i, u, s, pre
Semantic Style Elements --	语义样式标签strong, em, ins, del, code
应该准确使用语义样式标签,但不能滥用,如果不能确定时首选使用自然样式标签。
```



25. 实现不使用 border 画出 1px 高的线，在不同浏览器的标准模式与怪异模式下都能保持一致的效果？
    参考答案:

    ```html
    <div style="width:100%;height:1px;background-color:black"></div>
    ```


26.	HTML5 标签的作用?(用途)

参考答案:

> a、使 Web 页面的内容更加有序和规范；
>
> b、使搜索引擎更加容易按照 HTML5 规则识别出有效的内容
>
> c、使 Web 页面更接近于一种数据字段和表；

27.	简述一下 src 与 href 的区别？

参考答案:

src 用于替换当前元素，href 用于在当前文档和引用资源之间确立联系。
src 是 source 的缩写，指向外部资源的位置，指向的内容将会嵌入到文档中当前标签所在位置；
在请求 src 资源时会将其指向的资源下载并应用到文档内，例如 js 脚本，img 图片和 frame 等元素。

```html
<script src ='js.js'></script>
```

``` html
当浏览器解析到该元素时，会暂停其他资源的下载和处理，直到将该资源加载、编译、执行完毕，图片和框架等元素也如此，类似于将所指向资源嵌入当前标签内。这也是为什么将 js 脚本放在底部而不是头部。
href 是 Hypertext Reference 的缩写，指向网络资源所在位置，建立和当前元素（锚点）或当前文档（链接）之间的链接，如果我们在文档中添加<link href='common.css' rel='stylesheet'/>
那么浏览器会识别该文档为 css 文件，就会并行下载资源并且不会停止对当前文档的处理。这也是为什么建议使用 link 方式来加载 css，而不是使用@import 方式。
```


28.	谈谈你对 canvas 的理解？

参考答案:

> canvas 是 HTML5 中新增一个 HTML5 标签与操作 canvas 的 javascript API，它可以实现在网页中完成动态的 2D 与 3D 图像技术。标记和 SVG 以及 VML 之间的一个重要的不同是，有一个基于 JavaScript 的绘图 API，而 SVG 和 VML 使用一个 XML 文档来描述绘图。SVG 绘图很容易编辑与生成，但功能明显要弱一些。canvas 可以完成动画、游戏、图表、图像处理等原来需要 Flash 完成的一些功能。

29.	WebSocket 与消息推送？

参考答案:

> B/S 架构的系统多使用 HTTP 协议， HTTP 协议的特点：
> 1)	无状态协议
> 2)	用于通过 Internet 发送请求消息和响应消息
> 3)	使用端口接收和发送消息，默认为 80 端口 底层通信还是使用 Socket 完成。
>
> HTTP 协议决定了服务器与客户端之间的连接方式，无法直接实现消息推送（F5 已坏）,一些变相的解决办法：
> 双向通信与消息推送
> 轮询：客户端定时向服务器发送 Ajax 请求，服务器接到请求后马上返回响应信息并关闭连接。
> 优点：后端程序编写比较容易。
> 缺点：请求中有大半是无用，浪费带宽和服务器资源。实例：适于小型应用。
>
> 长轮询：客户端向服务器发送 Ajax 请求，服务器接到请求后 hold 住连接， 直到有新消息才返回响应信息并关闭连接，客户端处理完响应信息后再向服务器发送新的请求。
> 优点：在无消息的情况下不会频繁的请求，耗费资小。
> 缺点：服务器 hold 连接会消耗资源，返回数据顺序无保证，难于管理维护。Comet 异步的 ashx，
> 实例：WebQQ、Hi 网页版、Facebook IM。
> 长连接：在页面里嵌入一个隐蔵 iframe，将这个隐蔵 iframe 的 src 属性设为对一个长连接的请求或是采用 xhr 请求，服务器端就能源源不断地往客户端输入数据。
> 优点：消息即时到达，不发无用请求；管理起来也相对便。缺点：服务器维护一个长连接会增加开销。
> 实例：Gmail 聊天
> Flash Socket：在页面中内嵌入一个使用了 Socket 类的 Flash 程序 JavaScript 通过调用此 Flash 程序提供的 Socket 接口与服务器端的 Socket 接口进行通信， JavaScript 在收到服务器端传送的信息后控制页面的显示。
> 优点：实现真正的即时通信，而不是伪即时。
> 缺点：客户端必须安装 Flash 插件；非 HTTP 协议，无法自动穿越防火墙。实例：网络互动游戏。
> Websocket:
> WebSocket 是HTML5 开始提供的一种浏览器与服务器间进行全双工通讯的网络技术。依靠这种技术可以实现客户端和服务器端的长连接，双向实时通信。
> 特点:
> a、事件驱动b、异步
>
> c、使用 ws 或者 wss 协议的客户端 socket
>
>  d、能够实现真正意义上的推送功能
>
>
> 缺点：少部分浏览器不支持，浏览器支持的程度与方式有区别。

30.	mg 的 title 和 alt 有什么区别？

参考答案:

> Alt 用于图片无法加载时显示 Title 为该属性提供信息，通常当鼠标滑动到元素上的时候显示。

31.	表单的基本组成部分有哪些，表单的主要用途是什么？

参考答案:

> 组成：表单标签、表单域、表单按钮
> a、表单标签：这里面包含了处理表单数据所用 CGI 程序的 URL,以及数据提交到服务器的方法。
> b、表单域：包含了文本框、密码框、隐藏域、多行文本框、复选框、单选框、下拉选择框、和文件上传框等。
> c、表单按钮：包括提交按钮，复位按钮和一般按钮；用于将数据传送到服务器上的 CGI 脚本或者取消输入，还可以用表单按钮来控制其他定义了处理脚本的处理工作。
> 主要用途：表单在网页中主要负责数据采集的功能，和向服务器传送数据。

32.	表单提交中 Get 和 Post 方式的区别？

参考答案：

```
(1)	get 是从服务器上获取数据，post 是向服务器传送数据。
(2)	get 是把参数数据队列加到提交表单的 ACTION 属性所指的 URL 中，值和表单内各个字段一一对应，在 URL 中可以看到。post 是通过 HTTP post 机制，将

表单内各个字段与其内容放置在 HTML HEADER 内一起传送到 ACTION 属性所指的URL 地址,用户看不到这个过程。
(3)	对于 get 方式，服务器端用 Request.QueryString 获取变量的值，对于 post 方式，服务器端用 Request.Form 获取提交的数据。
(4)	get 传送的数据量较小，不能大于 2KB。post 传送的数据量较大，一般被默认为不受限制。但理论上，IIS4 中最大量为 80KB，IIS5 中为 100KB	

(5)、get 安全性低，post 安全性较高。
```



33.	HTML5 有哪些新增的表单元素？

参考答案：

> HTML5 新增了很多表单元素让开发者构建更优秀的 Web 应用程序，主要有： datalist
> keygen output

34.	HTML5 废弃了哪些 HTML4 标签？

参考答案：

```html
HTML5 废弃了一些过时的，不合理的 HTML 标签：
·	frame
·	frameset
·	noframe
·	applet
·	big
·	center
·	basefront
```




35.	HTML5 标准提供了哪些新的 API？

参考答案：

HTML5 提供的应用程序 API 主要有：

- ·	Media API
- ·	Text Track API
- ·	Application Cache API
- ·	User Interaction
- ·	Data Transfer API
- ·	Command API
- ·	Constraint Validation API
- ·	History API

36.	HTML5 存储类型有什么区别？

参考答案：

> HTML5 能够本地存储数据，在之前都是使用 cookies 使用的。HTML5 提供了下面两种本地存储方案：
>
> localStorage 用于持久化的本地存储，数据永远不会过期，关闭浏览器也不会丢失。
> sessionStorage 同一个会话中的页面才能访问并且当会话结束后数据也随之销毁。因此 sessionStorage 不是一种持久化的本地存储，仅仅是会话级别的存储

37.	HTML5 应用程序缓存和浏览器缓存有什么区别？

参考答案：

>
> 应用程序缓存是 HTML5 的重要特性之一，提供了离线使用的功能，让应用程序可以获取本地的网站内容，例如 HTML 、CSS 、图片以及 JavaScript。这个特性可以提高网站性能，它的实现借助于 manifest 文件，如下：
>
> ```html
> <!doctype html>
> <html manifest="example.appcache">
> …..
> </html>
> 与传统浏览器缓存相比，它不强制用户访问的网站内容被缓存。
> ```




 38.	HTML5 Canvas 元素有什么用？

参考答案：
Canvas 元素用于在网页上绘制图形，该元素标签强大之处在于可以直接在 HTML 上进行图形操作，

```html
<canvas id=“canvas1”	width=“300”	height=“100”>
</canvas>
```


39.	除了 audio 和 video，HTML5 还有哪些媒体标签？

参考答案：

```html
HTML5 对于多媒体提供了强有力的支持，除了 audio 和 video 标签外，还支持以下标签：

<embed>标签定义嵌入的内容，比如插件。
<embed type=“video/quicktime”	src=“Fishing.mov”>
<source>对于定义多个数据源很有用。
<video width=“450”	height=“340”	controls>
</video>

<source src="jamshed.mp4"	type="video/mp4">
<source src="jamshed.ogg"	type="video/ogg">

<track>标签为诸如 video 元素之类的媒介规定外部文本轨道。用于规定字幕文件或其他包含文本的文件，当媒介播放时，这些文件是可见的。

<video width=“450”	height=“340”	controls>
<source src=“jamshed.mp4”	type=“video/mp4”>
<source src=“jamshed.ogg”	type=	“video/ogg”>
<track kind=“subtitles”		label=“English”	src= “jamshed_en.vtt”	srclang=“en”	default></track>
<track kind=“subtitles”	label=“Arabic”	src= “jamshed_ar.vtt”	srclang=“ar”></track>
</video>

据源很有用。标签为诸如 video 元素之类的媒介规定外部文本轨道。 用于规定字幕文件或其他包含文本的文件，当媒介播放时，这些文件是可见的。
```



40.	HTML5 中如何嵌入视频？

参考答案：

和音频类似，HT

```html
ML5 支持 MP4、WebM 和 Ogg 格式的视频， 简单示例：

<video width=“450”	height=“340”	controls>
<source src=“jamshed.mp4”	type=“video/mp4”>
Your browser does’ nt support video embedding feature.
</video>
```



41.	HTML5 中如何嵌入音频？

参考答案：
HTML5 支持 MP3、Wav 和 Ogg 格式的音频，下面是在网页中嵌入音频的简单示例：
<audio controls>
<source src=“jamshed.mp3”	type=“audio/mpeg”>
Your browser does’	nt support audio embedding feature.
</audio>
```html
<audio controls>
<source src=“jamshed.mp3”	type=“audio/mpeg”>
Your browser does’	nt support audio embedding feature.
</audio>
```


42.	新的 HTML5 文档类型和字符集是？

参考答案：

HTML5 文档类型很简单：

```html
<!doctype html>
HTML5 使用 UTF-8 编码示例：
<meta charset=“UTF-8”>
```