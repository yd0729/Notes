class Solution {
 public:
  unordered_map<TreeNode *, int> memo;
  int rob(TreeNode *root) {
    if (root == nullptr) return 0;
    if (memo.count(root)) return memo[root];
    // 偷
    int steal =
        root->val +
        (root->left ? rob(root->left->left) + rob(root->left->right) : 0) +
        (root->right ? rob(root->right->left) + rob(root->right->right) : 0);
    // 不偷
    int no_steal = rob(root->left) + rob(root->right);
    memo[root] = max(steal, no_steal);
    return memo[root];
  }
};