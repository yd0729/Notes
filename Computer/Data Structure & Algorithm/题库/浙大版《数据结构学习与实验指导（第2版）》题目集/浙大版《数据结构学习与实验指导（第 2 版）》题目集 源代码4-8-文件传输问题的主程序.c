#include <stdio.h>

#define MaxSize 10000
typedef int ElementType;
typedef int SetName;

/*-----���϶���-----*/
typedef ElementType SetType[MaxSize];
void Initialization(SetType S, int n);
void Union(SetType S, SetName Root1, SetName Root2);
SetName Find(SetType S, ElementType X);
/*-----���϶������-----*/

void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S, int n);

int main() {
  SetType S;
  int n;
  char in;

  scanf("%d\n", &n);
  Initialization(S, n);
  do {
    scanf("%c", &in);
    switch (in) {
      case 'I':
        Input_connection(S);
        break;
      case 'C':
        Check_connection(S);
        break;
      case 'S':
        Check_network(S, n);
        break;
    }
  } while (in != 'S');
  return 0;
}
