#include <algorithm>
#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct {
  double price;
  vector<int> child;
} node[100005];

int main() {
  int n, k, c;
  double r;

  cin >> n >> node[0].price >> r;

  r = 1 + r / 100;

  for (int i = 0; i < n; ++i) {
    cin >> k;
    for (int j = 0; j < k; ++j) {
      cin >> c;
      node[i].child.push_back(c);
    }
  }

  queue<int> q;
  q.push(0);

  int cnt = 0;
  double min_price = 0;
  while (!q.empty()) {
    int top = q.front();
    q.pop();

    vector<int> &child = node[top].child;
    if (child.size() == 0) {  // 找到了一个零售商
      if (cnt == 0) {
        min_price = node[top].price;
        cnt = 1;
      } else if (min_price == node[top].price)
        ++cnt;
      else  // 可以直接退出
        break;
    } else
      for (int i = 0, size = child.size(); i < size; ++i) {
        node[child[i]].price = node[top].price * r;
        q.push(child[i]);
      }
  }

  cout << fixed << setprecision(4) << min_price << " " << cnt;
}