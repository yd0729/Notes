#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
int total = 0;
string name[2000];
unordered_map<string, int> id;
map<string, int> gangs;  // head -> cnt
bool vi[2000];
int w[2000], e[2000][2000];  // 点权 边权
int get_id(string &s) {
  if (not id.count(s)) {  // 给新名字分配一个id
    id[s] = total++;
    name[id[s]] = s;
  }
  return id[s];
}
void dfs(int cur, int &head, int &cnt, int &net) {
  ++cnt;
  vi[cur] = true;
  if (w[cur] > w[head]) head = cur;
  for (int i = 0; i < total; ++i) {  // 要把连通分量里的所有边全都加上
    if (e[cur][i] > 0) {
      net += e[cur][i];
      e[cur][i] = e[i][cur] = 0;
      if (not vi[i]) dfs(i, head, cnt, net);
    }
  }
}
int main() {
  string s[2];
  int n, k, wt, id[2];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> s[0] >> s[1] >> wt;
    for (int j = 0; j < 2; j++) {
      id[j] = get_id(s[j]);
      w[id[j]] += wt;
    }
    for (int j = 0; j < 2; j++) e[id[j]][id[1 - j]] += wt;
  }
  for (int i = 0; i < total; ++i)
    if (not vi[i]) {
      int head = i, cnt = 0, net = 0;
      dfs(i, head, cnt, net);
      if (net > k and cnt > 2) gangs[name[head]] = cnt;
    }
  cout << gangs.size() << "\n";
  for (auto &g : gangs) cout << g.first << " " << g.second << "\n";
}