class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        // 找到空位置插入新节点
        if (root == null)
            return new TreeNode(val);
        // 如果已存在，则不要再重复插入了，直接返回
        if (root.val == val)
            return root;
        // val 小，则应该插到左子树上面
        if (root.val < val)
            root.right = insertIntoBST(root.right, val);
        // val 大，则应该插到右子树上面
        if (root.val > val)
            root.left = insertIntoBST(root.left, val);
        return root;
    }
}