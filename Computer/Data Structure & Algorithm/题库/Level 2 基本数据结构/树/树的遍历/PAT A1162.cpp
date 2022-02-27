#include <iostream>
#include <string>

using namespace std;

struct Node {
  string val;
  int l_child, r_child, parent = -1;
} node[30];

void post_trav(int root) {
  cout << "(";
  if (node[root].l_child == -1 or node[root].r_child == -1) {
    cout << node[root].val;
    if (node[root].l_child != -1) post_trav(node[root].l_child);
    if (node[root].r_child != -1) post_trav(node[root].r_child);
  } else {
    post_trav(node[root].l_child);
    post_trav(node[root].r_child);
    cout << node[root].val;
  }
  cout << ")";
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> node[i].val >> node[i].l_child >> node[i].r_child;
    node[node[i].l_child].parent = i;
    node[node[i].r_child].parent = i;
  }

  int root = 1;
  while (node[root].parent != -1) root = node[root].parent;

  post_trav(root);
}