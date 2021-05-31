
## 🎈数值型：Number

在JS中所有的数值都是 Number 类型，包括整数和浮点数（小数）。

```javascript
	var a = 100; // 定义一个变量 a，并且赋值整数100
	console.log(typeof a); // 输出变量 a 的类型

	var b = 12.3; // 定义一个变量 b，并且赋值浮点数 12.3
	console.log(typeof a);
```

上方代码的输出结果为：

```
number

number
```

再次补充：在 JS 中，只要是数，就是 Number 数值型的。无论整浮、浮点数（即小数）、无论大小、无论正负，都是 Number 类型的。

### ✨数值范围

由于内存的限制，ECMAScript 并不能保存世界上所有的数值。

- 最大值：`Number.MAX_VALUE`，这个值为： 1.7976931348623157e+308

- 最小值：`Number.MIN_VALUE`，这个值为： 5e-324

如果使用 Number 表示的变量超过了最大值，则会返回Infinity。

- 无穷大（正无穷）：Infinity

- 无穷小（负无穷）：-Infinity

注意：`typeof Infinity`的返回结果是number。

🎉`提示`

> 整数精度：-2^53~2^53,超过这个范围，整数将会失去尾部的精确度。(这个问题 便利蜂 面过我)

### ✨进制转换

在JavaScript中，可以将用Number的toString（x）方法把十进制数转为其他进制。

```js
var n = 32;
console.log(n.toString(2)); //返回字符串10000
console.log(n.toString(4)); //返回字符串200
console.log(n.toString(16)); //返回字符串20
console.log(n.toString(30)); //返回字符串12
console.log(n.toString(32)); //返回字符串10
```

🎉`提示`

> 对于数值直接量，不能直接调用toString（），必须用小括号强制运算数值直接量后，才可以调用该方法
>
> ```js
> console.log(32.toString(2)) //错误
> console.log((32).toString(2)) //返回字符串10000
> ```

### ✨NaN

**NaN**：是一个特殊的数字，表示Not a Number，非数值。比如：

```javascript
  
+ '0' //0
+ 'abc' //NaN

//单独一个+跟上一个字符串，默认会首选转为number。

console.log("abc" / 18);  //结果是NaN
console.log("abc" * "abcd"); //按理说，字符串相乘是没有结果的，但如果你非要让JS去算，它就一定会给你一个结果。结果是NaN
```

注意：`typeof NaN`的返回结果是 number。

`Undefined和任何数值计算的结果为 NaN`。`NaN 与任何值都不相等，包括 NaN 本身。`即NaN===NaN：false

🎉为了方便检验NaN值，JavaScript提供了 isNaN() 函数

```js
isNaN(NaN) //true
isNaN(0) //false
isNaN('asdf') //true
isNaN('1') //false
//对字符串量，isNaN会尽可能将其转为number。即先想办法转换，然后在判断。
```



### ✨连字符和加号的区别

键盘上的`+`可能是连字符，也可能是数字的加号。如下：

```js
console.log("我" + "爱" + "你");	//连字符，把三个独立的汉字，连接在一起了
console.log("我+爱+你");			//原样输出
console.log(1+2+3);				//输出6
```

输出：

```
我爱你
我+爱+你
6
```

**总结**：如果加号两边**都是** Number 类型，此时是数字相加。否则，就是连字符（用来连接字符串）。

举例1：

```javascript
var a = "1";
var b = 2;
console.log(a + b);
```

控制台输出：

```
12
```

举例2：

```
var a = 1;
var b = 2;
console.log("a" + b);	//"a"就不是变量了！所以就是"a"+2 输出a2

```

控制台输出：

```
a2
```

于是我们明白了，在变量中加入字符串进行拼接，可以被同化为字符串。【重要】


### ✨隐式转换

我们知道，`"2"+1`得到的结果其实是字符串，但是`"2"-1`得到的结果却是数值1，这是因为计算机自动帮我们进行了“**隐式转换**”。

也就是说，`-`、`*`、`/`、`%`这几个符号会自动进行隐式转换。例如：

```javascript
var a = "4" + 3 - 6;
console.log(a);
```

输出结果：

```javascript
37
```

虽然程序可以对`-`、`*`、`/`、`%``这几个符号自动进行“隐式转换”；但作为程序员，我们最好自己完成转换，方便程序的可读性。


## 🎈浮点数的运算

### 运算精度问题

在JS中，整数的运算**基本**可以保证精确；但是**小数的运算，可能会得到一个不精确的结果**。所以，千万不要使用JS进行对精确度要求比较高的运算。

经典题目：🔥**0.1+0.2为什么不等于0.3？**

```javascript
var a = 0.1 + 0.2;
console.log(a===0.3) //false
console.log(a);  //打印结果：0.30000000000000004
```

上方代码中，打印结果并不是0.3，而是0.30000000000000004。

这是因为，计算机在做运算时，所有的运算都要转换成二进制去计算。然而，有些数字转换成二进制之后，无法精确表示。比如说，0.1和0.2转换成二进制之后，是`无穷的`，因此存在浮点数的计算不精确的问题。

