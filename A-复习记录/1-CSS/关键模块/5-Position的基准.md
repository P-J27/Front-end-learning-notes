##### **absolute**

absolute定位的元素，是相对于它的**第一个position值不为static的祖先元素的padding box**来进行定位的。这句话我们可以这样来理解，我们首先需要找到绝对定位元素的一个position的值不为static的祖先元素，然后相对于这个祖先元素的padding box来定位，也就是说在计算定位距离的时候，**padding的值也要算进去。**

##### fixed（老IE不支持）

生成绝对定位的元素，相对于**浏览器窗口进行定位。**

##### relative

生成相对定位的元素，相对于其**元素本身所在正常位置进行定位**。

##### static

默认值。没有定位，元素出现在正常的流中（忽略top,bottom,left,right,z-index声明）。

##### inherit

规定从父元素继承position属性的值。