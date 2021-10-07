#### 前言

> 最开始接触flex布局，就是在接触居中布局时，看见 justify-content:center与align-items:center。
>
> 完全看不懂。于是就去学flex。我想除了我之外的大部分人，也都是在被flex垂直水平居中方式所惊艳后才对其有所了解，以至于在日常开发中对于flex的使用，也确实更偏向于元素对齐方式的使用。这里我就想做一个系列来好好的讲一讲flex布局。

-----

#### Flex布局是什么？

Flex 是 Flexible Box 的缩写，意为"`弹性布局`"，用来为盒状模型提供最大的灵活性。

任何一个容器都可以指定为 Flex 布局。

```css
.box{
  display: flex;
}
```

行内元素也可以使用 Flex 布局。

```css
.box{
  display: inline-flex;
}
```

Webkit 内核的浏览器，必须加上`-webkit`前缀。

```css
.box{
  display: -webkit-flex; /* Safari */
  display: flex;
}
```

注意，设为 Flex 布局以后，子元素的`float`、`clear`和`vertical-align`属性将失效。

---

#### 概念

当我们的元素被指定为Flex布局后，我们称作容器，它的所有子元素自动成为容器成员，称作项目。

![image-20210630225010706](https://gitee.com/p_pj/picgo/raw/master/img/20210630225010.png)

从图中，我们可以看见两条线main axis（水平的主轴） cross axis(垂直的交叉轴)

项目默认沿主轴排列。单个项目占据的主轴空间叫做`main size`，占据的交叉轴空间叫做`cross size`。

------------

#### 容器的属性

我们先讲讲容器的属性值，容器可以设置以下6个属性

- flex-direction
- flex-wrap
- flex-flow
- justify-content
- align-items
- align-content

 

-------



##### flex-direction

`flex-direction`属性决定`主轴的方向`（即项目的排列方向）。

```css
.box {
  flex-direction: row | row-reverse | column | column-reverse;
}
/*
- row（默认值）：主轴为水平方向，起点在左端。
- row-reverse：主轴为水平方向，起点在右端。
- column：主轴为垂直方向，起点在上沿。
- column-reverse：主轴为垂直方向，起点在下沿。
演示如下图
项目排列顺序为正序1-2-3；row-reverse同为横向排列，但项目顺序为倒序3-2-1。
column 与row相反，为纵向排列，项目顺序为正序1-2-3，column-reverse同为纵向排列，项目顺序为倒序3-2-1。
*/
```

![](https://gitee.com/p_pj/picgo/raw/master/img/20210630233020.png)

-------

##### flex-wrap

默认情况下，项目都排在一条线（又称"轴线"）上。`flex-wrap`属性定义，如果一条轴线排不下，`如何换行`。

```css
.box{
  flex-wrap: nowrap | wrap | wrap-reverse;
}

```

1. `nowrap`（默认）：不换行。

![](https://gitee.com/p_pj/picgo/raw/master/img/20210630233123.png)

2. `wrap`：换行，第一行在上方。

![](https://gitee.com/p_pj/picgo/raw/master/img/20210630233139.png)

3. `wrap-reverse`：换行，第一行在下方。需要注意的是`第一排会紧贴容器底部，而不是我们想象的项目6紧贴容器顶部`，效果与wrap相反。

![](https://gitee.com/p_pj/picgo/raw/master/img/20210630233148.png)

---------

##### flex-flow

`flex-flow`属性是`flex-direction`属性和`flex-wrap`属性的`简写`形式，默认值为`row nowrap`。

```css
.box {
  flex-flow: <flex-direction> || <flex-wrap>;
}
```

--------

##### justify-content

这就是我们最常见的属性之一了，`justify-content`属性定义了项目在主轴上的对齐方式。

```css
.box {
  justify-content: flex-start | flex-end | center | space-between | space-around;
}
/*
它可能取5个值，具体对齐方式与轴的方向有关。下面假设主轴为从左到右。
flex-start（默认值）：左对齐
flex-end：右对齐
center： 居中
space-between：两端对齐，项目之间的间隔都相等。
space-around：每个项目两侧的间隔相等。所以，项目之间的间隔比项目与边框的间隔大一倍。
如下图演示
*/
```

![image-20210630233320196](https://gitee.com/p_pj/picgo/raw/master/img/20210630233320.png)
space-around为`项目之间间距为左右两侧项目到容器间距的2倍`，比较特别的布局，日常使用不太多。

![image-20210630233418674](https://gitee.com/p_pj/picgo/raw/master/img/20210630233418.png)

space-evenly为项目之间间距与项目与容器间距相等，相当于除去项目宽度，平均分配了剩余宽度作为项目左右margin。

![image-20210630233427546](https://gitee.com/p_pj/picgo/raw/master/img/20210630233427.png)


-------------

##### align-items属性

同justify-content，`align-items`属性定义项目在交叉轴上如何对齐。

```css
.box {
  align-items: flex-start | flex-end | center | baseline | stretch;
}
/*它可能取5个值。同理，具体的对齐方式与交叉轴的方向有关，下面假设交叉轴从上到下。
flex-start：交叉轴的起点对齐。
flex-end：交叉轴的终点对齐。
center：交叉轴的中点对齐。
baseline: 项目的第一行文字的基线对齐。
stretch（默认值）：如果项目未设置高度或设为auto，将占满整个容器的高度。
*/
```

![](https://gitee.com/p_pj/picgo/raw/master/img/20210630233617.png)

-----------

##### align-content

`align-content`属性定义了多根轴线的对齐方式。如果项目只有一根轴线，该属性不起作用。

```css
.box {
  align-content: flex-start | flex-end | center | space-between | space-around | stretch;
}
/*
flex-start：与交叉轴的起点对齐。
flex-end：与交叉轴的终点对齐。
center：与交叉轴的中点对齐。
space-between：与交叉轴两端对齐，轴线之间的间隔平均分布。
space-around：每根轴线两侧的间隔都相等。所以，轴线之间的间隔比轴线与边框的间隔大一倍。
stretch（默认值）：轴线占满整个交叉轴。*/
```

![](https://gitee.com/p_pj/picgo/raw/master/img/20210630233752.png)



今天就先讲到这里，后续持续更新。。。