#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int n, c;
struct Student {
  string id, name;
  int grade;
  bool operator<(const Student &x) const {
    if (c == 2 and name != x.name) return name < x.name;
    if (c == 3 and grade != x.grade) return grade < x.grade;
    return id < x.id;
  }
} s[100010];
int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios::sync_with_stdio(false);
  cin >> n >> c;
  for (int i = 0; i < n; i++) cin >> s[i].id >> s[i].name >> s[i].grade;
  sort(s, s + n);
  for (int i = 0; i < n; ++i)
    cout << s[i].id << " " << s[i].name << " " << s[i].grade << "\n";
}
