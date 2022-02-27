#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Record {
  set<int> in;    // 打进的电话
  int out[1005];  // 打出的电话
};

using Gang = vector<int>;

int k, n, m;

Gang gang[1005];
Record record[1005];

int parent[1005];

Gang suspect;  // 所有可疑人员

int id(int x) {
  if (parent[x] != x) {
    parent[x] = id(parent[x]);
  }
  return parent[x];
}

void merge(int a, int b) {
  int fa = id(a);
  int fb = id(b);
  parent[fa] = fb;  // 注意是fa
}

int main() {
  //    freopen("in.txt", "r", stdin);
  //    freopen("out.txt", "w", stdout);

  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k >> n >> m;
  for (int i = 0; i < m; ++i) {
    int caller, receiver, duration;
    cin >> caller >> receiver >> duration;

    record[caller].out[receiver] += duration;
    record[receiver].in.insert(caller);
  }

  // 找出所有可疑的人
  for (int i = 1; i <= n; ++i) {
    int short_call_cnt = 0, call_back_cnt = 0;
    for (int j = 1; j <= n; ++j) {
      if (record[i].out[j] > 0 and record[i].out[j] <= 5) {
        ++short_call_cnt;
        if (record[i].in.count(j)) ++call_back_cnt;
      }
    }
    if (short_call_cnt > k and call_back_cnt * 5 <= short_call_cnt) {
      suspect.push_back(i);
    }
  }

  if (suspect.size() == 0) {
    cout << "None\n";
    return 0;
  }

  // 通过并查集计算团伙
  for (int i = 1; i <= n; ++i) parent[i] = i;
  for (int i = 0; i < suspect.size(); ++i) {
    for (int j = i + 1; j < suspect.size(); ++j) {
      if (record[suspect[i]].out[suspect[j]] != 0 and
          record[suspect[j]].out[suspect[i]] != 0)
        merge(suspect[i], suspect[j]);
    }
  }

  int gang_cnt = 0;
  map<int, int> head_to_id;
  for (int i = 0; i < suspect.size(); ++i) {
    int head = id(suspect[i]);
    if (!head_to_id.count(head)) {
      head_to_id[head] = gang_cnt++;
    }
    gang[head_to_id[head]].push_back(suspect[i]);
  }

  for (auto &g : gang) {  // 对 gang 的内部排序
    sort(g.begin(), g.end());
  }

  sort(gang, gang + gang_cnt, [](Gang &a, Gang &b) { return a[0] < b[0]; });

  for (int i = 0; i < gang_cnt; ++i) {
    for (int j = 0; j < gang[i].size(); ++j) {
      cout << gang[i][j];
      if (j != gang[i].size() - 1) cout << " ";
    }
    cout << "\n";
  }
}