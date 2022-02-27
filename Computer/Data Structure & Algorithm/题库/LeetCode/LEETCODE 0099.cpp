class Solution {
 public:
  void traverse(TreeNode *t, TreeNode *&first, TreeNode *&second,
                TreeNode *&prev) {
    if (t == nullptr) return;

    traverse(t->left, first, second, prev);

    if (prev and t->val < prev->val) {
      if (first) {
        second = t;
      } else {
        first = prev;
        second = t;
      }
    }
    prev = t;

    traverse(t->right, first, second, prev);
  }

  void recoverTree(TreeNode *root) {
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    traverse(root, first, second, prev);
    swap(first->val, second->val);
  }
};