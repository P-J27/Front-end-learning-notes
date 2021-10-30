#### this是什么？

**this** 是 javascript 中的一个**关键字**，它提供了一种更优雅的方式来 **隐式“传递”** 一个**对象引用**，因此可以将 API 设计得**更加简洁并且易于复用**。



#### this 是个什么样的机制，如何分析它的指向

- `this` 是在**运行时进行绑定**的，并**不是在编写时绑定**，它的上下文取决于函数调用时的各种条件。**`this` 的绑定和函数声明的位置没有任何关系，只取决于函数的调用方式。**
- 当一个函数被调用时，会创建一个**执行上下文**【关联概念】。这个记录会包含函数在哪里被调用(调用栈，执行栈)、函数的调用方法、传入的参数等信息。this 就是记录的其中一个属性，会在函数执行的过程中用到。**执行上下文的创建过程的一环就是 `this Binding`。**
- **this 实际上是在函数被调用时发生的绑定，它指向什么完全取决于函数在哪里被如何调用。**

首先，调用位置就是函数在代码中**被调用的位置(而不是声明的位置)**。 最重要的是要分析调用栈(就是为了到达当前执行位置所调用的所有函数)。我们关心的调用位置就在当前正在执行的函数的前一个调用中。

#### 指向问题

##### 1. 全局上下文

全局上下文默认this指向window, 严格模式下指向undefined。

##### 2. 直接调用函数

比如:

```js
let obj = {
  a: function() {
    console.log(this);
  }
}
let func = obj.a;
func();
```

这种情况是直接调用。this相当于全局上下文的情况。

##### 3. 对象.方法的形式调用

还是刚刚的例子，我如果这样写:

```js
obj.a();
```

这就是`对象.方法`的情况，this指向这个对象

##### 4. DOM事件绑定

onclick和addEventerListener中 this 默认指向绑定事件的元素。

IE比较奇异，使用attachEvent，里面的this默认指向window。

##### 5. new+构造函数

此时构造函数中的this指向实例对象。

##### 6. 箭头函数？

由于箭头函数没有自己单独的 this 值。 this 与**声明所在的上下文相同**。也就是说调用箭头
函数的时候，不会隐士的调用 this 参数，而是从**定义时的函数继承上下文**。

```js
let obj = {
  a: function() {
    let do = () => {
      console.log(this);
    }
    do();
  }
}
obj.a(); // 找到最近的非箭头函数a，a现在绑定着obj, 因此箭头函数中的this是obj

```

> 优先级: new  > call、apply、bind  > 对象.方法 > 直接调用。

#### 如何改变指向？

all、apply、bind三者为改变this指向的方法。

**共同点：**

- 第一个参数都为改变this的指针。
- 若第一参数为null/undefined，this默认指向window

##### call（无数个参数）

- 第一个参数：改变this指向
- 第二个参数：实参
- 使用之后会自动执行该函数

```js
function fn(a,b,c){
        console.log(this,a+b+c); // this指向window
}
fn();
fn.call(document,1,2,3);//call改变之后this指向document  
//输出 #document 6   1,2,3是实参 结果相加为6
```

##### apply（两个参数）

- 第一个参数：改变this指向
- 第二个参数：数组（里面为实参）
- 使用时候会自动执行函数

```js
function fn(a,b,c){
     console.log(this,a+b+c); 
}
fn();
fn.apply(document,[1,2,3]); 
```

##### bind（无数个参数）

- 第一个参数：改变this指向
- 第二个参数之后：实参
- 返回值为一个新的函数
- 使用的时候需要手动调用下返回 的新函数（不会自动执行）

```js
function fn(a,b,c){
    console.log(this,a+b+c); //window
}
let ff = fn.bind('小明',1,2,3); //手动调用一下
```

##### 区别

- call、apply与bind区别：前两个可以自动执行，bind不会自动执行，需要手动调用

- call、bind与apply区别：前两个都有无数个参数，apply只有两个参数，而且第二个参数为数组小结

#### 小结

- 全局对象的 this 指向 window 对象
- 全局函数执行 this 指向 window
- this 永远指向最后调用它的那个对象
- new 关键词改变了 this 指向
- apply call bind 可以改变 this 指向
- 箭头函数的 this 在定义时确定
- 匿名函数的 this 永远指向 window

