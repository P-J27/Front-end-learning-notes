#### let 

let 关键字用来声明变量，使用 let 声明的变量有几个特点：

1. `不允许重复声明`；
2. `块儿级作用域（局部变量）`；
3. `不存在变量提升`；
4. `不影响作用域链`；


#### const

const 关键字用来声明 **常量** ，const 声明有以下特点：

1. `声明必须赋初始值`·；
2. `标识符一般为大写（习惯`）；
3. `不允许重复声明`；
4. `值不允许修改`；
5. `块儿级作用域（局部变量）`；

`注:`当常量为对象时，`值不允许修改`含义是指向的对象不能修改，但是可以改变对象内部的属性


##### 

#### var、let和const的区别

1. var定义的变量，函数作用域，没有块的概念，可以`跨块访问`, `不能跨函数访问.` `并不是全局作用域`

2. let定义的变量，块级作用域，只能在块作用域里访问，不能跨块访问，也不能跨函数访问。

3. const用来定义常量，使用时`必须初始化`(即必须赋值)，只能在块作用域里访问，而且不能修改。

4. var声明的变量存在`变量提升现象`，let和const声明的变量不存在变量提升现象（遵循：“先声明，后使用”的原则，否则会报错）。

5. var不存在暂时性死区，let和const存在暂时性死区，所以let和const声明前不可访问

    解析：只要块级作用域内存在let命令，那么它所声明的变量就会绑定到这个区域，不再受外部的影响。

6. var允许重复声明同一个变量，let和const在同一作用域下不允许重复声明同一个变量。

   解析：var允许重复声明变量，后一个变量会覆盖前一个变量，const和let会报错。