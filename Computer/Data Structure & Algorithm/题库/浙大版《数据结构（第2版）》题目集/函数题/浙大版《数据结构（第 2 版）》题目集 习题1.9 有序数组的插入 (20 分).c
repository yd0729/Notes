
Position BinarySearch(
    List L, ElementType X) { /* 在顺序存储的表L中查找关键字为X的数据元素 */
  Position Left, Right, Mid;

  Left = 0;        /* 初始左边界下标值 */
  Right = L->Last; /* 初始右边界下标值 */
  while (Left <= Right) {
    Mid = (Left + Right) / 2; /* 计算中间元素坐标 */
    if (L->Data[Mid] < X)
      Right = Mid - 1; /* 调整右边界 */
    else if (L->Data[Mid] > X)
      Left = Mid + 1; /* 调整左边界 */
    else              /* L->Data[Mid] == X */
      return Mid;     /* 查找成功，返回数据元素的下标 */
  }
  return Left; /* 返回应该插入的位置 */
}

bool Insert(List L, ElementType X) {
  if (L->Last == MAXSIZE - 1) {
    return false;
  }
  Position pos = BinarySearch(L, X);
  if (L->Data[pos] == X) {
    return false;
  }
  for (Position i = ++L->Last; i > pos; --i) {
    L->Data[i] = L->Data[i - 1];
  }
  L->Data[pos] = X;
  return true;
}