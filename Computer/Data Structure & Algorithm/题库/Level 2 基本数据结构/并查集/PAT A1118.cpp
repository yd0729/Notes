#include <algorithm>
#include <iostream>

using namespace std;

int father[10005];

int find(int x) {
  if (father[x] != x) father[x] = find(father[x]);
  return father[x];
}

void unin(int a, int b) {
  if (find(a) != find(b)) father[father[b]] = a;
}

int main() {
  for (int i = 0; i < 10005; ++i) father[i] = i;

  int n, k, t1, t2, q, bird_num = 0;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> k >> t1;
    bird_num = max(bird_num, t1);
    for (int j = 1; j < k; ++j) {
      cin >> t2;
      bird_num = max(bird_num, t2);
      unin(t1, t2);
    }
  }

  int cnt = 0;
  for (int i = 1; i <= bird_num; ++i) {
    if (find(i) == i) ++cnt;
  }

  cout << cnt << " " << bird_num << "\n";

  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> t1 >> t2;
    if (find(t1) == find(t2))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}