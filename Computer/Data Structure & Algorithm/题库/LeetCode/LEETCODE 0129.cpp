class Solution {
 public:
  int sumNumbers(TreeNode *root) { return _sumNumbers(root, 0); }

  int _sumNumbers(TreeNode *root, int number) {
    if (!root) return 0;
    number = number * 10 + root->val;
    if (!root->left and !root->right) return number;
    return _sumNumbers(root->left, number) + _sumNumbers(root->right, number);
  }
};