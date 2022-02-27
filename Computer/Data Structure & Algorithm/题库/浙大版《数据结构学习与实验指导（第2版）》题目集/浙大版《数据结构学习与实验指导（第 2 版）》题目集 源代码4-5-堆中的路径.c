#include <stdio.h>
#include <stdlib.h>

#define MINDATA -10001 /* ����Сֵ��С���ڱ� */
typedef int ElementType;

typedef struct HNode *Heap; /* �ѵ����Ͷ��� */
struct HNode {
  ElementType *Data; /* �洢Ԫ�ص����� */
  int Size;          /* ���е�ǰԪ�ظ��� */
  int Capacity;      /* �ѵ�������� */
};
typedef Heap MinHeap; /* ��С�� */

MinHeap CreateHeap(int MaxSize);
void Insert(MinHeap H, ElementType X);

int main() {
  int N, M, i, j;
  ElementType X;
  MinHeap H;

  scanf("%d %d", &N, &M);
  H = CreateHeap(N); /* �����ն� */
  for (i = 0; i < N; i++) {
    scanf("%d", &X);
    Insert(H, X); /* ��һ���� */
  }
  for (j = 0; j < M; j++) { /* ��һ��ӡ·�� */
    scanf("%d", &i);
    printf("%d", H->Data[i]);   /* ����������H[i] */
    for (i /= 2; i > 0; i /= 2) /* ˳�η���H[i]�ĸ���� */
      printf(" %d", H->Data[i]);
    printf("\n");
  }
  return 0;
}

MinHeap CreateHeap(int MaxSize) { /* ��������ΪMaxSize�Ŀյ����� */

  MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
  H->Data = (ElementType *)malloc((MaxSize + 1) * sizeof(ElementType));
  H->Size = 0;
  H->Capacity = MaxSize;
  H->Data[0] =
      MINDATA; /* ����"�ڱ�"ΪС�ڶ������п���Ԫ�ص�ֵ
                */

  return H;
}

void Insert(
    MinHeap H,
    ElementType
        X) { /* ��Ԫ��X������С��H������H->Data[0]�Ѿ�����Ϊ�ڱ�
              */
  int i;
  for (i = ++H->Size; H->Data[i / 2] > X; i /= 2)
    H->Data[i] = H->Data[i / 2]; /* ����X */
  H->Data[i] = X;                /* ��X���� */
}
