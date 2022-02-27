#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

char ACME[] = "ACME";

struct Student {
  int id, best_r = 9999, grade[4];
  char best_c;
} s[2005];

int id2pos[1000000];

int main() {
  int n, m, id;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> s[i].id;
    for (int j = 1; j < 4; j++) {
      cin >> s[i].grade[j];
      s[i].grade[0] += s[i].grade[j];
    }
    s[i].grade[0] /= 3;
  }

  for (int i = 0; i < 4; ++i) {
    sort(s, s + n, [i](auto &a, auto &b) { return a.grade[i] > b.grade[i]; });

    for (int j = 0, rank = 1, pre = -1; j < n; ++j) {  // 计算排名
      if (s[j].grade[i] != pre) {
        rank = j + 1;
        pre = s[j].grade[i];
      }

      if (s[j].best_r > rank) {
        s[j].best_r = rank;
        s[j].best_c = ACME[i];
      }
    }
  }

  for (int i = 0; i < n; i++)  // 排序会改变元素位置，要获得排名后再遍历。
    id2pos[s[i].id] = i + 1;

  for (int i = 0; i < m; ++i) {
    cin >> id;
    if (id2pos[id])
      cout << s[id2pos[id] - 1].best_r << " " << s[id2pos[id] - 1].best_c
           << "\n";
    else
      cout << "N/A\n";
  }
}
