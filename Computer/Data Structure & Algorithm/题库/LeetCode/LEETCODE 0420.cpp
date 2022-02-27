class Solution {
 public:
  int strongPasswordChecker(string s) {
    int length = int(s.length());
    auto continuity = get_continuity(s);
    int type = get_type(s);

    int step = 0;

    while (length > 20) {
      ++step;
      --length;
      if (not continuity.empty()) {
        int t = continuity.top();
        continuity.pop();
        --t;
        if (t > 2) continuity.push(t);
      }
    }

    while (length < 6 or not continuity.empty()) {
      ++step;
      ++length;
      if (not continuity.empty()) {
        int t = continuity.top();
        continuity.pop();
        t -= 3;
        if (t > 2) continuity.push(t);
      }
      if (type < 3) ++type;
    }

    step += 3 - type;
    return step;
  }

  struct cmp {
    bool operator()(int a, int b) { return a % 3 > b % 3; }
  };

  priority_queue<int, vector<int>, cmp> get_continuity(string &s) {
    priority_queue<int, vector<int>, cmp> continuity;
    for (int i = 0, j; i < s.length(); i = j) {
      j = i + 1;
      while (s[j] == s[i]) ++j;
      if (j - i > 2) continuity.push(j - i);
    }
    return continuity;
  }

  int get_type(string &s) {
    int type = 0;
    if (any_of(s.begin(), s.end(), [](char c) { return islower(c); })) ++type;
    if (any_of(s.begin(), s.end(), [](char c) { return isupper(c); })) ++type;
    if (any_of(s.begin(), s.end(),
               [](char c) { return isalnum(c) and not isalpha(c); }))
      ++type;
    return type;
  }
};