PtrToNode Reverse(PtrToNode Pre, PtrToNode Rear);

void K_Reverse(List L, int K) {
  PtrToNode Pre = L, Rear = L;
  while (1) {
    int i = 0;
    for (; Rear and i < K; i++) {
      Rear = Rear->Next;
    }
    if (Rear and i == K) {
      Pre = Rear = Reverse(Pre, Rear);
    } else
      break;
  }
}

// 反转 (Pre, Rear]
PtrToNode Reverse(PtrToNode Pre, PtrToNode Rear) {
  PtrToNode Last = Pre->Next;
  for (PtrToNode T = Pre->Next; Pre->Next != Rear;) {
    PtrToNode Tmp = T;
    T = T->Next;
    Tmp->Next = Pre->Next;
    Pre->Next = Tmp;
    Last->Next = T;
  }
  return Last;
}