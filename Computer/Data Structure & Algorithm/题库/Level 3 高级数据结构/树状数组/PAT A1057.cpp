#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
#define lowbit(i) ((i) & -(i))  // xxx100...
const int MAX_N = 100010;
stack<int> s;
int c[MAX_N];                // 树状数组
void update(int x, int v) {  // 更新操作，将位置x的元素加上v
  for (int i = x; i < MAX_N; i += lowbit(i)) c[i] += v;  // 依次向上更新
}
int get_sum(int x) {  // 求和操作，返回1~x的元素的个数
  int sum = 0;
  for (int i = x; i > 0; i -= lowbit(i)) sum += c[i];
  return sum;
}
void peek_median() {  // 二分法求第K大
  int l = 1, r = MAX_N, mid, k = (s.size() + 1) / 2;
  while (l < r) {
    mid = (l + r) / 2;
    if (get_sum(mid) >= k)
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
}
int main() {
  int n, x;
  char str[12];
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", str);
    if (strcmp(str, "Push") == 0) {
      scanf("%d", &x);
      s.push(x);     // 入栈
      update(x, 1);  // 将位置x加1
    } else if (strcmp(str, "Pop") == 0) {
      if (s.empty())
        printf("Invalid\n");
      else {
        printf("%d\n", s.top());
        update(s.top(), -1);  // 将栈顶元素所在位置减1
        s.pop();              // 出栈
      }
    } else if (strcmp(str, "PeekMedian") == 0) {
      if (s.empty())
        printf("Invalid\n");
      else
        peek_median();
    }
  }
}