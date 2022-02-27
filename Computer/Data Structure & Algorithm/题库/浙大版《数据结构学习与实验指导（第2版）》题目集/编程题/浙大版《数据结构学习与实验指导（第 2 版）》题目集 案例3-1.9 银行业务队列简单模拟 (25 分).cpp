#include <stdio.h>
#include <stdlib.h>

#define MaxQSize 1000

typedef int ElementType;

/*-----队列的定义-----*/
typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
  ElementType *Data;
  Position Front, Rear;
  int MaxSize;
};
typedef PtrToQNode Queue;

Queue CreateQueue(int MaxSize);
bool IsEmptyQ(Queue Q);
void AddQ(Queue Q, ElementType X);
ElementType DeleteQ(Queue Q);
/*-----队列的定义结束-----*/

int main() {
  int N, Customer, i;
  Queue A, B;

  /* 初始化两个队列 */
  A = CreateQueue(MaxQSize);
  B = CreateQueue(MaxQSize);

  scanf("%d", &N);
  for (i = 0; i < N; i++) { /* 根据整数的奇偶性，将每个整数插入相应队列中 */
    scanf("%d", &Customer);
    if (Customer % 2)
      AddQ(A, Customer);
    else
      AddQ(B, Customer);
  }
  /* 输出第1个顾客 */
  if (!IsEmptyQ(A))
    printf("%d", DeleteQ(A));
  else
    printf("%d", DeleteQ(B));
  /* 输出后面的顾客 */
  while (!IsEmptyQ(A) and !IsEmptyQ(B)) { /*A和B两个队列都不空 */
    printf(" %d", DeleteQ(A));
    printf(" %d", DeleteQ(B));
    if (!IsEmptyQ(A)) printf(" %d", DeleteQ(A));
  }
  while (!IsEmptyQ(A)) /*A队列不空,B空 */
    printf(" %d", DeleteQ(A));
  while (!IsEmptyQ(B)) /*B队列不空,A空 */
    printf(" %d", DeleteQ(B));
  printf("\n");
  return 0;
}

Queue CreateQueue(int MaxSize) {
  Queue Q = (Queue)malloc(sizeof(struct QNode));
  Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  Q->Front = Q->Rear = 0;
  Q->MaxSize = MaxSize;
  return Q;
}

bool IsEmptyQ(Queue Q) { return (Q->Front == Q->Rear); }

void AddQ(Queue Q, ElementType X) { /* 简版入列，不检查队列满的问题 */
  Q->Rear = (Q->Rear + 1) % Q->MaxSize;
  Q->Data[Q->Rear] = X;
}

ElementType DeleteQ(Queue Q) { /* 简版出列。不检查队列空的问题 */
  Q->Front = (Q->Front + 1) % Q->MaxSize;
  return Q->Data[Q->Front];
}
