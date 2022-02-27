// 线性复杂度算法
List Delete(List L, ElementType minD, ElementType maxD) {
  int i, p;

  for (i = 0; i <= L->Last; i++)
    if ((L->Data[i] > minD) and (L->Data[i] < maxD))
      break;                /*找到第1个待删元素*/
  p = i;                    /* p指向最左边可以填充的空格 */
  for (; i <= L->Last; i++) /* i继续向右扫描 */
    if (!((L->Data[i] > minD) and (L->Data[i] < maxD))) /* 对每个应保留的元素 */
      L->Data[p++] = L->Data[i]; /* 将之存到最左边可以填充的空格 */
  /* p继续向右移动1格，指向下一个最左边可以填充的空格 */
  L->Last = p - 1; /* p最后指向表尾最后一个空格处 */

  return L;
}

// 平方复杂度算法
// List Delete(List L, ElementType minD, ElementType maxD) {
//     int i, j;

//     for (i = 0; i <= L->Last; i++)                        /*
//     扫描每个元素L->Data[i] */
//         if ((L->Data[i] > minD) and (L->Data[i] < maxD)) { /* 如果要删除 */
//             for (j = i + 1; j <= L->Last; j++)
//                 L->Data[j - 1] = L->Data[j]; /* 整体左移 */
//             L->Last--;                       /* /* 更新表长L->Last */
//             i--;                             /*
//             令i指向当前最后一个不删除的元素*/
//         }

//     return L;
// }
