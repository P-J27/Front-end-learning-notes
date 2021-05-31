##### 前言

> 本文对ES5新加的一些方法的使用做个简单演示

##### 1.`forEach()` ：

 `arr.forEach(function(vlaue, index, [array]))` 分别对应数组的value（值）、index（索引号）、数组本身

遍历数组的全部元素，即使return true也不会终止迭代，因为forEach本质是一个函数，参数是一个回调函数，回调函数的return只是终止了回调函数而已，不是终止forEach，而forEach内部应该是多次调用了那个函数

```js
   var arr = [1, 2, 3];
        var s = 0;
        arr.forEach(function (value, index, arr) {
            s += value;
        })
        console.log(s);
```

##### 2.`filter()`: 

filter() 方法创建一个新数组，新数组中的元素是通过检查指定数组中符合条件的所有元素，主**要用于筛选数组**（注意它直接**返回一个新数组**）

`array.filter(function(currentValue, index, [arr]))` 分别对应currentValue（数组当前项的值），index（索引号），arr（数组本身），它的回调函数返回的必须是一个Boolean值，返回true自动将value加入新数组中，false则过滤掉，最后整体返回一个新数组


```js
var newArr = arr.filter(function(value, index) {
    return value >= 20;
})
```

##### 3.`some()` ：

some()方法用于检测数组中的元素是否 **存在** 满足指定条件，通俗点就是查找数组中是否有满足条件的元素，**找到第一个满足条件的元素则停止**

（注意它**返回的是布尔值**）在`some`里设置`return true` 以终止遍历

`array.some(function(currentValue, index, [arr]))` 分别对应currentValue（数组当前项的值），index（索引号），arr（数组本身）

```js
    var arr = ['pink', 'red', 'green'];
        var flag=arr.some(function (value, index, arr) {
           return value == 'pink';
        })
        console.log(flag);
```

##### 4.`map()` 

方法返回一个新数组，数组中的元素为原始数组元素调用函数处理后的值。和forEach相似，不同在于：

 如果更改数组内的值，`forEach` 不能确保数组的不变性。这个方法只有在你不接触里面的任何值时，才能保证不变性。由于它们之间的主要区别在于是否有返回值

`map会制作一个新的数组，而forEach只会映射到原数组，所以可能改变原数组的值。`

```js
let newarr = arr.map(function(value, index) {
    return value * 2;
})
```

**map的不变性：当数组为基础类型时原数组不变**

```js
let array=[1,2,3,4,5]
let newArray=array.map((item) => item*2)
console.log(array); // [1,2,3,4,5]
console.log(newArray);//[2, 4, 6, 8, 10]
```

**当数组为引用类型时原数组发生改变：** `map是浅拷贝`

```js
let array = [{ name: 'Anna', age: 16 }, { name: 'James', age: 18 }]
let newArray=array.map((item) => {
    item.like='eat';
    return item;
})
console.log(array); // [{ name: 'Anna', age: 16,like: "eat"},{ name: 'James', age: 18,like: "eat"}]
console.log(newArray);//[{ name: 'Anna', age: 16,like: "eat"},{ name: 'James', age: 18,like: "eat"}]
```

##### 5.`every()` 

方法用于检测数组**所有元素是否都符合**指定条件

##### 6.reduce

`arr.reduce(callback(accumulator, currentValue[, index[, array]])[, initialValue])`

参数分别对应回调函数(callback)和初始值(initialValue)对数组中所有内容进行汇总,有点像递归

```js
let total = a.reduce(function (preValue, currValue) {
  return preValue + currValue;
}, 0);
//第二个参数0，是作为初始化，为第一次回调函数的prevalue
// 遍历到第一次时，preValue为初始值，currValue为数组里的第一个值
// 遍历到第二次时，preValue为第一次返回的值，currValue为数组里第二个数
```

**以上ES5数组方法有助于链式编程（函数式编程）**，比如：

```js
//this.$store.state.cartList 是一个数组
this.$store.state.cartList
    .filter((item) => item.checked === true)
    .reduce((preValue, item) => {
    return preValue + item.count * item.price;
}, 0)
    .toFixed(2);
```



##### forEach、some和filter区别

```js
  var arr = ['pink', 'red', 'green'];

        arr.forEach(element => {
            if (element == 'pink') {
                return true; //不会终止迭代
            }

        });
        arr.some(e => {
            if (e == 'pink') {
                return true; //终止迭代，效率更高，适合查找唯一性元素。
            }

        });
        arr.filter(e => {
            if (e == 'pink') {
                return true; //也不会停止迭代
            }
        });
     
```



##### 小案例

###### 需求

- 过滤掉数组中小于100的数
- 将过滤后的数组中所有元素*2
- 乘2后数组中元素的和
- 三种函数链式使用

```js
const app = new Vue({
    el:"#app",
    data:{
      nums:[10,20,111,222,333,444,40,50]
    },
    methods:{
        //规范版
      useOnceCount(){
        let total = this.nums.filter(function (n) {
          return n < 100
        }).map(function (n) {
          return n * 2
        }).reduce(function (preValue,n) {
          return preValue + n
        },0)
        return total
      },
        //箭头函数版
      useOnceRowCount(){
        let total = this.nums.filter(n => n < 100).map(n => n * 2).reduce((preValue,n) => preValue+n)
        return total
      }
    }
  })

```

