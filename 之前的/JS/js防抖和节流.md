# 前言

今天看到阿里有一道面试题就是谈谈**函数节流**和**函数防抖**。 糟了，这可触碰到我的知识盲区了，好像听也没听过这2个东西，痛定思痛，赶紧学习学习。here we go！

![15341407332107](https://gitee.com/p_pj/pig/raw/master/img/165a252b4b69aab5)

# 概念和例子

### 函数防抖(debounce)



> 函数防抖（debounce）：当持续触发事件时，一定时间段内没有再触发事件，事件处理函数才会执行一次，如果设定的时间到来之前，又一次触发了事件，就重新开始延时。如下图，持续触发scroll事件时，并不执行handle函数，当1000毫秒内没有触发scroll事件时，才会延时触发scroll事件。
>
> 归纳：`在事件被触发n秒后再执行回调，如果在这n秒内又被触发，则重新计时。`

我们来看一个🌰（栗子）：

```js
//模拟一段ajax请求
function ajax(content) {
  console.log('ajax request ' + content)
}

let inputa = document.getElementById('unDebounce')

inputa.addEventListener('keyup', function (e) {
    ajax(e.target.value)
})

```

看一下运行结果：



![2018-09-04 09 23 46](https://gitee.com/p_pj/pig/raw/master/img/165a252be5c94d6b.gif)



可以看到，我们只要按下键盘，就会触发这次ajax请求。不仅从资源上来说是很浪费的行为，而且实际应用中，用户也是输出完整的字符后，才会请求。下面我们优化一下：

```js
//模拟一段ajax请求
function ajax(content) {
  console.log('ajax request ' + content)
}

function debounce(fun, delay) {
    return function (args) {
        let that = this
        let _args = args
        clearTimeout(fun.id)
        fun.id = setTimeout(function () {
            fun.call(that, _args)
        }, delay)
    }
}
    
let inputb = document.getElementById('debounce')

let debounceAjax = debounce(ajax, 500)

inputb.addEventListener('keyup', function (e) {
        debounceAjax(e.target.value)
    })
```

看一下运行结果：



![2018-09-04 09 29 50](https://gitee.com/p_pj/pig/raw/master/img/165a252b4b429b56)



可以看到，我们加入了防抖以后，当你在频繁的输入时，并不会发送请求，只有当你在指定间隔内没有输入时，才会执行函数。如果停止输入但是在指定间隔内又输入，会重新触发计时。 再看一个🌰：

```js
let biu = function () {
    console.log('biu biu biu',new Date().Format('HH:mm:ss'))
}

let boom = function () {
    console.log('boom boom boom',new Date().Format('HH:mm:ss'))
}

setInterval(debounce(biu,500),1000)
setInterval(debounce(boom,2000),1000)
```

看一下运行结果：



![2018-09-04 09 32 21](https://gitee.com/p_pj/pig/raw/master/img/165a252b4b809a23)

> 分析：这个🌰就很好的解释了，如果在时间间隔内执行函数，会重新触发计时。biu会在第一次1.5s执行后，每隔1s执行一次，而boom一次也不会执行。因为它的时间间隔是2s，而执行时间是1s，所以每次都会重新触发计时




> **个人理解**： 函数防抖就是法师发技能的时候要读条，技能读条没完再按技能就会重新读条。最后放出的技能是最后一次放出来。



### 函数节流(throttle)

> 函数节流（throttle）：当持续触发事件时，保证一定时间段内只调用一次事件处理函数。节流通俗解释就比如我们水龙头放水，阀门一打开，水哗哗的往下流，秉着勤俭节约的优良传统美德，我们要把水龙头关小点，最好是如我们心意按照一定规律在某个时间间隔内一滴一滴的往下滴。如下图，持续触发scroll事件时，并不立即执行handle函数，每隔1000毫秒才会执行一次handle函数。
>
> 归纳：规定在一个单位时间内，只能触发一次函数。如果这个`单位时间`内触发多次函数，只有`一次生效`。

对于节流，一般有两种方式可以实现，分别是时间戳版和定时器版。

时间戳：

```js
function throttle(func, wait) {
    var previous = 0;
    return function() {
        let now = Date.now();
        let context = this;
        let args = arguments;
        if (now - previous > wait) {
            func.apply(context, args);
            previous = now;
        }
    }
}

```

定时器版:

```js
function throttle(func, wait) {
    let timeout;
    return function() {
        let context = this;
        let args = arguments;
        if (!timeout) {
            timeout = setTimeout(() => {
                timeout = null;
                func.apply(context, args)
            }, wait)
        }

    }
}
```

我们应该可以很容易的发现，其实时间戳版和定时器版的节流函数的区别

- 时间戳版的函数触发是在时间段内开始的时候
- 而定时器版的函数触发是在时间段内结束的时候。

如果我们想要第一次触发是在时间段内开始的时候，但希望最后一次触发有效，即最后一次不管是不是在规定时间内点击的，但也让他在规定时间内触发。

我们来看另外的一个🌰(时间戳+定时器)

```js
  function throttle(fun, delay) {
        let last, deferTimer
        return function (args) {
            let that = this
            let _args = arguments
            let now = +new Date()
            if (last && now < last + delay) {
                clearTimeout(deferTimer)
                deferTimer = setTimeout(function () {
                    last = now
                    fun.apply(that, _args)
                }, delay+last-now)
            }else {
                last = now
                fun.apply(that,_args)
            }
        }
    }

    let throttleAjax = throttle(ajax, 1000)

    let inputc = document.getElementById('throttle')
    inputc.addEventListener('keyup', function(e) {
        throttleAjax(e.target.value)
    })
```

看一下运行结果：



![2018-09-04 09 36 49](https://gitee.com/p_pj/pig/raw/master/img/165a252b4c1a9686)



可以看到，我们在不断输入时，ajax会按照我们设定的时间，每1s执行一次。

结合刚刚biubiubiu的🌰：

```js
    let biubiu = function () {
        console.log('biu biu biu', new Date().Format('HH:mm:ss'))
    }

    setInterval(throttle(biubiu,1000),10)

```



![2018-09-04 09 37 58](https://gitee.com/p_pj/pig/raw/master/img/165a252b46818296)



不管我们设定的执行时间间隔多小，总是1s内只执行一次。

**个人理解** : 函数节流就是fps游戏的射速，`就算一直按着鼠标射击`，也只会在`规定射速内射出子弹。`



# 总结

- 函数防抖和函数节流都是防止某一时间频繁触发，但是这两兄弟之间的原理却不一样。
- 函数防抖是某一段时间内只执行一次，而函数节流是间隔时间执行。
- **「防抖重在清零 `clearTimeout(timer)`」「节流重在开关锁 `now 是否大于last + delay`」**

**最直白的话**： 

- 防抖：就是一定时间内，只会执行最后一次任务； 
  - 原理是维护一个计时器，规定在delay时间后触发函数，但是在delay时间内再次触发的话，就会取消之前的计时器而重新设置。这样一来，只有最后一次操作能被触发。
- 节流：就是一定时间内，只执行一次 ； 
  - 原理是通过判断是否到达一定时间来触发函数。
- 前者就是清除计时器，后者就是等计时器执行完当前任务之后，才会执行下一次任务 ； 
- 所以 scroll 事件 是要用节流方法，而不是防抖。

**区别：** 

> 函数节流不管事件触发有多频繁，都会保证在规定时间内一定会执行一次真正的事件处理函数，而函数防抖只是在最后一次事件后才触发一次函数。 比如在页面的无限加载场景下，我们需要用户在滚动页面时，每隔一段时间发一次 Ajax 请求，而不是在用户停下滚动页面操作时才去请求数据。这样的场景，就适合用节流技术来实现。

### 结合应用场景

- debounce
  - search搜索联想，用户在不断输入值时，用防抖来节约请求资源。
  - window触发resize的时候，不断的调整浏览器窗口大小会不断的触发这个事件，用防抖来让其只触发一次
- throttle
  - 鼠标不断点击触发，mousedown(单位时间内只触发一次)
  - 监听滚动事件，比如是否滑到底部自动加载更多，用throttle来判断





