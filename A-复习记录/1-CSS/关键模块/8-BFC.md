块格式化上下文，它是一个独立的渲染区域，只有块级盒子参与，它规定了内部的块级盒子如何布局，并且与这个区域外部毫不相干。

![图来源于 yachen168](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/4a73e2276d8b41f0a905361f151157e2~tplv-k3u1fbpfcp-watermark.awebp)

#### **BFC 渲染规则**

- 内部的盒子会在垂直方向，一个接一个地放置；
- 盒子垂直方向的距离由 margin 决定，属于同一个 BFC 的两个相邻盒子的 margin 会发生重叠；
- 每个元素的 margin 的左边，与包含块 border 的左边相接触(对于从左往右的格式化，否则相反)，即使存在浮动也是如此；
- BFC 的区域不会与 float 盒子重叠；
- BFC 就是页面上的一个隔离的独立容器，容器里面的子元素不会影响到外面的元素。反之也如此。
- 计算 BFC 的高度时，浮动元素也参与计算。

#### **如何创建 BFC？**

- 根元素：html
- 非溢出的可见元素：overflow 不为 visible
- 设置浮动：float 属性不为 none
- 设置定位：position 为 absolute 或 fixed
- 定义成块级的非块级元素：display: inline-block/table-cell/table-caption/flex/inline-flex/grid/inline-grid

#### **BFC 应用场景**

##### 1、 自适应两栏布局

应用原理：BFC 的区域不会和浮动区域重叠，所以就可以把侧边栏固定宽度且左浮动，而对右侧内容触发 BFC，使得它的宽度自适应该行剩余宽度。

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/cc555b773b304ec2af61a8fcbb9bafcb~tplv-k3u1fbpfcp-watermark.awebp)

```html
<div class="layout">
    <div class="aside">aside</div>
    <div class="main">main</div>
</div>
.aside {
    float: left;
    width: 100px;
}
.main {
    <!-- 触发 BFC -->
    overflow: auto;
}
```

##### 2、清除内部浮动

浮动造成的问题就是父元素高度坍塌，所以清除浮动需要解决的问题就是让父元素的高度恢复正常。而用     BFC 清除浮动的原理就是：计算 BFC 的高度时，浮动元素也参与计算。只要触发父元素的 BFC 即可。

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/b1b790fa15ca4e3599aa53a8d1c2e973~tplv-k3u1fbpfcp-watermark.awebp)

```css
.parent {
    overflow: hidden;
}
```

##### 3、 防止垂直 margin 合并

BFC 渲染原理之一：同一个 BFC 下的垂直 margin 会发生合并。所以如果让 2 个元素不在同一个 BFC 中即可阻止垂直 margin 合并。那如何让 2 个相邻的兄弟元素不在同一个 BFC 中呢？可以给其中一个元素外面包裹一层，然后触发其包裹层的 BFC，这样一来 2 个元素就不会在同一个 BFC 中了。

![img](https://p3-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/7e533424631140d5b8bbb48266303709~tplv-k3u1fbpfcp-watermark.awebp)

```html
<div class="layout">
    <div class="a">a</div>
    <div class="contain-b">
        <div class="b">b</div>
    </div>
</div>

```

```css
.a,
.b {
    border: 1px solid #999;
    margin: 10px;
}
.contain-b {
    overflow: hidden;
}
```


