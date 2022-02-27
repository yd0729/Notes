#include <algorithm>
#include <cstdio>

using namespace std;

struct User {
  int id;
  int final[6] = {-1, -1, -1, -1, -1, -1};  // -1代表用户没提交过
  int total = 0;
  int full_cnt = 0;
  bool show = false;
} user[10005];

int full[5];

int main() {
  int n, k, m;
  scanf("%d %d %d\n", &n, &k, &m);
  for (int i = 1; i <= n; ++i)  // 设置用户id
    user[i].id = i;
  for (int i = 1; i <= k; ++i)  // 读入每道题的满分
    scanf("%d", &full[i]);
  for (int i = 0; i < m; ++i) {
    int uid, pid, score;
    scanf("%d %d %d\n", &uid, &pid, &score);  // 读入一个提交
    User &u = user[uid];
    int &final = u.final[pid];
    final = max(final,
                0);  // 对于应该 show
                     // 的人，即使没编译通过的题目也要显示0，没提交过的才显示-
    if (score >= 0)  // 至少有一道题通过了编译
      u.show = true;
    if (final < score) {  // 更新用户的分数
      u.total += score - final;
      if (score == full[pid]) u.full_cnt++;
      final = score;
    }
  }

  sort(user + 1, user + 1 + n, [](User &a, User &b) {
    if (a.show != b.show)
      return a.show > b.show;
    else if (a.total != b.total)
      return a.total > b.total;
    else if (a.full_cnt != b.full_cnt)
      return a.full_cnt > b.full_cnt;
    else
      return a.id < b.id;
  });

  int cnt = 0, rank = 0, last_sum = -1;
  for (int i = 1; i <= n and user[i].show; ++i) {
    ++cnt;
    if (last_sum != user[i].total) {
      rank = cnt;
      last_sum = user[i].total;
    }
    printf("%d %05d %d ", rank, user[i].id, user[i].total);
    for (int j = 1; j <= k; ++j) {
      if (user[i].final[j] >= 0)
        printf("%d", user[i].final[j]);
      else
        printf("-");
      if (j != k) printf(" ");
    }
    printf("\n");
  }
}