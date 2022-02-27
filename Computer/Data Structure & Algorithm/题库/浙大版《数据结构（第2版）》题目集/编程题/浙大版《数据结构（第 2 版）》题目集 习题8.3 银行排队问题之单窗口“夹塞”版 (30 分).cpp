#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

struct Customer {
  string name;
  int arrive, process_time;
};

int main() {
  int N, M, L;
  cin >> N >> M;

  unordered_map<string, int> friend_circle;
  for (int i = 0; i < M; i++) {
    cin >> L;
    for (int j = 0; j < L; j++) {
      string name;
      cin >> name;
      friend_circle[name] = i;
    }
  }

  vector<Customer> customers(N);
  for (int i = 0; i < N; i++) {
    auto &c = customers[i];
    cin >> c.name >> c.arrive >> c.process_time;
    c.process_time = min(60, c.process_time);
  }

  double total_wait_time = 0;
  list<queue<Customer *>> q;

  q.push_back(queue<Customer *>());
  q.back().push(&customers[0]);  // N >= 1

  int cur_time = customers[0].arrive, cur_customer = 1;
  while (!q.empty() or cur_customer != N) {
    if (q.empty()) {  // 有可能窗口空了一段时间
      q.push_back(queue<Customer *>());
      q.front().push(&customers[cur_customer]);
      cur_time = customers[cur_customer].arrive;
      cur_customer++;
    }

    auto &front_queue = q.front();
    auto &processing_customer = front_queue.front();

    total_wait_time += cur_time - processing_customer->arrive;
    int finish_time = cur_time + processing_customer->process_time;

    // 把在正在窗口处理的客户离开之前到达的所有客户插入合适的队列中去
    for (; cur_customer < N and customers[cur_customer].arrive <= finish_time;
         cur_customer++) {
      auto &c = customers[cur_customer];
      // 找到顾客所在的分支队列
      auto iter = q.begin();
      for (; iter != q.end(); iter++) {
        // 有可能这个人没有朋友，要先判断
        if (friend_circle.count(iter->front()->name) and
            friend_circle.count(c.name) and
            friend_circle[iter->front()->name] == friend_circle[c.name]) {
          break;
        }
      }
      if (iter != q.end()) {
        iter->push(&c);
      } else {
        q.push_back(queue<Customer *>());
        q.back().push(&c);
      }
    }
    cout << processing_customer->name << "\n";
    // 将当前用户出队
    front_queue.pop();
    if (front_queue.empty()) {
      q.pop_front();
    };
    // 更新当前时间
    cur_time = finish_time;
  }

  cout << fixed << setprecision(1) << total_wait_time / N;
}