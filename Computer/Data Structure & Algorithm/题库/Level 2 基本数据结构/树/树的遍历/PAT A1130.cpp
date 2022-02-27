#include <iostream>
#include <map>
#include <string>

using namespace std;

struct {
  string v;
  int l_child = -1, r_child = -1, parent = -1;
} tree[25];

void in_order(int root) {
  if (tree[root].parent != -1 and
      (tree[root].l_child != -1 or tree[root].r_child != -1))
    cout << "(";
  if (tree[root].l_child != -1) in_order(tree[root].l_child);
  cout << tree[root].v;
  if (tree[root].r_child != -1) in_order(tree[root].r_child);
  if (tree[root].parent != -1 and
      (tree[root].l_child != -1 or tree[root].r_child != -1))
    cout << ")";
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> tree[i].v >> tree[i].l_child >> tree[i].r_child;
    if (tree[i].l_child != -1) tree[tree[i].l_child].parent = i;
    if (tree[i].r_child != -1) tree[tree[i].r_child].parent = i;
  }

  int root = 1;
  while (tree[root].parent != -1) root = tree[root].parent;

  in_order(root);
}