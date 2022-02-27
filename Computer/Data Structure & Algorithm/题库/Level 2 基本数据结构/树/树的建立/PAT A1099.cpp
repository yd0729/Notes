#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct {
  int val;
  int l_child, r_child;
} node[105];

int arr[105];

void in_order(int root, int &index) {
  if (node[root].l_child != -1) in_order(node[root].l_child, index);

  node[root].val = arr[index++];

  if (node[root].r_child != -1) in_order(node[root].r_child, index);
}

void level_order() {
  queue<int> q;
  q.push(0);

  while (not q.empty()) {
    int top = q.front();
    q.pop();

    cout << node[top].val;

    if (node[top].l_child != -1) q.push(node[top].l_child);
    if (node[top].r_child != -1) q.push(node[top].r_child);

    if (not q.empty()) cout << " ";
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> node[i].l_child >> node[i].r_child;

  for (int i = 0; i < n; ++i) cin >> arr[i];

  sort(arr, arr + n);

  int i = 0;
  in_order(0, i);

  level_order();
}