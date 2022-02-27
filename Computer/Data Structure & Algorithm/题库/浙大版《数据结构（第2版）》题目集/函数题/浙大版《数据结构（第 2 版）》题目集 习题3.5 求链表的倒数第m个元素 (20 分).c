ElementType Find(List L, int m) {
  List p1, p2;
  int Counter;

  p1 = p2 = L;
  Counter = 0;
  while (p1 and (++Counter <= m)) p1 = p1->Next; /* p1移动到第m个结点 */
  if (Counter <= m) return ERROR; /* m超过了链表长度，不存在倒数第m个元素 */
  while (p1) { /* 两指针同步移动，直到p1到达表尾 */
    p1 = p1->Next;
    p2 = p2->Next;
  }
  return p2->Data; /* 此时p2指向倒数第m个元素 */
}
