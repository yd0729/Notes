#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *left, *right;
};

void l_rotate(Node *&A) {
  Node *B = A->right;
  A->right = B->left;
  B->left = A;
  A = B;
}

void r_rotate(Node *&A) {
  Node *B = A->left;
  A->left = B->right;
  B->right = A;
  A = B;
}

void lr_rotate(Node *&A) {
  l_rotate(A->left);
  r_rotate(A);
}

void rl_rotate(Node *&A) {
  r_rotate(A->right);
  l_rotate(A);
}

int height(Node *A) {
  if (A == nullptr) return 0;
  int l = height(A->left);
  int r = height(A->right);
  return max(l, r) + 1;
}

void insert(Node *&A, int val) {
  if (A == nullptr) {
    A = new Node{val};
  } else if (A->val > val) {
    insert(A->left, val);
    if (height(A->left) - height(A->right) >= 2) {
      if (val < A->left->val)
        r_rotate(A);
      else
        lr_rotate(A);
    }
  } else {
    insert(A->right, val);
    if (height(A->left) - height(A->right) <= -2) {
      if (val > A->right->val)
        l_rotate(A);
      else
        rl_rotate(A);
    }
  }
}

int main() {
  int n, a;
  Node *root = nullptr;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    insert(root, a);
  }

  queue<Node *> q;
  q.push(root);

  vector<int> level_order;
  bool complete = true, leaf = false;

  while (not q.empty()) {
    auto front = q.front();
    q.pop();
    if (front->left) q.push(front->left);
    if (front->right) q.push(front->right);
    level_order.push_back(front->val);
    // 判定完全二叉树
    if (!front->left and !front->right)  // 注意这个判断应该放在前面
      leaf = true;                       // 后面全应该是叶子
    else if (leaf)
      complete = false;
    if (front->right and !front->left)  // 右有左无一定不能出现
      complete = false;
    else if (!front->right and front->left)
      leaf = true;  // 后面全应该是叶子
  }

  for (auto i = level_order.begin(); i != level_order.end(); ++i)
    cout << *i << (i + 1 == level_order.end() ? "\n" : " ");
  cout << (complete ? "YES" : "NO") << "\n";
}