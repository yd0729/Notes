#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> gen_fb() {
  vector<int> fb = {0, 1};
  for (int i = 2; fb.back() < 1e8; i++) {
    fb.push_back(fb[i - 1] + fb[i - 2]);
  }
  return fb;
}

int main() {
  vector<int> fb = gen_fb();

  int x;
  cin >> x;

  auto i = lower_bound(fb.begin(), fb.end(), x);

  int dif1 = *i - x;
  int dif2 = x - *(i - 1);

  if (dif1 >= dif2) {
    cout << *(i - 1);
  } else {
    cout << *i;
  }
}