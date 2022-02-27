class Solution {
 public:
  void build(TreeNode *&root, int preL, int inL, int len, vector<int> &preorder,
             vector<int> &inorder) {
    if (len == 0) return;

    int root_val = preorder[preL];
    root = new TreeNode(root_val);

    int pos = inL;
    for (; pos < inL + len; ++pos) {
      if (inorder[pos] == root_val) break;
    }

    int left_len = pos - inL;
    int right_len = inL + len - pos - 1;

    build(root->left, preL + 1, inL, left_len, preorder, inorder);
    build(root->right, preL + left_len + 1, pos + 1, right_len, preorder,
          inorder);
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) return nullptr;
    TreeNode *root = nullptr;
    build(root, 0, 0, preorder.size(), preorder, inorder);
    return root;
  }
};