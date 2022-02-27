#include <algorithm>
#include <iostream>

using namespace std;

int n, ori[111], mid[111];

void down_adjust(int low, int high) {  // 对heap数组在[low, high]范围进行调整
  for (int i = low, j = i * 2; j <= high;
       i = j, j = i * 2) {  // i为欲调整节点，j为其左孩子节点
    if (j + 1 <= high and mid[j + 1] > mid[j])
      j = j + 1;  // 找出左右孩子较大的一个
    if (mid[j] > mid[i])
      swap(
          mid[j],
          mid[i]);  // 如果孩子节点中最大的权值比父亲节点大，交换最大权值的孩子节点与父亲节点
    else
      break;  // 孩子节点的权值均比父亲节点的小，调整结束
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &ori[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &mid[i]);

  int i = 1;
  while (i < n and mid[i] <= mid[i + 1]) ++i;
  int j = i + 1;
  while (j < n and ori[j] == mid[j]) ++j;

  if (j == n) {
    printf("Insertion Sort\n");
    sort(mid + 1, mid + i + 2);
  } else {
    // 堆排序是每次用最大堆的堆顶和堆中最后的元素交换，堆的规模 -1
    // 然后向下调整使之再次成为最大堆
    printf("Heap Sort\n");
    int j = n;
    while (j > 1 and mid[j] >= mid[1])  // 找到堆中最后的元素
      --j;  // 取出的元素一定比堆中的元素大
    swap(mid[1], mid[j]);
    down_adjust(1, j - 1);  // 堆的规模 -1，向下调整
  }

  for (int i = 1; i <= n; ++i) cout << mid[i] << (i == n ? "" : " ");
}