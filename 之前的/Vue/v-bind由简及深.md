

#### 前言

> 本篇记录一下的v-bind指令，从简单使用到复杂应用。



#### 简述

> v-bind 主要用于动态地`属性绑定`，比方你的`class属性，style属性，value属性，href属性`等等，只要是属性，就可以用v-bind指令进行绑定.



#### 简单使用

```html
<div id="app">
    //错误写法
  <img src="{{imgURL}}" alt="">
    
    //正确写法
  <img v-bind:src="imgURL" alt="">
  <a v-bind:href="aHref">v-bind的基本使用</a>
<!--  语法糖，动态绑定简写-->
  <img :src="imgURL" alt="">
  <a :href="aHref">v-bind的基本使用</a>
</div>
<script>
  const app = new Vue({
    el:"#app",
    data:{
      message:"Hello Ting,I am Key!",
      imgURL:"https:www.baidu.com",
      aHref:"https://blog.csdn.net/weixin_43745075?spm=1001.2101.3001.5343"
    }
  })
</script>

```

#### 绑定class

##### 1.绑定方式：对象语法

- 对象语法的含义是：class后面跟的是一个对象

##### 2.用法：

```html
1.直接通过{ }绑定一个类，isActive是一个boolean值
<h2 :class="{'active':isActive}">Hello Ting, I am Key!</h2>

2.通过判断，传入多个值
<h2 :class="{'active':isActive,'family':isFamily}">Hello Ting, I am Key!</h2>

3.和普通的类同时存在，并不冲突
注：如果isActive和isFamily都为true，那么会有size/active/family三个类
<h2 class="size" :class="{'active':isActive,'family':isFamily}">Hello Ting, I am Key!</h2>

4.如果过于复杂，可以放在一个methods或者computed中. 
注意：classes是一个计算属性或者一个function
<h2 class="size" :class="classes">Hello Ting, I am Key!</h2>

```

#### 绑定style

##### 1.绑定方式：对象语法

- 对象语法的含义是：style后面跟的是一个对象

##### 2.用法：

```html

<div id="app">
<!--  <h2 v-bind:style="{key(属性名):value(属性值)}">{{message}}</h2>-->
<!--  <h2 :style="{fontSize:'50px'}">{{message}}</h2>-->
<!--  <h2 :style="{fontSize:finalSize+'px',color:finalColor,background:finalBackgroundColor}">{{message}}</h2>-->
  <h2 :style="getStyles()">{{message}}</h2>
</div>
<script>
  const app = new Vue({
    el:"#app",
    data:{
      message:"Hello Ting,I am Key!",
      finalSize:100,
      finalColor:"red",
      finalBackgroundColor:"pink"
    },
    methods:{
      getStyles(){
        return {fontSize:this.finalSize+'px',color:this.finalColor,background:this.finalBackgroundColor}
      }
    }
  })
</script>

```

#### **对于对象语法注意事项**

- 属性名一般采用驼峰命名法，属性值可以来源于data项，也可以是自己设置的固定值，
- 不建议直接在DOM中写对象，因为不容易维护，可以将样式对象写在data项中或者是计算属性中

#### 小应用案例

需求：点击列表中的哪一项，那么该项的文字就变成红色

预期效果





源码

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<style>
    .red {
        color: red;
    }
</style>

<body>
    <div id="app">
        <ul>
            <li v-for="(item,index) in da" :class="{'red': index===currentIndex}" v-on:click="change(index)">
                {{item}}
            </li>
        </ul>
    </div>
    <script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
                da: ['大哥', '二哥', '三哥'],
                currentIndex:0
            },
            methods: {
                change(i) {
                   this.currentIndex=i;
                }
            }
        })
    </script>

</body>

</html>
```

