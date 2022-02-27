#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Node {
  int addr, data, next;
} node[100005];

set<int> values;
vector<Node> removed, keep;

void print_list(vector<Node> &list) {
  for (int i = 0, size = list.size(); i < size; ++i) {
    printf("%05d %d ", list[i].addr, list[i].data);
    if (i == size - 1)
      printf("-1\n");
    else
      printf("%05d\n", list[i + 1].addr);
  }
}

int main() {
  int head, n, addr;
  cin >> head >> n;

  for (int i = 0; i < n; ++i) {
    cin >> addr;
    node[addr].addr = addr;
    cin >> node[addr].data >> node[addr].next;
  }

  for (int iter = head, pre = -1; iter != -1; iter = node[iter].next) {
    if (values.count(abs(node[iter].data))) {
      removed.push_back(node[iter]);
    } else {
      keep.push_back(node[iter]);
      values.insert(abs(node[iter].data));
    }
  }

  if (head == -1)
    printf("-1\n");
  else {
    print_list(keep);
    print_list(removed);
  }
}