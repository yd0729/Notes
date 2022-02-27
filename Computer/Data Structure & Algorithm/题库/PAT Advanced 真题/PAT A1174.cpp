#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int val, level;
  Node *left, *right;
};

Node *rebuild(vector<int> &in, vector<int> &pre, int inL, int preL, int len,
              int level) {
  if (len == 0) return nullptr;
  int root = pre[preL];
  int i = inL;
  for (; i < inL + len; i++) {
    if (in[i] == root) break;
  }
  Node *n = new Node{root, level};
  int left_len = i - inL;
  n->left = rebuild(in, pre, inL, preL + 1, left_len, level + 1);
  int right_len = len - left_len - 1;
  n->right = rebuild(in, pre, i + 1, preL + 1 + left_len, right_len, level + 1);
  return n;
}

int main() {
  int N;
  cin >> N;

  vector<int> inorder(N), preorder(N);
  for (int i = 0; i < N; i++) {
    cin >> inorder[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> preorder[i];
  }

  Node *root = rebuild(inorder, preorder, 0, 0, N, 1);

  queue<Node *> q;
  q.push(root);

  bool first = true;
  int cur_level = 0;
  while (!q.empty()) {
    Node *front = q.front();
    q.pop();

    if (cur_level != front->level) {
      cur_level = front->level;
      if (first) {
        first = false;
      } else {
        cout << " ";
      }
      cout << front->val;
    }

    if (front->left) q.push(front->left);
    if (front->right) q.push(front->right);
  }
}