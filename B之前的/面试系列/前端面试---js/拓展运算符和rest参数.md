#### **前言**

**ES6中的三个点 ... 有两个名字:rest参数和扩展运算符.**

- **当用在函数定义时的形参前面时,称为rest参数,当函数调用时,用于接收不确定的参数.**
- **当与解构赋值组合使用时,称为rest参数,用于接收剩余的值,存储在数组中.**
- **当用在字符串或数组前面时称为扩展运算符,将数组或字符串进行拆解.**

---------------------

#### rest参数

`ES6 引入 rest 参数，用于获取函数的实参，用来代替 arguments`；

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <title>rest参数</title>
</head>
<body>
    <script>
        // ES6 引入 rest 参数，用于获取函数的实参，用来代替 arguments；
        // ES5获取实参的方式
        function data() {
            console.log(arguments);
        data("大哥", "二哥", "三哥", "四哥");
        // ES6的rest参数...args，rest参数必须放在最后面
        function data(...args) {
           // args是一个数组
            console.log(args); // fliter some every map
        }
        data("大哥", "二哥", "三哥", "四哥");
    </script>
</body>

</html>
```

-----

#### 扩展运算符

`... 扩展运算符`，能将`数组转换为逗号分隔的参数序列`；

扩展运算符（spread）也是三个点（...）。它好比` rest 参数的逆运算`，将一个`数组转`为用`逗号分隔的参数序列`，对数组进行`解包`；

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>扩展运算符</title>
</head>

<body>
    <script>
        // ... 扩展运算符能将数组转换为逗号分隔的参数序列
        //声明一个数组 ...
        const tfboys = ['易烊千玺', '王源', '王俊凯'];
        // => '易烊千玺','王源','王俊凯'
        // 声明一个函数
        function chunwan() {
            console.log(arguments);
        }
        chunwan(...tfboys); // chunwan('易烊千玺','王源','王俊凯')
    </script>
</body>

</html
```

```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <title>扩展运算符应用</title>
</head>

<body>
    <div id="d1"></div>
    <div id="d2"></div>
    <script>
        //1. 数组的合并 
        const kuaizi = ['王太利', '肖央'];
        const fenghuang = ['曾毅', '玲花'];
        // 传统的合并方式
        // const zuixuanxiaopingguo = kuaizi.concat(fenghuang);
        const zuixuanxiaopingguo = [...kuaizi, ...fenghuang];
        console.log(zuixuanxiaopingguo);

        //2. 数组的克隆
        const sanzhihua = ['E', 'G', 'M'];
        const sanyecao = [...sanzhihua]; // ['E','G','M']
        console.log(sanyecao);
        
        //3. 将伪数组转为真正的数组
        const divs = document.querySelectorAll('div');
        const divArr = [...divs];
        console.log(divArr); // arguments
    </script>
</body>
</html>
```

