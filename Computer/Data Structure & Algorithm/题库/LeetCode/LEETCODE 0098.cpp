class Solution {
 public:
  bool isValidBST(TreeNode *root) { return isValidBST(root, nullptr, nullptr); }

  bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (root == nullptr) return true;
    if (min != nullptr and root->val <= min->val) return false;
    if (max != nullptr and root->val >= max->val) return false;
    return isValidBST(root->left, min, root) and
           isValidBST(root->right, root, max);
  }
};