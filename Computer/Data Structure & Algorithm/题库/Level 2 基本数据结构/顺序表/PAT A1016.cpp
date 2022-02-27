#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Record {
  string name;
  int timestamp, month, day, hour, minute, status;
  bool operator<(const Record &x) const {
    if (name != x.name)
      return name < x.name;
    else
      return timestamp < x.timestamp;
  }
} r[1005];

int rate[25];

double bill0(Record &r) {  // 计算从本月00:00:00开始到 r 一直打电话所需的费用
  double bill = rate[24] * r.day * 60 + rate[r.hour] * r.minute;
  for (int i = 0; i < r.hour; ++i) bill += rate[i] * 60;
  return bill / 100;
}

void print_date(Record &r) {
  printf("%02d:%02d:%02d ", r.day, r.hour, r.minute);
}

int main() {
  string status;
  int n, valid = 0;

  for (int i = 0; i < 24; ++i) {
    cin >> rate[i];
    rate[24] += rate[i];  // rate[24]存放通话一整天的费用
  }

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> r[i].name;
    scanf("%d:%d:%d:%d", &r[i].month, &r[i].day, &r[i].hour, &r[i].minute);
    cin >> status;

    r[i].timestamp = r[i].day * 24 * 60 + r[i].hour * 60 + r[i].minute;
    r[i].status = status == "on-line";
  }

  sort(r, r + n);  // 选出合理的记录
  for (int i = 1; i < n; ++i) {
    if (r[i - 1].name == r[i].name and r[i - 1].status == 1 and
        r[i].status == 0) {
      r[valid++] = r[i - 1];
      r[valid++] = r[i];
    }
  }

  for (int i = 0, j; i < valid; i = j) {
    j = i + 1;  // 找到同一个人的所有记录
    while (j < valid and r[j].name == r[i].name) ++j;

    printf("%s %02d\n", r[i].name.c_str(), r[i].month);

    double total = 0;
    for (int k = i; k < j; k += 2) {
      double bill = bill0(r[k + 1]) - bill0(r[k]);
      total += bill;
      print_date(r[k]);
      print_date(r[k + 1]);
      printf("%d $%.2f\n", r[k + 1].timestamp - r[k].timestamp, bill);
    }
    printf("Total amount: $%.2f\n", total);
  }
}
