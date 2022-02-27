#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
  ElementType Data[MAXSIZE];
  Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput() {
  List L;
  int N;

  L = (List)malloc(sizeof(struct LNode));
  scanf("%d", &N);
  for (L->Last = 0; L->Last < N; L->Last++) scanf("%d", &L->Data[L->Last]);
  L->Last--;
  return L;
}

void PrintResult(List L, Position Left, Position Right) {
  Position i;

  printf("%d", L->Data[Left]);
  for (i = Left + 1; i <= Right; i++) printf(" %d", L->Data[i]);
  printf("\n");
}

int main() {
  List L;
  Position Left, Right, thisL, thisR, i;
  int maxLen, thisLen;

  L = ReadInput(); /* 读入整个序列 */
  /* 初始化当前子序列为Data[0] */
  Left = Right = thisL = thisR = 0;
  maxLen = thisLen = 1;

  for (i = 1; i <= L->Last; i++) {
    if (L->Data[i] > L->Data[i - 1]) { /*递增*/
      thisLen++;                       /* 当前长度递增*/
      thisR++;                         /* 当前右端点延伸 */
    } else {                           /* Data[i]不属于当前子序列 */
      if (thisLen > maxLen) {          /*更长序列 */
        maxLen = thisLen;
        Left = thisL;
        Right = thisR;
      }
      /* 将Data[i]计入下一个子序列 */
      thisLen = 1;
      thisL = thisR = i;
    }
  }
  if (thisLen > maxLen) { /* 处理末尾的子序列 */
    maxLen = thisLen;
    Left = thisL;
    Right = thisR;
  }
  PrintResult(L, Left, Right);

  return 0;
}
