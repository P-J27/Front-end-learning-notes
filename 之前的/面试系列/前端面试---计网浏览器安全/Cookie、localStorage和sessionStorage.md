---
theme: channing-cyan
highlight: agate
---


![image.png](https://gitee.com/p_pj/picgo/raw/master/img/20210605214855.png)

--------------------------




#### **Cookie 介绍** 

由于 HTTP 是无状态的协议，不能保存每一次请求的状态，所以需要给客户端增加 Cookie 来保存客 户端的状态。 Cookie 的作用主要用于	` 用户识别` 和` 状态管理 。`（比如网页常见的记住密码）

**安全性** 

> 在 Cookie 传输和管理的时候，要确保 Cookie 的安全性，不被窃取。 

- **Secure** ：仅在 HTTPS 安全通信时才会发送 Cookie 。
- **HttpOnly** ：使用 Cookie 不能被 Javascript 脚本访问（`防止跨站脚本攻击 XSS 对 Cookie 信 息的窃取`）。 
- **SameSite** ：`防止跨站伪造 CORF 的攻击 `
  - Strict ：浏览器完全禁止第三方请求携带 Cookie。
  - Lax ：只能在 get 方法提交表单 情况或者 a 标签发送 get 请求 的情况下可以携带 Cookie。 
  - None ：默认，请求会自动携带上 Cookie。

#### **webStorage基于HTML5规范**

> HTML5 提供了两种在客户端存储数据的新方法：`localStorage和sessionStorage`，挂载在window对象下。
>
> webStorage是本地存储，数据不是由服务器请求传递的。从而它可以存储大量的数据，而不影响网站的性能。
>
> Web Storage的目的是为了克服由cookie带来的一些限制，当数据需要被严格控制在客户端上时，无须持续地将数据发回服务器。比如客户端需要保存的一些用户行为或数据，或从接口获取的一些短期内不会更新的数据，我们就可以利用Web Storage来存储。



##### **localStorage**:

> 生命周期是永久性的。localStorage存储的数据，即使关闭浏览器，也不会让数据消失，除非主动的去删除数据。如果 想设置失效时间，需自行封装。

##### **sessionStorage** 

> 生命周期是在浏览器相关
>
> - 关闭浏览器或者页面，sessionStorage 就会失效；
> - 页面刷新不会消除数据；
> - 只有在当前页面打开的链接，才可以访sessionStorage的数据，使用window.open打开页面和改变localtion.href方式都可以获 取到sessionStorage内部的数据;

#### **总结：**

|      特性      |                            Cookie                            |                  localStorage                  |                sessionStorage                |
| :------------: | :----------------------------------------------------------: | :--------------------------------------------: | :------------------------------------------: |
|  数据的生命期  | 一般由服务器生成，可设置失效时间。如果在浏览器端生成Cookie，默认是关闭浏览器后失效 |            除非被清除，否则永久保存            | 仅在当前会话下有效，关闭页面或浏览器后被清除 |
|  存放数据大小  |                           4KB左右                            |                   一般为5MB                    |                同localstroage                |
| 与服务器端通信 | 每次都会携带在HTTP头中，发送给服务端。但是使用cookie保存过多数据会带来性能问题 | 仅在客户端（即浏览器）中保存，不和服务器的通信 |                同localstroage                |
