#include <cmath>
#include <cstdio>
bool is_prime(int n) {
  if (n == 2) return true;
  if (n < 2 || n % 2 == 0) return false;
  for (int i = 3, sqr = sqrt(n); i <= sqr; i += 2)
    if (n % i == 0) return false;
  return true;
}
int num[111];
int main() {
  int n, rad;
  while (scanf("%d", &n) != EOF) {
    if (n < 0) break;  // n 是负数时退出循环
    scanf("%d", &rad);
    if (not is_prime(n))  // n 不是素数，输出 No，结束
      printf("No\n");
    else {
      int len = 0;
      do {  // 转换为raidx进制，同时逆序
        num[len++] = n % rad;
        n /= rad;
      } while (n != 0);
      for (int i = 0; i < len; ++i)  // 计算这个数在十进制下的值
        n = n * rad + num[i];
      if (is_prime(n))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
}
