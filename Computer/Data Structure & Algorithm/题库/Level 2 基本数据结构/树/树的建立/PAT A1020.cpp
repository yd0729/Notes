#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int post_order[35], in_order[35];
vector<pair<int, int>> layer;
void build(int in_l, int post_l, int len, int id) {  // id 是根在层序中的序号
  if (len <= 0) return;
  int &p_root = post_order[post_l + len - 1];
  layer.push_back({id, p_root});
  int in_root = in_l;  // 找到 root 在中序的位置
  while (in_root < in_l + len and in_order[in_root] != p_root) ++in_root;
  int l_len = in_root - in_l, r_len = len - l_len - 1;  // 子树序列的长度
  build(in_l, post_l, l_len, id * 2);                   // 构建子树
  build(in_root + 1, post_l + l_len, r_len, id * 2 + 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &post_order[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &in_order[i]);
  build(0, 0, n, 1);
  sort(layer.begin(), layer.end());
  for (auto i = layer.begin(); i < layer.end(); ++i)
    printf("%d%s", i->second, (i + 1 != layer.end()) ? " " : "");
}
