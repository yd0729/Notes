#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  bool visit;                     // 访问标志
  vector<string> pre;             // 最短路径上的前驱
  vector<pair<int, string>> adj;  // 邻接表
  int dist = -1, h, path_cnt;  // 最短路径估计 快乐值 最短路径个数
};

unordered_map<string, Node> node;

void dijkstra(string start) {
  node[start].dist = 0;
  node[start].path_cnt = 1;

  using p = pair<int, string>;
  priority_queue<p, vector<p>, greater<p>> pq;
  pq.push({0, start});

  while (not pq.empty()) {
    int u_dist = pq.top().first;
    string u = pq.top().second;
    pq.pop();

    node[u].visit = true;

    if (node[u].dist < u_dist) continue;
    for (auto &e : node[u].adj) {
      string v = e.second;
      int uv = e.first;

      if (not node[v].visit and
          (node[v].dist == -1 or node[v].dist > node[u].dist + uv)) {
        node[v].dist = node[u].dist + uv;
        pq.push({node[v].dist, v});

        node[v].pre.clear();
        node[v].pre.push_back(u);

        node[v].path_cnt = node[u].path_cnt;
      } else if (node[v].dist == node[u].dist + uv) {
        node[v].pre.push_back(u);
        node[v].path_cnt += node[u].path_cnt;
      }
    }
  }
}

int max_sum = 0;
double max_avg = 0;
vector<string> tmp, path;

void dfs(string name, int sum_h) {
  sum_h += node[name].h;
  tmp.push_back(name);
  if (node[name].pre.empty()) {  // 深搜到了路径的源点
    double avg_h = double(sum_h) / (int(tmp.size()) - 1);
    if (sum_h > max_sum or (sum_h == max_sum and avg_h > max_avg)) {
      max_sum = sum_h;
      max_avg = avg_h;

      path = tmp;
    }
  } else {
    for (auto e : node[name].pre) dfs(e, sum_h);
  }
  tmp.pop_back();
}

int main() {
  int n, k;
  string start, end = "ROM";
  cin >> n >> k >> start;

  // 读取每个城市的快乐值
  for (int i = 0; i < n - 1; ++i) {
    int h;
    string name;
    cin >> name >> h;
    node[name].h = h;
  }

  // 读取所有的道路
  for (int i = 0; i < k; ++i) {
    int cost;
    string c1, c2;
    cin >> c1 >> c2 >> cost;
    node[c1].adj.push_back({cost, c2});
    node[c2].adj.push_back({cost, c1});
  }

  dijkstra(start);  // dijkstra找出所有最短路径
  dfs(end, 0);  // dfs选出快乐值最大且平均快乐值尽可能大的最短路径
  reverse(path.begin(), path.end());
  cout << node["ROM"].path_cnt << " " << node["ROM"].dist << " " << max_sum
       << " " << int(max_avg) << "\n";

  for (auto iter = path.begin(); iter != path.end(); ++iter) {
    cout << *iter;
    if (iter + 1 != path.end()) cout << "->";
  }
}