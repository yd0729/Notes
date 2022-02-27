#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 21

typedef char ElementType;

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
ElementType Peek(Stack S);
ElementType Pop(Stack S);
/*-----堆栈的定义结束 -----*/

typedef enum {
  lpr,
  rpr,
  plus = 2,
  minus = 2,
  times = 3,
  divide = 3,
  eos = 4,
  operand
} Precedence; /* 运算符的优先级类型 */

bool IsSign(char *expr, int i);
char GetOp(char *expr, int *i, char *Postfix, int *j);
Precedence GetToken(char op);
void ToPostfix(char *Expr);

int main() {
  char Str[MAXL];

  scanf("%s", Str);
  ToPostfix(Str);
  return 0;
}

void ToPostfix(char *expr) {
  int i, j, L;
  char Postfix[2 * MAXL], Op;
  Stack S;
  Precedence token;

  S = CreateStack(MAXL);
  L = strlen(expr);
  j = 0; /* j指向Postfix[]中当前要写入的位置 */
  for (i = 0; i < L; i++) {
    Op = GetOp(expr, &i, Postfix, &j);
    token = GetToken(Op);
    if (token == operand) continue; /* 不处理数字 */
    switch (token) {                /* 处理运算符 */
      case lpr:
        Push(S, '(');
        break;  /* 左括号入栈 */
      case rpr: /* 括号内的中缀表达式已经扫描完毕 */
        /* 把左括号前的所有运算符写入Postfix[]*/
        while (Peek(S) != '(') {
          Postfix[j++] = Pop(S);
          Postfix[j++] = ' ';
        }
        Pop(S); /* 删除左括号 */
        break;
      default: /* 其它运算符 */
        while (!IsEmpty(S) and Peek(S) != '(' and token <= GetToken(Peek(S))) {
          Postfix[j++] = Pop(S);
          Postfix[j++] = ' ';
        }
        Push(S, Op);
        break;
    }
  }
  while (!IsEmpty(S)) {
    Postfix[j++] = Pop(S);
    Postfix[j++] = ' ';
  }
  Postfix[j - 1] = '\0';
  printf("%s\n", Postfix);
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

ElementType Peek(Stack S) { return (S->Data[S->Top]); }

ElementType Pop(Stack S) { /* 简版出栈，不担心栈空的问题 */
  return (S->Data[(S->Top)--]);
}

bool IsSign(char *expr, int i) {
  if (!i or (!isdigit(expr[i - 1]) and (expr[i - 1] != ')')))
    return true;
  else
    return false;
}

char GetOp(char *expr, int *i, char *Postfix,
           int *j) { /* 如果是数字则直接写入Postfix[]并返回'0'；
如果是运算符则返回字符 */

  if (isdigit(expr[(*i)])) { /* 读入一个纯数字 */
    while (isdigit(expr[(*i)]) or (expr[(*i)] == '.'))
      Postfix[(*j)++] = expr[(*i)++];
    Postfix[(*j)++] = ' ';
    (*i)--;
    return '0';
  }
  switch (expr[(*i)]) {
    case '+':
      if (IsSign(expr, (*i))) { /* 如果是正号 */
        (*i)++;
        return GetOp(expr, i, Postfix, j);
      } else
        return '+';
    case '-':
      if (IsSign(expr, (*i))) { /* 如果是负号 */
        Postfix[(*j)++] = '-';
        (*i)++;
        return GetOp(expr, i, Postfix, j);
      } else
        return '-';
    default:
      return expr[(*i)];
  }
}

Precedence GetToken(char op) { /* 返回运算符优先级类型 */
  switch (op) {
    case '(':
      return lpr;
    case ')':
      return rpr;
    case '+':
      return plus;
    case '-':
      return minus;
    case '*':
      return times;
    case '/':
      return divide;
    case '\0':
      return eos;
    default:
      return operand;
  }
}
