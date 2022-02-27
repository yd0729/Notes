#include <iostream>
#include <unordered_map>
#include <vector>

#define SIZE 10005

using namespace std;

int in_order[SIZE], pre_order[SIZE];
unordered_map<int, int> in_pos;  // 记录每个结点在中序遍历中的位置

void lca(int in, int pre, int len, int a, int b) {
  if (len <= 0) return;

  int p_root = in_pos[pre_order[pre]], p_a = in_pos[a], p_b = in_pos[b];

  if (p_a < p_root and p_b < p_root) {  // LCA 在 root 的左子树
    lca(in, pre + 1, p_root - in, a, b);
  } else if ((p_a < p_root and p_b > p_root) or
             (p_a > p_root and p_b < p_root)) {  // LCA 就是 root
    printf("LCA of %d and %d is %d.\n", a, b, in_order[p_root]);
  } else if (p_a > p_root and p_b > p_root) {  // LCA 在 root 的右子树
    int l_len = p_root - in;
    int r_len = len - l_len - 1;
    lca(p_root + 1, pre + l_len + 1, r_len, a, b);
  } else {
    if (p_b == p_root) {
      swap(a, b);
    }
    printf("%d is an ancestor of %d.\n", a, b);
  }
}

int main() {
  int m, n, a, b;
  scanf("%d %d", &m, &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &in_order[i]);
    in_pos[in_order[i]] = i;  // 免得重建时还需要查找，也便于确定是否存在
  }

  for (int i = 1; i <= n; i++) {
    scanf("%d", &pre_order[i]);
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    if (in_pos[a] == 0 and in_pos[b] == 0)
      printf("ERROR: %d and %d are not found.\n", a, b);
    else if (in_pos[a] == 0 or in_pos[b] == 0)
      printf("ERROR: %d is not found.\n", in_pos[a] == 0 ? a : b);
    else
      lca(1, 1, n, a, b);
  }
}
