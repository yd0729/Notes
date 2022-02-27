#include <iostream>

using namespace std;

int main() {
  int n, cur = 0, time = 0;
  cin >> n;
  while (n--) {
    int des, mov;
    cin >> des;
    mov = des - cur;
    time += (mov > 0 ? 6 : -4) * mov + 5;
    cur = des;
  }
  cout << time;
}
