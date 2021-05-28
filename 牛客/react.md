### 1. 谈谈对react的理解

参考答案：

React 是一个用于构建用户界面的 JAVASCRIPT 库。React 主要用于构建 UI，很多人认为 React 是 MVC 中的 V（视图）

React 特点有：

声明式设计 −React 采用声明范式，可以轻松描述应用。

高效 −React 通过对 DOM 的模拟，最大限度地减少与 DOM 的交互。灵活 −React 可以与已知的库或框架很好地配合。

JSX − JSX 是 JavaScript 语法的扩展。React 开发不一定使用 JSX ，但我们建议使用它。

组件 − 通过 React 构建组件，使得代码更加容易得到复用，能够很好的应用在大项目的开发中。

单向响应的数据流 − React 实现了单向响应的数据流，从而减少了重复代码， 这也是它为什么比传统数据绑定更简单。



### 2. React 单项数据流是什么？

 

参考答案：

在 React 中，数据是单向流动的，是从上向下的方向，即从父组件到子组件的方向。

state 和 props 是其中重要的概念，如果顶层组件初始化 props，那么 React 会向下遍历整颗组件树，重新渲染相关的子组件。其中 state 表示的是每个组件中内部的的状态，这些状态只在组件内部改变。

把组件看成是一个函数，那么他接受 props 作为参数，内部由 state 作为函数的内部参数，返回一个虚拟 dom 的实现。

 

 

### 3. react 生命周期函数和 react 组件的生命周期的区别？

 

参考答案：



React 的组件在第一次挂在的时候首先获取父组件传递的 props，接着获取初始的 state 值 ， 接 着 经 历 挂 载 阶 段 的 三 个 生 命 周 期 函 数 ， 也 就 是ComponentWillMount，render，ComponentDidMount，这三个函数分别代表组件将会挂载，组件渲染，组件挂载完毕三个阶段，在组件挂载完成后，组件的 props 和state 的任意改变都会导致组建进入更新状态，在组件更新阶段，如果是 props 改 变 ， 则 进 入 ComponentWillReceiveProps 函 数 ， 接 着 进 入ComponentShouldUpdate 进行判断是否需要更新，如果是 state 改变则直接进入ComponentShouldUpdate 判定，这个默认是 true，当判定不需要更新的话，组件继续运行， 需要更新的话则依次进入 ComponentWillMount ， render ， ComponentDidMount 三个函数， 当组件卸载时， 会首先进入生命周期函数ComponentWillUnmount,之后才进行卸载，如图

 



![img](../../../AppData/Local/Temp/msohtmlclip1/01/clip_image003.jpg)

 

React 的生命周期函数：

 

 

初始化阶段：

getDefaultProps 获取实例的默认属性， getInitialState 获取每个实例的初始化状态，

ComponentWillMount：组件将被装载，渲染到页面上，render：组件在这里生成虚拟的 DOM 节点，

ComponentDidMount:组件真正被装载之后

 

 

运行中状态：

componentWillReceiveProps:组件将要接收到属性的时候调用shouldComponentUpdate: 组件接受到新属性或者新状态的时候（ 可以返回false，接收数据后不更新，阻止 render 调用，后面的函数不会被继续执行了） shouldComponentUpdate 这个方法用来判断是否需要调用 render 方法重新描绘 dom。因为 dom 的描绘非常消耗性能，如果我们能在shouldComponentUpdate 方法中能够写出更优化的 dom diff 算法，可以极大的





提高性能。

componentWillUpdate:组件即将更新不能修改属性和状态 render:组件重新描绘

componentDidUpdate:组件已经更新

销毁阶段： componentWillUnmount:组件即将销毁

 



### 4. react 和 Vue 的原理，区别，亮点，作用

 

参考答案：

曾经看过 vue 作者尤雨溪的一个专访，他说过这样一段话(大概内容)：做框架的时候我们也很纠结，到底是定制内容少一点好还是定制内容多一点好。定制少了， 很多人不知道一些情况应该怎么处理，所以他就乱来，写的代码乱七八糟，性能也不好，然后他就会认为你的框架没做好，有的人还去网上喷你。但是当大家经验越来越丰富，反而希望受到框架的限制越少越好。因为随着经验的增加，大家都知道了各种场景下应该怎么处理，优化自己的代码。限制越少，自我发挥的空间就越大。

最终我们可以看到，纠结之后，vue 的选择居于 react 与 angular 之间，框架自身的语法比 react 多一点，但是又比 angular 少一点。

 

也正是由于选择的不同，所呈现出来的写法与思考方式就一定会有所差异，不论优劣，但肯定会导致不同的偏好。

 

react 的简单在于，它的核心 API 其实非常少。所以我们会看到很多地方在说react 其实是一个 UI 库，并不是一个完整的框架。他只是告诉我们如何创建组件以及组件之间如何进行数据传递。甚至于创建组件的方式正是使用 ES6 的class 语法(createClass 将会在 react 16 被丢弃)。



因此开发中 react 的使用对于 ES6 的语法依赖非常高。因为 react 自身本来就没有多少强限制的语法。我们只需要掌握组件里的 props，state，ref，生命周期， 就好像没有过多额外的知识了。就连如果想要在 jsx 模板来遍历渲染，还得使用原生的 map 方法。而 react 的高阶组件，理解之后发现，其实就是 JavaScript 函数式编程中所涉及到的思维方式。

 

所以在我看来，react 的最大特点就是简单并且与原生 JavaScript 非常接近。即给开发者带来的束缚非常少。一个功能的实现， 如果你知道使用原生JavaScript 如何实现，那么你就一定能够很轻松的知道使用 react 如何实现。

 

当然，核心 API 简单并不代表上手容易。在使用之初，如果你经验缺乏，那么你用 react 写出来的页面，性能可能会非常差。因为无意识的，你的组件可能会有非常多的多余的渲染。

 

比如很多人在学习 react 的时候，会接触到一个倒计时的例子，这个例子使用修改组件中 state 的方式来实现。但是其实后来大家会慢慢知道，这种方式是非常错误的。因为 state 的每次修改，都会导致组件及其所有子组件的重新渲染。这是成本非常高的行为。当然，我还知道很多人，在调试 react 的时候，由于高频的重复渲染直接把浏览器都卡死的。这些问题都是尤雨溪所担心的限制过少带来的。

 

网上有的自以为牛逼的人，用着 react/vue 这样的框架，其实写着很烂的代码， 恐怖的是他们还嘲讽这嘲讽那的。还遇到过一个人， 口口声声说自己用了angular 好多年，说 angular 真的好垃圾啊，性能好差啊，什么什么的各种黑， 结果连 track by 都不会用。而 react 由于没有真正意义上的双向绑定。因此在处理一些复杂场景会非常麻烦，比如复杂的表单验证。





而相对而言，vue 提供的能力则更多一点，这些便捷的能力会让初学者感觉到非常的幸福，因为很多效果只需要一些简单的代码既可以实现。我大概列举几条我个人认为非常棒的能力：

 

统一管理的计算属性

 

 

JavaScript 的表达式非常便利，无论是 vue 还是 react，表达式的能力是必不可少的。但正如 vue 官方文档所说，在模板中放入太多的逻辑会让模板过重且难以维护。而 vue 的组件中提供了一个计算属性来统一管理表达式。

 

```html
<template>

<div id="example">

<p>Original message: "{{ message }}"</p>

<p>Computed reversed message: "{{ reversedMessage }}"</p>

</div>

</template>

<script>

export default { name: 'example', data () {

return { message: 'Hello'

}

},

computed: {

reversedMessage: function() {



return this.message.split('').reverse().join('')

}

}

}

</script>
```

class 的动态语法让我感觉非常爽

 

 

在实践中我们会发现非常多这样的场景，需要根据不同的状态来决定一个元素class 的具体值。而如果仅仅只是简单的表达式或者条件判断在 jsx 模板中，例如下面这个样子就会让人感觉非常难受

 

<p className={active ? 'note active' : 'note'}></p>

当稍微复杂一点的逻辑还这样处理就是难受到忍不了了。而 vue 中支持的语法则非常轻松的搞定了这个问题。

 

```js


// 可以放在任何你觉得舒服的位置
const pcls = {

active: active, note: true

}
```



<p class={pcls}></p>

这样我们继续添加更多的 class 名也不会造成额外的复杂度了。

当然，这仅仅只是一个工具方法就能搞定的问题，在使用 react 时，大家可以借助 classnames 来完成同样的功能。但 vue 是直接支持了。

 

双向绑定



> 由于 react 并不支持双向绑定，因此在复杂的表单验证时实现起来非常痛苦。而vue 在以单向数据流为核心的同时，又没有完全抛弃双向绑定，这让在这样复杂的表单验证场景开发效率比 react 高出非常多。这也是 vue 省事儿的一个方面。

 

修饰符

> 我们在写事件处理逻辑时，常常需要 e.preventDefault 等操作。vue 提供的修饰符功能可以帮助我们省去这些代码，极为方便。用多了就会发现，真 TM 好用。

```html
<!-- 阻止单击事件冒泡 -->

<a v-on:click.stop="doThis"></a>

<!-- 提交事件不再重载页面 -->

<form v-on:submit.prevent="onSubmit"></form>

<!-- 修饰符可以串联 -->

<a v-on:click.stop.prevent="doThat"></a>

<!-- 只有修饰符 -->

<form v-on:submit.prevent></form>

<!-- 添加事件侦听器时使用事件捕获模式 -->

<div v-on:click.capture="doThis">...</div>

<!-- 只当事件在该元素本身（而不是子元素）触发时触发回调 -->
```



<div v-on:click.self="doThat">...</div>

当然，还有按键修饰符等，可以去官网进一步查看学习。

 

vue 提供的方便可爱的语法糖还有很多，就不细说，大家可以在官网上一一体验。正如文章开头所说，vue 会有一些语法限制，而这些语法限制在某种程度上来说降低了我们的开发成本，提高了开发效率。这大概也就是很多人认为 vue 更加简



单易学的原因所在吧。



就从学习难易程度上来说，react 之所以上手更加困难，主要的原因并不在于react 本身，而在于围绕 react 的丰富的生态圈。正是由于 react 本身足够简单， 所以我们需要掌握的 react 组件就更多。比如 react-router，react-redux 等。而且很多好用的，功能特别棒的组件在我们涉猎不广的时候都不知道。

 

### 5. reactJs 的组件交流

 

参考答案：

React 组件之间的交流方式可以分为以下三种

（1） 父组件向子组件传值:主要是利用 props 来进行交流

（2）  子组件向父组件传值：子组件通过控制自己的 state 然后告诉父组件的点击状态。然后在父组件中展示出来，如图



|      |                                                              |
| ---- | ------------------------------------------------------------ |
|      | ![img](../../../AppData/Local/Temp/msohtmlclip1/01/clip_image004.jpg) |

（3） 没有任何嵌套关系的组件之间传值：如果组件之间没有任何关系，组件嵌套层次比较深（个人认为 2 层以上已经算深了），或者你为了一些组件能够订阅、写入一些信号，不想让组件之间插入一个组件，让两个组件处于独立的关系。对于事件系统，这里有 2 个基本操作步骤：订阅（subscribe）/监听（listen） 一个事件通知，并发送（send）/触发（trigger）/发布（publish）/发送（dispatch）一个事件通知那些想要的组件。



 

### 6. 有了解过 react 的虚拟 DOM 吗，虚拟 DOM 是怎么对比的呢

 

参考答案：



当然是使用的 diff 算法，diff 算法有三种优化形式：

（1） tree diff：将新旧两颗 DOM 树按照层级遍历，只对同级的 DOM 节点进行比较，即同一父节点下的所有子节点，当发现节点已经不存在，则该节点及其子节点会被完全删除，不会进一步比较

（2） component diff：不同组件之间的对比，如果组件类型相同，暂不更新， 否则删除旧的组件，再创建一个新的组件，插入到删除组件的位置

（3） element diff:在类型相同的组件内，再继续对比组件内部的元素

 

 

 

### 7. 项目里用到了 react，为什么要选择 react，react 有哪些好处

参考答案：

（1） 声明式设计

（2） 高效：通过对 DOM 的模拟，最大限度的减少与 DOM 的交互。

（3） 灵活：可以与已知的框架或库很好的配合。

（4） JSX：是 js 语法的扩展，不一定使用，但建议用。

（5） 组件：构建组件，使代码更容易得到复用，能够很好地应用在大项目的开发中。

（6） 单向响应的数据流：React 实现了单向响应的数据流，从而减少了重复代码，这也是解释了它为什么比传统数据绑定更简单。

 

 

 

 

### 8. 怎么获取真正的 dom

 

参考答案：

ReactDOM.findDOMNode()或 this.refs

 

 

 

### 9.  选择 react 的原因

 

 **React效率极高**

React可以创建存放组件的虚拟DOM（文档对象模型Document Object Model），这一特点为开发人员提供了高度灵活性和惊人的性能收益，因为React能够提前计算出DOM中哪些内容需要更改，并对DOM树做出相应地更新。通过这种方式，React避免了代价高昂的DOM操作，从而大幅提升了工作效率。![DOM](http://ww1.sinaimg.cn/mw690/005NrfBdjw1f9128qif6ij30f206dt8r.jpg)

**Javascript**库

JSX（http://jsx.github.io/）是Javascript和HTML的完美结合，可专门用于ReactJS，大大简化了编写网站组件的流程。React的主要优势是合理地利用了本地API达到了跨平台的效果。

![JSX](http://ww2.sinaimg.cn/mw690/005NrfBdjw1f9128q3p1wj30bh02twem.jpg)

**SEO友好**

JavaScript框架的缺陷之一是对搜索引擎十分不友好，尽管最近已经有所改进。

但是，React.js在这方面却做的很出色。你可以在服务器端运行React.js，虚拟DOM可以像常规的web页面一样返回给浏览器，不需要任何特殊技巧。

**注重用户界面**

与MeteorJS、Firebase、AngularJS不同的是，React Native十分重视用户界面。通过设备本地环境与React Native的Javascript交互，可以给用户提供完美的响应式界面。虽然这一定程度上增加了应用的加载时间，但也保证了程序运行过程中的流畅。

**简单，使用便捷**

如果准备开发React项目，别忘了安装ReactJS的官方Chrome插件，它能使你的调试过程变得更加简单。安装完插件之后，你就可以像在元素面板中浏览一个常规DOM树一样直接查看虚拟DOM。



### 10. react 的生命周期函数

 

参考答案： 初始化

1）getDefaultProps()设置默认的 props，也可以用 dufaultProps 设置组件的默认属性. 

2）getInitialState()在使用 es6 的 class 语法时是没有这个钩子函数的，可以直接在 constructor 中定义 this.state。此时可以访问 this.props

3）componentWillMount()组件初始化时只调用，以后组件更新不调用，整个生命周期只调用一次，此时可

以修改 state。

4）render()react 最重要的步骤，创建虚拟 dom，进行 diff 算法，更新 dom 树都在此进行。此时就不能更改 state 了。

5） componentDidMount()组件渲染之后调用，只调用一次。更新

6） componentWillReceiveProps(nextProps)组件初始化时不调用，组件接受新的 props 时调用。

7）shouldComponentUpdate(nextProps, nextState)react 性能优化非常重要的一环。组件接受新的 state 或者 props 时调用，我们可以设置在此对比前后两个 props 和 state 是否相同，如果相同则返回 false 阻止更新，因为相同的属性状态一定会生成相同的 dom 树，这样就不需要创造新的 dom 树和旧的 dom 树进行 diff 算法对比，节省大量性能，尤其是在 dom 结构复杂的时候

8）componentWillUpdata(nextProps, nextState)组件初始化时不调用，只有在组件将要更新时才调用，此时可以修改 state 

9）render()组件渲染

10）componentDidUpdate()组件初始化时不调用，组件更新完成后调用，此时可以获取 dom 节点。卸载

11）componentWillUnmount()组件将要卸载时调用，一些事件监听和定时器需要在此时清除。



### 11. setState 之后的流程

 

参考答案：

在代码中调用 setState 函数之后，React 会将传入的参数对象与组件当前的状态合并，然后触发所谓的调和过程（Reconciliation）。 经过调和过程，React 会以相对高效的方式根据新的状态构建 React 元素树并且着手重新渲染整个UI 界面。 在 React 得到元素树之后，React 会自动计算出新的树与老树的节点差异，然后根据差异对界面进行最小化重渲染。 在差异计算算法中，React 能够相对精确地知道哪些位置发生了改变以及应该如何改变，这就保证了按需更新，而不是全部重新渲染。

 

 

 

### 12. react 高阶组件知道吗？

 

参考答案：

高阶组件接收 React 组件作为参数，并且返回一个新的 React 组件。高阶组件本质上也是一个函数，并不是一个组件。



### 13. React 的生命周期

 

参考答案：

React 生命周期分为三种状态

​	1. 初始化

2. 更新

3. 销毁

具体见下图：

![img](../../../AppData/Local/Temp/msohtmlclip1/01/clip_image006.jpg)

 

 

 

 

 

### 14. 说说自己理解的 react

 

参考答案：

React 是用于构建用户界面的 JavaScript 库。React 可以创建交互式 UI。为应用程序中的每个状态建立的视图，并且 React 将在数据更改时进行更新，呈现正确的组件。另外，我们也可以构建管理自己状态的封装组件，然后将它们组合成复杂的 UI。因为组件用 JS 编写而不是模板，所以可以通过应用传递数据，并使状态与 DOM 分离

 

 

### 15. react 的组件是通过什么去判断是否刷新的

 

参考答案：

通过 state 是否改变

 

 

 