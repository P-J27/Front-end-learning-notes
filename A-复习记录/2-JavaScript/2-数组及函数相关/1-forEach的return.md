在forEach中用return不会返回，函数会继续执行。

```js
let nums = [1, 2, 3];
nums.forEach((item, index) => {
  return;//无效
})
```

中断方法：

1. 使用try监视代码块，在需要中断的地方抛出异常。
2. 官方推荐方法（替换方法）：用every和some替代forEach函数。every在碰到return false的时候，中止循环。some在碰到return true的时候，中止循环


