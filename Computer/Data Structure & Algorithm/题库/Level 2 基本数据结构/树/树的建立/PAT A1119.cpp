#include <iostream>
#include <vector>

using namespace std;

vector<int> in;
bool uniq = true;
int pre_order[35], post_order[35];

void in_trav(int pre, int post, int n) {
  if (n == 1) {
    in.push_back(pre_order[pre]);
    return;
  }

  int root = pre_order[pre];
  int l_root = pre_order[pre + 1];  // 左子树的根

  int post_r = post;  // 后序遍历中，右子树的开始位置
  for (; post_r < post + n and post_order[post_r] != l_root; ++post_r)
    ;  // 在后序遍历中，左子树的根是左子树中最后一个被访问的
  post_r += 1;

  int l_len = post_r - post;

  in_trav(pre + 1, post, l_len);  // 向左子树递归

  in.push_back(root);

  if (post_r == post + n - 1)  // 右子树的位置 == 根的位置
    uniq = false;  // 说明只有一个子树，那是左子树还是右子树就都有可能了
  else
    in_trav(pre + 1 + l_len, post_r, n - l_len - 1);  // 向右子树递归
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> pre_order[i];
  for (int i = 0; i < n; ++i) cin >> post_order[i];

  in_trav(0, 0, n);

  cout << (uniq ? "Yes\n" : "No\n");
  for (auto i = in.begin(); i != in.end(); ++i)
    cout << *i << (i + 1 == in.end() ? "\n" : " ");
}