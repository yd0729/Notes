#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

struct Node {
  int T, S;
  Node() {}
  Node(int T, int S) : T(T), S(S) {}
};

bool is_consistent(vector<vector<Node>> &adj, unordered_set<int> &entrances) {
  vector<int> indegree(adj.size());
  for (int i = 0; i < adj.size(); i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      indegree[adj[i][j].T]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < indegree.size(); i++) {
    if (indegree[i] == 0) {
      q.push(i);
      entrances.insert(i);
    }
  }

  while (!q.empty()) {
    int f = q.front();
    q.pop();
    for (int i = 0; i < adj[f].size(); i++) {
      indegree[adj[f][i].T]--;
      if (indegree[adj[f][i].T] == 0) {
        q.push(adj[f][i].T);
      }
    }
  }

  for (int i = 0; i < indegree.size(); i++) {
    if (indegree[i] != 0) return false;
  }
  return true;
}

void dijkstra(int start, vector<vector<Node>> &adj, vector<vector<int>> &pre) {
  vector<int> visited(adj.size(), false), score(adj.size(), -1);

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, start});
  score[start] = 0;

  while (!pq.empty()) {
    auto top = pq.top();
    pq.pop();

    int s = top.first, u = top.second;

    visited[u] = true;

    if (score[u] != -1 && score[u] < s) continue;

    for (int i = 0; i < adj[u].size(); i++) {
      auto &v = adj[u][i];
      if (!visited[v.T] and
          (score[v.T] == -1 or score[v.T] >= score[u] + v.S)) {
        if (score[v.T] == -1 || score[v.T] > score[u] + v.S) {
          score[v.T] = score[u] + v.S;
          pq.push({score[v.T], v.T});
          pre[v.T].clear();
        }
        pre[v.T].push_back(u);
      }
    }
  }
}

void dfs(int end, vector<vector<int>> &pre, vector<int> &tmp_path,
         vector<int> &path, vector<vector<int>> &vouchers, int &max_voucher,
         int cur_voucher) {
  if (pre[end].empty()) {
    if (cur_voucher > max_voucher) {
      path = tmp_path;
      path.pop_back();
      max_voucher = cur_voucher;
    }
    return;
  }
  for (auto i : pre[end]) {
    tmp_path.push_back(i);
    dfs(i, pre, tmp_path, path, vouchers, max_voucher,
        cur_voucher + vouchers[end][i]);
    tmp_path.pop_back();
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<Node>> adj(N + 1);
  vector<vector<int>> vouchers(N + 1, vector<int>(N + 1));

  int T1, T2, S, D;
  for (int i = 0; i < M; i++) {
    cin >> T1 >> T2 >> S >> D;
    adj[T1].emplace_back(T2, S);
    vouchers[T1][T2] = vouchers[T2][T1] = D;
  }

  // 判断图中是否有环，并找到所有的入口
  unordered_set<int> entrances;
  bool consistent = is_consistent(adj, entrances);
  if (consistent) {
    cout << "Okay.\n";
  } else {
    cout << "Impossible.\n";
  }

  // 用一个超级节点连接所有的入口，使之成为唯一的入口
  for (auto entrance : entrances) {
    adj[N].emplace_back(entrance, 0);
  }

  vector<vector<int>> pre(N + 1);
  if (consistent) dijkstra(N, adj, pre);

  int K;
  cin >> K;

  int x;
  for (int i = 0; i < K; i++) {
    cin >> x;
    if (entrances.count(x)) {
      cout << "You may take test " << x << " directly.\n";
    } else if (consistent) {
      int max_voucher = 0;
      vector<int> path, tmp_path = {x};
      dfs(x, pre, tmp_path, path, vouchers, max_voucher, 0);

      for (auto i = path.rbegin(); i != path.rend(); i++) {
        cout << *i;
        if (i + 1 != path.rend()) {
          cout << "->";
        } else {
          cout << "\n";
        }
      }
    } else {
      cout << "Error.\n";
    }
  }
}