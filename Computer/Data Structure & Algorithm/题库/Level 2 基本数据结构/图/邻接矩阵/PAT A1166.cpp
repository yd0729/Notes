#include <iostream>
#include <unordered_set>

using namespace std;

bool is_friend[205][205];

bool is_ok(int x, unordered_set<int> &area) {
  for (auto &e : area) {
    if (e == x) continue;
    if (!is_friend[e][x]) return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    is_friend[a][b] = is_friend[b][a] = 1;
  }

  int k;
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    int l, a;
    cin >> l;

    unordered_set<int> area;
    for (int j = 0; j < l; ++j) {
      cin >> a;
      area.insert(a);
    }

    for (auto &e : area) {
      if (!is_ok(e, area)) {
        printf("Area %d needs help.\n", i);
        goto done;
      }
    }

    for (int j = 1; j <= n; ++j) {
      if (area.count(j)) continue;
      if (is_ok(j, area)) {
        printf("Area %d may invite more people, such as %d.\n", i, j);
        goto done;
      }
    }

    printf("Area %d is OK.\n", i);

  done : {}
  }
}