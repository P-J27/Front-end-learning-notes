ES6-ES11学习笔记

# 一、概述

## 1 、什么是 ECMA

> ECMA（European Computer Manufacturers Association）中文名称为欧洲计算机制造商协会，这个
> 组织的目标是评估、开发和认可电信和计算机标准。 1994 年后该组织改名为 Ecma 国际；

## 2 、什么是 ECMAScript

> ECMAScript 是由 Ecma 国际通过 ECMA-262 标准化的脚本程序设计语言；
>
> 百度百科：https://baike.baidu.com/history/ECMAScript/1889420/

## 3 、什么是 ECMA-

> Ecma 国际制定了许多标准，而 ECMA-262 只是其中的一个，所有标准列表查看：
>
> [http://www.ecma-international.org/publications/standards/Standard.htm](http://www.ecma-international.org/publications/standards/Standard.htm)

## 4 、ECMA-262 历史

> ECMA-262（ECMAScript）历史版本查看网址：
>
> [http://www.ecma-international.org/publications/standards/Ecma-262-arch.htm](http://www.ecma-international.org/publications/standards/Ecma-262-arch.htm)
>
> ##### 注：从 ES6 开始，每年发布一个版本，版本号比年份最后一位大 1 ；

## 5 、谁在维护 ECMA-

> TC39（Technical Committee 39）是推进 ECMAScript 发展的委员会。其会员都是公司（其中主要是浏
> 览器厂商，有苹果、谷歌、微软、因特尔等）。TC39 定期召开会议，会议由会员公司的代表与特邀专家
> 出席；

## 6 、为什么要学习 ES

> ##### ES6 的版本变动内容最多，具有里程碑意义；
>
> ##### ES6 加入许多新的语法特性，编程实现更简单、高效；
>
> ##### ES6 是前端发展趋势，就业必备技能；

## 7 、ES6 兼容性


查看网址：http://kangax.github.io/compat-table/es

# 二、ES6 新特性



## 1 、let 关键字

### 特性

let 关键字用来声明变量，使用 let 声明的变量有几个特点：

1. `不允许重复声明`；
2. `块儿级作用域（局部变量）`；
3. `不存在变量提升`；
4. `不影响作用域链`；

### let创建变量代码示例：
```js
// let关键字使用示例：
let a; // 单个声明
let b,c,d; // 批量声明
let e = 100 ; // 单个声明并赋值
let f = 521 , g = 'iloveyou', h = []; // 批量声明并赋值
```
### 不允许重复声明：

```js
let dog = "狗";
let dog = "狗";
// 报错：Uncaught SyntaxError: Identifier 'dog' has already been
declared
```

### 块儿级作用域（局部变量）

```js
let cat = "猫";
console.log(cat);
}
console.log(cat);
// 报错：Uncaught ReferenceError: cat is not defined
```



### 不存在变量提升：



```js
// 什么是变量提升：就是在变量创建之前使用（比如输出：输出的是默认值），let不存在，var存在；

console.log(people1); // 可输出默认值
console.log(people2); // 报错：Uncaught ReferenceError: people2 is not defined
var people1 = "大哥"; // 存在变量提升
let people2 = "二哥"; // 不存在变量提升
```



### 不影响作用域链：



```js
 

// 什么是作用域链：很简单，就是代码块内有代码块，跟常规编程语言一样，上级代码块中的局部变量下级可用

		{
            let p = "大哥";
			var s;               //p的作用域是块(花括号内)级的，而s的作用域为全局
            function fn() {
                console.log(p); // 这里是可以使用的
            }
            fn();
        }
```


### 应用场景

`以后声明变量使用 let 就对了`；

### let案例：点击div更改颜色



```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>let案例：点击div更改颜色</title>
    <link crossorigin="anonymous" href="https://cdn.bootcss.com/twitterbootstrap/3.3.7/css/bootstrap.min.css"
        rel="stylesheet">
    <style>
        .item {
            width: 100px;
            height: 50px;
            border: solid 1px rgb(42, 156, 156);
            float: left;
            margin-right: 10px;
        }
    </style>
</head>

<body>
    <div class="container">
        <h2 class="page-header">let案例：点击div更改颜色</h2>
        <div class="item"></div>
        <div class="item"></div>
        <div class="item"></div>
    </div>
    <script>
        // 获取div元素对象
        let items = document.getElementsByClassName('item');
        // 遍历并绑定事件
        for (let i = 0; i < items.length; i++) {
            items[i].onclick = function () {
                // 修改当前元素的背景颜色
                // this.style.background = 'pink'; // 写法一：常规写法一般无异常
                items[i].style.background = 'pink'; // 写法二
                // 写法二：需要注意的是for循环内的i必须使用let声明 //点击事件是异步的
                // 如果使用var就会报错，因为var是全局变量，
                // 经过循环之后i的值会变成3，items[i]就会下标越界
                // let是局部变量
                // 我们要明白的是当我们点击的时候，这个i是哪个值
                // 使用var相当于是：
                // { var i = 0; }
                // {  i = 1; }
                // {  i = 2; }
                // {  i = 3; }
                // 下面的声明会将上面的覆盖掉，所以点击事件每次找到的都是3
                // 而使用let相当于是：
                // { let i = 0; }
                // { let i = 1; }
                // { let i = 2; }
                // { let i = 3; }
                // 由于let声明的是局部变量，每一个保持着原来的值
                // 点击事件调用的时候拿到的是对应的i
            }
        }
    </script>
</body>

</html>
```


## 2 、const 关键字

### 特性：

const 关键字用来声明 **常量** ，const 声明有以下特点：

1. `声明必须赋初始值`·；
2. `标识符一般为大写（习惯`）；
3. `不允许重复声明`；
4. `值不允许修改`；
5. `块儿级作用域（局部变量）`；

### const创建变量代码示例：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>const</title>
</head>

<body>
    <script>
        // const声明常量
        const DOG = "旺财";
        console.log(DOG);
        // 1. 声明必须赋初始值；
        // const CAT;
        // 报错：Uncaught SyntaxError: Missing initializer in const  declaration
        
        // 2. 标识符一般为大写（习惯）；
        // const dog = "旺财"; // 小写也不错
        
        // 3. 不允许重复声明；
        // const CAT = "喵喵";
        // const CAT = "喵喵";
        // 报错：Uncaught SyntaxError: Identifier 'CAT' has already been declared
        
       //  注意：对数组元素的修改和对对象内部的修改是可以的（数组和对象存的是引用地址）；
        // 4. 值不允许修改；
        // const CAT = "喵喵";
        // CAT = "咪咪";
        // 特例：const arr = ['55','66'];
        // arr.push('77');  //arr的中已经接上了‘77’ 这是因为arr指向的地址并没有发生改变
        // 报错：Uncaught TypeError: Assignment to constant variable.
        
        // 5. 块儿级作用域（局部变量）；
        // {
        // const CAT = "喵喵";
        // console.log(CAT);
        // }
        // console.log(CAT);
        // 报错：Uncaught ReferenceError: CAT is not defined
    </script>
</body>

</html>
```


### 应用场景：

`声明对象类型使用 const，非对象类型声明选择 let；`

## 3 、变量和对象的解构赋值

### 什么是解构赋值

##### ES6 允许按照一定模式，从`数组和对象中提取值`，`对变量进行赋值`，这被称为 `解构赋值` ；

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>解构赋值</title>
</head>

<body>
    <script>
        // ES6 允许按照一定模式，从数组和对象中提取值，对变量进行赋值，这被称为解构赋值；
        // 1、数组的解构赋值
        const F4 = ["大哥", "二哥", "三哥", "四哥"];
        let [a, b, c, d] = F4;
        // 这就相当于我们声明4个变量a,b,c,d，其值分别对应"大哥","二哥","三哥","四哥"
        console.log(a + b + c + d); // 大哥二哥三哥四哥
        // 2、对象的解构赋值
        const F3 = {
            name: "大哥",
            age: 22,
            sex: "男",
            xiaopin: function () { // 常用
                console.log("我会演小品！");
            }
        }
        let {
            name,
            age,
            sex,
            xiaopin
        } = F3; // 注意解构对象这里用的是{} 
        console.log(name + age + sex + xiaopin); // 大哥22男
        xiaopin(); // 此方法可以正常调用
        //好像只是一个指向
        console.log(name===F3.name);//true
        console.log(xiaopin===F3.xiaopin);//true  
    </script>
</body>

</html>
```

### 应用场景：

##### `频繁使用对象方法、数组元素，就可以使用解构赋值形式`；



## 4 、模板字符串

### 概述：

模板字符串（template string）是增强版的字符串，用**反引号（`）标识**，特点：

1. 字符串中可以出现换行符；
2. 可以使用 ${xxx} 形式引用变量

### 代码演示及相关说明：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title></title>
</head>

<body>
    <script>
        // 声明字符串的方法：单引号（''）、双引号（""）、反引号（``）
        // 声明
        let string = `我也一个字符串哦！`;
        console.log(string);
        // 特性
        // 1、字符串中可以出现换行符
        let str =
            `<ul>
<li>大哥</li>
<li>二哥</li>
<li>三哥</li>
<li>四哥</li>
</ul>`;
        console.log(str);
        // 2、可以使用 ${xxx} 形式引用变量
        let s = "大哥";
        let out = `${s}是我最大的榜样！`;

        console.log(out);
    </script>
</body>

</html>
```


### 应用场景：

##### `当遇到字符串与变量拼接的情况使用模板字符串`；



## 5 、简化对象和函数写法

### 概述：

`ES6 允许在大括号里面，直接写入变量和函数，作为对象的属性和方法。这样的书写更加简洁`；

### 代码示例及相关说明：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>简化对象写法</title>
</head>

<body>
    <script>
        // ES6允许在对象的大括号内直接写入变量和函数作为对象的属性和方法
        // 变量和函数
        let name = "訾博";
        let change = function () {
            console.log("活着就是为了改变世界！");
        }
        //创建对象
        const school = {
            // 完整写法
            // name:name,
            // change:change
            // 简化写法
            name,
            change,
            // 声明方法的简化
            say() {
                console.log("言行一致！");
            }
        }
        school.change();
        school.say();
    </script>
</body>

</html>
```


## 6 、箭头函数

### 概述：

ES6允许使用`箭头（=>）定义函`数，箭头函数提供了一种更加简洁的函数书写方式，箭头函数`多用于匿名函数的定义`；

### 箭头函数的注意点：

1. 如果形参只有一个，则小括号可以省略；

2. 函数体如果只有一条语句，则花括号可以省略，并省略return，函数的返回值为该条语句的执行结果；

3. 箭头函数 this 指向声明时所在作用域下 this 的值；
4. 箭头函数不能作为构造函数实例化；
5. 不能使用 arguments；

### 特性：

> 1. 箭头函数的this`是静态的`，`始终指向函数声明时所在作用域下的this`的值；
> 2. 不能作为构造实例化对象；
> 3. 不能使用 arguments 变量；

### 代码演示及相关说明：

注意：箭头函数不会更改 this 指向，用来`指定回调函数`会非常合适；

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>箭头函数</title>
</head>

<body>
    <script>
        // ES6允许使用箭头（=>）定义函数
        // 传统写法：无参数
        var say = function () {
            console.log("hello！");
        }
        say();

        // ES写法2：无参数
        let speak = () => console.log("hello 哈哈！");
        speak();

        // 传统写法：一个参数
        var hello = function (name) {
            return "hello " + name;
        }
        console.log(hello("pj"));

        // ES6箭头函数：一个参数
        let hi = name => "hi " + name;
        console.log(hi("pj"));

        // 传统写法：多个参数
        var sum = function (a, b, c) {
            return a + b + c;
        }
        console.log(sum(1, 2, 3));
        // ES6箭头函数：多个参数
        let he = (a, b, c) => a + b + c;
        console.log(he(1, 2, 3));
        
        // 特性
        // 1、箭头函数的this是静态的，始终指向函数声明时所在作用域下的this的值
        const school = {
            name: "大哥",
        }
        // 传统函数
        function getName() {
            console.log("getName：" + this.name);
        }
        // 箭头函数
        getName1 = () => console.log("getName1：" + this.name);
        window.name = "訾博";
        // 直接调用
        getName();
        getName1();
        // 使用call调用
        getName.call(school);
        getName1.call(school);
        // 结论：箭头函数的this是静态的，始终指向函数声明时所在作用域下的this的值

        // 2、不能作为构造实例化对象
        let Persion = (name,age) => {
        this.name = name;
        this.age = age;
        }
        let me = new Persion("pj",24);
        console.log(me);
        // 报错：Uncaught TypeError: Persion is not a constructor


        // 3、不能使用 arguments 变量
        let fn = () => console.log(arguments);
        fn(1,2,3);
        // 报错：Uncaught ReferenceError: arguments is not defined
    </script>
</body>

</html>
```



### 需求-1：点击 div 2s 后颜色变成『粉色』：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>箭头函数的实践和应用场景</title>
    <style>
        div {
            width: 200px;
            height: 200px;
            background: #58a;
        }
    </style>
</head>

<body>
    <div id="ad"></div>
    <script>
        // 需求-1 点击 div 2s 后颜色变成『粉色』
        // 获取元素
        let ad = document.getElementById('ad');

        // 绑定事件
        ad.addEventListener("click", function () {

            // 传统写法
            // 定时器：参数1：回调函数；参数2：时间；
            setTimeout(function () {
                console.log(this);
                this.style.background = 'pink';
            }, 2000);
            // 报错Cannot set property 'background' of undefined

            // 传统解决
            // 保存 this 的值
            let _this = this;
            // 定时器：参数1：回调函数；参数2：时间；
            setTimeout(function () {
                console.log(this);
                _this.style.background = 'pink';
            }, 2000);
        });
		
        //ES6写法
        let ad = document.getElementById('ad');
        // 绑定事件：这也是错误写法，这里的this还是window
        // ad.addEventListener("click", () => {
        // // ES6写法
        // // 定时器：参数1：回调函数；参数2：时间；
        // setTimeout(() => this.style.background = 'pink',2000);
        // }
        // )
        // 绑定事件
        ad.addEventListener("click", function () {
            // ES6写法
            // 定时器：参数1：回调函数；参数2：时间；
            // 这个this才是ad
            setTimeout(() => this.style.background = 'pink', 2000);
        })
    </script>
</body>

</html>
```



### 需求-2 从数组中返回偶数的元素：



```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>箭头函数的实践和应用场景</title>
    <style>
        div {
            width: 200px;
            height: 200px;
            background: #58a;
        }
    </style>
</head>

<body>
    <div id="ad"></div>
    <script>
        // 需求-1 点击 div 2s 后颜色变成『粉色』
        // 获取元素
        let ad = document.getElementById('ad');
        // 绑定事件：这也是错误写法，这里的this还是window
        // ad.addEventListener("click", () => {
        // // ES6写法
        // // 定时器：参数1：回调函数；参数2：时间；
        // setTimeout(() => this.style.background = 'pink',2000);
        // }
        // )
        // 绑定事件
        ad.addEventListener("click", function () {
            // ES6写法
            // 定时器：参数1：回调函数；参数2：时间；
            // 这个this才是ad
            setTimeout(() => this.style.background = 'pink', 2000);
        })
        //需求-2 从数组中返回偶数的元素
        const arr = [1, 6, 9, 10, 100, 25];
        // const result = arr.filter(function(item){
        // if(item % 2 === 0){
        // return true;
        // }else{
        // return false;
        // }
        // });
        const result = arr.filter(item => item % 2 === 0);
        console.log(result);
        // 箭头函数适合与 this 无关的回调. 定时器, 数组的方法回调
        // 箭头函数不适合与 this 有关的回调. 事件回调, 对象的方法
    </script>
</body>

</html>
```

### 场景

1.  箭头函数适合与 `this 无关的回调. 定时器, 数组的方法回调`
2.  箭头函数不适合与 this 有关的回调. `事件回调, 对象的方法`



## 7 、ES6中函数参数的默认值

### 概述

> ##### `ES允许给函数的参数赋初始值；`

### 代码示例及相关说明：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    8、rest参数
    概述：
    ES6 引入 rest 参数，用于获取函数的实参，用来代替 arguments；
    参考文章：https://www.jianshu.com/p/50bcb376a419
    代码示例及相关说明：
    <title>函数参数默认值</title>
</head>

<body>
    <script>
        //ES6 允许给函数参数赋值初始值
        //1. 形参初始值 具有默认值的参数, 一般位置要靠后(潜规则)
        function add(a, b, c = 10) {
            return a + b + c;
        }
        let result = add(1, 2);
        console.log(result); // 13
        //2. 与解构赋值结合
        // 注意这里参数是一个对象
        function connect({//参数
            host = "127.0.0.1",
            username,
            password,
            port
        }) {//函数体
            console.log(host)
            console.log(username)
            console.log(password)
            console.log(port)
        }
        connect({
            host: 'atguigu.com',
            username: 'root',
            password: 'root',
            port: 3306
        })
    </script>
    </bod
```


## 8 、rest参数

### 概述

`ES6 引入 rest 参数，用于获取函数的实参，用来代替 arguments`；

参考文章：https://www.jianshu.com/p/50bcb376a419

### 代码示例及相关说明：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>rest参数</title>
</head>

<body>
    <script>
        // ES6 引入 rest 参数，用于获取函数的实参，用来代替 arguments；
        // ES5获取实参的方式
        function data() {
            console.log(arguments);
        }

        data("大哥", "二哥", "三哥", "四哥");
        // ES6的rest参数...args，rest参数必须放在最后面
        function data(...args) {
           // args是一个数组
            console.log(args); // fliter some every map
        }
        data("大哥", "二哥", "三哥", "四哥");
    </script>
</body>

</html>
```


## 9 、扩展运算符

### 介绍：

##### `... 扩展运算符`

能将数组转换为逗号分隔的参数序列；

扩展运算符（spread）也是三个点（...）。它好比` rest 参数的逆运算`，将一个`数组转`为用`逗号分隔的参数序列`，对数组进行`解包`；



```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>扩展运算符</title>
</head>

<body>
    <script>
        // ... 扩展运算符能将数组转换为逗号分隔的参数序列
        //声明一个数组 ...
        const tfboys = ['易烊千玺', '王源', '王俊凯'];
        // => '易烊千玺','王源','王俊凯'
        // 声明一个函数
        function chunwan() {
            console.log(arguments);
        }
        chunwan(...tfboys); // chunwan('易烊千玺','王源','王俊凯')
    </script>
</body>

</html
```


### 应用

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>扩展运算符应用</title>
</head>

<body>
    <div id="d1"></div>
    <div id="d2"></div>
    <script>
        //1. 数组的合并 
        const kuaizi = ['王太利', '肖央'];
        const fenghuang = ['曾毅', '玲花'];
        // 传统的合并方式
        // const zuixuanxiaopingguo = kuaizi.concat(fenghuang);
        const zuixuanxiaopingguo = [...kuaizi, ...fenghuang];
        console.log(zuixuanxiaopingguo);

        //2. 数组的克隆
        const sanzhihua = ['E', 'G', 'M'];
        const sanyecao = [...sanzhihua]; // ['E','G','M']
        console.log(sanyecao);
        
        //3. 将伪数组转为真正的数组
        const divs = document.querySelectorAll('div');
        const divArr = [...divs];
        console.log(divArr); // arguments
    </script>
</body>

</html>
```



## 10 、Symbol

### 概述

ES6 引入了一种新的原始数据类型 `Symbol`，表示独一无二的值。它是JavaScript 语言的`·第七种数据类型`·，是一种`类似于字符串的数据类型`；

参考文章：https://blog.csdn.net/fesfsefgs/article/details/108354248

### 特点

1. Symbol 的值是`唯一的`，用来解决`命名冲突`的问题；
2. Symbol 值`不能与其他数据进行运算`；
3. Symbol 定义的对象属性不能使用for...in循环遍历 ，但是可以使用Reflect.ownKeys 来获取对象的所有键名；

### 基本使用：

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>symbol</title>
</head>

<body>
    <script>
        //创建Symbol
        let s = Symbol();
        // console.log(s, typeof s);
        let s2 = Symbol('尚硅谷');
        let s3 = Symbol('尚硅谷');
        console.log(s2 == s3); // false
        //Symbol.for 创建
        let s4 = Symbol.for('尚硅谷');
        let s5 = Symbol.for('尚硅谷');
        console.log(s4 == s5); // true
        //不能与其他数据进行运算
        // let result = s + 100;
        // let result = s > 100;
        // let result = s + s;
        
        //七种数据类型
        // USONB you are so niubility
        
        // u undefined
        // s string symbol
        // o object
        // n null number
        // b boolean
    </script>
</body>

</html>
```

### Symbol创建对象属性
```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Symbol创建对象属性</title>
</head>

<body>
    <script>
        // 向对象中添加方法 up down
        let game = {
            name: '俄罗斯方块',
            up: function () {},
            down: function () {}
        };
        // 我们要往game对象里面添加方法，但是怕game对象已经存在同名方法，所以我们这时使用到了Symbol
        // 方式一
        // 声明一个对象
        let methods = {
            up: Symbol(),
            down: Symbol()
        };
        game[methods.up] = function () {
            console.log("我可以改变形状");
        }
        game[methods.down] = function () {
            console.log("我可以快速下降!!");
        }
        console.log(game);
        //调用方法
        game[methods.up]();

        // 方式二
        let youxi = {
            name: "狼人杀",
            [Symbol('say')]: function () {
                console.log("我可以发言")
            },
            [Symbol('zibao')]: function () {
                console.log('我可以自爆');
            }
        }
        console.log(youxi);

        let say = Symbol('say'); //'say'类似一个注解作用，没有实际意义
        let youxi1 = {
            name: "狼人杀",
            [say]: function () {
                console.log("我可以发言")
            },
            [Symbol('zibao')]: function () {
                console.log('我可以自爆');
            }
        }
        // 调用
        youxi1[say]();
    </script>
</body>

</html>
```



### Symbol内置值：

#### 概述：

除了定义自己使用的 Symbol 值以外，ES6 还提供了 11 个内置的 Symbol 值，指向语言内部使用的方
法。可以称这些方法为魔术方法，因为它们会在特定的场景下自动执行；

#### 方法：

```
Symbol.isConcatSpreadable 对象的 Symbol.isConcatSpreadable 属性等于的是一个布尔值，表示该对象用于
Array.prototype.concat()时，是否可以展开。
Symbol.species 创建衍生对象时，会使用该属性
Symbol.match 当执行 str.match(myObject) 时，如果该属性存在，会调用它，返回该方法的返回值。
Symbol.replace 当该对象被 str.replace(myObject)方法调用时，会返回该方法的返回值。
Symbol.search 当该对象被 str. search (myObject)方法调用时，会返回该方法的返回值。
Symbol.split 当该对象被 str. split (myObject)方法调用时，会返回该方法的返回值。
Symbol.iterator 对象进行 for...of 循环时，会调用 Symbol.iterator 方法，返回该对象的默认遍历器
Symbol.toPrimitive 该对象被转为原始类型的值时，会调用这个方法，返回该对象对应的原始类型值。
Symbol. toStringTag 在该对象上面调用 toString 方法时，返回该方法的返回值
Symbol. unscopables 该对象指定了使用 with 关键字时，哪些属性会被 with环境排除。
```

**`特别的：`** Symbol内置值的使用， **`都是作为某个对象类型的属性去使用`** ；

#### 演示：

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Symbol内置属性</title>
</head>

<body>
    <script>
        class Person {
            static[Symbol.hasInstance](param) {
                console.log(param);  ///可以自定义类型检测
                console.log("我被用来检测类型了");
                return false;
            }
        }

        let o = {};
        console.log(o instanceof Person);


        const arr = [1, 2, 3];
        const arr2 = [4, 5, 6];
        // 合并数组：false数组不可展开，true可展开
        arr2[Symbol.isConcatSpreadable] = false;
        console.log(arr.concat(arr2));
    </script>
</body>

</html>
```


## 11 、迭代器

### 概述

遍历器（Iterator）就是一种机制。它是一种接口，为各种不同的数据结构提供统一的访问机制。任何数据结构`只要部署 Iterator 接口`，就可以完成遍历操作；

### 特性

ES6 创造了一种新的遍历命令 for...of 循环，`Iterator 接口主要供 for...of 消费`；

原生具备 iterator 接口的数据(可用 for of 遍历)：

1. Array；
2. Arguments；
3. Set；
4. Map；
5. String；
6. TypedArray；
7. NodeList；

### 工作原理

1. `创建一个指针对象，指向当前数据结构的起始位置`；

2. `第一次调用对象的 next 方法，指针自动指向数据结构的第一个成员`；
3. `接下来不断调用 next 方法，指针一直往后移动，直到指向最后一个成员`；
4. `每调用 next 方法返回一个包含 value 和 done 属性的对象`；

**注：需要自定义遍历数据的时候，要想到迭代器；**


### 代码示例及相关说明：

### 运行结果：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>迭代器</title>
</head>

<body>
    <script>
        // 声明一个数组
        const xiyou = ['唐僧', '孙悟空', '猪八戒', '沙僧'];
        // 使用 for...of 遍历数组
        for (let v of xiyou) {
            console.log(v); //v是值  
        }

        let iterator = xiyou[Symbol.iterator]();
        // 调用对象的next方法
        console.log(iterator.next());
        console.log(iterator.next());
        console.log(iterator.next());
        console.log(iterator.next());
        console.log(iterator.next());

        // 重新初始化对象，指针也会重新回到最前面
        let iterator1 = xiyou[Symbol.iterator]();
        console.log(iterator1.next());
    </script>
</body>

</html>
```


### 迭代器自定义遍历对象：

#### 代码实现：

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>迭代器自定义遍历数据</title>
</head>

<body>
    <script>
        // 声明一个对象
        const banji = {
            name: "终极一班",
            stus: [
                'xiaoming',
                'xiaoning',
                'xiaotian',
                'knight'
            ],
            
            /*
            迭代器工作原理
            1. 创建一个指针对象，指向当前数据结构的起始位置；
			2. 第一次调用对象的 next 方法，指针自动指向数据结构的第一个成员；
			3. 接下来不断调用 next 方法，指针一直往后移动，直到指向最后一个成员；
			4. 每调用 next 方法返回一个包含 value 和 done 属性的对象；
            */
            [Symbol.iterator]() {
                // 索引变量
                let index = 0;
                // 保存this
                let _this = this;
                return {
                    next: function () {
                        if (index < _this.stus.length) {
                            const result = {
                                value: _this.stus[index],
                                done: false //false是还没有遍历完
                            };
                            // 下标自增
                            index++;
                            // 返回结果
                            return result;
                        } else {
                            return {
                                value: undefined,
                                done: true
                            };
                        }
                    }
                };
            }
        }
        // 遍历这个对象
        for (let v of banji) {
            console.log(v);
        }
    </script>
</body>

</html>
```



## 12 、生成器

### 概述

**`生成器函数是 ES6 提供的一种异步编程解决方案，语法行为与传统函数完全不同`；**

### 基本使用

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>生成器</title>
</head>

<body>
    <script>
        // 生成器其实就是一个特殊的函数
        // 异步编程 纯回调函数 node fs ajax mongodb
        // yield：函数代码的分隔符
        function* gen() {

            console.log(111);

            yield '一只没有耳朵';

            console.log(222);

            yield '一只没有尾部';

            console.log(333);

            yield '真奇怪';
            
            console.log(444);
        }
        let iterator = gen();
        console.log(iterator.next());
        console.log(iterator.next());
        console.log(iterator.next());
        console.log(iterator.next());
        console.log("遍历：");
        //遍历
        for (let v of gen()) {
            console.log(v);
        }
    </script>
</body>

</html>
```
### 生成器函数的参数传递

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>生成器函数的参数传递</title>
</head>

<body>
    <script>
        function* gen(arg) {
            console.log(arg);
            let one = yield 111;
            console.log(one);
            let two = yield 222;
            console.log(two);
            let three = yield 333;
            console.log(three);
        }

        let iterator = gen("AAA");
        console.log(iterator.next()); // 会执行到yield 111;

        // next()方法是可以传入参数的，传入的参数作为第一条(上一条)语句yield 111的返回结果
        console.log(iterator.next("BBB")); // 会执行yield 222;
        console.log(iterator.next("CCC")); // 会执行yield 333;
        console.log(iterator.next("DDD")); // 继续往后走，未定义;
    </script>
</body>

</html>
```

### 生成器函数实例 1 

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>生成器函数实例1</title>
</head>

<body>
    <script>
        // 异步编程 文件操作 网络操作（ajax，request） 数据库操作
        // 需求：1s后控制台输出111 再过2s后控制台输出222 再过3s后控制台输出333

        // 一种做法：回调地狱
        // setTimeout(() => {
        //     console.log(111);
        //     setTimeout(() => {
        //         console.log(222);
        //         setTimeout(() => {
        //             console.log(333);
        //         }, 3000)
        //     }, 2000)
        // }, 1000)
        
        // 生成器做法
        function one() {
            setTimeout(() => {
                console.log(111);
                iterator.next();
            }, 1000)
        }

        function two() {
            setTimeout(() => {
                console.log(222);
                iterator.next();
            }, 1000)
        }

        function three() {
            setTimeout(() => {
                console.log(333);
                iterator.next();
            }, 1000)
        }

        function* gen() {
            yield one();
            yield two();
            yield three();
        }
        // 调用生成器函数
        let iterator = gen();
        iterator.next();
    </script>
</body>

</html>
```


### 生成器函数实例 2

```html

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>生成器函数实例2</title>
</head>

<body>
    <script>
        // 模拟获取: 用户数据 订单数据 商品数据
        function getUsers() {
            setTimeout(() => {
                let data = "用户数据";
                // 第二次调用next，传入参数，作为第一个的返回值
                iterator.next(data); // 这里将data传入
            }, 1000);
        }
        
        function getOrders() {
            setTimeout(() => {
                let data = "订单数据";
                iterator.next(data); // 这里将data传入
            }, 1000);
        }

        function getGoods() {
            setTimeout(() => {
                let data = "商品数据";
                iterator.next(data); // 这里将data传入
            }, 1000);
        }

        function* gen() {
            let users = yield getUsers();
            console.log(users);
            let orders = yield getOrders();
            console.log(orders);
            let goods = yield getGoods();
            console.log(goods); // 这种操作有点秀啊！
        }
        let iterator = gen();
        iterator.next();
    </script>
</body>

</html>
```


## 13 、Promise



### 概述

Promise 是 ES6 引入的 **·`异步编程的新解决方案`** 。语法上 Promise 是一个 **`构造函数`** ，用来`封装异步操作`并可以获取其成功或失败的结果；

1. Promise 构造函数: Promise (excutor) {}；
2. Promise.prototype.then 方法；
3. Promise.prototype.catch 方法；

### 基本使用

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Promise</title>
</head>

<body>
    <script>
        // 实例化 Promise 对象
        // Promise 对象三种状态：初始化、成功、失败
        
        const p = new Promise(function (resolve, reject) {
            setTimeout(function () {
                // 成功
                // let data = "数据";
                // 调用resolve，这个Promise 对象的状态就会变成成功
                // resolve(data);
                // 失败
                let err = "失败了！";
                reject(err);
            }, 1000);
        });

        // 成功
        // 调用 Promise 对象的then方法，两个参数为函数
        p.then(function (value) { // 成功
            console.log(value);
        }, function (season) { // 失败
            console.log(season);
        });
    </script>
</body>

</html>
```


### Promise封装读取文件

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Promise</title>
</head>

<body>
    <script>
        // 1、引入 fs 模块
        const fs = require("fs");

        
        // 2、调用方法，读取文件
        // fs.readFile("resources/text.txt",(err,data)=>{
        // // 如果失败则抛出错误
        // if(err) throw err;
        // // 如果没有出错，则输出内容
        // console.log(data.toString());
        // });


        // 3、使用Promise封装
        const p = new Promise(function (resolve, reject) {
            fs.readFile("resources/text.txt", (err, data) => {
                // 判断如果失败
                if (err) reject(err);
                // 如果成功
                resolve(data);
            });
        });
        p.then(function (value) {
            console.log(value.toString());
        }, function (reason) {
            console.log(reason); // 读取失败
        })
    </script>
</body>

</html>
```
### Promise封装Ajax请求

#### 原生请求

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Promise封装Ajax请求</title>
</head>

<body>
    <script>
        // 请求地址：https://api.apiopen.top/getJoke
        // 原生请求
        // 1、创建对象
        const xhr = new XMLHttpRequest();
        // 2、初始化
        xhr.open("GET", "https://api.apiopen.top/getJoke");
        // 3、发送
        xhr.send();
        // 4、绑定事件，处理响应结果
        xhr.onreadystatechange = function () {
            // 判断状态
            if (xhr.readyState == 4) {
                // 判断响应状态码 200-299
                if (xhr.status >= 200 && xhr.status <= 299) {
                    // 成功
                    console.log(xhr.response);
                } else {
                    // 失败
                    console.error(xhr.status);
                }
            }
        }
    </script>
</body>

</html>
```

#### Promise封装Ajax请求

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Promise封装Ajax请求</title>
</head>

<body>
    <script>
        // 请求地址：https://api.apiopen.top/getJoke
        const p = new Promise(function (resolve, reject) {
            // 原生请求
            // 1、创建对象
            const xhr = new XMLHttpRequest();
            // 2、初始化
            xhr.open("GET", "https://api.apiopen.top/getJoke");
            // 3、发送
            xhr.send();
            // 4、绑定事件，处理响应结果
            xhr.onreadystatechange = function () {
                // 判断状态
                if (xhr.readyState == 4) {
                    // 判断响应状态码 200-299
                    if (xhr.status >= 200 && xhr.status <= 299) {
                        // 成功
                        resolve(xhr.response);
                    } else {
                        // 失败
                        reject(xhr.status);
                    }
                }
            }
        });

        p.then(function (value) {
            console.log(value.toString());
        }, function (reason) {
            console.log(reason); // 读取失败
        })
    </script>
</body>

</html>
```


### Promise.prototype.then

```html

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Promise.prototype.then</title>
</head>

<body>
    <script>
        // 创建 Promise 对象
        const p = new Promise((resolve, reject) => {
            setTimeout(() => {
                resolve("用户数据");
            }, 1000);
        });

        const result = p.then(value => {


            // 调用then方法，then方法的返回结果是promise对象 对象的状态由回调函数的结果决定;

            // 1、如果回调函数中返回的结果是 非promise 类型的数据，
            // 状态为成功，返回值为对象的成功值resolved
            // [[PromiseStatus]]:"resolved"
            // [[PromiseValue]]:123
            // return 123;

            // 2、如果...是promise类型的数据
            // 此Promise对象的状态决定上面Promise对象p的状态
            // return new Promise((resolve,reject)=>{
            // // resolve("ok"); // resolved
            // reject("ok"); // rejected
            // });

            // 3、抛出错误
            // throw new Error("失败啦！");
            // 状态：rejected
            // value：失败啦！

            console.log(value);

        }, reason => {
            console.error(reason);
        })
        // then方法的返回结果是promise对象，所以可以链式调用
        // then里面两个函数参数，可以只写一个
        p.then(value => {}, reason => {}).then(value => {}, reason => {});
        console.log(result);
    </script>
</body>

</html>

```

#### 

### Promise实践练习



```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Promise.prototype.then</title>
</head>

<body>
    <script>
        // 1、引入 fs 模块
        const fs = require("fs");
        // 2、调用方法，读取文件
        // fs.readFile("resources/text.txt", (err, data1) => {
        //     fs.readFile("resources/test1.txt", (err, data2) => {
        //         fs.readFile("resources/test2.txt", (err, data3) => {
        //             let result = data1 + data2 + data3;
        //             console.log(result);
        //         });
        //     });
        // });
        
        // 3、使用Promise实现
        const p = new Promise((resolve, reject) => {
            fs.readFile("resources/text.txt", (err, data) => {
                resolve(data);

            });
        });
        p.then(value => {
            return new Promise((resolve, reject) => {
                fs.readFile("resources/test1.txt", (err, data) => {
                    resolve([value, data]);
                });
            })
        }).then(value => {
            return new Promise((resolve, reject) => {
                fs.readFile("resources/test2.txt", (err, data) => {
                    // 存入数组
                    value.push(data);
                    resolve(value);
                });
            })
        }).then(value => {
            console.log(value.join("\r\n"));
        })
    </script>
</body>

</html>
```

### Promise对象catch方法

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>Promise对象catch方法</title>
</head>

<body>

    <script>
        // Promise对象catch方法
        const p = new Promise((resolve, reject) => {
            setTimeout(() => {
                // 设置p对象的状态为失败，并设置失败的值
                reject("失败啦~！");
            }, 1000);
        })
        // p.then(value => {
        //     console.log(value);
        // }, reason => {
        //     console.warn(reason);
        // });
        p.catch(reason => {
            console.warn(reason);
        });
    </script>
</body>

</html>
```




## 14 、Set集合

### 概述

ES6 提供了新的数据结构 Set（集合）。 **它类似于数组，但成员的值都是唯一的** ，集合实现了 iterator接口，所以可以使用『扩展运算符』和『for...of...』进行遍历，集合的属性和方法

1. size 返回集合的元素个数；
2. add 增加一个新元素，返回当前集合；
3. delete 删除元素，返回 boolean 值；
4. has 检测集合中是否包含某个元素，返回 boolean 值；
5. clear 清空集合，返回 undefined；



```js
   // Set集合
        let s = new Set();
        console.log(s, typeof s);
        let s1 = new Set(["大哥", "二哥", "三哥", "四哥", "三哥"]);
        console.log(s1); // 自动去重
        // 1. size 返回集合的元素个数；
        console.log(s1.size);
        // 2. add 增加一个新元素，返回当前集合；
        s1.add("大姐");
        console.log(s1);
        // 3. delete 删除元素，返回 boolean 值；
        let result = s1.delete("三哥");
        console.log(result);
        console.log(s1);
        // 4. has 检测集合中是否包含某个元素，返回 boolean 值；
        let r1 = s1.has("二姐");
        console.log(r1);
        // 5. clear 清空集合，返回 undefined；
        s1.clear();
        console.log(s1);
```
```js
   // Set集合实践
        let arr = [1, 2, 3, 4, 5, 4, 3, 2, 1];
        // 数组去重
        let s1 = new Set(arr);
        console.log(s1);
        // 交集
        let arr2 = [3, 4, 5, 6, 5, 4, 3];

        let result = [...new Set(arr)].filter(item => new Set(arr2).has(item));
        console.log(result);
        // 并集
        // ... 为扩展运算符，将数组转化为逗号分隔的序列
        let union = [...new Set([...arr, ...arr2])];
        console.log(union);
        // 差集：比如集合1和集合2求差集，就是1里面有的，2里面没的.就是并集减去交集。
        let result1 = [...new Set(arr)].filter(item => !(new Set(arr2).has(item)));
        console.log(result1);
```


## 15 、Map集合

### 概述

ES6 提供了 Map 数据结构。它类似于对象，也是键值对的集合。但是“键”的范围不限于字符串，各种类
型的值（包括对象）都可以当作键。Map 也实现了iterator 接口，所以可以使用『扩展运算符』和
『for...of...』进行遍历；

### Map 的属性和方法

1. size 返回 Map 的元素个数；
2. set 增加一个新元素，返回当前 Map；
3. get 返回键名对象的键值；
4. has 检测 Map 中是否包含某个元素，返回 boolean 值；
5. clear 清空集合，返回 undefined；

### 

```js
   // Map集合
        // 创建一个空 map
        let m = new Map();
        // 创建一个非空 map
        let m2 = new Map([
            ['name', '尚硅谷'],
            ['slogon', '不断提高行业标准']
        ]);
        // 1. size 返回 Map 的元素个数；
        console.log(m2.size);
        // 2. set 增加一个新元素，返回当前 Map；
        m.set("皇帝", "大哥");
        m.set("丞相", "二哥");
        console.log(m);
        // 3. get 返回键名对象的键值；
        console.log(m.get("皇帝"));
        // 4. has 检测 Map 中是否包含某个元素，返回 boolean 值；
        console.log(m.has("皇帝"));
        // 5. clear 清空集合，返回 undefined；
        m.clear();
        console.log(m);
```



## 16 、class类

### 概述

ES6 提供了更接近传统语言的写法，引入了 Class（类）这个概念，作为对象的模板。通过 class 关键字，可以定义类。基本上，ES6 的 class 可以看作只是一个语法糖，它的绝大部分功能，ES5 都可以做到，新的 class 写法只是让对象原型的写法更加清晰、更像面向对象编程的语法而已；

### 知识点

1. class 声明类；
2. constructor 定义构造函数初始化；
3. extends 继承父类；
4. super 调用父级构造方法；
5. static 定义静态方法和属性；
6. 父类方法可以重写；



### class静态成员

```js
 // class静态成员

        // ES5写法
        // function Phone() {}
        // Phone.name = "手机";

        // Phone.change = function () {
        //     console.log("我可以改变世界！");
        // }
        // let nokia = new Phone();
        // console.log(nokia.name); // undefined
        // // nokia.change();
        // // 报错：Uncaught TypeError: nokia.change is not a function
        // Phone.prototype.color = "黑色";
        // console.log(nokia.color); // 黑色
        // console.log(Phone.name);
        // Phone.change();

        // 注意：实例对象和函数对象的属性是不相通的

        // ES6写法
        class Phone {
            // 静态属性，只有类有，实例对象是没有的
            static name = "手机";
            static change() {
                console.log("我可以改变世界！");
            }
        }
        let nokia = new Phone();
        console.log(nokia.name);
        console.log(Phone.name);
        Phone.change();
```


### ES5构造函数实现继承

```js
 // ES5构造函数继承
        // 手机
        function Phone(brand, price) {
            this.brand = brand;
            this.price = price;
        }
        Phone.prototype.call = function () {
            console.log("我可以打电话！");
        }
        // 智能手机
        function SmartPhone(brand, price, color, size) {
            Phone.call(this, brand, price);
            this.color = color;
            this.size = size;
        }

        // 设置子级构造函数的原型
        SmartPhone.prototype = new Phone;
        SmartPhone.prototype.constructor = SmartPhone;
        
        // 声明子类的方法
        SmartPhone.prototype.photo = function () {
            console.log("我可以拍照！");
        }
        SmartPhone.prototype.game = function () {
            console.log("我可以玩游戏！");
        }
        const chuizi = new SmartPhone("锤子", 2499, "黑色", "5.5inch");
        console.log(chuizi);
        chuizi.call();
        chuizi.photo();
        chuizi.game();
```

### ES6class类继承

注意：super只能用在子类的构造函数中，不能用于普通函数，且类的方法只能用 name(){};，不支持name:function(){};

```js
   // ES6class类继承
        class Phone {
            constructor(brand, price) {
                this.brand = brand;
                this.price = price;
            }
            call() {
                console.log("我可以打电话！");
            }
        }
        class SmartPhone extends Phone {
            // 构造函数
            constructor(brand, price, color, size) {
                super(brand, price); // 调用父类构造函数
                this.color = color;
                this.size = size;
            }
            photo() {
                console.log("我可以拍照！");
            }
            game() {
                console.log("我可以玩游戏！");
            }
        }
        
        const chuizi = new SmartPhone("小米", 1999, "黑色", "5.15inch");
        console.log(chuizi);
        chuizi.call();
        chuizi.photo();
        chuizi.game();
```

### class中的getter和setter设置

```js
  // class中的getter和setter设置

        class Phone {

            get price() { //当price这个属性被读取，会执行这个函数
                console.log("价格属性被读取了！");
                // 返回值
                return 123;
            }
            set price(value) {//当price这个属性被修改，会执行这个函数
                console.log("价格属性被修改了！");
            }
        }

        // 实例化对象
        let s = new Phone();

        console.log(s.price); // 返回值
        s.price = 2999;

```


## 17 、数值扩展

### Number.EPSILON：

Number.EPSILON 是 JavaScript 表示的最小精度；

EPSILON 属性的值接近于 2.2204460492503130808472633361816E-16；

### 二进制和八进制：

ES6 提供了二进制和八进制数值的新的写法，分别用前缀 0b 和 0o 表示；

### Number.isFinite() 与 Number.isNaN() ：

Number.isFinite() 用来检查一个数值是否为有限的；

Number.isNaN() 用来检查一个值是否为 NaN；

### Number.parseInt() 与 Number.parseFloat()：

ES6 将全局方法 parseInt 和 parseFloat，移植到 Number 对象上面，使用不变；

### Math.trunc：

##### 用于去除一个数的小数部分，返回整数部分；

### Number.isInteger：

Number.isInteger() 用来判断一个数值是否为整数；

```js
 // 数值扩展
        // 0. Number.EPSILON 是 JavaScript 表示的最小精度
        // EPSILON 属性的值接近于 2.2204460492503130808472633361816E-16

        function equal(a, b) {
            return Math.abs(a - b) < Number.EPSILON;
        }
        console.log("0、Number.EPSILON 是 JavaScript 表示的最小精度");

        // 箭头函数简化写法
        equal = (a, b) => Math.abs(a - b) < Number.EPSILON;
        console.log(0.1 + 0.2);
        console.log(0.1 + 0.2 === 0.3); // false
        console.log(equal(0.1 + 0.2, 0.3)); // true
        // 1. 二进制和八进制
        console.log("1、二进制和八进制");
        let b = 0b1010;
        let o = 0o777;
        let d = 100;
        let x = 0xff;
        console.log(x);
        // 2. Number.isFinite 检测一个数值是否为有限数
        console.log("2、Number.isFinite 检测一个数值是否为有限数");
        console.log(Number.isFinite(100));
        console.log(Number.isFinite(100 / 0));
        console.log(Number.isFinite(Infinity));
        // 3. Number.isNaN 检测一个数值是否为 NaN
        console.log("3. Number.isNaN 检测一个数值是否为 NaN");
        console.log(Number.isNaN(123));
        // 4. Number.parseInt Number.parseFloat字符串转整数
        console.log("4. Number.parseInt Number.parseFloat字符串转整数");
        console.log(Number.parseInt('5211314love'));
        console.log(Number.parseFloat('3.1415926神奇'));
        // 5. Number.isInteger 判断一个数是否为整数
        console.log("5. Number.isInteger 判断一个数是否为整数");
        console.log(Number.isInteger(5));
        console.log(Number.isInteger(2.5));
        // 6. Math.trunc 将数字的小数部分抹掉
        console.log("6. Math.trunc 将数字的小数部分抹掉 ");
        console.log(Math.trunc(3.5));

        // 7. Math.sign 判断一个数到底为正数 负数 还是零
        console.log("7. Math.sign 判断一个数到底为正数 负数 还是零");
        console.log(Math.sign(100));//1
        console.log(Math.sign(0));//0
        console.log(Math.sign(-20000));//-1
```



## 18 、对象扩展



ES6 新增了一些 Object 对象的方法：


1. `Object.is `比较两个值是否`严格相等`，与『===』行为基本一致（+0 与 NaN）；
2. Object.assign 对象的合并，将源对象的所有可枚举属性，复制到目标对象；
3. `proto` 、setPrototypeOf、 setPrototypeOf 可以直接设置对象的原型；

```js
      // 对象扩展
        // 1. Object.is 比较两个值是否严格相等，与『===』行为基本一致（+0 与 NaN）；
        console.log(Object.is(120, 120)); // ===
        // 注意下面的区别
        console.log(Object.is(NaN, NaN));
        console.log(NaN === NaN);
        // NaN与任何数值做===比较都是false，跟他自己也如此！
        // 2. Object.assign 对象的合并，将源对象的所有可枚举属性，复制到目标对象；
        const config1 = {
            host: "localhost",
            port: 3306,
            name: "root",
            pass: "root",
            test: "test" // 唯一存在
        }
        const config2 = {
            host: "http://zibo.com",
            port: 300300600,
            name: "root4444",
            pass: "root4444",
            test2: "test2"
        }
        // 如果前边有后边没有会添加，如果前后都有，后面的会覆盖前面的
        console.log(Object.assign(config1, config2));
        // 3. __proto__、setPrototypeOf、 getPrototypeOf 可以直接设置对象的原型；
        const school = {
            name: "尚硅谷"
        }
        const cities = {
            xiaoqu: ['北京', '上海', '深圳']
        }
        // 并不建议这么做
        Object.setPrototypeOf(school, cities);
        console.log(Object.getPrototypeOf(school));
        console.log(school);
```



## 19 、模块化

### 概述

 模块化是指将一个大的程序文件，拆分成许多小的文件，然后将小文件组合起来；

##### 模块化的优势有以下几点：

1. 防止命名冲突；

 2. 代码复用；

 3. 高维护性；

##### ES6 之前的模块化规范有：

```
1. CommonJS => NodeJS、Browserify；
2. AMD => requireJS；
3. CMD => seaJS；
```
### ES6 模块化语法

模块功能主要由两个命令构成：export 和 import；

1. export 命令用于规定模块的对外接口（导出模块）；
2. import 命令用于输入其他模块提供的功能（导入模块）；

### ES6导出模块语法汇总

#### m.js（逐个导出）

```js
export let school = "尚硅谷";
export function teach(){
	console.log("我们可以教你开发技术！");
}
```

#### n.js（统一导出）

```js
// 统一暴露（导出）
let school = "尚硅谷";
function findJob(){
	console.log("我们可以帮你找到好工作！");
}
export {school,findJob}
```



#### o.js（默认导出）

```js
export default{
	school : "尚硅谷",
	change : function(){
		console.log("我们可以帮你改变人生！");
	}
}
```



### ES6导入模块语法汇总



```js
 <script type="module">
        // 通用方式
        // 引入m.js模块内容
        import * as m from "./js/m.js";
        console.log(m);
        console.log(m.school);
        m.teach();
        // 引入n.js模块内容
        import * as n from "./js/n.js";
        console.log(n);
        console.log(n.school);
        n.findJob();
        // 引入o.js模块内容
        import * as o from "./js/o.js";
        console.log(o);
        // 注意这里调用方法的时候需要加上default
        console.log(o.default.school);
        o.default.change();
        // 解构赋值形式
        import { school, teach } from "./js/m.js";
        // 重名的可以使用别名
        import { school as xuexiao, findJob } from "./js/n.js";
        // 导入默认导出的模块，必须使用别名
        import { default as one } from "./js/o.js";
        // 直接可以使用
        console.log(school);
        teach();

        console.log(xuexiao);
        console.log(one);
        console.log(one.school);
        one.change();
        // 简便形式，只支持默认导出
        import oh from "./js/o.js";
        console.log(oh);
        console.log(oh.school);
        oh.change();
</script>
```



### 使用模块化的另一种方式

#### 将js语法整合到一个文件app.js：

```js
// 通用方式
// 引入m.js模块内容
import * as m from "./m.js";
console.log(m);
console.log(m.school);
m.teach();
```
#### 使用模块化的另一种方式.html：

```html
<!DOCTYPE html>
<html>
	<head>
		<meta charset="utf-8">
		<title>使用模块化的另一种方式</title>
	</head>
	<body>
		<script src="./js/app.js" type="module"></script>
	</body>
</html>
```



## 20 、Babel对ES6模块化代码转换

### Babel概述

Babel 是一个 JavaScript 编译器；

Babel 能够将新的ES规范语法转换成ES5的语法；

因为不是所有的浏览器都支持最新的ES规范，所以，一般项目中都需要使用Babel进行转换；

步骤：使用Babel转换JS代码——打包成一个文件——使用时引入即可；

### 步骤

第一步：安装工具babel-cli（命令行工具） babel-preset-env（ES转换工具） browserify（打包工具，
项目中使用的是webpack）；

第二步：初始化项目

```
npm init -y
```

##### 第三步：安装

```
npm i babel-cli babel-preset-env browserify
```

第四步：使用babel转换

```
npx babel js（js目录） -d dist/js（转化后的js目录） --presets=babel-preset-env
```
##### 第五步：打包

```
npx browserify dist/js/app.js -o dist/bundle.js
```

第六步：在使用时引入bundle.js

```js
<script src="./js/bundle.js" type="module"></script>
```

## 21 、ES6模块化引入NPM包

第一步：安装jquery

```
npm i jquery
```

第二步：在app.js使用jquery

```js
//入口文件
//修改背景颜色为粉色
import $ from 'jquery';// 相当于const $ = require("jquery");
$('body').css('background','pink');
```



## 21 、Array.prototype.includes

Includes 方法用来检测数组中是否包含某个元素，返回布尔类型值；

判断数组中是否包含某元素，语法：arr.includes(元素值)；

```js
js
// includes
let arr = [1,2,3,4,5];
console.log(arr.includes(1));//和indexOf类似，区别在于indexOf返回下标，其返回布尔
```



## 22 、指数操作符

在 ES7 中引入指数运算符「**」，用来实现幂运算，功能与 Math.pow 结果相同；

幂运算的简化写法，例如： 2 的 10 次方：2**10；

```js
// 指数操作符
console.log(Math.pow(2,10))
console.log(2**10);
```



## 23 、async 和 await

### 概述

- async 和 await 两种语法结合可以让异步代码看起来像同步代码一样；
- 简化异步函数的写法；



### async 函数

1. async 函数的返回值为` promise `对象；
2. promise 对象的结果由` async 函数执行的返回值`决定；

```js
        // async函数：异步函数
        async function fn() {
            // return 123; // 返回普通数据
            // 若报错，则返回的Promise对象也是错误的
            // throw new Error("出错啦！");
            // 若返回的是Promise对象，那么返回的结果就是Promise对象的结果
            return new Promise((resolve, reject) => {
                // resolve("成功啦！");
                reject("失败啦！");
            })
        }
        const result = fn();
        // console.log(result); // 返回的结果是一个Promise对象
        // 调用then方法
        result.then(value => {
            console.log(value);
        }, reason => {
            console.warn(reason);
        });
```

### await 表达式

1. await 必须写在 async 函数中；
2. await 右侧的表达式一般为 promise 对象；
3. await 返回的是 promise 成功的值；
4. await 的 promise 失败了, 就会抛出异常, 需要通过 try...catch 捕获处理；

```js
// async函数 + await表达式：异步函数

// 创建Prmise对象
const p = new Promise((resolve,reject)=>{
	resolve("成功啦！");
})
async function fn(){
	// await 返回的是 promise 成功的值
	let result = await p;
	console.log(result); // 成功啦！
}
fn();
```



### async 和 await 读取文件案例

```js

  // 导入模块
        const fs = require("fs");
        // 读取
        function readText() {
            return new Promise((resolve, reject) => {
                fs.readFile("../resources/text.txt", (err, data) => {
                    //如果失败
                    if (err) reject(err);
                    //如果成功
                    resolve(data);
                })
            })
        }
        function readTest1() {
            return new Promise((resolve, reject) => {
                fs.readFile("../resources/test1.txt", (err, data) => {
                    //如果失败
                    if (err) reject(err);
                    //如果成功
                    resolve(data);
                })
            })
        }
        function readTest2() {
            return new Promise((resolve, reject) => {
                fs.readFile("../resources/test2.txt", (err, data) => {
                    //如果失败
                    if (err) reject(err);
                    //如果成功
                    resolve(data);
                })
            })
        }
        //声明一个 async 函数
        async function main() {
            //获取为学内容
            let t0 = await readText();
            //获取插秧诗内容
            let t1 = await readTest1();
            // 获取观书有感
            let t2 = await readTest2();
            console.log(t0.toString());
            console.log(t1.toString());
            console.log(t2.toString());
        }
        main();
```
### async 和 await 结合发送ajax请求

```js

     // async 和 await 结合发送ajax请求
        function sendAjax(url) {
            return new Promise((resolve, reject) => {
                // 1、创建对象
                const x = new XMLHttpRequest();
                // 2、初始化
                x.open("GET", url);
                // 3、发送
                x.send();
                // 4、事件绑定
                x.onreadystatechange = function () {
                    if (x.readyState == 4) {
                        if (x.status >= 200 && x.status <= 299) {
                            // 成功
                            resolve(x.response);
                        } else {
                            // 失败
                            reject(x.status);
                        }
                    }
                }
            });
        }
        // 测试
        // const result = sendAjax("https://api.apiopen.top/getJoke");
        // result.then(value => {
        //     console.log(value);
        // }, reason => {
        //     console.warn(reason);
        // })
        // 使用async和await
        async function main() {
            let result = await sendAjax("https://api.apiopen.top/getJoke");
            console.log(result);
        }
        main();
```






#### 运行结果：

## 2 、对象方法扩展

### Object.values、Object.entries和

### Object.getOwnPropertyDescriptors：

```
1. Object.values()方法：返回一个给定对象的所有可枚举属性值的数组；
2. Object.entries()方法：返回一个给定对象自身可遍历属性 [key,value] 的数组；
3. Object.getOwnPropertyDescriptors()该方法：返回指定对象所有自身属性的描述对象；
```
### 代码实现：

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>对象方法扩展</title>
</head>
<body>
<script>
// 对象方法扩展
let school = {
name : "訾博",
age : 24 ,
sex : "男"
}
// 获取对象所有的键
console.log(Object.keys(school));
// 获取对象所有的值
console.log(Object.values(school));
// 获取对象的entries
console.log(Object.entries(school));
// 创建map
const map = new Map(Object.entries(school));
```

## 运行结果：

# 五、ES9 新特性

## 0 、功能概述

**1 、Rest 参数与 spread 扩展运算符**

```
console.log(map);
console.log(map.get("name"));
// 返回指定对象所有自身属性的描述对象
console.log(Object.getOwnPropertyDescriptors(school));
// 参考内容：
const obj = Object.create(null,{
name : {
// 设置值
value : "訾博",
// 属性特性
writable : true,
configuration : true,
enumerable : true
}
});
</script>
</body>
</html>
```

```
在对象中使Rest参数与spread扩展运算符；
```
**2 、正则扩展**

```
简化和增强正则匹配；
```
## 1 、Rest 参数与 spread 扩展运算符

### 概述：

Rest 参数与 spread 扩展运算符在 ES6 中已经引入，不过 ES6 中只针对于数组，在 ES9 中为对象提供了
像数组一样的 rest 参数和扩展运算符；

### 代码实现：

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Rest参数与spread扩展运算符</title>
</head>
<body>
<script>
// Rest参数与spread扩展运算符
// Rest 参数与 spread 扩展运算符在 ES6 中已经引入，
// 不过 ES6 中只针对于数组，在 ES9 中为对象提供了像
// 数组一样的 rest 参数和扩展运算符；
//rest 参数
function connect({
host,
port,
...user
}) {
console.log(host);
console.log(port);
console.log(user);
}
```
```
connect({
host: '127.0.0.1',
port: 3306 ,
username: 'root',
password: 'root',
type: 'master'
});
```
```
//对象合并
const skillOne = {
q: '天音波'
}
```
```
const skillTwo = {
w: '金钟罩'
}
```

### 运行结果：

## 2 、正则扩展：命名捕获分组

### 概述：

##### ES9 允许命名捕获组使用符号『?』,这样获取捕获结果可读性更强；

### 代码实现：

```
const skillThree = {
e: '天雷破'
}
const skillFour = {
r: '猛龙摆尾',
// 自己测试，可用
z: '胡说八道'
}
```
```
const mangseng = {
...skillOne,
...skillTwo,
...skillThree,
...skillFour
};
```
```
console.log(mangseng)
```
```
// ...skillOne => q: '天音波', w: '金钟罩'
</script>
</body>
</html>
```
```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>正则扩展：命名捕获分组</title>
</head>
<body>
<script>
```

### 运行结果：

##### // 正则扩展：命名捕获分组

##### // 声明一个字符串

```
let str = '<a href="http://www.baidu.com">訾博</a>';
// 需求：提取url和标签内文本
// 之前的写法
const reg = /<a href="(.*)">(.*)<\/a>/;
```
```
// 执行
const result = reg.exec(str);
console.log(result);
// 结果是一个数组，第一个元素是所匹配的所有字符串
// 第二个元素是第一个(.*)匹配到的字符串
// 第三个元素是第二个(.*)匹配到的字符串
// 我们将此称之为捕获
console.log(result[ 1 ]);
console.log(result[ 2 ]);
// 命名捕获分组
const reg1 = /<a href="(?<url>.*)">(?<text>.*)<\/a>/;
const result1 = reg1.exec(str);
console.log(result1);
// 这里的结果多了一个groups
// groups:
// text:"訾博"
// url:"http://www.baidu.com"
console.log(result1.groups.url);
console.log(result1.groups.text);
</script>
</body>
</html>
```

## 3 、正则扩展：反向断言

### 概述：

##### ES9 支持反向断言，通过对匹配结果前面的内容进行判断，对匹配进行筛选；

### 代码实现：

### 运行结果：

## 4 、正则扩展：dotAll 模式

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>正则扩展：反向断言</title>
</head>
<body>
<script>
// 正则扩展：反向断言
// 字符串
let str = "JS5201314你知道么 555 啦啦啦";
// 需求：我们只想匹配到 555
// 正向断言
const reg = /\d+(?=啦)/; // 前面是数字后面是啦
const result = reg.exec(str);
console.log(result);
// 反向断言
const reg1 = /(?<=么)\d+/; // 后面是数字前面是么
const result1 = reg.exec(str);
console.log(result1);
</script>
</body>
</html>
```

### 概述：

正则表达式中点.匹配除回车外的任何单字符，标记『s』改变这种行为，允许行终止符出现；

### 代码实现：

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>正则扩展：dotAll 模式</title>
</head>
<body>
<script>
// 正则扩展：dotAll 模式
// dot就是. 元字符，表示除换行符之外的任意单个字符
let str = `
<ul>
<li>
<a>肖生克的救赎</a>
<p>上映日期: 1994-09-10</p>
</li>
<li>
<a>阿甘正传</a>
<p>上映日期: 1994-07-06</p>
</li>
</ul>
`;
// 需求：我们想要将其中的电影名称和对应上映时间提取出来，存到对象
// 之前的写法
// const reg = /<li>\s+<a>(.*?)<\/a>\s+<p>(.*?)<\/p>/;
// dotAll 模式
const reg = /<li>.*?<a>(.*?)<\/a>.*?<p>(.*?)<\/p>/gs;
// const result = reg.exec(str);
// console.log(result);
let result;
let data = [];
while(result = reg.exec(str)){
console.log(result);
data.push({title:result[ 1 ],time:result[ 2 ]});
}
console.log(data);
```
```
</script>
</body>
</html>
```

## 运行结果：

# 六、ES10 新特性

## 0 、功能概述

**1 、Object.fromEntries**

```
将二维数组或者map转换成对象；
```
**2 、trimStart 和 trimEnd**

```
去除字符串前后的空白字符；
```
**3 、Array.prototype.flat 与 flatMap**

```
将多维数组降维；
```
**4 、Symbol.prototype.description**

```
获取Symbol的字符串描述；
```
## 1 、Object.fromEntries

## 概述：

将二维数组或者map转换成对象；

之前学的Object.entries是将对象转换成二维数组；


### 代码实现：

### 运行结果：

## 2 、trimStart 和 trimEnd

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Object.fromEntries</title>
</head>
<body>
<script>
// Object.fromEntries：将二维数组或者map转换成对象
// 之前学的Object.entries是将对象转换成二维数组
// 此方法接收的是一个二维数组，或者是一个map集合
// 二维数组
const result = Object.fromEntries([
["name","訾博"],
["age", 24 ],
]);
console.log(result);
```
```
const m = new Map();
m.set("name","訾博");
m.set("age", 24 );
const result1 = Object.fromEntries(m);
console.log(result1);
</script>
</body>
</html>
```

### 概述：

##### 去掉字符串前后的空白字符；

### 代码实现：

### 运行结果：

## 3 、Array.prototype.flat 与 flatMap

### 概述：

##### 将多维数组转换成低维数组；

### 代码实现：

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>trimStart 和 trimEnd</title>
</head>
<body>
<script>
// trimStart 和 trimEnd
let str = " zibo ";
console.log(str.trimLeft());
console.log(str.trimRight());
console.log(str.trimStart());
console.log(str.trimEnd());
</script>
</body>
</html>
```
```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Array.prototype.flat 与 flatMap</title>
```

### 运行结果：

## 4 、Symbol.prototype.description

### 概述：

获取Symbol的描述字符串；

```
</head>
<body>
<script>
// Array.prototype.flat 与 flatMap
// flat
// 将多维数组转换成低维数组
// 将二维数组转换成一维数组
const arr = [ 1 , 2 , 3 ,[ 4 , 5 ], 6 , 7 ];
console.log(arr.flat());
// 将三维数组转换成二维数组
const arr2 = [ 1 , 2 , 3 ,[ 4 , 5 ,[ 6 , 7 ]], 8 , 9 ];
console.log(arr2.flat());
// 将三维数组转换成一维数组
console.log(arr2.flat( 2 ));
```
```
// flatMap
const arr3 = [ 1 , 2 , 3 , 4 , 5 ];
const result0 = arr3.map(item => item * 10 );
console.log(result0);
const result = arr3.map(item => [item * 10 ]);
console.log(result);
const result1 = arr3.flatMap(item => [item * 10 ]);
console.log(result1);
</script>
</body>
</html>
```

## 代码实现：

## 运行结果：

# 七、ES11 新特性

## 0 、功能概述

**1 、String.prototype.matchAll**

```
用来得到正则批量匹配的结果；
```
**2 、类的私有属性**

```
私有属性外部不可访问直接；
```
**3 、Promise.allSettled**

```
获取多个promise执行的结果集；
```
**4 、可选链操作符**

```
简化对象存在的判断逻辑；
```
**5 、动态 import 导入**

```
动态导入模块，什么时候使用什么时候导入；
```
**6 、BigInt**

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Symbol.prototype.description</title>
</head>
<body>
<script>
// Symbol.prototype.description
// 获取Symbol的描述字符串
// 创建Symbol
let s = Symbol("訾博");
console.log(s.description)
</script>
</body>
</html>
```

##### 大整型；

**7 、globalThis 对象**

```
始终指向全局对象window；
```
## 1 、String.prototype.matchAll

### 概述：

##### 用来得到正则批量匹配的结果；

### 代码实现：

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>String.prototype.matchAll</title>
</head>
<body>
<script>
// String.prototype.matchAll
// 用来得到正则批量匹配的结果
let str = `
<ul>
<li>
<a>肖生克的救赎</a>
<p>上映日期: 1994-09-10</p>
</li>
<li>
<a>阿甘正传</a>
<p>上映日期: 1994-07-06</p>
</li>
</ul>
`;
// 正则
const reg = /<li>.*?<a>(.*?)<\/a>.*?<p>(.*?)<\/p>/sg;
const result = str.matchAll(reg);
// 返回的是可迭代对象，可用扩展运算符展开
// console.log(...result);
// 使用for...of...遍历
for(let v of result){
console.log(v);
}
</script>
</body>
</html>
```

### 运行结果：

## 2 、类的私有属性

### 概述：

##### 私有属性外部不可访问直接；

### 代码实现：

```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>类的私有属性</title>
</head>
<body>
<script>
// 类的私有属性
class Person{
// 公有属性
name;
// 私有属性
#age;
#weight;
// 构造方法
constructor(name, age, weight){
this.name = name;
this.#age = age;
this.#weight = weight;
}
intro(){
console.log(this.name);
console.log(this.#age);
console.log(this.#weight);
}
}
```
```
// 实例化
const girl = new Person("小兰", 18 ,"90kg");
console.log(girl);
// 公有属性的访问
console.log(girl.name);
```



## 3 、Promise.allSettled

### 概述：

获取多个promise执行的结果集；

### 代码实现：

##### // 私有属性的访问

```
console.log(girl.age); // undefined
// 报错Private field '#age' must be declared in an enclosing class
// console.log(girl.#age);
girl.intro();
</script>
</body>
</html>
```
```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>Promise.allSettled</title>
</head>
<body>
<script>
// Promise.allSettled
// 获取多个promise执行的结果集
// 声明两个promise对象
const p1 = new Promise((resolve,reject)=>{
setTimeout(()=>{
resolve("商品数据——1");
}, 1000 );
});
const p2 = new Promise((resolve,reject)=>{
setTimeout(()=>{
reject("失败啦");
}, 1000 );

 });
```



## 4 、可选链操作符

### 概述：

##### 如果存在则往下走，省略对对象是否传入的层层判断；

### 代码实现：

##### 

```
// 调用Promise.allSettled方法
const result = Promise.allSettled([p1,p2]);
console.log(result);
const result1 = Promise.all([p1,p2]); // 注意区别
console.log(result1);
</script>
</body>
</html>
```
```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>可选链操作符</title>
</head>
<body>
<script>
// 可选链操作符
// ?.
function main(config){
// 传统写法
// const dbHost = config && config.db && config.db.host;
// 可选链操作符写法
const dbHost = config?.db?.host;
console.log(dbHost);
```

### 

## 5 、动态 import 导入

### 概述：

##### 动态导入模块，什么时候使用时候导入；

### 代码实现：

```
main({
db:{
host:"192.168.1.100",
username:"root"
},
cache:{
host:"192.168.1.200",
username:"admin"
}
});
</script>
</body>
</html>
```
```
export function hello(){
alert('Hello');
}
```
```
// import * as m1 from "./hello.js"; // 传统静态导入
//获取元素
const btn = document.getElementById('btn');
```
```
btn.onclick = function(){
import('./hello.js').then(module => {
module.hello();
});
}
```

#### 动态import加载.html：

### 运行结果：

## 6 、BigInt

### 概述：

##### 更大的整数；

### 代码实现：

```
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>动态 import </title>
</head>
<body>
<button id="btn">点击</button>
<script src="app.js" type="module"></script>
</body>
</html>
```
```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>BigInt</title>
</head>
<body>
<script>
// BigInt
// 大整型
let n = 100n;
console.log(n,typeof(n));
```
```
// 函数：普通整型转大整型
let m = 123 ;
console.log(BigInt(m));
```

### 运行结果：

## 7 、globalThis 对象

### 概述：

始终指向全局对象window；

### 代码实现：

##### // 用于更大数值的运算

```
let max = Number.MAX_SAFE_INTEGER;
console.log(max);
console.log(max+ 1 );
console.log(max+ 2 ); // 出错了
```
```
console.log(BigInt(max));
console.log(BigInt(max)+BigInt( 1 ));
console.log(BigInt(max)+BigInt( 2 ));
</script>
</body>
</html>
```
```
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>globalThis 对象</title>
</head>
<body>
<script>
// globalThis 对象 : 始终指向全局对象window
console.log(globalThis);
</script>
</body>
</html>
```

### 