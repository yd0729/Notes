#include <array>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
  int k;
  string s;
  queue<char> q;
  array<bool, 300> is_stuck, is_visited;

  is_visited.fill(false);
  is_stuck.fill(false);

  cin >> k >> s;
  for (auto i = s.begin(); i != s.end();) {
    int c = *i, cnt = 0;
    while (i != s.end() and *i == c) {
      ++cnt;
      ++i;
    }
    if (cnt % k == 0 and !is_visited[c]) {
      is_stuck[c] = true;
      q.push(c);
    } else if (cnt % k)
      is_stuck[c] = false;
    is_visited[c] = true;  // 保证只加入一次队列
  };

  while (!q.empty()) {
    char c = q.front();
    q.pop();
    if (is_stuck[c]) cout << c;
  }
  cout << "\n";

  for (auto i = s.begin(); i != s.end(); is_stuck[*i] ? i += k : ++i)
    cout << *i;
}