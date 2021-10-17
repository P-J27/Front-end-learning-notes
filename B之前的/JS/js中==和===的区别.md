#### 前言

> 之前学js的时候，也没仔细的研究过==和===两个操作符之间的具体区别，但是本着实事求是的态度，今天上网查了一下他们两个的区别，最后得出的结论是：

```js
`===` 严格相等，会比较两个`值的类型和值`
`==`  抽象相等，比较时，会`先进行类型转换，然后再比较值`
```

然后我就更迷惑了，先类型转换，我擦，怎么转换，左边转换成右边类型还是右边转换成左边类型？



先看几个例子：

```js
console.log([10] == 10);                //true
console.log('10' == 10);                //true
console.log([] == 0);                   //true
console.log(true == 1);                 //true
console.log([] == false);               //true
console.log(![] == false);              //true
console.log('' == 0);                   //true
console.log('' == false);               //true
console.log(null == false);             //false
console.log(!null == true);             //true
console.log(null == undefined);         //true
```

看完这几个例子，我更迷糊了，啥，不是说好先进行类型转换嘛，怎么转换？除了 `null==false`是false外，其他的都是true?但是 `!null==true`却是true?这是为啥？

没辙，越查越迷糊，乖乖去看ECMA的规范吧，看看`标准`是怎么规定的。

#### `===`

- 如果Type(x)和Type(y)不同，返回false
- 如果Type(x)和Type(y)相同
  - 如果Type(x)是Undefined，返回true,即`undefined===undefined ：true`
  - 如果Type(x)是Null，返回true，即`Null===Null：true`
  - 如果Type(x)是String，当且仅当x,y字符序列完全相同（长度相同，每个位置上的字符也相同）时返回true，否则返回false
  - 如果Type(x)是Boolean，如果x,y都是true或x,y都是false返回true，否则返回false
  - 如果Type(x)是Symbol，如果x,y是相同的Symbol值，返回true,否则返回false
  - 如果Type(x)是Number类型
    - 如果x或者y是NaN，返回false
    - 如果x的数字值和y相等，返回true
    - 如果x是+0/-0，y是-0/+0，返回true
    - 其他返回false

#### `==`

- 如果Type(x)和Type(y)相同，返回x===y的结果

- 如果Type(x)和Type(y)不同

  - 如果x是null，y是undefined，返回true, `null==undefined :true`
  - 如果Type(x)是Number，Type(y)是String，返回 x==ToNumber(y) 的结果,
  - 如果Type(x)是Boolean，返回 ToNumber(x)==y 的结果
  - 如果Type(x)是String或Number或Symbol中的一种并且Type(y)是Object，返回 x==ToPrimitive(y) 的结果
  - 其他返回false

  

  > 上面两个片段是ecma262规范中对`===`和`==`计算过程的定义，我摘录过来并做了翻译和整理。可能一时半会有点不好理解，慢慢解释。

  其中涉及到几个es定义的抽象操作：

  - Type(x) : 获取x的类型
  - ToNumber(x) : 将x转换为Number类型
  - ToBoolean(x) : 将x转换为Boolean类型
  - ToString(x) : 将x转换为String类型
  - SameValueNonNumber(x,y) : 计算非数字类型x,y是否相同
  - ToPrimitive(x) : 将x转换为原始值

  #### 

**小总结**：

- **标准相等操作符 ==**
  1. 如果 X 和 Y 类型相同 —— 执行 `===`；
  2. 如果 X 和 Y 一个是 `null` 一个是 `undefined` —— 返回`true`；
  3. 如果一个是 number 类型，则把另一个也强制转换为 number 类型；
  4. 如果一个是对象，则强制转换为原始类型；
  5. 其它情况，返回 `false`。

- **严格相等操作符 ===**
  1. 类型不同 —— 返回`false`；
  2. 类型相同 —— 比较值是否相同（都为 `NaN` 时返回 `false`）；
  3. `-0 === +0` —— 返回`true`。

**非原始类型 [Objects, Arrays]**：不应该使用 `==` 或 `===` 来比较对象和数组等非原始类型。

#### 指导方案

1. 能使用 `==` 时尽量使用 `==`；
2. 知道变量类型时，或者您需要转换变量类型时，使用 `==`；
3. 知道变量类型总比不知道好；
4. 不知道变量类型时不要使用 `==`；
5. 知道变量的类型时，`==` 和 `===` 就是一样的；
6. 当类型不相同时，使用 `===` 是无意义的；
7. 而当类型相同时，使用 `===` 是没必要的；

------

#### 避免使用 `==` 的情况

在没有真正理解 JavaScript 中 `falsy` 值之前，某些情况下应避免使用 `==`。

```js
== 后面是 0 或者 "" 或者 "   "

== 后面是非原始类型

== true  或者  == false
复制代码
```

------

#### 总结

根据我的经验，到目前为止，我编码时总是会知道要处理的变量的类型，如果不知道，我就使用 `typeof` 来判断。4 点建议：

1. 如果您无法知道变量的类型，那么使用 `===` 是唯一合理的选择；
2. 不知道变量的类型可能意味着您不够理解代码，也许您需要重构；
3. 了解变量的类型有助于编写出更好的程序；
4. 如果变量的类型已知，则最好使用 `==`，否则只能使用 `===`。

