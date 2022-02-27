#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Applicant {
  int id, ge, gi, gf, school, preferred_school[5];
} applicant[40005];

int admit_cnt = 0;    // 被录取的总人数
int quota[105];       // 每所学校拟录取人数
int cnt[105];         // 每所学校已录取的学生人数
int last_admit[105];  // 每所学校最后一个录取的学生ID

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; ++i) scanf("%d", &quota[i]);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &applicant[i].ge, &applicant[i].gi);
    for (int j = 0; j < k; ++j) scanf("%d", &applicant[i].preferred_school[j]);
    applicant[i].id = i;
    applicant[i].gf = applicant[i].ge + applicant[i].gi;
  }

  sort(applicant, applicant + n, [](Applicant &a, Applicant &b) {
    if (a.gf != b.gf)
      return a.gf > b.gf;
    else
      return a.ge > b.ge;
  });

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      int school = applicant[i].preferred_school[j];
      auto last = cnt[school] ? &applicant[last_admit[school]] : nullptr;
      if (cnt[school] < quota[school] or
          (applicant[i].gi == last->gi and applicant[i].ge == last->ge)) {
        ++cnt[school];
        applicant[i].school = school;
        applicant[admit_cnt] = applicant[i];
        last_admit[school] = admit_cnt++;
        break;
      }
    }
  }

  sort(applicant, applicant + admit_cnt, [](Applicant &a, Applicant &b) {
    if (a.school != b.school)
      return a.school < b.school;
    else
      return a.id < b.id;
  });

  for (int i = 0, k = 0; i < m; ++i) {
    for (int j = 0; j < cnt[i]; ++j)
      printf("%s%d", j == 0 ? "" : " ", applicant[k++].id);
    printf("\n");
  }
}