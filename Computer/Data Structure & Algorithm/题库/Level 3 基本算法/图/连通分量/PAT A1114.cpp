#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct {
  int estate = 0, area = 0, visit = 1;
  vector<int> relative;
} person[10005];

struct Family {
  int member_cnt = 0, estate_cnt = 0, area = 0, id = 10000;

  double avg_area() const { return area * 1.0 / member_cnt; }

  bool operator<(const Family &x) const {
    if (avg_area() != x.avg_area())
      return avg_area() > x.avg_area();
    else
      return id < x.id;
  }
};

vector<Family> family;

void dfs(int id, Family &f) {
  person[id].visit = 1;
  f.member_cnt += 1;
  f.estate_cnt += person[id].estate;
  f.area += person[id].area;
  f.id = min(f.id, id);

  for (auto &c : person[id].relative)
    if (not person[c].visit) dfs(c, f);
}

void add_relative(int id, int parent_id) {
  person[id].visit = 0;
  if (parent_id != -1) {
    person[parent_id].visit = 0;
    person[id].relative.push_back(parent_id);
    person[parent_id].relative.push_back(id);
  }
}

int main() {
  int n, id, k, c, father, mother;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> id >> father >> mother >> k;
    add_relative(id, father);
    add_relative(id, mother);
    for (int j = 0; j < k; ++j) {
      cin >> c;
      add_relative(c, id);
    }
    cin >> person[id].estate >> person[id].area;
  }

  for (int i = 0; i < 10005; ++i) {
    if (not person[i].visit) {
      Family f;
      dfs(i, f);
      family.push_back(f);
    }
  }

  sort(family.begin(), family.end());

  cout << family.size() << "\n";
  for (auto &f : family)
    printf("%04d %d %.3f %.3f\n", f.id, f.member_cnt,
           f.estate_cnt * 1.0 / f.member_cnt, f.area * 1.0 / f.member_cnt);
}