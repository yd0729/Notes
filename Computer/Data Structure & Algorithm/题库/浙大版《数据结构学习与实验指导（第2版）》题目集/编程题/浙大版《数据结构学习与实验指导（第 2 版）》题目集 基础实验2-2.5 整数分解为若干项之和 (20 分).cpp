#include <iostream>
#include <vector>

using namespace std;

void search(int left, int start, vector<int> &term, int &n, int &count) {
  if (left == 0) {
    ++count;
    if (count % 4 != 1) {
      cout << ";";
    }
    cout << n << "=";
    for (int i = 0; i < term.size(); i++) {
      cout << term[i] << (i == term.size() - 1 ? "" : "+");
    }
    if (count % 4 == 0) {
      cout << "\n";
    }
  }
  for (int i = start; i <= left; i++) {
    term.push_back(i);
    if (left - i == 0 or left - i >= i)  // 这个 if 用来剪枝
      search(left - i, i, term, n, count);
    term.pop_back();
  }
}

int main() {
  int n, count = 0;
  vector<int> term;
  cin >> n;
  search(n, 1, term, n, count);
  if (count % 4 != 0) cout << "\n";
}