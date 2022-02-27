#include <iostream>
#include <queue>

using namespace std;

struct Record {
  int value, run;
  bool operator>(const Record &r) const {
    if (run != r.run)
      return run > r.run;
    else
      return value > r.value;
  }
};

int main() {
  int N, M, x;
  cin >> N >> M;

  priority_queue<Record, vector<Record>, greater<Record>> pq;
  for (int i = 0; i < M; i++) {
    cin >> x;
    pq.push({x, 1});
  }
  bool first = true;
  int cur_run = 0;
  for (int i = 0; i < N - M or !pq.empty();) {
    Record top = pq.top();
    pq.pop();
    if (top.run == cur_run) {
      cout << " ";
    } else {
      cur_run = top.run;
      if (first) {
        first = false;
      } else
        cout << "\n";
    }
    cout << top.value;
    if (i < N - M) {
      cin >> x;
      i++;
      pq.push({x, x > top.value ? cur_run : cur_run + 1});
    }
  }
}

// 败者树
// #include <iostream>

// using namespace std;

// int n, m;

// struct WorkArea {
//     int key = 0, run = 0;

//     bool operator<(const WorkArea& x) const {
//         if (run != x.run) return run < x.run;
//         else return key < x.key;
//     }
// } wa[100005];

// int loser_tree[100005];
// int& winner = loser_tree[0];

// void update_loser_tree(int pos, int y) {
//     if (pos == 0) winner = y;
//     else {
//         if (wa[loser_tree[pos]] < wa[y]) {
//             update_loser_tree(pos / 2, loser_tree[pos]);
//             loser_tree[pos] = y;
//         }
//         else update_loser_tree(pos / 2, y);
//     }
// }

// void print() {
//     static int current_run = 1;
//     static bool first_in_run = true;

//     if (current_run < wa[winner].run) {
//         current_run = wa[winner].run;
//         cout << "\n";
//         first_in_run = true;
//     }

//     if (first_in_run) {
//         first_in_run = false;
//     }
//     else cout << " ";

//     cout << wa[winner].key;
// }

// int main() {
//     cin >> n >> m;

//     for (int i = m - 1; i >= 0; --i) {
//         cin >> wa[i].key;
//         wa[i].run = 1;
//         update_loser_tree((m + i) / 2, i);
//     }

//     for (int i = m; i < n + m; ++i) {
//         print();

//         int k = 2147483647;
//         if (i < n) cin >> k;

//         if (i >= n or k < wa[winner].key) {
//             wa[winner].run += 1;
//         }
//         wa[winner].key = k;
//         update_loser_tree((m + winner) / 2, winner);
//     }
// }