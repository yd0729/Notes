#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct Person {
  char id[10];
  int v, t, cls, sum;
} p[100005];
int main() {
  int n, l, h;
  scanf("%d %d %d\n", &n, &l, &h);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%s %d %d", p[m].id, &p[m].v, &p[m].t);
    if (!(p[m].v < l or p[m].t < l)) {
      p[m].sum = p[m].v + p[m].t;
      if (p[m].v >= h and p[m].t >= h)
        p[m].cls = 1;
      else if (p[m].v >= h and p[m].t < h)
        p[m].cls = 2;
      else if (p[m].v < h and p[m].t < h and p[m].t <= p[m].v)
        p[m].cls = 3;
      else
        p[m].cls = 4;
      ++m;
    }
  }
  sort(p, p + m, [](Person &a, Person &b) {
    if (a.cls != b.cls)
      return a.cls < b.cls;
    else if (a.sum != b.sum)
      return a.sum > b.sum;
    else if (a.v != b.v)
      return a.v > b.v;
    else
      return strcmp(a.id, b.id) < 0;
  });
  printf("%d\n", m);
  for (int i = 0; i < m; ++i) printf("%s %d %d\n", p[i].id, p[i].v, p[i].t);
}