class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> preorder;
    stack<TreeNode *> ancestors;
    TreeNode *pointer = root;
    while (pointer != nullptr or !ancestors.empty()) {
      if (pointer != nullptr) {
        preorder.push_back(pointer->val);
        ancestors.push(pointer);
        pointer = pointer->left;
      } else {
        pointer = ancestors.top();
        ancestors.pop();
        pointer = pointer->right;
      }
    }
    return preorder;
  }
};