#include <iostream>

using namespace std;

int main() {
  int co, ex;
  bool first = true;
  while (cin >> co >> ex) {
    if (ex > 0) {
      if (first)
        first = false;
      else
        cout << " ";
      cout << co * ex << " " << ex - 1;
    }
  }
  if (first) cout << "0 0";
}