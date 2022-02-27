#include <algorithm>
#include <cctype>
#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

struct {
  int l_child = -1, r_child = -1;
} node[15];

bool is_child[15];

void level_order(int root) {
  queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int top = q.front();
    q.pop();
    if (node[top].l_child != -1) q.push(node[top].l_child);
    if (node[top].r_child != -1) q.push(node[top].r_child);

    cout << top;
    if (!q.empty()) cout << " ";
  }

  cout << "\n";
}

void in_order(int root) {
  if (node[root].l_child != -1) {
    in_order(node[root].l_child);
    cout << " ";
  }
  cout << root;
  if (node[root].r_child != -1) {
    cout << " ";
    in_order(node[root].r_child);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (isdigit(c)) {  // 在读入时反向
      int r = c - '0';
      node[i].r_child = r;
      is_child[r] = true;
    }
    cin >> c;
    if (isdigit(c)) {
      int l = c - '0';
      node[i].l_child = l;
      is_child[l] = true;
    }
  }

  int root = 0;
  while (is_child[root]) ++root;

  level_order(root);
  in_order(root);
}