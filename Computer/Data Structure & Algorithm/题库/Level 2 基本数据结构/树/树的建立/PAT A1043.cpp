#include <iostream>
#include <vector>
using namespace std;
int pre[1005];
vector<int> p;
bool post(int l, int len, bool m) {
  if (len < 1) return true;
  int &root = pre[l];
  int l_child = l + 1;
  while (l_child < l + len and (m ? pre[l_child] >= root
                                  : pre[l_child] < root))  // 三目运算符要加括号
    ++l_child;
  int r_child = l_child--;
  while (r_child < l + len and (m ? pre[r_child] < root : pre[r_child] >= root))
    ++r_child;
  if (r_child-- == l + len and post(l + 1, l_child - l, m) and
      post(l_child + 1, r_child - l_child, m)) {
    p.push_back(root);
    return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> pre[i];
  if (not post(0, n, 0)) {
    p.clear();
    if (not post(0, n, 1)) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (auto i = p.begin(); i != p.end(); ++i)
    cout << *i << (i + 1 == p.end() ? "\n" : " ");
}