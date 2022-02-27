bool IS_BST(BinTree T, int *min,
            int *max) { /* min 和 max 是 T 中所有结点值的下、上界 */
  int lmin, lmax, rmin, rmax, Left_flag, Right_flag;

  if (!T) return true;          /* 空树肯定是BST */
  if (!T->Left and !T->Right) { /* 只有一个根结点 */
    (*min) = (*max) = T->Data;  /* 树中最大最小值都是根的值 */
    return true;                /* 单结点树肯定是BST */
  }

  Left_flag = Right_flag = false; /* 左右子树判断结果初始化 */

  /* 分别判断左右两边是否可以 */
  if ((T->Left and IS_BST(T->Left, &lmin, &lmax) and T->Data > lmax) or
      !T->Left)
    Left_flag = true;
  if ((T->Right and IS_BST(T->Right, &rmin, &rmax) and T->Data < rmin) or
      !T->Right)
    Right_flag = true;

  if (Left_flag and Right_flag) { /* 如果两边都可以，更新上下界 */
    if (T->Left)
      (*min) = lmin;
    else
      (*min) = T->Data;
    if (T->Right)
      (*max) = rmax;
    else
      (*max) = T->Data;
    return true;
  } else
    return false;
}

bool IsBST(BinTree T) {
  int minT, maxT;

  minT = maxT = -1;
  return IS_BST(T, &minT, &maxT);
}
