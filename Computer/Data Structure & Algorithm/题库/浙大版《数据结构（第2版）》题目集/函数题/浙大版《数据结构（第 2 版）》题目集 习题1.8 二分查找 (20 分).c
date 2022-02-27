// 非递归实现
Position BinarySearch(
    List L, ElementType X) { /* 在顺序存储的表L中查找关键字为X的数据元素 */
  Position Left, Right, Mid;

  Left = 1;        /* 初始左边界下标值 */
  Right = L->Last; /* 初始右边界下标值 */
  while (Left <= Right) {
    Mid = (Left + Right) / 2; /* 计算中间元素坐标 */
    if (L->Data[Mid] > X)
      Right = Mid - 1; /* 调整右边界 */
    else if (L->Data[Mid] < X)
      Left = Mid + 1; /* 调整左边界 */
    else              /* L->Data[Mid] == X */
      return Mid;     /* 查找成功，返回数据元素的下标 */
  }
  return NotFound; /* 返回查找不成功的标识 */
}

// 递归实现
// Position BS(List L, ElementType X, Position Left, Position Right) { /*
// Left和Right分别是当前要处理的L->Data[]中最左和最右的下标值 */

//     if (Left > Right)    /* 如果当前范围内没有元素了 */
//         return NotFound; /* 返回查找不成功的标识 */

//     Position Mid = (Left + Right) / 2; /* 计算中间元素坐标 */
//     if (L->Data[Mid] > X)
//         return BS(L, X, Left, Mid - 1); /*在左边的子系列中查找*/
//     else if (L->Data[Mid] < X)
//         return BS(L, X, Mid + 1, Right); /*在右边的子系列中查找*/
//     else                                 /* L->Data[Mid] == X */
//         return Mid;                      /* 查找成功，返回数据元素的下标 */
// }

// Position BinarySearch(List L, ElementType X) { /*
// 在顺序存储的表L中查找关键字为X的数据元素 */

//     return BS(L, X, 1, L->Last);
// }
