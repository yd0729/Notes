#include <cstdio>
#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Person {
  string id, birth;

  Person() = default;
  Person(string &id) : id(id) { birth = id.substr(6, 8); }

  bool operator<(const Person &x) const {
    if (birth != x.birth)
      return birth < x.birth;
    else
      return id < x.id;
  }
};

int main() {
  //    freopen("in.txt", "r", stdin);
  //    freopen("out.txt", "w", stdout);

  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  string s, INF = "999999999999999999";
  Person oldest_alumni(INF), oldest_person(INF);
  set<Person> alumni;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    alumni.insert(Person(s));
  }

  cin >> n;
  int alumni_cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    Person p(s);

    if (p < oldest_person) {
      oldest_person = p;
    }

    if (alumni.count(Person(s))) {
      ++alumni_cnt;
      if (p < oldest_alumni) {
        oldest_alumni = p;
      }
    }
  }

  cout << alumni_cnt << "\n";
  if (alumni_cnt == 0)
    cout << oldest_person.id;
  else
    cout << oldest_alumni.id;
}