#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

typedef enum { ret, lc, lbrc, lbrkt, lpr, rc, rbrc, rbrkt, rpr, others } Token;
typedef Token ElementType;

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
void Pop(Stack S);
/*-----堆栈的定义结束 -----*/

bool IsEnd(int newline, char *c);
Token GetToken(char c);
bool IsPaired(Token t1, Token t2);
void PrintS(Token t);
int Check(Token *T1, Token *T2);

int main() {
  Token T1, T2;
  int error = Check(&T1, &T2);

  if (!error)
    printf("YES\n");
  else {
    printf("NO\n");
    switch (error) {
      case 1:
        printf("?-");
        PrintS(T1);
        break;
      case 2:
        PrintS(T2);
        printf("-?");
        break;
      default:
        break;
    }
    printf("\n");
  }
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

void Push(Stack S, ElementType X) { S->Data[++(S->Top)] = X; }

ElementType Peek(Stack S) { return (S->Data[S->Top]); }

void Pop(Stack S) { (S->Top)--; }

int Check(Token *T1, Token *T2) {
  Stack S;            /* 检测匹配用的堆栈 */
  char c;             /* 存读入的字符 */
  Token t;            /* 存字符转换后的类型 */
  int newline, error; /* newline标识当前是否新行，error标识错误 */

  S = CreateStack(MAXN);
  newline = 1;
  error = 0; /* 初始为新行，没有错误 */
  while (1) {
    scanf("%c", &c);
    if (IsEnd(newline, &c))
      break; /* 如果已经读到结尾，则跳出循环 */
    else {
      switch (t = GetToken(c)) { /* 解析c的类型 */
        /* 如果是左半符 */
        case lc:
        case lbrc:
        case lbrkt:
        case lpr:
          /* 左半符入栈，不再是新行 */
          Push(S, t);
          newline = 0;
          break;
          /* 如果是右半符 */
        case rc:
        case rbrc:
        case rbrkt:
        case rpr:
          /* 若堆栈已空，右半符不匹配 */
          if (IsEmpty(S)) error = 1;
          /* 若栈顶元素和当前读入不匹配，左半符不匹配*/
          else if (!IsPaired(t, Peek(S)))
            error = 2;
          else
            Pop(S);    /* 一切正常，消去一对 */
          newline = 0; /* 不再是新行 */
          break;
        case ret:
          newline = 1;
          break; /* 遇回车则标识新行 */
        default:
          newline = 0;
          break; /* 其他字符跳过不处理 */
      }
      if (error) break; /* 如果发现错误则跳出循环 */
    }
  }
  /* 读到结尾时堆栈还没空，左半符有多 */
  if (!error and !IsEmpty(S)) error = 2;
  (*T1) = t;
  (*T2) = Peek(S);

  return error;
}

bool IsEnd(int newline, char *c) { /* 判断是否读到结尾 */
  if (newline and (*c) == '.') {
    scanf("%c", c);
    if ((*c) == '\n')
      return true;
    else
      return false;
  } else
    return false;
}

Token GetToken(char c) { /* 返回字符的类型 */
  switch (c) {
    case '\n':
      return ret;
    case '{':
      return lbrc;
    case '[':
      return lbrkt;
    case '(':
      return lpr;
    case '/':
      scanf("%c", &c);
      if (c == '*')
        return lc;
      else
        return GetToken(c);
      /* 如果不是左注释符，还要检查c的类型 */
    case '}':
      return rbrc;
    case ']':
      return rbrkt;
    case ')':
      return rpr;
    case '*':
      scanf("%c", &c);
      if (c == '/')
        return rc;
      else
        return GetToken(c);
      /* 如果不是右注释符，还要检查c的类型 */
    default:
      return others;
  }
}

bool IsPaired(Token t1, Token t2) {
  return (t1 - t2) == 4;
  /* t1是右半符，t2是左半符 */
  /* 如果它们的enum值差4，说明是匹配的 */
}

void PrintS(Token t) {
  switch (t) {
    case lc:
      printf("/*");
      break;
    case lbrc:
      printf("{");
      break;
    case lbrkt:
      printf("[");
      break;
    case lpr:
      printf("(");
      break;
    case rc:
      printf("*/");
      break;
    case rbrc:
      printf("}");
      break;
    case rbrkt:
      printf("]");
      break;
    case rpr:
      printf(")");
      break;
    default:
      break;
  }
}
