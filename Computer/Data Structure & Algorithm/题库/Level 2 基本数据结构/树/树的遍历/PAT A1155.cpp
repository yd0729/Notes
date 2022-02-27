#include <iostream>
#include <vector>

using namespace std;

int n, a[1005], flag;

bool check(int p, int c) {
  if (flag == 1) return p >= c;
  if (flag == 2) return p <= c;
  return false;
}

vector<int> path;

void print() {
  for (auto i = path.begin(); i != path.end(); ++i) {
    cout << *i;
    if (i + 1 != path.end()) cout << " ";
  }
  cout << "\n";
}

void dfs(int s) {
  if (flag and s * 2 <= n and not check(a[s], a[s * 2])) flag = 0;
  if (flag and s * 2 + 1 <= n and not check(a[s], a[s * 2 + 1])) flag = 0;

  path.push_back(a[s]);
  if (s * 2 + 1 <= n) {
    dfs(s * 2 + 1);
  }
  if (s * 2 <= n) {
    dfs(s * 2);
  } else {
    print();
  }
  path.pop_back();
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  if (a[1] >= a[2])
    flag = 1;
  else if (a[1] <= a[2])
    flag = 2;

  dfs(1);

  if (flag == 1)
    cout << "Max Heap";
  else if (flag == 2)
    cout << "Min Heap";
  else
    cout << "Not Heap";
}