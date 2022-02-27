#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct {
  int N;       /* 盘数  */
  char A;      /* 起始柱  */
  char B;      /* 借助柱  */
  char C;      /* 目标柱  */
} ElementType; /* 汉诺塔问题结构类型 */

/*-----堆栈的定义 -----*/
typedef int Position;
typedef struct SNode *PtrToSNode;
struct SNode {
  ElementType *Data;
  Position Top;
  int MaxSize;
};
typedef PtrToSNode Stack;

Stack CreateStack(int MaxSize);
bool IsEmpty(Stack S);
void Push(Stack S, ElementType X);
ElementType Pop(Stack S);
/*-----堆栈的定义结束 -----*/

void Hanoi(int n) /* 借助堆栈的非递归实现 */
{
  Stack S;
  ElementType P, toPush;

  /* 初始化 */
  S = CreateStack(MAXSIZE);
  P.N = n;
  P.A = 'a';
  P.B = 'b';
  P.C = 'c';
  Push(S, P);           /* 将初始问题(n,a,b,c)放入堆栈 */
  while (!IsEmpty(S)) { /* 当堆栈不空时 */
    P = Pop(S);
    if (P.N == 1)
      printf("%c -> %c\n", P.A, P.C);
    else {
      toPush.N = P.N - 1;
      toPush.A = P.B;
      toPush.B = P.A;
      toPush.C = P.C;
      Push(S, toPush); /* 将第二个待解子问题(n-1,b,a,c)入栈 */
      toPush.N = 1;
      toPush.A = P.A;
      toPush.B = P.B;
      toPush.C = P.C;
      Push(S, toPush); /* 将可直接求解的子问题(1,a,b,c)入栈 */
      toPush.N = P.N - 1;
      toPush.A = P.A;
      toPush.B = P.C;
      toPush.C = P.B;
      Push(S, toPush); /* 将第一个待解子问题(n-1,a,c,b)入栈 */
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  Hanoi(n);
  return 0;
}

Stack CreateStack(int MaxSize) {
  Stack S = (Stack)malloc(sizeof(struct SNode));
  S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
  S->Top = -1;
  S->MaxSize = MaxSize;
  return S;
}

bool IsEmpty(Stack S) { return (S->Top == -1); }

void Push(Stack S, ElementType X) { /* 简版入栈，不担心栈满的问题 */
  S->Data[++(S->Top)] = X;
}

ElementType Pop(Stack S) { /* 简版出栈，不担心栈空的问题 */
  return (S->Data[(S->Top)--]);
}
