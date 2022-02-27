#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int timestamp(int h, int m, int s) { return s + m * 60 + h * 3600; }

int main() {
  int n;
  cin >> n;

  if (n == 0) {
    cout << 0;
    return 0;
  }

  vector<pair<int, int>> request;
  for (int i = 0; i < n; i++) {
    int h1, m1, s1, h2, m2, s2;
    scanf("%d:%d:%d %d:%d:%d", &h1, &m1, &s1, &h2, &m2, &s2);
    int t1 = timestamp(h1, m1, s1);
    int t2 = timestamp(h2, m2, s2);
    request.emplace_back(t1, t2);
  }

  sort(
      request.begin(), request.end(),
      [](pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; });

  int t = request[0].second, cnt = 1;
  for (int i = 1; i < n; i++) {
    if (request[i].first >= t) {
      cnt++;
      t = request[i].second;
    }
  }
  cout << cnt;
}
