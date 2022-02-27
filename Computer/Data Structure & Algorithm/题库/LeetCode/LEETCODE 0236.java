class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // base case
        if (root == null)
            return null;
        if (root == p or root == q)
            return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        // 情况 1 祖先一定是 root
        if (left != null and right != null) {
            return root;
        }
        // 情况 2 祖先不在 root 这棵树中
        if (left == null and right == null) {
            return null;
        }
        // 情况 3 祖先是左孩子或右孩子
        return left == null ? right : left;
    }
}