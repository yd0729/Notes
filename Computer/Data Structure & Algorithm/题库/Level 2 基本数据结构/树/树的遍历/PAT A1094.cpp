#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> children[105];
int level[105], level_cnt[105];

int main() {
  int n, m, id, k, c;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> id >> k;
    for (int j = 0; j < k; ++j) {
      cin >> c;
      children[id].push_back(c);
    }
  }

  level[1] = 1;

  queue<int> q;
  q.push(1);
  int largest_level = 1;

  while (not q.empty()) {
    int top = q.front();
    q.pop();

    if (++level_cnt[level[top]] > level_cnt[largest_level])
      largest_level = level[top];

    for (auto i : children[top]) {
      level[i] = level[top] + 1;
      q.push(i);
    }
  }

  cout << level_cnt[largest_level] << " " << largest_level;
}