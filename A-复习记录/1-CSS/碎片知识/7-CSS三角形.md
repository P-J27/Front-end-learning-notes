原理：**相邻边框连接处的均分原理。**

步骤：

1.  将元素的宽高设为0，
2. 设置border的宽度，样式
3.  通过transparent隐藏其中三条边剩下的就是一个三角形。



```css
  #demo {
    width: 0;
    height: 0;
    border: 40px solid transparent;
    border-top: 40px solid red;
  }
```

![image-20211022171135304](https://gitee.com/p_pj/pig/raw/master/img/image-20211022171135304.png)