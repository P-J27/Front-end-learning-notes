####  `$route` 和 `$router` 的区别

`$router` 是VueRouter的实例，在script标签中想要导航到不同的URL,使用 `$router.push` 方法。返回上一个历史history用 `$router.to(-1)`

`$route` 为当前router跳转对象。里面可以获取当前路由的name,path,query,parmas等。

