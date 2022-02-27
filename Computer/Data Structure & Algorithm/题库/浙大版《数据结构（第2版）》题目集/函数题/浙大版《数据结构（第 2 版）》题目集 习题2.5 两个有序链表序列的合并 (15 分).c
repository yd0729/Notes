List Merge(List L1, List L2) {
  List L3, Rear;

  L3 = (PtrToNode)malloc(sizeof(struct Node)); /* 建头结点 */
  L3->Next = NULL;
  Rear = L3;                      /* 尾指针初始状态下指向头结点 */
  while (L1->Next and L2->Next) { /* 当L1和L2都没被清空时 */
    if (L1->Next->Data < L2->Next->Data) { /* 如果L1较小 */
      /* 将L1当前结点摘除，贴到L3末尾 */
      Rear->Next = L1->Next;
      L1->Next = L1->Next->Next;
      Rear->Next->Next = NULL;
      Rear = Rear->Next;
    } else { /* 如果L2较小 */
      /* 将L2当前结点摘除，贴到L3末尾 */
      Rear->Next = L2->Next;
      L2->Next = L2->Next->Next;
      Rear->Next->Next = NULL;
      Rear = Rear->Next;
    }
  }
  if (L1->Next) { /* 把L1的剩余链表转贴到L3的末尾*/
    Rear->Next = L1->Next;
    L1->Next = NULL;
  }
  if (L2->Next) { /* 把L2的剩余链表转贴到L3的末尾*/
    Rear->Next = L2->Next;
    L2->Next = NULL;
  }
  return L3;
}
