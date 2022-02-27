// 保证字典序
#include <stdio.h>

#define MAXN 9

void RightShift(int L[], int Left, int i) {
  int j, Tmp = L[i];
  for (j = i; j > Left; j--) L[j] = L[j - 1];
  L[j] = Tmp;
}

void LeftShift(int L[], int Left, int i) {
  int j, Tmp = L[Left];
  for (j = Left; j < i; j++) L[j] = L[j + 1];
  L[j] = Tmp;
}

void Permutation(int L[], int Left,
                 int Right) { /* 递归处理从L[Left]到L[Right]的全排列 */
  int i;
  if (Left == Right) { /* 如果只剩1个数字，就输出当前的一组排列 */
    for (i = 0; i <= Right; i++) printf("%d", L[i]);
    printf("\n");
  } else {
    for (i = Left; i <= Right; i++) {
      RightShift(L, Left, i);
      Permutation(L, Left + 1, Right);
      LeftShift(L, Left, i);
    }
  }
}

int main() {
  int N, L[MAXN], i;

  scanf("%d", &N);
  for (i = 0; i < N; i++) L[i] = i + 1;
  Permutation(L, 0, N - 1);

  return 0;
}

// 不保证字典序
// #include <stdio.h>

// #define MAXN 9

// void Swap(int L[], int i, int j) { /* 交换L[i]和L[j] */
//     int Tmp = L[i];
//     L[i] = L[j];
//     L[j] = Tmp;
// }

// void Permutation(int L[], int Left, int Right) { /*
// 递归处理从L[Left]到L[Right]的全排列 */
//     int i;

//     if (Left == Right) { /* 如果只剩1个数字，就输出当前的一组排列 */
//         for (i = 0; i <= Right; i++)
//             printf("%d", L[i]);
//         printf("\n");
//     } else {
//         for (i = Left; i <= Right; i++) {
//             Swap(L, Left, i);                /* 挑出第i个数字，交换到最左边
//             */ Permutation(L, Left + 1, Right); /* 递归解决剩余问题 */
//             Swap(L, Left, i);                /* 完成一次排列后恢复原貌 */
//         }
//     }
// }

// int main() {
//     int N, L[MAXN], i;

//     scanf("%d", &N);
//     for (i = 0; i < N; i++)
//         L[i] = i + 1; /* 将1~N顺序存入数组 */
//     Permutation(L, 0, N - 1);

//     return 0;
// }
