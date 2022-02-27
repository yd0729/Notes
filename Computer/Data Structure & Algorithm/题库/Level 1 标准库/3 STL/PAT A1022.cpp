#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, unordered_map<string, vector<string>>> m;

int main() {
  int n;
  string id, item, q;
  for (cin >> n, cin.get(); n--;) {
    getline(cin, id);
    for (int i = 1; i <= 5; ++i) {
      getline(cin, item);
      if (i == 3) {  // 处理关键字
        stringstream ssm;
        ssm << item;
        while (ssm >> item) m[i][item].push_back(id);
      } else {
        m[i][item].push_back(id);
      }
    }
  }
  cin >> n, cin.get();
  while (n--) {
    getline(cin, q);
    cout << q << '\n';
    if (m[q[0] - '0'].count(q.substr(3)) == 0)
      cout << "Not Found\n";
    else {
      auto &ids = m[q[0] - '0'].at(q.substr(3));
      if (!is_sorted(ids.begin(), ids.end()))
        sort(ids.begin(), ids.end());  // 查询时再排序
      for (auto &e : ids) cout << e << '\n';
    }
  }
}
