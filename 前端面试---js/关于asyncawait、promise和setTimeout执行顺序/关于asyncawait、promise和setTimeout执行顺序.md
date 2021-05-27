#### 前言



之前面试遇到这样一个题目。关于async/await、promise和setTimeout的执行顺序，当时没做对。

后来查了查是非常经典的题目。也给大家解疑答惑一下，说出自己的理解。

------------



题目是看代码写结果。

```js
async function async1() {
	console.log('async1 start');
	await async2();
	console.log('asnyc1 end');
}
async function async2() {
	console.log('async2');
}
console.log('script start');
setTimeout(() => {
	console.log('setTimeOut');
}, 0);
async1();
new Promise(function (reslove) {
	console.log('promise1');
	reslove();
}).then(function () {
	console.log('promise2');
})
console.log('script end');
```

大家可以先自己做一做。看和结果对不对，结果再下面公布。



--------

**我们来分析这个题目，要先知道几个概念。**

#### EventLoop 事件循环机制

**JavaScript的事件分两种，宏任务(macro-task)和微任务(micro-task)**

- 宏任务：包括整体代码script，setTimeout，setInterval
- 微任务：Promise.then(非new Promise)，process.nextTick(node中)
- 事件的执行顺序，是先执行宏任务，然后执行微任务，这个是基础，任务可以有同步任务和异步任务，同步的进入主线程，异步的进入Event Table并注册函数，异步事件完成后，会将回调函数放入Event Queue中(宏任务和微任务是不同的Event Queue)，同步任务执行完成后，会从Event Queue中读取事件放入主线程执行，回调函数中可能还会包含不同的任务，因此会循环执行上述操作。
- [具体可以参考EventLoop详解](https://blog.csdn.net/weixin_43745075/article/details/115461936)

`注意`： setTimeOut并不是直接的把你的回掉函数放进上述的异步队列中去，而是在定时器的时间到了之后，把回掉函数放到执行异步队列中去。如果此时这个队列已经有很多任务了，那就排在他们的后面。这也就解释了为什么setTimeOut为什么不能精准的执行的问题了。setTimeOut执行需要满足两个条件：

> 1. 主进程必须是空闲的状态，如果到时间了，主进程不空闲也不会执行你的回掉函数 
> 2. 这个回掉函数需要等到插入异步队列时前面的异步函数都执行完了，才会执行 
>

 上面是比较官方的解释，说一下自己的理解吧：

> 了解了什么是宏任务和微任务，就好理解多了，首先执行 宏任务 => 微任务的Event Queue => 宏任务的Event Queue

#### **promise、async/await**

1. 首先，new Promise是同步的任务，会被放到主进程中去立即执行(当做立即执行函数去理解)。而`then()函数是异步任务会放到异步队列中去`，那什么时候放到异步队列中去呢？当你的promise状态结束(就是执行reject或者resolve)的时候，就会立即放进异步队列中去了。
2. 带async关键字的函数会返回一个promise对象，如果里面没有await，执行起来等同于普通函数；如果没有await，async函数并没有很厉害是不是
3. await 关键字要在 async 关键字函数的内部，await 写在外面会报错；await如同他的语意，就是在等待，等待右侧的表达式完成。此时的`await会让出线程`，`阻塞async内后续的代码，先去执行async外的代码`。等外面的同步代码执行完毕，才会执行里面的后续代码。`就算await的不是promise对象，是一个同步函数`，也会等这样操作

#### await 等待的机制

一般来说，都认为 await 是在等待一个 async 函数完成。准确说，await 等待的是一个表达式，这个表达式的 是 Promise 对象或者其它值 。

因为 async 函数返回一个 Promise 对象，所以 await 可以用于等待一个 async 函数的返回值——这也可以说是 await 在等 async 函数，但要清楚，它等的实际是一个返回值 ，await 后面实际是可以接普通函数调用或者直接量的。

await 等到了它要等的东西，一个 Promise 对象，或者其它值，然后呢？await 是个运算符，用于组成表达式，await 表达式的运算结果取决于它等的东西。

如果它等到的不是一个 Promise 对象，那 await 表达式的运算结果就是它等到的东西。

如果它等到的是一个 Promise 对象，`await 就忙起来了，它会阻塞后面的代码，等着 Promise 对象 resolve，然后得到 resolve 的值，作为 await 表达式的运算结果`。这就是 await 必须用在 async 函数中的原因。async 函数调用不会造成阻塞，它内部所有的阻塞都被封装在一个 Promise 对象中异步执行。

**阮一峰老师的解释我觉得更容易理解**：

> async 函数返回一个 Promise 对象，当函数执行的时候，一旦遇到 await 就会先返回，等到触发的异步操作完成，再接着执行函数体内后面的语句。 可以理解为，是`让出了线程，跳出了async 函数体`





**公布答案了**✨

```js
script start
async1 start
async2
promise1
script end
asnyc1 end
promise2
setTimeOut
```

![image-20210525112101275](https://gitee.com/p_pj/picgo/raw/master/img/20210525112102.png)

**解析来了**

1. 执行console.log('script start')，输出script start；
2. 执行setTimeout，是一个异步动作，放入宏任务异步队列中；
   
3. 执行async1()，输出async1 start，继续向下执行；
   
4. 执行async2()，输出async2，并返回了一个promise对象，await让出了线程，把返回的promise加入了微任务异步队列，await让出线程。后面的代码被堵塞，跳出async1函数。所以async1()下面的代码也要等待上面完成后继续执行;
   
5. 执行 new Promise，输出promise1，然后将resolve放入微任务异步队列；
   
6. 执行console.log('script end')，输出script end；
   
7. 到此同步的代码就都执行完成了，然后去微任务异步队列里去获取任务
   
8. 接下来执行resolve（async2返回的promise返回的），输出了async1 end。
   
9. 然后执行resolve（new Promise的），输出了promise2。
   
10. 最后执行setTimeout，输出了settimeout。

------------

个人理解，欢迎大佬指正。🎉