#include <iostream>
#include <vector>
using namespace std;
vector<int> child[105];
int leaf[105], level[105] = {0, 1},
               max_level;  // 第 i 层的叶子结点的个数，结点 i 的层数，最大层数
void dfs(int id) {
  int l = level[id];
  if (l > max_level) max_level = l;
  if (child[id].size() == 0)  // 这个结点是叶子结点，则这层的叶子结点数 + 1
    ++leaf[l];
  else  // 这个结点不是叶子节点，则遍历他的孩子
    for (auto &c : child[id]) {
      level[c] = l + 1;
      dfs(c);
    }
}
int main() {
  int n, m, id, k, c;
  cin >> n;
  if (n == 0) return 0;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> id >> k;
    for (int j = 0; j < k; ++j) {
      cin >> c;
      child[id].push_back(c);
    }
  }
  dfs(1);
  for (int i = 1; i <= max_level; ++i)
    cout << leaf[i] << (i == max_level ? "" : " ");
}