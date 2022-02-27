class Solution {
 public:
  bool isMatch(string s, string p) {
    int sl = 0, slen = int(s.length());
    int pl = 0, plen = int(p.length());
    while (plen != 0) {
      if (p[pl] == '*') {
        int len = 0;
        while (len < plen and p[pl + len] == '*') ++len;
        if (len == plen) return true;
        pl += len;
        plen -= len;
      } else {
        int len = 0;
        while (len < plen and p[pl + len] != '*') ++len;
        if (pl == 0) {
          if (slen < len) return false;
          if (!stringEqual(s, p, sl, pl, len)) return false;
          sl += len;
          slen -= len;
        } else if (len == plen) {
          if (len > slen) return false;
          return stringEqual(s, p, sl + slen - len, pl, len);
        } else {
          bool match = false;
          int i = sl;
          for (; i + len <= sl + slen; ++i) {
            if (stringEqual(s, p, i, pl, len)) {
              match = true;
              break;
            }
          }
          if (!match) return false;
          i += len;
          slen -= i - sl;
          sl = i;
        }
        pl += len;
        plen -= len;
      }
    }
    return slen == 0;
  }

  bool stringEqual(string &s, string &p, int sl, int pl, int len) {
    for (int i = 0; i < len; ++i) {
      if (!charEqual(p[i + pl], s[i + sl])) return false;
    }
    return true;
  }

  bool charEqual(char a, char b) { return a == '?' or b == '?' or a == b; }
};