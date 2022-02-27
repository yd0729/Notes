#include <algorithm>
#include <cstdio>
#include <functional>  // 使用 greater

using namespace std;

const int SIZE = 1010;

int father[SIZE];   // 存放父节点
int is_root[SIZE];  // 记录每个节点是否作为某个集合的根节点
int hobby[SIZE];

int find(int x) {  // 查找x所在集合的根节点
  int a = x;
  while (x != father[x]) {
    x = father[x];
  }

  // 路径压缩
  while (a != father[a]) {
    int z = a;
    a = father[a];
    father[z] = x;
  }

  return x;
}

void unin(int a, int b) {  // 合并a和b所在的集合
  int faA = find(a);
  int faB = find(b);
  if (faA != faB) father[faA] = faB;
}

void init(int n) {  // 初始化father[i]为i，且flag[i]为false
  for (int i = 1; i <= n; ++i) {
    father[i] = i;
    is_root[i] = false;
  }
}

int main() {
  int n, k, h;
  scanf("%d", &n);

  init(n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d:", &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &h);
      if (hobby[h] == 0) {
        hobby[h] = i;
      }
      unin(i, find(hobby[h]));
    }
  }

  for (int i = 1; i <= n; ++i) {
    ++is_root[find(i)];
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (is_root[i] != 0) ++ans;
  }

  printf("%d\n", ans);
  sort(is_root + 1, is_root + n + 1, greater<int>());
  for (int i = 1; i <= ans; ++i) {
    printf("%d", is_root[i]);
    if (i < ans) printf(" ");
  }
}