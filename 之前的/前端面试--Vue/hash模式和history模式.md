vue-router 中hash模式和history模式。

在vue的路由配置中有mode选项，最直观的区别就是在hash模式下的地址栏里的URL夹杂着‘#’号 ，而history模式下没有。vue默认使用hash。

mode:"hash";
mode:"history";
**hash**
hash模式依靠的是onhashchange()事件去监听location.hash的改变。
比如这个 URL：http://www.aaa.com/#/hello，hash 的值为 #/hello。它的特点在于：hash 虽然出现在 URL 中，但不会被包括在 HTTP 请求中，对后端完全没有影响，因此改变 hash 不会重新加载页面。


**history**
利用了 HTML5 History Interface 中新增的 pushState() 和 replaceState() 方法。（需要特定浏览器支持）

pushState()方法可以改变URL地址且不会发送请求，replaceState()方法可以读取历史记录栈，还可以对浏览器记录进行修改。
这两个方法应用于浏览器的历史记录栈，在当前已有的 back、forward、go 的基础之上，它们提供了对历史记录进行修改的功能。只是当它们执行修改时，虽然改变了当前的 URL，但浏览器不会立即向后端发送请求。

因此可以说，hash 模式和 history 模式都属于浏览器自身的特性，Vue-Router 只是利用了这两个特性（通过调用浏览器提供的接口）来实现前端路由。

**history模式的问题**
通过history api，我们丢掉了丑陋的#，但是它也有个问题：不怕前进，不怕后退，就怕刷新，f5，（如果后端没有准备的话）,因为刷新是实实在在地去请求服务器的。
在hash模式下，前端路由修改的是#中的信息，而浏览器请求时不会将 # 后面的数据发送到后台，所以没有问题。但是在history下，你可以自由的修改path，当刷新时，如果服务器中没有相应的响应或者资源，则会刷新出来404页面。