#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student {
  string reg;
  int loc, score, rank[2];
} s[30005];
bool operator<(const Student &a, const Student &b) {
  if (a.score != b.score)
    return a.score > b.score;
  else
    return a.reg < b.reg;
};
void set_rank(Student *begin, Student *end, int id) {
  sort(begin, end);
  int rank = 1;
  int score = begin->score;
  for (auto i = begin; i != end; ++i) {
    if (i->score != score) {
      rank = int(i - begin) + 1;
      score = i->score;
    }
    i->rank[id] = rank;
  }
}
int main() {
  int n, k, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i, cnt += k) {
    cin >> k;
    for (auto j = s + cnt; j != s + cnt + k; j++) {
      j->loc = i + 1;
      cin >> j->reg >> j->score;
    }
    set_rank(s + cnt, s + cnt + k, 0);
  }
  set_rank(s, s + cnt, 1);
  cout << cnt << "\n";
  for (auto i = s; i != s + cnt; ++i) {
    cout << i->reg << ' ' << i->rank[1] << ' ' << i->loc << ' ' << i->rank[0]
         << '\n';
  }
}
