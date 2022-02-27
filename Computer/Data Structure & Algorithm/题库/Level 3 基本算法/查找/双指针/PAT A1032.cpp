#include <cstdio>
int nxt[100005];
int main() {
  int s[2], n, ans = -1, len[2] = {};
  scanf("%d %d %d", &s[0], &s[1], &n);
  for (int i = 0, id, d; i < n; i++)
    scanf("%d", &id),
        scanf(" %c %d", &d, &nxt[id]);  // scanf 不能写在一起， cin 可以
  for (int i = 0; i < 2; i++)
    for (int p = s[i]; p != -1; p = nxt[p]) ++len[i];
  for (int i = 0; i < 2; i++)
    if (len[i] > len[1 - i])
      for (; len[i] > len[1 - i]; --len[i]) s[i] = nxt[s[i]];
  for (; s[0] != -1 && s[1] != -1; s[0] = nxt[s[0]], s[1] = nxt[s[1]])
    if (s[0] == s[1]) {
      ans = s[0];
      break;
    }
  printf("%0*d", ans == -1 ? 0 : 5, ans);
}
