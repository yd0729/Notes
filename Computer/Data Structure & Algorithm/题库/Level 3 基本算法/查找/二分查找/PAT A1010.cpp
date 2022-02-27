#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
char n[2][15];
int val(char a) {  // 把 0 - 9 和 a - z 转换成对应的数字
  if (isdigit(a))
    return a - '0';
  else
    return a - 'a' + 10;
}
ll rad_val(char x[], int rad) {  // 获得 rad 进制的 x 的值
  ll v = 0;
  for (int i = 0; x[i] != '\0'; ++i) {
    v = v * rad + val(x[i]);
    if (v <= 0) return -1;  // 溢出返回 -1
  }
  return v;
}
ll b_search(char x[], ll v) {  // 二分答案 x：未知进制的数，v：已知进制数的值
  ll left = val(*max_element(x, x + strlen(x))) + 1, right = v + 1;
  while (left <= right) {
    ll mid = (left + right) / 2, val = rad_val(x, mid);
    if (val < 0 or val > v)
      right = mid - 1;
    else if (val < v)
      left = mid + 1;
    else if (val == v)
      return mid;
  }
  return -1;
}
int main() {
  int tag, r;
  scanf("%s %s %d %d", n, n + 1, &tag, &r);
  if (tag == 2) swap(n[0], n[1]);
  ll v = rad_val(n[0], r), rad = b_search(n[1], v);
  if (rad == -1)
    printf("Impossible");
  else
    printf("%lld", rad);
}
