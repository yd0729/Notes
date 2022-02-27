List Insert(List L, ElementType X) {
  List Pre, Tmp;

  Pre = L;            /* 前驱结点从头结点开始 */
  while (Pre->Next) { /* 当Pre的下一个结点存在时 */
    if (X < Pre->Next->Data)
      break; /* 找到第一个比X大的结点 */
    else
      Pre = Pre->Next;
  }
  Tmp = (PtrToNode)malloc(sizeof(struct Node));
  Tmp->Data = X; /* 建立X结点 */
  Tmp->Next = Pre->Next;
  Pre->Next = Tmp; /* 将X插入Pre后一个位置 */

  return L;
}
