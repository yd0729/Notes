#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct Mouse {
  int rank = -1;
  int w = 0;
};
void set_rank(vector<Mouse> &mouse, vector<int> &seq, int ng) {
  if (seq.size() == 1) {  // 剩下一只老鼠，排名为1
    mouse[seq[0]].rank = 1;
    return;
  }
  int max_idx = seq[0];  // 重量最大的老鼠的序号
  vector<int> next_seq;  // 下一轮比较的顺序
  for (int i = 1, j = 1, sz = seq.size(); i < sz; ++i, j = (j + 1) % ng) {
    if (mouse[max_idx].w < mouse[seq[i]].w) max_idx = seq[i];
    if (j == ng - 1 or i == sz - 1) {
      next_seq.push_back(max_idx);
      if (i + 1 < sz) max_idx = seq[i + 1];
    }
  }
  set_rank(mouse, next_seq, ng);   // 先进行下一轮比较
  int rank = next_seq.size() + 1;  // 本轮被淘汰的老鼠的排名
  for (int i = 0, sz = seq.size(); i < sz; ++i)
    if (mouse[seq[i]].rank == -1) mouse[seq[i]].rank = rank;
}
int main() {
  int np, ng;
  cin >> np >> ng;
  vector<Mouse> m(np);
  for (int i = 0; i < np; ++i) cin >> m[i].w;
  vector<int> seq(np);
  for (int i = 0; i < np; ++i) cin >> seq[i];
  set_rank(m, seq, ng);
  for (int i = 0, sz = m.size(); i < sz; ++i)
    cout << m[i].rank << (i != sz - 1 ? " " : "");
}