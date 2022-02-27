#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int D, P;
  cin >> D >> P;
  vector<pair<int, int>> distrib;
  // 第 P - 1 轮分配，第 P - 1 名海盗一颗钻石也得不到，否则他会被推下去
  distrib.emplace_back(D, P);
  distrib.emplace_back(0, P - 1);
  // 逆推前边的分配
  for (int i = P - 2; i > 0; --i) {
    sort(distrib.begin(), distrib.end());
    // 为了获得多数同意，给上一轮得到的钻石较少的一半多分一颗 💎
    int j = 0, cnt = 0;
    for (; j < (P - i + 1) / 2; j++) {
      cnt += ++distrib[j].first;
    }
    // 不需要其他人同意，其他人没有钻石
    while (j < distrib.size()) distrib[j++].first = 0;
    // 剩下的钻石归本轮的分配者
    distrib.emplace_back(D - cnt, i);
  }
  cout << distrib.back().first;
}