#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node {
  int l = -1, r = -1, p = -1;
} node[25];

int max_index = 0, last;
void dfs(int root, int idx) {
  if (idx > max_index) {
    max_index = idx;
    last = root;
  }
  if (node[root].l != -1) dfs(node[root].l, idx * 2);
  if (node[root].r != -1) dfs(node[root].r, idx * 2 + 1);
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string l, r;
    cin >> l >> r;
    if (l != "-") {
      int idx = stoi(l);
      node[i].l = idx;
      node[idx].p = i;
    }
    if (r != "-") {
      int idx = stoi(r);
      node[i].r = idx;
      node[idx].p = i;
    }
  }

  int p = 0;
  while (node[p].p != -1) p = node[p].p;
  dfs(p, 1);

  if (n == max_index)  // 完全二叉树中最大的结点序号一定等于结点个数
    cout << "YES " << last;
  else
    cout << "NO " << p;
}