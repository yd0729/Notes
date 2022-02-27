#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
  int address, data, next;
} node[100005], list[100005], ans[100005];

int main() {
  int head, n, k, address;
  cin >> head >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> address;
    node[address].address = address;
    cin >> node[address].data >> node[address].next;
  }

  int cnt = 0;
  for (int i = head; i != -1; i = node[i].next) {
    list[cnt++] = node[i];
  }

  int j = 0;
  for (int i = cnt / k * k; i < cnt; ++i) {
    ans[j++] = list[i];
  }

  for (int i = cnt / k * k - k; i >= 0; i -= k) {
    for (int p = 0; p < k; ++p) {
      ans[j++] = list[p + i];
    }
  }

  for (int i = 0; i < cnt - 1; ++i) {
    printf("%05d %d %05d\n", ans[i].address, ans[i].data, ans[i + 1].address);
  }
  printf("%05d %d -1\n", ans[cnt - 1].address, ans[cnt - 1].data);
}