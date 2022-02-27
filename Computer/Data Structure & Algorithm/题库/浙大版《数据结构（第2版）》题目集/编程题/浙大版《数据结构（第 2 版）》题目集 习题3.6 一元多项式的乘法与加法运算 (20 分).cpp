#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *PtrToPolyNode;
struct PolyNode {
  int Coef;
  int Expon;
  PtrToPolyNode Next;
};
typedef PtrToPolyNode Polynomial;

void Attach(
    int Coef, int Expon,
    Polynomial *PtrRear) { /* 将由(Coef,
                              Expon)构成的新项插入到PtrRear间接指向的结点后面 */
  Polynomial P;

  P = (Polynomial)malloc(sizeof(struct PolyNode)); /* 申请一新结点 */
  P->Coef = Coef;                                  /* 对新结点赋值  */
  P->Expon = Expon;
  P->Next = NULL;
  (*PtrRear)->Next = P; /* 将P指向的新项插入到当前结果表达式尾项的后面 */
  *PtrRear = P; /* 修改PtrRear值 */
}

Polynomial ReadPoly() { /* 读入并建立多项式 */
  Polynomial P, Rear, t;
  int Coef, Expon, N;

  scanf("%d", &N);
  /* 为了程序处理方便起见，先构造一个链表头空结点 */
  P = (Polynomial)malloc(sizeof(struct PolyNode));
  P->Next = NULL;
  Rear = P;
  while (N--) {
    scanf("%d %d", &Coef, &Expon);
    Attach(Coef, Expon, &Rear); /* 将当前项插入多项式尾部 */
  }
  /* 删除临时生成的头结点 */
  t = P;
  P = P->Next;
  free(t);
  return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2) {
  Polynomial P, Rear, t1, t2, t;
  int Coef, Expon;

  if (!P1 or !P2) return NULL;

  t1 = P1;
  t2 = P2;
  P = (Polynomial)malloc(sizeof(struct PolyNode));
  P->Next = NULL;
  Rear = P;
  while (t2) { /* 先用P1的第1项乘以P2，得到P */
    Attach(t1->Coef * t2->Coef, t1->Expon + t2->Expon, &Rear);
    t2 = t2->Next;
  }
  t1 = t1->Next;
  while (t1) { /* 用P1的每一项乘以P2 */
    t2 = P2;
    Rear = P;
    while (t2) { /* P1与P2的两项相乘并插入P */
                 /* 计算乘积项 */
      Expon = t1->Expon + t2->Expon;
      Coef = t1->Coef * t2->Coef;
      /* 找到合适的插入位置 */
      while (Rear->Next and Rear->Next->Expon > Expon) Rear = Rear->Next;
      /* 如果P有指数相同的项，叠加 */
      if (Rear->Next and Rear->Next->Expon == Expon) {
        if (Rear->Next->Coef + Coef)
          Rear->Next->Coef += Coef;
        else { /* 如果系数叠加后为0，则删除该项 */
          t = Rear->Next;
          Rear->Next = t->Next;
          free(t);
        }
      } else { /* P中没有指数相同项，插入新结点 */
        t = (Polynomial)malloc(sizeof(struct PolyNode));
        t->Coef = Coef;
        t->Expon = Expon;
        t->Next = Rear->Next;
        Rear->Next = t;
        Rear = Rear->Next;
      }
      t2 = t2->Next;
    }
    t1 = t1->Next;
  }
  /* 删除临时生成的头结点 */
  t = P;
  P = P->Next;
  free(t);

  return P;
}

int Compare(
    int e1,
    int e2) { /*比较两项指数e1和e2，根据大、小、等三种情况分别返回1，-1，0 */
  if (e1 > e2)
    return 1; /* e1大，返回1       */
  else if (e1 < e2)
    return -1; /* e2大，返回-1      */
  else
    return 0; /* e1和e2相等，返回0 */
}

Polynomial Add(Polynomial P1, Polynomial P2) {
  Polynomial front, rear, temp;
  int sum;

  /* 为方便表头插入，先产生一个临时空结点作为结果多项式链表头 */
  rear = (Polynomial)malloc(sizeof(struct PolyNode));
  front = rear;     /* 由front 记录结果多项式链表头结点 */
  while (P1 and P2) /* 当两个多项式都有非零项待处理时 */
    switch (Compare(P1->Expon, P2->Expon)) {
      case 1: /* P1中的数据项指数较大 */
        Attach(P1->Coef, P1->Expon, &rear);
        P1 = P1->Next;
        break;
      case -1: /* P2中的数据项指数较大 */
        Attach(P2->Coef, P2->Expon, &rear);
        P2 = P2->Next;
        break;
      case 0: /* 两数据项指数相等 */
        sum = P1->Coef + P2->Coef;
        if (sum) Attach(sum, P1->Expon, &rear);
        P1 = P1->Next;
        P2 = P2->Next;
        break;
    }
  /* 将未处理完的另一个多项式的所有节点依次复制到结果多项式中去 */
  for (; P1; P1 = P1->Next) Attach(P1->Coef, P1->Expon, &rear);
  for (; P2; P2 = P2->Next) Attach(P2->Coef, P2->Expon, &rear);
  rear->Next = NULL;
  temp = front;
  front = front->Next; /*令front指向结果多项式第一个非零项 */

  free(temp); /* 释放临时空表头结点 */
  return front;
}

void PrintPoly(Polynomial P) { /* 输出多项式 */
  if (!P)
    printf("0 0\n"); /* 输出零多项式 */
  else {
    printf("%d %d", P->Coef, P->Expon);
    P = P->Next;
    while (P) {
      printf(" %d %d", P->Coef, P->Expon);
      P = P->Next;
    }
    printf("\n");
  }
}

int main() {
  Polynomial P1, P2, P, Q;

  P1 = ReadPoly();
  P2 = ReadPoly();
  P = Mult(P1, P2);
  Q = Add(P1, P2);
  PrintPoly(P);
  PrintPoly(Q);

  return 0;
}
