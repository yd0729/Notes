---
created: 2022-04-09T08:44:15 (UTC +08:00)
tags: 数学
source: https://leetcode-cn.com/problems/reaching-points/solution/dao-da-zhong-dian-by-leetcode-solution-77fo/
---

# LeetCode 0780 到达终点

如果从 $(sx, sy)$ 开始正向计算，则可能的情况非常多，会超出时间限制。注意到 $sx,sy,tx,ty$ **都是正整数**，因此对于给定的状态 $(tx,ty)$，只有当 $tx\ne ty$ 时才存在上一个状态，且上一个状态唯一，可能的情况如下：

- 如果 $tx=ty$，不存在上一个状态，状态 $(tx,ty)$ 即为起点状态；
- 如果 $tx>ty$，则上一个状态是 $(tx−ty,ty)$；
- 如果 $tx<ty$，则上一个状态是 $(tx,ty−tx)$。

因此可以从 $(tx,ty)$ 开始反向计算，判断是否可以到达状态 $(sx, sy)$。当 $tx>sx,ty>sy,tx≠ty$ 三个条件同时成立时，执行反向操作，每一步操作更新 $(tx,ty)$ 的值，直到反向操作的条件不成立。

**由于每一步反向操作一定是将 $tx$ 和 $ty$ 中的较大的值减小**，因此当 $tx>ty$ 时可以直接将 $ tx \mod ty$，当 $tx<ty$ 时可以直接将 $ty$ 的值更新为 $ty \mod tx$。

当反向操作的条件不成立时，根据 $tx$ 和 $ty$ 的不同情况分别判断是否可以从起点转换到终点。

- 如果 $tx=sx$ 且 $ty=sy$，则已经到达起点状态，因此可以从起点转换到终点。
- 如果 $tx=sx$ 且 $ty≠sy$，则 $tx$ 不能继续减小，只能减小 $ty$，因此只有当 $ty>sy$ 且 $(ty−sy) \mod tx=0$ 时可以从起点转换到终点。
- 如果 $ty=sy$ 且 $tx≠sx$，则 $ty$ 不能继续减小，只能减小 $tx$，因此只有当 $tx>sx$ 且 $(tx−sx) \mod ty=0$ 时可以从起点转换到终点。
- 如果 $tx≠sx$ 且 $ty≠sy$，则不可以从起点转换到终点。

```c++
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy) {
            return true;
        } else if (tx == sx) {
            return ty > sy && (ty - sy) % tx == 0;
        } else if (ty == sy) {
            return tx > sx && (tx - sx) % ty == 0;
        } else {
            return false;
        }
    }
};
```

**复杂度分析**

- 时间复杂度：反向计算的过程与辗转相除法相似，时间复杂度是 $O(\log⁡\max⁡(tx,ty))$。
- 空间复杂度：$O(1)$。
