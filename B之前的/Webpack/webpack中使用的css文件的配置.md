#### 什么是loader？

![image-20210330001144507](webpack中使用的css文件的配置.assets/image-20210330001144507.png)

##### webpack关于loader的文档

https://webpack.docschina.org/loaders/#styling

![image-20210330002619168](webpack中使用的css文件的配置.assets/image-20210330002619168.png)

#### CSS文件处理

##### 准备工作

![image-20210330001505962](webpack中使用的css文件的配置.assets/image-20210330001505962.png)

##### 开始打包

![image-20210330002511498](webpack中使用的css文件的配置.assets/image-20210330002511498.png)



##### css-loader

**作用：**·`载 CSS 文件并解析 import 的 CSS 文件`，最终返回 CSS 代码

![image-20210330002950408](webpack中使用的css文件的配置.assets/image-20210330002950408.png)



```
npm install --save-dev css-loader
```



##### style-loader

**作用**：`将模块导出的内容作为样式并添加到 DOM 中`

![image-20210330003347419](webpack中使用的css文件的配置.assets/image-20210330003347419.png)

