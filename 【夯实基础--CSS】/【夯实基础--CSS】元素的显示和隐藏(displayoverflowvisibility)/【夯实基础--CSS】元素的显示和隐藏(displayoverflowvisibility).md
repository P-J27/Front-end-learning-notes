### 元素的显示与隐藏

- **目的:**让一个元素在页面中消失或者显示出来
- **场景:**类似网站广告，当我们点击关闭就不见了，但是我们重新刷新页面，会重新出现！

#### 1.1 display 显示（重点）

display设置或检索对象是否显示或如何显示。

- display: none 隐藏对象
  - 特点：`隐藏之后，不再保留位置。`
- display: block 除了转换为块级元素之外，同时还有显示元素的意思。

![img](data:image/gif;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVQImWNgYGBgAAAABQABh6FO1AAAAABJRU5ErkJggg==)实际开发场景：配合后面js做特效，比如下拉菜单，原先没有，鼠标经过，显示下拉菜单， 应用极为广泛

#### 1.2 visibility 可见性

设置或检索是否显示对象

```css
visibility：visible ;  对象可视

visibility：hidden;    对象隐藏
```

- 特点：`隐藏之后，继续保留原有位置。`

#### 1.3 overflow 溢出

检索或设置当对象的内容超过其指定高度及宽度时如何管理内容。

| 属性值  | 描述                                       |
| :------ | :----------------------------------------- |
| visible | 不剪切内容也不添加滚动条                   |
| hidden  | 不显示超过对象尺寸的内容，超出的部分隐藏掉 |
| scroll  | 不管超出内容否，总是显示滚动条             |
| auto    | 超出自动显示滚动条，不超出不显示滚动条     |

![img](data:image/gif;base64,iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAADUlEQVQImWNgYGBgAAAABQABh6FO1AAAAABJRU5ErkJggg==)`实际开发场景`：

1. 清除浮动
2. 隐藏超出内容，隐藏掉,  不允许内容超过父盒子。

#### 1.4 显示与隐藏总结

| 属性       | 区别                   | 用途                                                         |
| :--------- | :--------------------- | :----------------------------------------------------------- |
| display    | 隐藏对象，不保留位置   | 配合后面js做特效，比如下拉菜单，原先没有，鼠标经过，显示下拉菜单， 应用极为广泛 |
| visibility | 隐藏对象，保留位置     | 使用较少                                                     |
| overflow   | 只是隐藏超出大小的部分 | 1. 可以清除浮动 2. 保证盒子里面的内容不会超出该盒子范围      |

