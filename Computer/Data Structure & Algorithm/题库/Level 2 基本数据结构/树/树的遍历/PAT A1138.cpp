#include <iostream>

using namespace std;

int in_order[50005], pre_order[50005];

int first_of_post_order(int *in, int *pre, int len) {
  if (len == 1) return *in;

  int root = *pre;

  int *pos = in;
  while (*pos != root) ++pos;

  if (pos != in)
    return first_of_post_order(in, pre + 1, pos - in);  // 第一个数在左子树中
  else
    return first_of_post_order(in + 1, pre + 1, len - 1);  // 左子树为空
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) cin >> pre_order[i];
  for (int i = 1; i <= n; ++i) cin >> in_order[i];

  cout << first_of_post_order(in_order + 1, pre_order + 1, n);
}