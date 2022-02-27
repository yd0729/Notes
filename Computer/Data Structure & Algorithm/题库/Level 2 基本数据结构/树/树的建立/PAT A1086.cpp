#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> in_order, pre_order;

// pre：前序遍历起始位置，in：中序遍历起始位置，len：长度
void create(int pre, int in, int len) {
  int root;  // 当前子树的根节点在中序遍历中的位置
  for (root = in; root < in + len; ++root) {
    if (in_order[root] == pre_order[pre]) break;
  }

  int l_len = root - in;  // 当前子树的左子树的中序遍历长度
  int r_len = in + len - root - 1;  // 当前子树的右子树的中序遍历长度

  if (l_len > 0) {  // 递归地构建左子树
    create(pre + 1, in, l_len);
    cout << " ";
  }

  if (r_len > 0) {  // 递归地构建右子树
    create(pre + len - r_len, root + 1, r_len);
    cout << " ";
  }

  cout << pre_order[pre];
}

int main() {
  int n, val;
  cin >> n;
  string op;
  stack<int> s;  // 用这个栈去执行一遍给定的操作，得到前序遍历和中序遍历

  for (int i = 0; i < 2 * n; ++i) {
    cin >> op;
    if (op[1] == 'u') {
      cin >> val;
      s.push(val);
      pre_order.push_back(val);
    } else {
      in_order.push_back(s.top());
      s.pop();
    }
  }

  create(0, 0, n);
}