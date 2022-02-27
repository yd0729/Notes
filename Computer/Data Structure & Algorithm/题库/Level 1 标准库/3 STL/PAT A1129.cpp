#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

struct RecommendItem {
  int id, time;

  bool operator<(const RecommendItem &r) const {
    if (time != r.time)
      return time < r.time;
    else
      return id > r.id;
  }
};

unordered_map<int, int> times;
set<RecommendItem> recommend;

int main() {
  int n, k, x;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> x;

    if (i > 1) {
      cout << x << ":";
      for (auto j = recommend.rbegin(); j != recommend.rend(); ++j)
        cout << " " << j->id;
      cout << "\n";
    }

    recommend.erase({x, times[x]});

    auto item = RecommendItem{x, ++times[x]};

    if (recommend.size() < k or *recommend.begin() < item) {
      if (recommend.size() == k) recommend.erase(recommend.begin());
      recommend.insert(item);
    }
  }
}