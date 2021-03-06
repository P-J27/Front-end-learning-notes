

#### 前言

> 可以说这是银行我们面试遇到的最高频的一个问题，也是一个很基础的问题了。所以，我们定然在这个问题上，不能讲不清楚，那就当场发感谢信了。🚀

#### let 

let 关键字用来声明变量，使用 let 声明的变量有几个特点：

1. `不允许重复声明`；
2. `块儿级作用域（局部变量）`；
3. `不存在变量提升`；
4. `不影响作用域链`；

##### 示例

```js
// let关键字使用示例：
let a; // 单个声明
let b,c,d; // 批量声明
let e = 100 ; // 单个声明并赋值
let f = 521 , g = 'iloveyou', h = []; // 批量声明并赋值
```

##### 不允许重复声明

```js
let dog = "狗";
let dog = "狗";
// 报错：Uncaught SyntaxError: Identifier 'dog' has already been
declared
```

##### 块儿级作用域（局部变量）

```js
{
let cat = "猫";
console.log(cat);
}
console.log(cat);
// 报错：Uncaught ReferenceError: cat is not defined
```

##### 不存在变量提升

```js
// 什么是变量提升：就是在变量创建之前使用（比如输出：输出的是默认值），let不存在，var存在；

console.log(people1); // 可输出默认值
console.log(people2); // 报错：Uncaught ReferenceError: people2 is not defined
var people1 = "大哥"; // 存在变量提升
let people2 = "二哥"; // 不存在变量提升
```

##### 不影响作用域链：

```js
// 什么是作用域链：很简单，就是代码块内有代码块，跟常规编程语言一样，上级代码块中的局部变量下级可用
		{
            let p = "大哥";
			var s;               //p的作用域是块(花括号内)级的，而s的作用域为函数作用域全局
            function fn() {
                console.log(p); // 这里是可以使用的
            }
            fn();
        }
```


##### 应用场景

`以后声明变量使用 let 就对了`；

##### let案例：点击div更改颜色

```js
 // 获取div元素对象
        let items = document.getElementsByClassName('item');


        //ES5错误解法
        for (var i = 0; i < items.length; i++) {
            items[i].onclick = function () {
                items[i].style.background = 'pink'; 
                alert('点击了' + i + '个')
            }
            // 由于点击事件是异步的，i又是全局的，所以每个item用的i都是同一个i。

        }
        //ES5解法1
        for (var i = 0; i < items.length; i++) {
            items[i].onclick = function () {
                this.style.background = 'pink'; // 写法一：常规写法一般无异常
                alert('点击了' + i + '个')
            }
        }
        //ES5解法1
        for (var i = 0; i < items.length; i++) {
            //使用闭包，控制作用域
            (function (i) {
                items[i].onclick = function () {
                    items[i].style.background = 'pink'; // 写法二
                    alert('点击了' + i + '个')
                }
            })(i)
        }
        
        // ES6解法
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
                // 下面的声明会将上面的覆盖掉，所以点击事件每次找到的都是3
                // 由于let声明的是局部变量，每一个保持着原来的值
                // 点击事件调用的时候拿到的是对应的i
            }

        }
```


#### const

const 关键字用来声明 **常量** ，const 声明有以下特点：

1. `声明必须赋初始值`·；
2. `标识符一般为大写（习惯`）；
3. `不允许重复声明`；
4. `值不允许修改`；
5. `块儿级作用域（局部变量）`；

`注:`当常量为对象时，`值不允许修改`含义是指向的对象不能修改，但是可以改变对象内部的属性

##### 示例

```js

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
  
```


##### 应用场景：

`声明对象类型使用 const，非对象类型声明选择 let；`



#### var、let和const的区别

1. var定义的变量，没有块的概念，可以`跨块访问`, `不能跨函数访问.` `并不是全局作用域`

2. let定义的变量，只能在块作用域里访问，不能跨块访问，也不能跨函数访问。

3. const用来定义常量，使用时`必须初始化`(即必须赋值)，只能在块作用域里访问，而且不能修改。

4. var声明的变量存在`变量提升现象`，let和const声明的变量不存在变量提升现象（遵循：“先声明，后使用”的原则，否则会报错）。

5. var不存在暂时性死区，let和const存在暂时性死区。

    解析：只要块级作用域内存在let命令，那么它所声明的变量就会绑定到这个区域，不再受外部的影响。

6. var允许重复声明同一个变量，let和const在同一作用域下不允许重复声明同一个变量。

   解析：var允许重复声明变量，后一个变量会覆盖前一个变量，const和let会报错。

