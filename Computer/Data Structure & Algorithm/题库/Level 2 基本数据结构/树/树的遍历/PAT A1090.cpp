#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct {
  double p;
  vector<int> children;
} node[100005];

int n, root = -1, cnt;
double p, r, max_p;

void dfs(int x) {
  if (node[x].children.empty()) {
    if (node[x].p > max_p) {
      max_p = node[x].p;
      cnt = 1;
    } else if (node[x].p == max_p) {
      ++cnt;
    }
  } else {
    for (auto i : node[x].children) {
      node[i].p = node[x].p * r;
      dfs(i);
    }
  }
}

int main() {
  cin >> n >> p >> r;
  r = 1 + r / 100;

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    if (k == -1) {
      root = i;
      node[root].p = p;
    } else
      node[k].children.push_back(i);
  }
  dfs(root);
  printf("%.2f %d", max_p, cnt);
}