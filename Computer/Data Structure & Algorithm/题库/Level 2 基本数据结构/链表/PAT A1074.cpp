#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
  int addr, data, next;
} nodes[100005], list[100005];

int main() {
  int head, n, k, addr;
  cin >> head >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> addr;
    nodes[addr].addr = addr;
    cin >> nodes[addr].data >> nodes[addr].next;
  }

  int len = 0;
  for (int i = head; i != -1; i = nodes[i].next)  // 获得链表
    list[len++] = nodes[i];
  for (int i = k; i <= len; i += k)  // 分组倒置
    reverse(list + i - k, list + i);
  for (int i = 0; i < len - 1; ++i)
    printf("%05d %d %05d\n", list[i].addr, list[i].data, list[i + 1].addr);
  printf("%05d %d -1\n", list[len - 1].addr, list[len - 1].data);
}