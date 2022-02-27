#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Student {
  string name;
  int height;

  bool operator<(const Student &x) const {
    if (height != x.height)
      return height > x.height;
    else
      return name < x.name;
  }
} all[10005], line[10005];

int main() {
  int n, k;
  cin >> n >> k;
  int m = n / k;

  for (int i = 0; i < n; ++i) cin >> all[i].name >> all[i].height;
  sort(all, all + n);

  for (int i = 0, c = 0; i < k; ++i) {
    int m2 = m + (i == 0 ? n - m * k : 0);  // 处理最后一行的人数
    line[m2 / 2] = all[c];
    for (int j = 1; j <= m2 / 2; ++j) {
      line[m2 / 2 - j] = all[c + 2 * j - 1];              // 右边的人
      if (2 * j < m2) line[m2 / 2 + j] = all[c + 2 * j];  // 左边的人
    }
    c += m2;
    for (int j = 0; j < m2; ++j)
      cout << line[j].name << (j < m2 - 1 ? " " : "\n");
  }
}