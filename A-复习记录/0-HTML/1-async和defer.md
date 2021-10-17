#### 概念

先来试个一句话解释仨，当浏览器碰到 `script` 脚本的时候：

```js
<script src="script.js"></script>
//没有 defer 或 async，浏览器会立即加载并执行指定的脚本，“立即”指的是在渲染该 script 标签之下的文档元素之前，也就是说不等待后续载入的文档元素，读到就加载并执行。

<script async src="script.js"></script>
//有 async，加载和渲染后续文档元素的过程将和 script.js 的加载与执行并行进行（异步）。

<script defer src="myscript.js"></script>
//有 defer，加载后续文档元素的过程将和 script.js 的加载并行进行（异步），但是 script.js 的执行要在所有元素解析完成之后，DOMContentLoaded 事件触发之前完成。
```

#### 图解

![image-20211015153257468](https://gitee.com/p_pj/pig/raw/master/img/image-20211015153257468.png)

[原图地址](https://www.growingwiththeweb.com/2014/02/async-vs-defer-attributes.html)

