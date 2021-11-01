#### **温习一下**

##### call、apply、bind的异同

- **共同点：** 
  - 功能角度：三者都能改变` this 指向，且第一个传递的参数都是 this 指向的对象。`
  - 传参角度：三者都采用的后续传参的形式。 
- 不同点： 
  - 传参方面： call 的传参是单个传递（序列），而 apply 后续传递的参 数是数组形式。而 bind 与call相同。
  -  执行方面： call 和 apply 函数的执行是直接执行的，而 bind 函数会返回一个函数，然后我 们想要调用的时候才会执行。

#### 原理

**分析：** 🔥他们改变的this指向的原理：

- 其实就是通过在 某个对象上添加这样一个方法，
- 然后拿到参数，再去调用这个对象的这个方法(`符合this指向调用者。`) 。 
- 得到结果后，再在这个对象上删去这个属性方法。
- 最后返回结果。(想一想，其实很简单是不是)



#### 实现

##### call

- 首先 context 为可选参数，如果不传的话默认上下文为 window ；
-  接下来给 context 创建一个 fn 属性，并将值设置为需要调用的函数； 
- 因为 call 可以传入多个参数作为调用函数的参数，所以需要将参数剥离出来；
-  然后调用函数并将对象上的函数删除。

```js
// this 为调用的函数
// context 是参数对象
Function.prototype._Call = function (context) {
    // 判断调用者是否为函数
    if (typeof this !== 'function') {
        throw new TypeError('Error')
    }
    // 不传参默认为 window
    context = context || window
    // 新增 fn 属性,将值设置为需要调用的函数
    context.fn = this
    // 将 arguments 转化为数组将 call 的传参提取出来 [...arguments]
    const args = Array.from(arguments).slice(1)
    // 传参调用函数
    const result = context.fn(...args)
    // 删除函数
    delete context.fn
    // 返回执行结果
    return result;
}
// 普通函数
function test(age) {
    console.log(this.name + " " + age);
}
// 自定义对象
var obj = {
    name: 'PJ'
}
// 调用函数的 _Call 方法
test._Call(obj, 22)
```



##### apply

- 首先 context 为可选参数，
- 如果不传的话默认上下文为 window 接下来给 context 创建一个 fn 属性，并将值设置为需要调用的函数 
- 因为 apply 传参是数组传参，所以取得数组，将其剥离为顺序参数进行函数调用 
- 然后调用函数并将对象上的函数删除

```js
// 手写一个 apply 方法
Function.prototype._Apply = function (context) {
    // 判断调用者是否为函数
    if (typeof this !== 'function') {
        throw new TypeError('Error')
    }
    // 不传参默认为 window
    context = context || window
    // 新增 fn 属性,将值设置为需要调用的函数
    context.fn = this
    // 返回执行结果
    let result;
    // 判断是否有参数传入
    if (arguments[1]) {
        result = context.fn(...arguments[1])
    } else {
        result = context.fn()
    }
    // 删除函数
    delete context.fn
    // 返回执行结果
    return result;
}
// 普通函数
function test(age, age2, age3) {
    console.log(this.name + " " + age + " " + age2 + " " + age3);
}
// 自定义对象
var obj = {
    name: 'PJ'
}
// 调用函数的 call 方法
test._Apply(obj, [18, 22, 39])
```



##### bind

- 判断调用者是否为函数。 
- 截取参数，注意：这里有两种形式传参。 
- 返回一个函数，判断外部哪种方式调用了该函数（new | 直接调用）

 

```js
// 手写一个 bind 函数
Function.prototype._bind = function (context) {
    // 判断调用者是否为函数
    if (typeof this !== 'function') {
        throw new TypeError('Error')
    }
    // 截取传递的参数
    const args = Array.from(arguments).slice(1)
    // _this 指向调用的函数
    const _this = this;
    // 返回一个函数
    return function F() {
        // 因为返回了一个函数，我们可以 new F()，所以需要判断
        // 对于 new 的情况来说，不会被任何方式改变 this
        if (this instanceof F) {
            return new _this(...args, ...arguments)
        } else {
            return _this.apply(context, args.concat(...arguments))
        }
    }
}
// 普通函数
function test() {
    // new 的方式调用 bind 参数输出换做 [...arguments]
    console.log(this.name);
}
// 自定义对象
var obj = {
    name: 'PJ'
}
// 调用函数的 call 方法
let F = test._bind(obj, 1, 2, 3);
F();
// 返回对象
let obj1 = new F();


```

--------

**总结:其实只要知道原理思路了，手写一下call和apply是不是很简单。bind只要注意一下new的情况就好啦**