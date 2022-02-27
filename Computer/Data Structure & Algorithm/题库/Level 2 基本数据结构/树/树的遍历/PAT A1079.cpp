#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 100005

double p[SIZE], cnt[SIZE];
vector<int> child[SIZE];

int main() {
  int n, k, c;
  double r, sum = 0;

  cin >> n >> p[0] >> r;
  r = 1 + r / 100;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    if (k == 0)
      cin >> cnt[i];
    else
      for (int j = 0; j < k; ++j) {
        cin >> c;
        child[i].push_back(c);
      }
  }

  queue<int> q;
  q.push(0);
  while (not q.empty()) {
    int top = q.front();
    q.pop();
    auto &c = child[top];
    if (c.size() == 0)
      sum += cnt[top] * p[top];
    else
      for (int i = 0; i < c.size(); ++i) {
        p[c[i]] = p[top] * r;
        q.push(c[i]);
      }
  }
  printf("%.1f", sum);
}