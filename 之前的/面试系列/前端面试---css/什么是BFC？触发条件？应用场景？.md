---
theme: cyanosis
highlight: androidstudio
---
--------------------

![image.png](https://gitee.com/p_pj/picgo/raw/master/img/20210617134337.png)
>这是我参与更文挑战的第17天，活动详情查看： [更文挑战](https://juejin.cn/post/6967194882926444557)

----------------



#### BFC是什么

> BFC(Block formatting context)直译为"块级格式化上下文"。它是一个独立的渲染区域，只有Block-level box参与， 它规定了内部的Block-level Box如何布局，并且与这个区域外部毫不相干。
>
> `BFC是一个独立的布局环境，其中的元素布局是不受外界的影响，并且在一个BFC中，块盒与行盒（行盒由一行中所有的内联元素所组成）都会垂直的沿着其父元素的边框排列。`

----------------



#### 触发条件

一个HTML元素要创建BFC，则满足下列的任意一个或多个条件即可： 下列方式会创建块格式化上下文：

- 根元素()
- `浮动`元素（元素的 float 不是 none）
- `绝对定位`元素（元素的 position 为 absolute 或 fixed）
- `行内块`元素（元素的 display 为 inline-block）
- 表格单元格（元素的 display为 table-cell，HTML表格单元格默认为该值）
- 表格标题（元素的 display 为 table-caption，HTML表格标题默认为该值）
- 匿名表格单元格元素（元素的 display为 table、table-row、 table-row-group、table-header-group、table-footer-group（分别是HTML table、row、tbody、thead、tfoot的默认属性）或 inline-table）
- `overflow 值不为 visible 的块元素` -弹性元素（display为 flex 或 inline-flex元素的直接子元素）
- 网格元素（display为 grid 或 inline-grid 元素的直接子元素） 等等。

-------------------------

#### BFC渲染规则

- BFC垂直方向边距重叠
- BFC的区域不会与浮动元素的box重叠
- BFC是一个独立的容器，外面的元素不会影响里面的元素
- 计算BFC高度的时候浮动元素也会参与计算

-------------

#### 应用

###### 防止浮动导致父元素高度塌陷（清除浮动）

```css
--css
<style>
      .container {
        border: 10px solid red;
      }
      .inner {
        background: #08BDEB;
        height: 100px;
        width: 100px;
      }
    </style>
--html
 <body>
    <div class="container">
      <div class="inner"></div>
    </div>
  </body>
```

![img](https://gitee.com/p_pj/picgo/raw/master/img/20210617133133.webp)

接下来将inner元素设为浮动:



```css
  .inner {
    float: left;
    background: #08BDEB;
    height: 100px;
    width: 100px;
  }
```

会产生这样的塌陷效果：



![img](https://gitee.com/p_pj/picgo/raw/master/img/20210617133205.webp)



但如果我们对父元素设置BFC后, 这样的问题就解决了

```css
.container {
    border: 10px solid red;
    overflow: hidden;
}
```

同时是`清除浮动`的一种方式。

###### 避免外边距折叠

两个块在同一个BFC内，会造成外边距折叠。

```css
 --css
 .container {
      background-color: green;
      overflow: hidden;
    }

    .inner {
      background-color: lightblue;
      margin: 10px 0;
    }
  </style>
  --html
  <body>
  <div class="container">
    <div class="inner">1</div>
    <div class="inner">2</div>
    <div class="inner">3</div>
  </div>
</body>
```

![img](https://gitee.com/p_pj/picgo/raw/master/img/20210617133419.webp)

此时三个元素的上下间隔都是10px, 因为三个元素同属于一个BFC。 现在我们做如下操作:

```css
  --html
<div class="container">
    <div class="inner">1</div>
    <div class="bfc">
      <div class="inner">2</div>
    </div>
    <div class="inner">3</div>
  </div>
--css
.bfc{
    overflow: hidden;
}
```



![img](https://gitee.com/p_pj/picgo/raw/master/img/20210617133613.webp)

可以看到和我们的想法已经一样了。没有出现重叠。




