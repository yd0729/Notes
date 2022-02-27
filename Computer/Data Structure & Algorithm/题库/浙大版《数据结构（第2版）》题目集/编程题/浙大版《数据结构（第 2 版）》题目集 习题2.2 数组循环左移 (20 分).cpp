// 最优解
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int N, M;
  cin >> N >> M;
  M %= N;

  vector<int> Number(N);
  for (int i = 0; i < N; i++) {
    cin >> Number[i];
  }

  int Loop = gcd(M, N);
  for (int i = 0; i < Loop; i++) {
    int head = i, tmp = Number[i];
    do {
      int nxt = (i - M + N) % N;
      swap(Number[nxt], tmp);
      i = nxt;
    } while (i != head);
  }

  for (int i = 0; i < N; ++i) {
    cout << Number[i] << (i == N - 1 ? "\n" : " ");
  }
}

// 3N 次位移解
// #include <stdio.h>

// #define MAXN 100
// #define Swap(a, b) a ^= b, b ^= a, a ^= b;
// /* 通过连续三次异或运算交换a与b */

// void LeftShift(int Array[], int N, int M);

// int main() {
//     int Number[MAXN], N, M;
//     int i;

//     scanf("%d %d", &N, &M);
//     for (i = 0; i < N; i++)
//         scanf("%d", &Number[i]);
//     M %= N;                  /* 当M大于等于N时转化成等价的小于N的数 */
//     LeftShift(Number, N, M); /* 循环左移M位　*/
//     printf("%d", Number[0]); /* 打印输出 */
//     for (i = 1; i < N; i++)
//         printf(" %d", Number[i]);
//     printf("\n");

//     return 0;
// }

// void LeftShift(int Array[], int N, int M) {
//     int i, j;

//     if (M > 0 and M < N) {
//         for (i = 0, j = N - 1; i < j; i++, j--) /* 逆转N个数据 */
//             Swap(Array[i], Array[j]);
//         for (i = 0, j = N - M - 1; i < j; i++, j--) /* 逆转前N-M个数据 */
//             Swap(Array[i], Array[j]);
//         for (i = N - M, j = N - 1; i < j; i++, j--) /* 逆转后M个数据 */
//             Swap(Array[i], Array[j]);
//     }
// }

// 简单解
// #include <stdio.h>

// #define MAXN 100

// void Shift(int Array[], int N);

// int main() {
//     int Number[MAXN], N, M;
//     int i;

//     scanf("%d%d", &N, &M);
//     for (i = 0; i < N; i++)
//         scanf("%d", &Number[i]);
//     M %= N; /* 当M大于等于N时转化成等价的小于N的数　*/
//     for (i = 0; i < M; i++)
//         Shift(Number, N);       /* N个元素循环位移1位 */
//     for (i = 0; i < N - 1; i++) /* 打印输出 */
//         printf("%d ", Number[i]);
//     printf("%d\n", Number[N - 1]);
//     return 0;
// }

// void Shift(int Array[], int N) {
//     int i, ArrayHead;

//     ArrayHead = Array[0];
//     for (i = 0; i < N - 1; i++) /* N个元素循环位移1位 */
//         Array[i] = Array[i + 1];
//     Array[N - 1] = ArrayHead;
// }
