// 逐位累加
#include <stdio.h>

#define MAXN 100000

int main() {
  int A, N;
  int i, S[MAXN], C;

  scanf("%d %d", &A, &N);
  if (!N) { /* 处理N为0时的特殊情况 */
    printf("0\n");
    return 0;
  }
  for (i = 0; i < N; i++) S[i] = 0; /* 初始化大数和各位均为0 */
  C = 0;                            /* 初始化进位为0 */
  for (i = 0; i < N; i++) {         /* 对每一位 */
    C += A * (N - i);               /* 直接计算累加结果 */
    S[i] = C % 10;
    C /= 10;
  }
  if (C) printf("%d", C); /* 输出最高位的进位 */
  for (i = N - 1; i >= 0; i--) printf("%d", S[i]);
  printf("\n");

  return 0;
}

// 简单大数加法
// #include <stdio.h>

// #define MAXN 100000

// int main() {
//     int A, N;
//     int S[MAXN], K[MAXN], C, i, j;

//     scanf("%d %d", &A, &N);
//     if (!N) { /* 处理N为0时的特殊情况 */
//         printf("0\n");
//         return 0;
//     }
//     for (i = 0; i < N; i++) {
//         S[i] = 0; /* 初始化大数和各位均为0 */
//         K[i] = A; /* 数列项的每位都是A */
//     }
//     C = 0;                         /* 初始化进位为0 */
//     for (i = 0; i < N; i++) {      /* 对每个数列项K[0]~K[i]*/
//         for (j = 0; j <= i; j++) { /* 逐位求和 */
//             S[j] += (K[j] + C);
//             C = S[j] / 10;
//             S[j] %= 10;
//         }
//     }
//     if (C)
//         printf("%d", C); /* 输出最高位的进位 */
//     for (i = N - 1; i >= 0; i--)
//         printf("%d", S[i]);
//     printf("\n");

//     return 0;
// }

// 简单计算
// #include <stdio.h>

// int main() {
//     int A, N, K, S, i;

//     scanf("%d %d", &A, &N);
//     if (!N) { /* 处理N为0时的特殊情况 */
//         printf("0\n");
//         return 0;
//     }
//     S = K = A; /* 初始化K和总和S */
//     for (i = 1; i < N; i++) {
//         K = K * 10 + A; /* 计算下一个数列项 */
//         S += K;
//     }
//     printf("%d\n", S);

//     return 0;
// }
