#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> box(n, 100);

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    for (int j = 0; j < n; ++j) {
      if (box[j] >= a) {
        box[j] -= a;
        cout << a << " " << j + 1 << "\n";
        break;
      }
    }
  }

  int max_index = 0;
  while (max_index < n and box[max_index] != 100) ++max_index;

  cout << max_index;
}