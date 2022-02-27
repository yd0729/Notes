#include <iostream>

using namespace std;

int m, n, arr[1005];

void post_trav(int root) {
  if (root * 2 <= n) {
    post_trav(root * 2);
    cout << " ";
  }
  if (root * 2 + 1 <= n) {
    post_trav(root * 2 + 1);
    cout << " ";
  }
  cout << arr[root];
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; ++i) {
    bool max_heap = true, min_heap = true;

    for (int j = 1; j <= n; ++j) cin >> arr[j];

    for (int j = 1; j <= n; ++j) {
      if (j * 2 <= n) {
        if (arr[j * 2] > arr[j])
          max_heap = false;
        else if (arr[j * 2] < arr[j])
          min_heap = false;
      }
      if (j * 2 + 1 <= n) {
        if (arr[j * 2 + 1] > arr[j])
          max_heap = false;
        else if (arr[j * 2 + 1] < arr[j])
          min_heap = false;
      }
    }

    if (max_heap)
      cout << "Max Heap\n";
    else if (min_heap)
      cout << "Min Heap\n";
    else
      cout << "Not Heap\n";
      
    post_trav(1);
    cout << "\n";
  }
}