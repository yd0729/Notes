PtrToNode Suffix(List L1, List L2) {
  int Len1 = 0, Len2 = 0;
  PtrToNode T1 = L1->Next, T2 = L2->Next;
  for (; T1; T1 = T1->Next) Len1++;
  for (; T2; T2 = T2->Next) Len2++;

  T1 = L1->Next;
  T2 = L2->Next;
  for (int i = 0; i < Len1 - Len2; i++) {
    T1 = T1->Next;
  }
  for (int i = 0; i < Len2 - Len1; i++) {
    T2 = T2->Next;
  }

  while (T1 and T1 != T2) {
    T1 = T1->Next;
    T2 = T2->Next;
  }

  return T1;
}