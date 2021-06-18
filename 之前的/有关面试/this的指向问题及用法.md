## 前言

>  在前端的面试中，经常会问到有关 this 的指向问题。之前在学习笔记中也有这部分内容，今天特意拎出来，并整理成了这篇文章，自己巩固的同时，希望能帮到有需要的同学。

## 一道面试题

```js
var length = 10;
function fn () {
    console.log(this.length);
}
var obj = {
    length: 5,
    method: function (fn) {
        fn();
        arguments[0]();
    }
};
obj.method(fn, 1);
```

问：浏览器的输出结果是什么？

它的答案是：先输出一个 `10`，然后输出一个 `2`。

让我们来解析一下原因：

- 在我们这道题中，虽然 fn 作为 method 的参数传了进来，但它的调用者并不受影响，任然是 `window`，所以输出了 10。
- `arguments[0]();`这条语句并不常见，可能大家有疑惑的点在这里。 其实，**arguments 是一种特殊的对象。在函数中，我们无需指出参数名，就能访问。可以认为它是一种，隐式的传参形式**。
- 当执行 `arguments[0]()`; 时，其实调用了 fn()。而这时，fn 函数中 this 就指向了 arguments，这个特殊的对象。obj.method 方法接收了 2 个参数，所以 arguments 的 length，很显然就是 2 了。

## 改造一下

再来，不少同学对 this 的指向感到疑惑，是因为 this 并没有指向我们预期的那个对象。

就像这道题，从语义上来看，我们期望 fn() 输出的是 obj 自己的 length，也就是 5，而不是 10。那么如果要得到 5 的结果，我们该如何修改这段代码呢？

其实只要多做一步处理就好。就是让 this 指向 obj 自己。这里，我们可以用 call 来改变 this 的指向，像下面这样：

```js
var length = 10;

function fn () {
    console.log(this.length);
}

var obj = {
    length: 5,
    method: function (fn) {
        // 在这里用call 将 this 指向 obj 自己
        fn.call(this);
    }
};
 
obj.method(fn);
```

输出的结果就是 5 了，搞定。

看吧，this 也没那么复杂吧，我们只需要一些简单的操作，就能控制 this 的指向了。那么，问题来了，为什么有时候 this 会失控呢？

其实，这与 this 机制背后的原理有关。不过别急，让我们从理解 this 的基本概念开始，先来看看 this 到底是什么？

注：不知道call的同学可以参考这篇

## this 是什么？

> this 是 JavaScript 中的一个关键字。它通常被运用于函数体内，依赖于函数调用的上下文条件，与函数被调用的方式有关。它指向谁，则完全是由函数被调用的调用点来决定的。
>
> 所以，this，是在运行时绑定的，而与编写时的绑定无关。随着函数使用场合的不同，this 的值也会发生变化。但是有一个总的原则：那就是**`this 总会指向，调用函数的那个对象`**。

## 为什么要用this？

从概念上理解起来，似乎有点费劲。那我们为什么还要使用 this 呢？用了 this 会带来什么好处？

让我们先看下面这个例子：

```js
function identify() {
    return this.name.toUpperCase();
}

var me = {
    name: "Kyle"
};

var you = {
    name: "Reader"
};

identify.call( me ); // KYLE
identify.call( you ); // READER
```

一开始我们可能太不明白为何这样输出。那不如先换个思路，与使用 this 相反，我们可以明确地将环境对象，传递给 identify()。像这样：

```js
function identify(context) {
    return context.name.toUpperCase();
}
identify( you ); // READER
```

在这个简单的例子中，结果是一样的。我们可以把环境对象直接传入函数，这样看来比较直观。但是，**当模式越发复杂时，将执行环境作为一个明确的参数传递给函数，就会显得非常混乱了**。

而 this 机制，可以提供一种更优雅的方式，来隐含地“传递”一个对象的引用，这会使得 API 的设计更加地干净，复用也会变得容易。

## this 的原理

明白了 this 的概念之后，不经让我好奇，为何 this 指向的就是函数运的执行环境呢？

之前，看到了 阮老师 的一篇文章，十分透彻地分析了 this 的原理。我根据自己的理解，整理如下。

很多教科书会告诉你，`this 指的是函数运行时所在的环境`。但是，为什么会这样？也就是说，函数的运行环境到底是怎么决定的？

理解 this 的原理，有助于帮我们更好地理解它的用法。**JavaScript 语言之所以有 this 的设计，跟内存里面的数据结构有关系**。

来看一个简单的示例：

```js
var obj = { foo: 5 };
```

上面的代码将一个对象赋值给变量 obj。JavaScript 引擎会先在内存里面，生成一个对象 { foo: 5 }，然后把这个对象的内存地址赋值给变量 obj。

也就是说，变量 obj 其实只是一个地址。后面如果要读取 obj.foo，引擎先从 obj 拿到内存地址，然后再从该地址读出原始的对象，返回它的 foo 属性。

这样的结构很清晰，但如果属性的值是一个函数，又会怎么样呢？比如这样：

```js
var obj = { foo: function () {} };
```

这时，JavaScript 引擎会将函数单独保存在内存中，然后再将函数的地址赋值给 foo 属性的 value 属性。

![img](https://gitee.com/p_pj/picgo/raw/master/img/20210619000325)

可以看到，函数是一个单独的值(以地址形式赋值)，所以才可以在不同的环境中执行。

又因为，JavaScript 允许在函数体内部，引用当前环境的其他变量。所以需要有一种机制，能够在函数体内部获得当前的运行环境（context）。所以，this就出现了，它的设计目的就是**`在函数体内部，指代函数当前的运行环境`**。

## this 的用法

在理解了 this 的原理之后，我们用下面的 5 种情况，来讨论 this 的用法。

#### 1、纯粹的函数调用

这是函数的最通常用法，属于全局性调用，因此 this 就代表全局对象` window`。

```js
function test(){
    this.x = 1;
    console.log(this.x);
}
test(); // 1
```

#### 2、作为对象方法的调用

函数作为某个对象的方法调用，这时` this 就指这个上级对象。`

```js
function test(){
    console.log(this.x);
}
var o = {};
o.x = 1;
o.m = test;
o.m(); // 1
```

#### 3、作为构造函数调用

所谓构造函数，就是通过这个函数生成一个新对象（object）。这时，`this 就指这个新对象。`

```js
function test(){
    this.x = 1;
}
var o = new test();
console.log(o.x); // 1
```

#### 4、apply调用

apply() 是函数对象的一个方法，它的作用是改变函数的调用对象，它的第一个参数就表示改变后的调用这个函数的对象。因此，this 指的就是这第一个参数。

```js
var x = 0;
function test() {
    console.log(this.x);
}
var o = {};
o.x = 1;
o.m = test;
o.m.apply(); //0
```

`apply() 的参数为空时，默认调用全局对象`。因此，这时的运行结果为0，证明this指的是全局对象。

它与上文中提到的 call 的作用是一样的，只是写法上略有区别。由于篇幅原因，我会另启一篇，来详述它们的用法。

#### 5、箭头函数

> ES6 中的箭头函数，在大部分情况下，使得 this 的指向，变得符合我们的预期。但有些时候，它也不是万能的，一不小心的话，this 同样会失控。

因为篇幅内容较多，我会另写一篇文章来介绍。

## 另一道面试题

最后，让我们来巩固一下 this 的概念和用法。来看一道面试题：

```js
window.val = 1;
 
var obj = {
    val: 2,
    dbl: function () {
        this.val *= 2; 
        val *= 2;       
        console.log('val:', val);
        console.log('this.val:', this.val);
    }
};

 // 说出下面的输出结果
 obj.dbl();
 var func = obj.dbl;
 func();
```

答案是输出：`2 、 4 、 8 、 8` 。

解析：

- 执行 obj.dbl(); 时， `this.val 的 this 指向 obj，而下一行的 val 指向 window`。所以，由 window.val 输出 2，obj.val 输出 4 。
- 最后一行 `func(); 的调用者是 window。 所以，现在的 this.val 的 this 指向 window`。
- 别忘了刚才的运算结果，window.val 已经是 2 了，所以现在 this.val *= 2; 的执行结果就是 4。
- val *= 2; 的执行结果，就是 8 了。 所以，最终的结果就是输出 8 和 8 。

## 总结

> this 指代了函数当前的运行环境，依赖于函数调用的上下文条件，在运行时才会进行绑定。
>
> 请牢记总原则：**`this 总会指向，调用函数的那个对象`**。