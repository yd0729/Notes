#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> pre;
unordered_set<int> all;

int main() {
  int m, n, x, y;

  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    all.insert(x);
    pre.push_back(x);
  }

  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    bool p = all.count(x);
    bool q = all.count(y);
    if (!p or !q) {
      if (p or q)
        printf("ERROR: %d is not found.\n", !p ? x : y);
      else
        printf("ERROR: %d and %d are not found.\n", x, y);
    } else {
      auto iter = pre.begin();
      for (; iter != pre.end(); ++iter) {
        if (*iter >= min(x, y) and *iter <= max(x, y)) break;
      }
      if (*iter == x)
        printf("%d is an ancestor of %d.\n", x, y);
      else if (*iter == y)
        printf("%d is an ancestor of %d.\n", y, x);
      else
        printf("LCA of %d and %d is %d.\n", x, y, *iter);
    }
  }
}