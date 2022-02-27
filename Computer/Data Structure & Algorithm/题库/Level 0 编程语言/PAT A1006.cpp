#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string id, lock, unlock, in_time, out_time, min_time = "24:00:00",
                                              max_time = "00:00:00";
  for (int i = 0; i < n; ++i) {
    cin >> id >> in_time >> out_time;
    if (in_time < min_time) {
      min_time = in_time;
      unlock = id;
    }
    if (out_time > max_time) {
      max_time = out_time;
      lock = id;
    }
  }
  cout << unlock << " " << lock;
}
