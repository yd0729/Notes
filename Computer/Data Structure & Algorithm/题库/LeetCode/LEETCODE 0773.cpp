class Solution {
 public:
  int slidingPuzzle(vector<vector<int>> &board) {
    string start;
    string target = "123450";
    // 将 2x3 的数组转化成字符串
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
        start.push_back(board[i][j] + '0');
      }
    }
    // 记录一维字符串的相邻索引
    vector<vector<int>> neighbor = {{1, 3}, {0, 4, 2}, {1, 5},
                                    {0, 4}, {3, 1, 5}, {4, 2}};
    // bfs
    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);
    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        string s = q.front();
        // 解开迷板
        if (s == target) {
          return step;
        }
        q.pop();
        // 找到 0 的位置
        int zero = 0;
        for (; zero < s.length(); zero++) {
          if (s[zero] == '0') {
            break;
          }
        }
        // 和相邻位置交换
        for (int i : neighbor[zero]) {
          swap(s[i], s[zero]);
          // 加入队列
          if (!visited.count(s)) {
            q.push(s);
            visited.insert(s);
          }
          swap(s[i], s[zero]);
        }
      }
      step++;
    }
    return -1;
  }
};