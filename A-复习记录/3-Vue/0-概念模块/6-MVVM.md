![image-20211020152109812](https://gitee.com/p_pj/pig/raw/master/img/image-20211020152109812.png)

#### MVVM

MVVM分为Model、View、ViewModel三者。

- **Model** 代表数据模型，数据和业务逻辑都在Model层中定义；
- **View** 代表UI视图，负责数据的展示；
- **ViewModel** 负责监听 **Model** 中数据的改变并且控制视图的更新，处理用户交互操作；

**Model** 和 **View** 并无直接关联不互通，而是通过 **ViewModel** 来进行联系的

**Model** 和 **ViewModel** 之间有着双向数据绑定的联系。因此当 **Model** 中的数据改变时会触发 **View** 层的刷新，**View** 中由于用户交互操作而改变的数据也会在 **Model** 中同步。
这种模式实现了 **Model** 和 **View** 的数据自动同步，因此开发者只需要专注对数据的维护操作即可，而不需要自己操作 **dom**。



#### 对比MVC

MVC：

- 所有通信都是单向的。