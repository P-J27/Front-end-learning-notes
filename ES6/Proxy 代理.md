## 什么是 Proxy？

[MDN](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Proxy) 上是这么描述的——`Proxy`对象用于定义基本操作的自定义行为（如属性查找，赋值，枚举，函数调用等）。

官方的描述总是言简意赅，以至于不明觉厉...

其实就是在对目标对象的操作之前提供了拦截，可以对外界的操作进行过滤和改写，修改某些操作的默认行为，这样我们可以不直接操作对象本身，而是通过操作对象的**代理对象**来间接来操作对象，达到预期的目的~

什么？还没表述清楚？下面我们看个例子，就一目了然了~

```js
    let obj = {
    	a : 1
    }
    let proxyObj = new Proxy(obj,{
        get : function (target,prop) {
            return prop in target ? target[prop] : 0
        },
        set : function (target,prop,value) {
            target[prop] = 888;
        }
    })
    
    console.log(proxyObj.a);        // 1
    console.log(proxyObj.b);        // 0

    proxyObj.a = 666;
    console.log(proxyObj.a)         // 888

```

上述例子中，我们事先定义了一个对象 `obj` , 通过 `Proxy` 构造器生成了一个 `proxyObj` 对象，并对其的 `set`(写入) 和 `get` (读取) 行为重新做了修改。

当我们访问对象内原本存在的属性时，会返回原有属性内对应的值，如果试图访问一个不存在的属性时，会返回`0` ，即我们访问 `proxyObj.a` 时，原本对象中有 `a` 属性，因此会返回 `1` ，当我们试图访问对象中不存在的 `b` 属性时，不会再返回 `undefined` ，而是返回了 `0` ，当我们试图去设置新的属性值的时候，总是会返回 `888` ，因此，即便我们对 `proxyObj.a` 赋值为 `666` ，但是并不会生效，依旧会返回 `888`!

## 语法

`ES6` 原生提供的 `Proxy` 语法很简单，用法如下：

```js
let proxy = new Proxy(target, handler);
```

参数 `target` 是用 `Proxy` 包装的目标对象（可以是任何类型的对象，包括原生数组，函数，甚至另一个代理）, 参数 `handler` 也是一个对象，其属性是当执行一个操作时定义代理的行为的函数，也就是自定义的行为。

`Proxy` 的基本用法就如同上面这样，不同的是 `handler` 对象的不同，`handler` 可以是空对象 `{}` ，则表示对 `proxy` 操作就是对目标对象 `target` 操作，即：

```js
    let obj = {}
    
    let proxyObj = new Proxy(obj,{})
    
    proxyObj.a = 1;
    proxyObj.fn = function () {
        console.log('it is a function')
    }

    console.log(proxyObj.a); // 1
    console.log(obj.a);      // 1
    console.log(obj.fn())    // it is a function
```

但是要注意的是，`handler` **不能** 设置为 `null` ，会抛出一个错误——`Cannot create proxy with a non-object as target or handler`！

要想 `Proxy` 起作用，我们就不能去操作原来对象的对象，也就是目标对象 `target` （上例是 `obj` 对象 ），必须针对的是 `Proxy` 实例（上例是 `proxyObj` 对象）进行操作，否则达不到预期的效果，以刚开始的例子来看，我们设置 `get` 方法后，试图继续从原对象 `obj` 中读取一个不存在的属性 `b` ， 结果依旧返回 `undefined` ：

```js
    console.log(proxyObj.b);     // 0
    console.log(obj.b);         // undefined
 
```

对于可以设置、但没有设置拦截的操作，则对 `proxy` 对象的处理结果也同样会作用于原来的目标对象 `target` 上，怎么理解呢？还是以刚开始的例子来看，我们重新定义了 `set` 方法，所有的属性设置都返回了 `888` , 并没有对某个特殊的属性（这里指的是 `obj` 的 `a` 属性 ）做特殊的拦截或处理，那么通过 `proxyObj.a = 666` 操作后的结果同样也会作用于原来目标对象（`obj` 对象）上，因此 `obj` 对象的 `a` 的值也将会变为 `888` !

```js
    proxyObj.a = 666;
    console.log( proxyObj.a);   // 888
    console.log( obj.a);        // 888
```



> 面试官：说说 ES6 中的 Proxy 和 getter、setter 的区别？

代理 proxy 是 ES6 新提出的。代理（ proxy ）使我们通过代理控制对另一个对象的访问。 proxy 和 getter 以及 setter 的区别是， getter 和 setter 仅仅控制的是单个对象属性，而 proxy 代理的 是对象交互的通用处理，包括对象的方法。

> 面试官：说说 Proxy 的基本应用？

最基本的应用如下一个： 

- 日志记录 —— 当访问属性时，可以在` get 和 set `中记录访问日志。
-  校验值 —— 有效的避免指定属性类型错误的发生。 
- 定义如何计算属性值 —— 每次访问属性值，都会进行计算属性值。 
- 数据的双向绑定（ Vue ）—— 在 Vue3.0 中将会通过 Proxy 来替换原本的 Object.defineProperty 来实现数据响应式。

## API

`ES6` 中 `Proxy` 目前提供了 13 种可代理操作，下面我对几个比较常用的 `api` 做一些归纳和整理，想要了解其他方法的同学可自行去官网查阅 ：

##### **handler.get(target,property,receiver)**

用于拦截对象的读取属性操作，`target` 是指目标对象，`property` 是被获取的属性名 ， `receiver` 是 `Proxy` 或者继承 `Proxy` 的对象，一般情况下就是 `Proxy` 实例。

```js
let proxy = new Proxy({},{
    get : function (target,prop) {
        console.log(`get ${prop}`);
        return 10;
    }
})
    
console.log(proxy.a)    // get a
                        // 10
 
```

我们拦截了一个空对象的 读取`get`操作， 当获取其内部的属性是，会输出 `get ${prop}` ， 并返回 10 ；

```js
let proxy = new Proxy({},{
    get : function (target,prop,receiver) {
            return receiver;
        }
    })

console.log(proxy.a)    // Proxy{}
console.log(proxy.a === proxy)  //true
 
```

上述 `proxy` 对象的 `a` 属性是由 `proxy` 对象提供的，所以 `receiver` 指向 `proxy` 对象，因此 `proxy.a === proxy` 返回的是 `true`。

要注意，如果要访问的目标属性是不可写以及不可配置的，则返回的值必须与该目标属性的值相同，也就是不能对其进行修改，否则会抛出异常~

```js
let obj = {};
Object.defineProperty(obj, "a", {
	configurable: false,
	enumerable: false,
	value: 10,
	writable: false
});

let proxy = new Proxy(obj,{
    get : function (target,prop) {
        return 20;
    }
})

console.log(proxy.a)    // Uncaught TypeError

 
```

上述 `obj` 对象中的 `a` 属性不可写，不可配置，我们通过 `Proxy` 创建了一个 `proxy` 的实例，并拦截了它的 `get` 操作，当我们输出 `proxy.a` 时会抛出异常，此时，如果我们将 `get` 方法的返回值修改跟目标属性的值相同时，也就是 10 ， 就可以消除异常~

#### **handler.set(target, property, value, receiver)**

用于拦截设置属性值的操作，参数于 `get` 方法相比，多了一个 `value` ，即要设置的属性值~

在**严格模式**下，`set`方法需要返回一个布尔值，返回 `true` 代表此次设置属性成功了，如果返回`false`且设置属性操作失败，并且会抛出一个`TypeError`。

```js
let proxy = new Proxy({},{
    set : function (target,prop,value) {
        if( prop === 'count' ){
            if( typeof value === 'number'){
                console.log('success')
            	target[prop] = value;
            }else{
            	throw new Error('The variable is not an integer')
            }
        }
    }
})
    
 proxy.count = '10';    // The variable is not an integer
 
 proxy.count = 10;      // success
 
```

上述我们通过修改 `set`方法，对 目标对象中的 `count` 属性赋值做了限制，我们要求 `count` 属性赋值必须是一个 `number` 类型的数据，如果不是，就返回一个错误 `The variable is not an integer`，我们第一次为 `count` 赋值字符串 `'10'` ， 抛出异常，第二次赋值为数字 `10` ， 打印成功，因此，我们可以用 `set` 方法来做一些数据校验！

同样，如果目标属性是不可写及不可配置的，则不能改变它的值，即赋值无效，如下：

```js
let obj = {};
Object.defineProperty(obj, "count", {
    configurable: false,
    enumerable: false,
    value: 10,
    writable: false
});

let proxy = new Proxy(obj,{
    set : function (target,prop,value) {
        target[prop] = 20;
    }
})

proxy.count = 20 ;
console.log(proxy.count)   // 10
 
```

上述 `obj` 对象中的 `count` 属性，我们设置它不可被修改，并且默认值，我们给定为 `10` ，那么即使给其赋值为 `20` ，结果仍旧没有变化！

#### **handler.apply(target, thisArg, argumentsList)**

用于拦截函数的调用，共有三个参数，分别是目标对象（函数）`target`，被调用时的上下文对象 `thisArg` 以及被调用时的参数数组 `argumentsList`，该方法可以返回任何值。

`target` 必须是是一个函数对象，否则将抛出一个`TypeError`；

```js
function sum(a, b) {
	return a + b;
}

const handler = {
    apply: function(target, thisArg, argumentsList) {
    	console.log(`Calculate sum: ${argumentsList}`); 
    	return target(argumentsList[0], argumentsList[1]) * 2;
    }
};

let proxy = new Proxy(sum, handler);

console.log(sum(1, 2));     // 3
console.log(proxy(1, 2));   // Calculate sum：1,2
                            // 6
 
```

实际上，`apply` 还会拦截目标对象的 `Function.prototype.apply()` 和 `Function.prototype.call()`，以及 `Reflect.apply()` 操作，如下：

```js
console.log(proxy.call(null, 3, 4));    // Calculate sum：3,4
                                        // 14

console.log(Reflect.apply(proxy, null, [5, 6]));    // Calculate sum: 5,6
                                                    // 22
 
```

#### **handler.construct(target, argumentsList, newTarget)**

`construct` 用于拦截 `new` 操作符，为了使 `new` 操作符在生成的 `Proxy`对象上生效，用于初始化代理的目标对象自身必须具有`[[Construct]]`内部方法；它接收三个参数，目标对象 `target` ，构造函数参数列表 `argumentsList` 以及最初实例对象时，`new` 命令作用的构造函数，即下面例子中的 `p`。

```js
let p = new Proxy(function() {}, {
    construct: function(target, argumentsList, newTarget) {
    	console.log(newTarget === p );                          // true
    	console.log('called: ' + argumentsList.join(', '));     // called：1,2
    	return { value: ( argumentsList[0] + argumentsList[1] )* 10 };
    }
});

console.log(new p(1,2).value);      // 30
 
```

另外，该方法必须返回一个对象，否则会抛出异常！

```js
var p = new Proxy(function() {}, {
    construct: function(target, argumentsList, newTarget) {
    	return 2
    }
});

console.log(new p(1,2));    // Uncaught TypeError
 
```

#### **handler.has(target,prop)**

`has`方法可以看作是针对 `in` 操作的钩子，当我们判断对象是否具有某个属性时，这个方法会生效，典型的操作就是 `in` ,改方法接收两个参数 目标对象 `target` 和 要检查的属性 `prop`，并返回一个 `boolean` 值。

```js
let p = new Proxy({}, {
    has: function(target, prop) {
    	if( prop[0] === '_' ) {
    		console.log('it is a private property')
    		return false;
    	}
    	return true;
    }
});

console.log('a' in p);      // true
console.log('_a' in p )     // it is a private property
                            // false

```

上述例子中，我们用 `has` 方法隐藏了属性以下划线`_`开头的私有属性，这样在判断时候就会返回 `false`，从而不会被 `in` 运算符发现~

要注意，如果目标对象的某一属性本身不可被配置，则该属性不能够被代理隐藏，如果目标对象为不可扩展对象，则该对象的属性不能够被代理隐藏，否则将会抛出 `TypeError`。

```js
let obj = { a : 1 };

Object.preventExtensions(obj); // 让一个对象变的不可扩展，也就是永远不能再添加新的属性

let p = new Proxy(obj, {
	has: function(target, prop) {
		return false;
	}
});

console.log('a' in p); // TypeError is thrown
```

## 数据绑定

上面介绍了这么多，也算是对 `Proxy` 又来一个初步的了解，那么我们就可以利用 `Proxy` 手动实现一个极其简单数据的双向绑定

主要看功能的实现，所以布局方面我就随手一挥了~

页面结构如下：

```html
<!--html-->
<div id="app">
    <h3 id="paragraph"></h3>
    <input type="text" id="input"/>
</div>
 
```

主要还是得看逻辑部分：

```js
//获取段落的节点
const paragraph = document.getElementById('paragraph');
//获取输入框节点
const input = document.getElementById('input');
    
//需要代理的数据对象
const data = {
	text: 'hello world'
}

const handler = {
	//监控 data 中的 text 属性变化
	set: function (target, prop, value) {
    	if ( prop === 'text' ) {
                //更新值
                target[prop] = value;
                //更新视图
                paragraph.innerHTML = value;
                input.value = value;
                return true;
    	} else {
    		return false;
    	}
	}
}

//添加input监听事件
input.addEventListener('input', function (e) {
    myText.text = e.target.value;   //更新 myText 的值
}, false)

//构造 proxy 对象
const myText = new Proxy(data,handler);

//初始化值
myText.text = data.text;    

```

上述我们通过`Proxy` 创建了 `myText` 实例，通过拦截 `myText` 中 `text` 属性 `set` 方法，来更新视图变化，实现了一个极为简单的 双向数据绑定~

## 总结

说了这么多 ， `Proxy` 总算是入门了，虽然它的语法很简单，但是要想实际发挥出它的价值，可不是件容易的事，再加上其本身的 `Proxy` 的兼容性方面的问题，所以我们实际应用开发中使用的场景的并不是很多，但不代表它不实用，在我看来，可以利用它进行数据的二次处理、可以进行数据合法性的校验，甚至还可以进行函数的代理等等...

