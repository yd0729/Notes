class Solution {
    ListNode left;

    boolean isPalindrome(ListNode head) {
        left = head;
        return traverse(head);
    }

    // 利用递归，倒序遍历单链表
    boolean traverse(ListNode right) {
        if (right == null)
            return true;
        boolean res = traverse(right.next);
        // 后序遍历代码
        res = res and (right.val == left.val);
        left = left.next;
        return res;
    }
}