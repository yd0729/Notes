#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
  int val, in_id, level_id, left = -1, right = -1;
} node[35];

void insert(int x, int root) {
  if (node[x].in_id < node[root].in_id) {
    if (node[root].left == -1) {
      node[root].left = x;
      node[x].level_id = node[root].level_id * 2;
    } else
      insert(x, node[root].left);

  } else {
    if (node[root].right == -1) {
      node[root].right = x;
      node[x].level_id = node[root].level_id * 2 + 1;
    } else
      insert(x, node[root].right);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    node[i].in_id = i;
    cin >> node[i].val;
  }

  sort(node, node + n, [](Node &a, Node &b) { return a.val < b.val; });

  node[0].level_id = 1;
  for (int i = 1; i < n; ++i) {
    insert(i, 0);
  }

  sort(node, node + n,
       [](Node &a, Node &b) { return a.level_id < b.level_id; });

  for (int i = 0; i < n; ++i) {
    cout << node[i].val << (i == n - 1 ? "" : " ");
  }
}
