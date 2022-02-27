class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null or root.val == val)
            return root;
        // 递归框架
        if (root.val < val)
            return searchBST(root.right, val);
        if (root.val > val)
            return searchBST(root.left, val);
        return null;
    }
}