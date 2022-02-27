#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct Node {
  int addr;
  int key;
  int next;
  bool valid;
  friend bool operator<(const Node &a, const Node &b) {
    if (!a.valid or !b.valid)
      return a.valid > b.valid;
    else
      return a.key < b.key;
  }
} node[100005];
int main() {
  int n, head, a, k, nt;
  cin >> n >> head;
  for (int i = 0; i < n; ++i) {
    cin >> a >> k >> nt;
    node[a] = {a, k, nt};
  }
  int size = 0;  // 统计所有有效的节点
  for (int p = head; p != -1; p = node[p].next) {
    node[p].valid = true;
    ++size;
  }
  cout << size << " ";
  sort(node, node + 100005);
  if (!node[0].valid)  // 坑点： size 可能为 0
    cout << -1 << '\n';
  else
    cout << setw(5) << setfill('0') << node[0].addr << '\n';
  for (int i = 0; i < size; ++i) {
    cout << setw(5) << setfill('0') << node[i].addr << " " << node[i].key
         << " ";
    if (i + 1 == size)
      cout << -1;
    else
      cout << setw(5) << setfill('0') << node[i + 1].addr;
    cout << '\n';
  }
}