

- action 提交的是 mutation，而不是直接变更状态。mutation可以直接变更状态。
- action 可以包含任意异步操作。mutation只能是同步操作。
- 提交方式不同，action 是用`this.$store.dispatch('ACTION_NAME',data)`来提交。mutation是用`this.$store.commit('SET_NUMBER',10)`来提交。
- 接收参数不同，mutation第一个参数是state，而action第一个参数是context，其包含了

```
{
    state,      // 等同于 `store.state`，若在模块中则为局部状态
    rootState,  // 等同于 `store.state`，只存在于模块中
    commit,     // 等同于 `store.commit`
    dispatch,   // 等同于 `store.dispatch`
    getters,    // 等同于 `store.getters`
    rootGetters // 等同于 `store.getters`，只存在于模块中
}

```

