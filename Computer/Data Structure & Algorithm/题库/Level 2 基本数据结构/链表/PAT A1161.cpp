#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data, addr;
} node[100005];

int main() {
  int head_a, head_b, n;
  cin >> head_a >> head_b >> n;

  for (int i = 0; i < n; ++i) {
    int address, data, next;
    cin >> address >> data >> next;
    node[address] = {data, next};
  }

  vector<Node> a, b, c;
  for (int p = head_a; p != -1; p = node[p].addr)
    a.push_back({node[p].data, p});
  for (int p = head_b; p != -1; p = node[p].addr)
    b.push_back({node[p].data, p});

  if (a.size() < b.size()) swap(a, b);
  reverse(b.begin(), b.end());
  for (int i = 0, j = 0, k = 0; i < a.size() or j < b.size(); ++k) {
    if (k % 3 == 2 and j < b.size())
      c.push_back(b[j++]);
    else
      c.push_back(a[i++]);
  }

  for (int i = 0; i < c.size(); ++i) {
    printf("%05d %d ", c[i].addr, c[i].data);
    if (i == c.size() - 1)
      cout << "-1\n";
    else
      printf("%05d\n", c[i + 1].addr);
  }
}