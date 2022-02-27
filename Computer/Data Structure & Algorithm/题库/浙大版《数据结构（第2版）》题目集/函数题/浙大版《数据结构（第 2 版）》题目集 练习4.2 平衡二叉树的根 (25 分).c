#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct AVLNode *Position;
typedef Position AVLTree; /* AVL树类型 */
struct AVLNode {
  ElementType Data; /* 结点数据 */
  AVLTree Left;     /* 指向左子树 */
  AVLTree Right;    /* 指向右子树 */
  int H;            /* 树高 */
};

int Max(int a, int b) { return a > b ? a : b; }

int GetH(AVLTree T);
AVLTree LL(AVLTree A);
AVLTree RR(AVLTree A);
AVLTree LR(AVLTree A);
AVLTree RL(AVLTree A);
AVLTree Insert(AVLTree T, ElementType X);

int main() {
  int N, K, i;
  AVLTree T = NULL; /* 初始为空的AVL树 */

  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &K);
    T = Insert(T, K); /* 逐一插入 */
  }
  printf("%d\n", T->Data); /* 打印根结点 */

  return 0;
}

int GetH(AVLTree T) { /* 返回T的高度 */
  if (T)
    return T->H;
  else
    return -1;
}

AVLTree LL(AVLTree A) { /* 注意：A必须有一个左子结点B */
  AVLTree B = A->Left;
  A->Left = B->Right;
  B->Right = A;
  A->H = Max(GetH(A->Left), GetH(A->Right)) + 1;
  B->H = Max(GetH(B->Left), A->H) + 1;
  return B;
}

AVLTree RR(AVLTree A) { /* 注意：A必须有一个右子结点B */
  AVLTree B = A->Right;
  A->Right = B->Left;
  B->Left = A;
  A->H = Max(GetH(A->Left), GetH(A->Right)) + 1;
  B->H = Max(GetH(B->Left), A->H) + 1;
  return B;
}

AVLTree LR(AVLTree A) { /* LR双旋的直接实现 */
  AVLTree B, C;
  B = A->Left;
  C = B->Right;
  B->Right = C->Left;
  A->Left = C->Right;
  C->Left = B;
  C->Right = A;
  B->H = Max(GetH(B->Left), GetH(B->Right)) + 1;
  A->H = Max(GetH(A->Left), GetH(A->Right)) + 1;
  C->H = Max(B->H, A->H) + 1;
  return C;
}

AVLTree RL(AVLTree A) { /* RL双旋的直接实现 */
  AVLTree B, C;
  B = A->Right;
  C = B->Left;
  B->Left = C->Right;
  A->Right = C->Left;
  C->Right = B;
  C->Left = A;
  B->H = Max(GetH(B->Left), GetH(B->Right)) + 1;
  A->H = Max(GetH(A->Left), GetH(A->Right)) + 1;
  C->H = Max(B->H, A->H) + 1;
  return C;
}

AVLTree Insert(AVLTree T,
               ElementType X) { /* 将X插入AVL树T中，并且返回调整后的AVL树 */
  if (!T) { /* 若插入空树，则新建包含一个结点的树 */
    T = (AVLTree)malloc(sizeof(struct AVLNode));
    T->Data = X;
    T->H = 0;
    T->Left = T->Right = NULL;
  } /* if (插入空树) 结束 */

  else if (X < T->Data) {
    /* 插入T的左子树 */
    T->Left = Insert(T->Left, X);
    /* 如果需要左旋 */
    if (GetH(T->Left) - GetH(T->Right) == 2)
      if (X < T->Left->Data)
        T = LL(T); /* 左单旋 */
      else
        T = LR(T); /* 左-右双旋 */
  }                /* else if (插入左子树) 结束 */

  else if (X > T->Data) {
    /* 插入T的右子树 */
    T->Right = Insert(T->Right, X);
    /* 如果需要右旋 */
    if (GetH(T->Left) - GetH(T->Right) == -2)
      if (X > T->Right->Data)
        T = RR(T); /* 右单旋 */
      else
        T = RL(T); /* 右-左双旋 */
  }                /* else if (插入右子树) 结束 */
  /* else X == T->Data，无须插入 */
  /* 别忘了更新树高 */
  T->H = Max(GetH(T->Left), GetH(T->Right)) + 1;

  return T;
}
