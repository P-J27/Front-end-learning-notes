#### 前言

**数组扁平化？**
听起来好像灰常的好大上？真的吗？

![image-20210626221835024](https://gitee.com/p_pj/picgo/raw/master/img/20210626221835.png)

那数组扁平化到底是什么？怎么实现呢？

数组的扁平化处理，其实就是多维数组转化为一维数组。如下，

![image-20210626222104150](https://gitee.com/p_pj/picgo/raw/master/img/20210626222104.png)

那怎么去实现呢？别着急。我们一个一个说。

-----------------

#### **ES6的flat**

```js
ary = arr.flat(Infinity)
console.log([1, [2, 3, [4, 5]]].flat(Infinity))
```

Array.protype.flat()用于将数组“拉平”，变成一维数组，返回一个新数组。flat()默认只会拉平一层，flat（n）拉平n层，Infinity无限次。好用归好用，但效率我们就心里明白，这也是我们面试官最不想听到的答案了。

----

#### **正则处理**

```js
//第一种处理
ary = str.replace(/(\[|\])/g, '');

//第二种处理
str = str.replace(/(\[|\]))/g, '');
str = '[' + str + ']';
ary = JSON.parse(str);

```

----------

#### **递归**

```js
 let arr = [1, [2, [3, 4]]];

 function flattern(arr) {
        let result = [];
        for(let i = 0; i < arr.length; i++) {
            if(Array.isArray(arr[i])) {
                flattern(arr[i])
            } else {
                result.push(arr[i])
            }
        }
        return result;
    }
console.log(flattern(arr));
```

这也是我当时面试想到最简单的解决方案，思路很简单，通过遍历最外层数组的每一个元素，看看是否还是数组，如果是的话，继续递归执行，不是的话，放到最后的结果数组当中

-------------

#### reduce

```js
let arr = [1, [2, [3, 4]]];
function flatten(arr) {
    return arr.reduce(function(prev, next){
        return prev.concat(Array.isArray(next) ? flatten(next) : next)
    }, [])
}
console.log(flatten(arr))

//reduce搭配扩展运算符
const flatten = (array) => array.reduce((acc,cur)=>
    (Array.isArray(cur)?[...acc,...flatten(cur)]:[...acc,cur]),[])
```

提到数组的方法，就会联想到非常常用的2个高阶函数map和reduce。其实思路上和上面递归的很相似。

------------

#### ES6扩展运算符...

```js
const arr = [1,2,[3,4,5,[6,7],8],9,10,[11,[12,13]]];
const flatten = (arr) => {
    while(arr.some(item=>Array.isArray(item))){
        arr=[].concat(...arr);
    }
    return arr;
}
console.log(flatten(arr)); // [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]
```

由于扩展运算符一次只能展开一层数组

```js
var arr = [1, [2, [3, 4]]];
console.log([].concat(...arr)); // [1, 2, [3, 4]]
```

因此考虑只要数组中还有数组，就使用扩展运算符展开一次。

----------

#### toString

```js
function flatten(arr){
    
    //arr.join(',').split(',');  join也可以实现  
    return arr.toString().split(',').map(function(item){ 
        return +item;  //+将字符转换为数字 
	})
}
```

如果数组的元素都是数字，可以考虑使用 toString 方法，因为：toString会将数组中的数以逗号形式结合起来。toString之后再split转成数组，并将其转换回数字。所以这种场景只适用于数组内全部是数字的情况，因为中间是全部转换为字符串了。

