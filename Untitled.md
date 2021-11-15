##### 题意描述

> 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
>
> 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
>

**示例 1：**

> 输入：nums = [1,2,0]
> 输出：3
> 示例 2：
>
> 输入：nums = [3,4,-1,1]
> 输出：2
> 示例 3：
>
> 输入：nums = [7,8,9,11,12]
> 输出：1

##### 思路1：抽屉原理

分析：数组的长度n，则答案最大只能是n+1。可以使用hash函数将答案空间映射到长度为n+1的数组上，再遍历数组找到最小的没出现的正整数。为实现常数空间复杂度，可以使用原数组的空间：

- 如果 0<nums[i]<=nums.length;
- 则将nums[i] 跟 nums[nums[i]-1]交换;
- 最后再遍历数组，如果num[i] != i+1,则i+1就是缺失的最小正整数。

```js
function firstMissingPositive(nums) {
  let max = 1;
  const record = {};
  let noPositiveNumber = true;

  nums.forEach(t => {
    if (t > 0) noPositiveNumber = false;
    max = t > max ? t : max;
    record[t] = true;
  });

  if (noPositiveNumber) return 1;

  for (let i = 1; i < max; i++) if (!record[i]) return i;
  return max + 1;
}
```



##### 思路2：数字占位法

分析：首先让数字找到自己本来的位置，例如nums[1] = 1;因为它要找的是第一个消失的正整数。让每个数找到位置后，接着尝试去找跟位置不匹配的第一个数，找到直接返回。刚才说到nums[1] = 1,nums[0]未讨论到，实际，如果数组有0，会是Nums[0] =0；否则会放置一个我们都不知道的数，所以我们把它记录下来，因为他很可能是最后的一个数，列如 [1,2,3],我们占位后会变成[3,1,2],1和2在自己位置上，我们找不到第一个位置和值不匹配的数，我们会尝试返回3，但是3实际在0位置上，所以我们需要排除下这种情况

```js
var firstMissingPositive = function(a) {
  const INF = 1e9 + 10
  let n = a.length
  a.push(0)
  for (let i = 0; i < n; ++i) {
    a[i] = Math.max(0, Math.min(a[i], n + 1))
  }
  for (let i = 0; i < n; ++i) {
    let v = a[i] % INF
    if (!v || v > n) continue
    if (a[v] > INF) continue
    a[v] += INF
  }
  for (let i = 1; i <= n; ++i) if (a[i] < INF) return i
  return n + 1
};
```

