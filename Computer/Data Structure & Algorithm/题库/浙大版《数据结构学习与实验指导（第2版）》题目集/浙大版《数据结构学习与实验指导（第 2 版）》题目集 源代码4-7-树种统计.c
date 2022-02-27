#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100000
#define MAXS 30

typedef struct TreeNode *BinTree;
struct TreeNode {
  char Data[MAXS + 1];
  int Cnt;
  BinTree Left;
  BinTree Right;
};

BinTree Insert(BinTree T,
               char *Name) { /* ������Name�������������T�����ۼ��Ѵ������� */
  int cmp;

  if (!T) { /* ������1����� */
    T = malloc(sizeof(struct TreeNode));
    strcpy(T->Data, Name);
    T->Cnt = 1;
    T->Left = T->Right = NULL;
  } else {                       /* ���� */
    cmp = strcmp(Name, T->Data); /* �Ƚ��������� */
    if (cmp < 0)
      T->Left = Insert(T->Left, Name);
    else if (cmp > 0)
      T->Right = Insert(T->Right, Name);
    else
      T->Cnt++; /* ���ִ��ڣ����� */
  }
  return T;
}

void Output(BinTree T, int N) {
  if (!T) return;     /* �ݹ���ֹ���� */
  Output(T->Left, N); /* ��������� */
  printf("%s %.4lf%c\n", T->Data, (double)T->Cnt / (double)N * 100.0, '%');
  Output(T->Right, N); /* ��������� */
}

int main() {
  int N, i;
  char Name[MAXS + 1];
  BinTree T = NULL;

  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    gets(Name);
    T = Insert(T, Name);
  }
  Output(T, N);

  return 0;
}
