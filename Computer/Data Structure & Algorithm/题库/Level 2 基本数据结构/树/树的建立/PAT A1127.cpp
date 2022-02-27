#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int in_order[35], post_order[35];

struct Node {
  int val, id, level;
  bool operator<(const Node &x) const {
    if (level != x.level)
      return level < x.level;
    else if (level % 2)
      return id > x.id;
    else
      return id < x.id;
  }
};

vector<Node> level_order;

void in_trav(int in, int post, int len, int id, int level) {
  if (len <= 0) return;

  int root = post_order[post + len - 1];
  level_order.push_back({root, id, level});

  // 找到 root
  int pos = in;
  while (in_order[pos] != root) ++pos;

  int l_len = pos - in;

  // 遍历子树
  in_trav(in, post, l_len, id * 2, level + 1);
  in_trav(pos + 1, post + l_len, len - l_len - 1, id * 2 + 1, level + 1);
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> in_order[i];
  for (int i = 1; i <= n; ++i) cin >> post_order[i];

  in_trav(1, 1, n, 1, 1);

  sort(level_order.begin(), level_order.end());  // 得到层序遍历

  for (auto i = level_order.begin(); i != level_order.end(); ++i)
    cout << i->val << (i + 1 == level_order.end() ? "\n" : " ");
}