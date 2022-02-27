#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Institution {
  int count;
  string code;
  double tws;
};

vector<Institution> institution;
unordered_map<string, int> institution_id;

int get_id(string &s) {
  if (institution_id.count(s))
    return institution_id[s];
  else {
    institution_id[s] = institution.size();
    institution.push_back(Institution{0, s, 0});
    return institution.size() - 1;
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    double tws;
    string id, code;

    cin >> id >> tws >> code;

    if (id[0] == 'B')
      tws /= 1.5;
    else if (id[0] == 'T')
      tws *= 1.5;

    // 不知道为啥不行
    // transform(code.begin(), code.end(), code.begin(), tolower);
    transform(code.begin(), code.end(), code.begin(), ::tolower);

    int sid = get_id(code);
    institution[sid].count++;
    institution[sid].tws += tws;
  }

  sort(institution.begin(), institution.end(),
       [](Institution &a, Institution &b) {
         if (int(a.tws) != int(b.tws))
           return a.tws > b.tws;
         else if (a.count != b.count)
           return a.count < b.count;
         else
           return a.code < b.code;
       });

  cout << institution.size() << "\n";
  int rank = 1, tws = institution.begin()->tws;
  for (auto i = institution.begin(); i != institution.end(); ++i) {
    if (tws != int(i->tws)) {
      rank = i - institution.begin() + 1;
      tws = i->tws;
    }
    printf("%d %s %d %d\n", rank, i->code.c_str(), tws, i->count);
  }
}