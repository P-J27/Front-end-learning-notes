#### 题意描述

> 第 `i` 个人的体重为 `people[i]`，每艘船可以承载的最大重量为 `limit`。
>
> 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 `limit`。
>
> 返回载到每一个人所需的最小船数。(保证每个人都能被船载)。

**示例 1：**

> 输入：people = [1,2], limit = 3
> 输出：1
> 解释：1 艘船载 (1, 2)

**思路分析：**贪心思维分析，双指针加排序，重量由小到大排序，最重的能不能带一个最轻的，不能最重的人数量减1，可以最轻最重都减1，即指针移动。

**结论：**

- 要得到最小的船数，则每条船上尽量装2个人
- 首先将people数组排序
- 双指针，i从第一个人开始，j从最后一个人开始
- 比较当前i和j指向的people的和是否小于limit
  - 如果是，则将结果+1，同时标记当前已经遍历了两个人，即vis+=2，然后将当前的i和j都指向对应方向的下一个人，
  - 重复这个过程，直到i=j结束
  - 当前遍历结束后，所有可以装个人的情况已经记录，剩下的所有未上船的人，任意两个人一定无法同时被装在一条船上



#### C++版

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //双指针加排序
        int left=0,right=people.size()-1;
        sort(people.begin(),people.end());
        int ans=0;
        while(left<=right){
            if(limit-people[right]>=people[left]){
                left++;
            }
            right--;
            ans++;
        }
        return ans;
    }
};
```



#### Java 版

```java
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int n = people.length,res = 0;
        for(int i = 0,j = n - 1;i <= j;){
            if(people[i] + people[j] <= limit){
                i++;
            }
            j--;
            res++;
        }
        return res;
    }
}
```