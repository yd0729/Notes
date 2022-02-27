#include <array>
#include <iostream>
#include <queue>

using namespace std;

int brain[65][130][130];
int step[6][3] = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                  {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};

using point = array<int, 3>;
point limit;

bool is_valid(point &p) {
  if (p[0] < 0 or p[0] >= limit[2]) return false;
  if (p[1] < 0 or p[1] >= limit[0]) return false;
  if (p[2] < 0 or p[2] >= limit[1]) return false;
  return brain[p[0]][p[1]][p[2]] == 1;
}

int bfs(point start) {
  int cnt = 0;
  queue<point> q;

  q.push(start);
  brain[start[0]][start[1]][start[2]] = 2;

  while (not q.empty()) {
    point p = q.front();
    q.pop();
    ++cnt;

    for (int i = 0; i < 6; ++i) {
      point next = p;
      for (int j = 0; j < 3; j++) {
        next[j] += step[i][j];
      }
      if (is_valid(next)) {
        q.push(next);
        brain[next[0]][next[1]][next[2]] = 2;
      }
    }
  }

  return cnt;
}

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> limit[i];
  }
  int t;
  cin >> t;

  for (int i = 0; i < limit[2]; ++i)
    for (int j = 0; j < limit[0]; ++j)
      for (int k = 0; k < limit[1]; ++k) cin >> brain[i][j][k];

  int total = 0;
  for (int i = 0; i < limit[2]; ++i)
    for (int j = 0; j < limit[0]; ++j)
      for (int k = 0; k < limit[1]; ++k)
        if (brain[i][j][k] == 1) {
          int cnt = bfs({i, j, k});
          if (cnt >= t) total += cnt;
        }

  cout << total;
}