#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct type1 {
  string card;
  int grade;

  bool operator>(const type1 &x) const {
    if (grade != x.grade)
      return grade > x.grade;
    else
      return card < x.card;
  }
};

struct type2 {
  int count = 0;
  int total_score = 0;
};

struct type3 {
  int site;
  int cnt;

  bool operator>(const type3 &x) const {
    if (cnt != x.cnt)
      return cnt > x.cnt;
    else
      return site < x.site;
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  unordered_map<char, vector<type1>> type_1;
  unordered_map<int, type2> type_2;
  unordered_map<int, vector<type3>> type_3;
  unordered_map<int, unordered_map<int, int>> type_3_raw;

  for (int i = 0; i < n; ++i) {
    int score;
    string card;
    cin >> card >> score;

    char level = card[0];

    int site, date;
    sscanf(card.substr(1, 3).c_str(), "%d", &site);
    sscanf(card.substr(4, 6).c_str(), "%d", &date);

    type_1[level].push_back({card, score});
    type_2[site].count += 1;
    type_2[site].total_score += score;
    type_3_raw[date][site] += 1;
  }

  for (auto &e : type_1) {  // 按照成绩排序
    sort(e.second.begin(), e.second.end(), greater<type1>());
  }

  for (auto &e : type_3_raw) {
    int date = e.first;
    for (auto &e : e.second) {
      type_3[date].push_back({e.first, e.second});
    }
  }

  for (auto &e : type_3) {
    auto &info = e.second;
    sort(info.begin(), info.end(), greater<type3>());
  }

  cin.get();  // 吃掉多余的空格

  for (int i = 0; i < m; ++i) {
    string input;
    getline(cin, input);

    cout << "Case " << i + 1 << ": " << input << "\n";

    stringstream ssm;
    ssm << input;

    int type;
    ssm >> type;

    if (type == 1) {
      char level;
      ssm >> level;

      if (type_1[level].empty())
        cout << "NA\n";
      else {
        for (auto &e : type_1[level]) {
          cout << e.card << " " << e.grade << "\n";
        }
      }
    } else if (type == 2) {
      int site;
      ssm >> site;

      if (!type_2.count(site))
        cout << "NA\n";
      else
        cout << type_2[site].count << " " << type_2[site].total_score << "\n";
    } else if (type == 3) {
      int date;
      ssm >> date;

      if (type_3[date].empty())
        cout << "NA\n";
      else {
        for (auto &e : type_3[date]) {
          cout << e.site << " " << e.cnt << "\n";
        }
      }
    }
  }
}