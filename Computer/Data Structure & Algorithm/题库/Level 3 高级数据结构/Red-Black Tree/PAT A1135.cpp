#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *left, *right;
};

bool is_black(Node *x) {
  return x == nullptr or x->val > 0;  // 3
}

bool is_red(Node *x) { return x and x->val < 0; }

void insert(Node *&root, int val) {
  if (root == nullptr)
    root = new Node{val};
  else if (abs(val) < abs(root->val))
    insert(root->left, val);
  else
    insert(root->right, val);
}

bool check_child(Node *root, int &black_cnt) {
  if (is_black(root)) ++black_cnt;

  if (root == nullptr) return true;

  if (is_red(root) and !(is_black(root->left) and is_black(root->right)))
    return false;  // 4

  int l_b_cnt = 0, r_b_cnt = 0;
  if (check_child(root->left, l_b_cnt) and check_child(root->right, r_b_cnt) and
      l_b_cnt == r_b_cnt) {  // 5
    black_cnt += l_b_cnt;
    return true;
  }
  return false;
}

void del_tree(Node *&root) {
  if (not root) return;
  if (root->left) del_tree(root->left);
  if (root->right) del_tree(root->right);
  delete root;
}

int main() {
  int k, n, x;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    int black_cnt = 0;
    Node *root = nullptr;

    cin >> n;
    for (int j = 0; j < n; ++j) {
      cin >> x;
      insert(root, x);
    }
    // 2
    cout << (is_black(root) and check_child(root, black_cnt) ? "Yes" : "No")
         << "\n";

    del_tree(root);  // clang-tidy
  }
}