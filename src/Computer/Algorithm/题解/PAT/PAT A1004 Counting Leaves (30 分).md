# 1004 Counting Leaves (30 分)

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

## Input Specification:

Each input file contains one test case. Each case starts with a line containing $0<N<100$, the number of nodes in a tree, and $M$ ($<N$), the number of non-leaf nodes. Then $M$ lines follow, each in the format:

    ID K ID[1] ID[2] ... ID[K]

where `ID` is a two-digit number representing a given non-leaf node, `K` is the number of its children, followed by a sequence of two-digit `ID`'s of its children. For the sake of simplicity, let us fix the root `ID` to be `01`.

The input ends with $N$ being 0. That case must NOT be processed.

## Output Specification:

For each test case, you are supposed to count those family members who have no child **for every seniority level** starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where `01` is the root and `02` is its only child. Hence on the root `01` level, there is `0` leaf node; and on the next level, there is `1` leaf node. Then we should output `0 1` in a line.

## Sample Input:

    2 1
    01 1 02

## Sample Output:

    0 1

## 题解

### 题意

给出一棵树，计算每一层的叶子节点的个数．

### 思路

用 dfs ，也可以用树的层序遍历，但 dfs 比较好写．对于这种给出结点 id 的树，用静态结点比较方便．

### 代码

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> child[105];
// 第 i 层的叶子结点的个数，结点 i 的层数，最大层数
int leaf[105], level[105] = {0, 1}, max_level;

void dfs(int id) {
  int l = level[id];
  if (l > max_level) max_level = l;
  if (child[id].size() == 0)  // 这个结点是叶子结点，则这层的叶子结点数 + 1
    ++leaf[l];
  else  // 这个结点不是叶子节点，则遍历他的孩子
    for (auto &c : child[id]) {
      level[c] = l + 1;
      dfs(c);
    }
}

int main() {
  int n, m, id, k, c;

  cin >> n;

  if (n == 0) return 0;

  cin >> m;

  for (int i = 0; i < m; ++i) {
    cin >> id >> k;
    for (int j = 0; j < k; ++j) {
      cin >> c;
      child[id].push_back(c);
    }
  }

  dfs(1);
  
  for (int i = 1; i <= max_level; ++i)
    cout << leaf[i] << (i == max_level ? "" : " ");
}
```
