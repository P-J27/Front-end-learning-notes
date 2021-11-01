#### 简述

- 因为`Vue是响应式`的，所以当数据发生变化时，Vue会自动检测`数据变化`，`视图会发生对应的更新`。

- Vue中包含了一组观察数组编译的方法，使用它们改变数组也会触发视图的更新。

  - 尾部追加：`push() `
  - 尾部删除：`pop()`
  - 首部删除：`shift()`
  - 首部添加：`unshift()`
  - 删除/插入/替换元素：`splice()`
  - 排序：`sort()`
  - 反转数组：`reverse()`

#### `push()`

  ```js
   //1.push方法,最后一位添加元素，响应式,数据改变
  let letters=['A','B','C','D','E']
  letters.push('K')
  ```

#### `pop()`

```js
   //2.pop()删除最后一位元素，响应式，数据改变
  let letters=['A','B','C','D','E']
  letters.pop()
```

#### `shift()`

```js
  //3.shift()删除第一个元素，响应式，数据改变
    let letters=['A','B','C','D','E']
    letters.shift()
```

#### `unshift()`

```js
 //4.unshift()在首位添加元素，响应式，数据改变
  let letters=['A','B','C','D','E']
  letters.unshift('K')
```

#### `splice()`

```js
  //5.splice作用：删除元素/插入元素/替换元素
    let letters=['A','B','C','D','E']
   
    //start起点，length长度，...arg可变数组
    //删除
    letters.splice(start)//从下标start及其后全部删除
	letters.splice(start,length)//下标start开始，长度为length
	//替换
	letters.splice(start,1,'K')//letters[start]='K',本质是先删除下标给start的，在插入'K'
	//插入
	letters.splice(start,0,'K','F'[,'G'[,..]])//在start后面插入任意个数的元素。
	letters.splice(start,0,...['s','q','y'])//插入数组可以用扩展服将数组转为序列
```

#### `sort()`

```js
  //排序，从小到大，响应式
    let letters=['A','B','C','D','E']
    letters.sort()
```

使用 sort() 方法时，应该注意下面几个问题。

-  所谓的字母顺序，实际上是根据字母在字符编码表中的顺序进行排列的，每个字符在字符表中都有一个唯一的编号。
- 如果元素不是字符串，则 sort() 方法试图把数组元素都转换成字符串，以便进行比较。
- sort() 方法将根据元素值进行逐位比较，而不是根据字符串的个数进行排序。在排序时，首先比较每个元素的第 1 个字符，在第 1 个字符相同的情况下，再比较第 2 个字符，以此类推。

```js
var a = ["aba","baa","aab"];  
a.sort();  //按字母顺序对元素进行排序console.log(a);  
//返回数组[aab,aba,baa]
```

- 在任何情况下，数组中 undefined 的元素都被排序在末尾。

- 可以自定义排序规则

  ```js
     let letters = [8,94,64,1,-5]
     letters.sort(function (a, b) {
          return a - b; //如果a>b 即返回一个正数，b就会排在a前面,即升序排法，
     });
     console.log(letters)
  //具体还是要按照实际需求来写函数
  ```

  

  

#### 示例1

#### `reverse()`

```js
 //反序，响应式
   let letters=['A','B','C','D','E']
   letters.reverse()
```

#### 不响应的情况

- 通过索引值直接修改数据，数据虽然被修改，但页面不会更新，因为vue里面没有对其监听。

```js
let letters=['A','B','C','D','E']
letters[0] = 'K'
```

##### 解决方案1(splice)`推荐`

```js
letters.splice(0,1,'K')
```

##### 解决方法2(Vue.set)

```js
Vue.set(letters,0,'K')
```





