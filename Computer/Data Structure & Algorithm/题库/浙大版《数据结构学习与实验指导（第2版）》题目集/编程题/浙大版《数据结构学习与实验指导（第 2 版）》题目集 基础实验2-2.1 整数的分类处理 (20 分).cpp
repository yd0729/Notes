#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int A1 = 0, A2 = 0, cnt = 0;
  double A3 = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    switch (a % 3) {
      case 0:
        A1 = max(A1, a);
        break;
      case 1:
        A2++;
        break;
      case 2:
        A3 += a;
        ++cnt;
        break;
    }
  }

  if (A1)
    cout << A1;
  else
    cout << "NONE";
  cout << " ";
  if (A2)
    cout << A2;
  else
    cout << "NONE";
  cout << " ";
  if (A3 != 0) {
    A3 /= cnt;
    cout << fixed << setprecision(1) << A3;
  } else
    cout << "NONE";
}