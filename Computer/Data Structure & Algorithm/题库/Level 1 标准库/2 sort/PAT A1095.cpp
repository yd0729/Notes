#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

const int IN = 0, OUT = 1;
map<string, int> park_time;

struct Record {
  string plate;
  int timestamp, status;
} record[10005];

int timestamp(string &time) {
  int h, m, s;
  sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
  return h * 3600 + m * 60 + s;
}

bool cmp(Record &a, Record &b) {
  if (a.timestamp != b.timestamp)
    return a.timestamp < b.timestamp;
  else
    return a.status < b.status;
}

int main() {
  int n, k;  // 读入所有记录
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    string time, status;
    cin >> record[i].plate >> time >> status;
    record[i].timestamp = timestamp(time);
    record[i].status = status[0] == 'o';
  }

  int valid_cnt = 0;  // 筛选出有效的记录
  sort(record, record + n, [](Record &a, Record &b) {
    if (a.plate != b.plate)
      return a.plate < b.plate;
    else
      return cmp(a, b);
  });

  for (int i = 0; i < n; ++i) {
    while (i < n and record[i].status != IN) ++i;
    if (i + 1 < n and record[i + 1].status == OUT and
        record[i + 1].plate == record[i].plate)
      for (int j = 0; j < 2; ++j) record[valid_cnt++] = record[i + j];
  }

  int longest_park = 0;  // 计算在校园内的最长时间
  for (int i = 0; i < valid_cnt; i += 2) {
    park_time[record[i].plate] += record[i + 1].timestamp - record[i].timestamp;
    longest_park = max(longest_park, park_time[record[i].plate]);
  }

  sort(record, record + valid_cnt, cmp);  // query
  string time;
  for (int i = 0, j = 0, cnt = 0; i < k; ++i) {
    cin >> time;

    for (; j < valid_cnt and timestamp(time) >= record[j].timestamp; ++j) {
      if (record[j].status == IN)
        ++cnt;
      else
        --cnt;
    }

    printf("%d\n", cnt);
  }

  for (auto &e : park_time) {  // map内部会按照车牌排序
    if (longest_park == e.second) cout << e.first << " ";
  }
  printf("%02d:%02d:%02d", longest_park / 3600, (longest_park % 3600) / 60,
         longest_park % 60);
}
