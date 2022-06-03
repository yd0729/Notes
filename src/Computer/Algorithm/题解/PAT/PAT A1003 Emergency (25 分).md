# 1003 Emergency (25 分)

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

## Input Specification:

Each input file contains one test case. For each test case, the first line contains 4 positive integers: $N$ ($\le 500$) - the number of cities (and the cities are numbered from 0 to $N−1$), $M$ - the number of roads, $C_1$ and $C_2$ - the cities that you are currently in and that you must save, respectively. The next line contains $N$ integers, where the $i$\-th integer is the number of rescue teams in the $i$-th city. Then $M$ lines follow, each describes a road with three integers $c_1$, $c_2$ and $L$, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from $C_1$ to $C_2$.

## Output Specification:

For each test case, print in one line two numbers: the number of different shortest paths between $C_1$ and $C_2$, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

## Sample Input:

    5 6 0 2
    1 2 1 5 3
    0 1 1
    0 2 2
    0 3 1
    1 2 1
    2 4 1
    3 4 1

## Sample Output:

    2 4

## 题解

### 题意

计算从起点到终点的所有最短路径的个数和这些路径中最大的点权之和．

### 代码

#### dijkstra

```cpp
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX_V 505
#define INF -1

using p = pair<int, int>;

bool visited[MAX_V];
vector<p> adj[MAX_V];
int dist[MAX_V], path[MAX_V], sum[MAX_V], team[MAX_V];

void dijkstra(int start) {
  priority_queue<p, vector<p>, greater<p>> pq;
  pq.push({0, start});

  fill_n(dist, MAX_V, INF);

  dist[start] = 0;
  path[start] = 1;
  sum[start] = team[start];

  while (not pq.empty()) {
    auto top = pq.top();
    pq.pop();

    int &u = top.second;
    int &u_dist = top.first;

    visited[u] = true;

    if (dist[u] < u_dist) {  // 1. 这里 dist[u] 不可能是 INF
      continue;  // 2. dist[u] < u_dist 说明 u 的邻居都更新过了
    }

    for (auto &e : adj[u]) {
      int &v = e.second;
      int &uv = e.first;

      if (not visited[v] and (dist[v] == INF or dist[v] > dist[u] + uv)) {
        dist[v] = dist[u] + uv;
        pq.push({dist[v], v});
        path[v] = path[u];
        sum[v] = team[v] + sum[u];
      } else if (dist[v] == dist[u] + uv) {
        path[v] += path[u];
        if (sum[v] < team[v] + sum[u]) {
          sum[v] = team[v] + sum[u];
        }
      }
    }
  }
}

int main() {
  int n, m, c1, c2;
  cin >> n >> m >> c1 >> c2;

  for (int i = 0; i < n; ++i) {
    cin >> team[i];
  }
  
  for (int i = 0; i < m; ++i) {
    int a, b, l;
    cin >> a >> b >> l;
    adj[a].push_back({l, b});
    adj[b].push_back({l, a});
  }

  dijkstra(c1);
  
  cout << path[c2] << " " << sum[c2];
}
```

#### Bellman-Ford

如果使用 Bellman-Ford 算法，因为会重复访问节点，所以不能只用一个 num 数组记录最短路径的个数，还要记录节点的前驱．下面是一种用邻接表的 Bellman-Ford ，在这道题表现还可以（如果不用邻接表的话还是挺慢的）．

```cpp
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_V = 510;
const int INF = 0x3fffffff;

struct node {
    int v, dis;
};
vector<node> adj[MAX_V];  // 邻接表
// n为顶点数，m为边数，st和ed分别为起点和终点，weight[]记录点权
int n, m, st, ed, weight[MAX_V];
// d[]记录最短距离，w[]记录最大点权之和，num[]记录最短路径条数
int d[MAX_V], w[MAX_V], num[MAX_V];
set<int> pre[MAX_V];  // 前驱

void bellman(int s) {
    fill_n(w, MAX_V, 0);
    fill_n(d, MAX_V, INF);
    fill_n(num, MAX_V, 0);

    // 起始节点
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;

    // 求解数组d
    for (int i = 0; i < n - 1; ++i)  // 更新n-1次
        for (int u = 0; u < n; ++u)  // 遍历每个节点
            for (int j = 0; j < adj[u].size(); ++j) {
                int v = adj[u][j].v;
                int dis = adj[u][j].dis;

                if (d[u] + dis < d[v]) {  // 以u为中间点时能另d[v]变小
                    d[v] = d[u] + dis;
                    w[v] = w[u] + weight[v];

                    num[v] = num[u];

                    pre[v].clear();
                    pre[v].insert(u);
                } else if (d[u] + dis == d[v]) {
                    if (w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];

                    pre[v].insert(u);  // 将u加入pre[v]
                    num[v] = 0;  // 重新统计num[v]
                    for (auto &e: pre[v]) num[v] += num[e];
                }
            }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &st, &ed);
    for (int i = 0; i < n; ++i)
        scanf("%d", &weight[i]);

    int u, v, wt;

    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &wt);
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    bellman(st);

    printf("%d %d\n", num[ed], w[ed]);
}
```
