#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX_SIZE = 1010;
int n, p = 0, nums[MAX_SIZE], cbt[MAX_SIZE];
void in_order(int root) {
  if (root > n) return;
  in_order(root * 2);
  cbt[root] = nums[p++];
  in_order(root * 2 + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", nums + i);
  sort(nums, nums + n);
  in_order(1);
  for (int i = 1; i <= n; ++i) {
    printf("%d", cbt[i]);
    if (i < n) printf(" ");
  }
}