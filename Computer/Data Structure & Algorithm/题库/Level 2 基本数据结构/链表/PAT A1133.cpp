#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int addr, data;
} list[100000];

vector<Node> ans;

int main() {
  int root, n, k, addr = 0;
  cin >> root >> n >> k;

  for (int i = 0; i < n; ++i) cin >> addr >> list[addr].data >> list[addr].addr;

  for (int i = root; i != -1; i = list[i].addr)
    if (list[i].data < 0) ans.push_back({i, list[i].data});

  for (int i = root; i != -1; i = list[i].addr)
    if (list[i].data >= 0 and list[i].data <= k)
      ans.push_back({i, list[i].data});

  for (int i = root; i != -1; i = list[i].addr)
    if (list[i].data > k) ans.push_back({i, list[i].data});

  for (auto i = ans.begin(); i + 1 != ans.end(); ++i)
    printf("%05d %d %05d\n", i->addr, i->data, (i + 1)->addr);
  printf("%05d %d -1\n", ans.rbegin()->addr, ans.rbegin()->data);
}