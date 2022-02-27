#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int val;
  Node *left, *right;
};

void insert(Node *&root, int val) {
  if (root == nullptr) {
    root = new Node{val};
    return;
  }

  if (root->val < val)  // 题写错了，按照题意这里应该是<=
    insert(root->right, val);
  else
    insert(root->left, val);
}

int cnt[1005];

void dfs(Node *root, int level) {
  if (not root) return;
  cnt[level]++;
  dfs(root->left, level + 1);
  dfs(root->right, level + 1);
}

// clang-tidy
void del_tree(Node *&root) {
  if (not root) return;
  del_tree(root->left);
  del_tree(root->right);
  delete root;
}

int main() {
  int n, c;
  Node *root = nullptr;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c;
    insert(root, c);
  }

  dfs(root, 1);

  del_tree(root);

  for (int i = 1004; i >= 1; --i) {
    if (cnt[i] != 0) {
      cout << cnt[i] << " + " << cnt[i - 1] << " = " << cnt[i] + cnt[i - 1];
      return 0;
    }
  }
}