#include <algorithm>
#include <cstdio>

using namespace std;

struct Node {
  int v;
  Node *left, *right;
  static int height(Node *root) {
    return root ? max(height(root->left), height(root->right)) + 1 : 0;
  }
  int balance_factor() { return height(left) - height(right); }
};

void l_rotate(Node *&root) {
  Node *temp = root->right;
  root->right = temp->left;
  temp->left = root;
  root = temp;
}

void r_rotate(Node *&root) {
  Node *temp = root->left;
  root->left = temp->right;
  temp->right = root;
  root = temp;
}

void insert(Node *&root, int v) {
  if (root == nullptr) {
    root = new Node{v};
    return;
  }
  if (v < root->v) {
    insert(root->left, v);
    if (root->balance_factor() == 2) {
      if (v < root->left->v) {
        r_rotate(root);
      } else {
        l_rotate(root->left);
        r_rotate(root);
      }
    }
  } else {
    insert(root->right, v);
    if (root->balance_factor() == -2) {
      if (v >= root->right->v) {
        l_rotate(root);
      } else {
        r_rotate(root->right);
        l_rotate(root);
      }
    }
  }
}

void del_tree(Node *&root) {
  if (not root) return;
  if (root->left) del_tree(root->left);
  if (root->right) del_tree(root->right);
  delete root;
}

int main() {
  Node *root = nullptr;
  int n, v;

  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d", &v);
    insert(root, v);
  }

  if (root) {  // clang-tidy
    printf("%d\n", root->v);
    del_tree(root);  // clang-tidy
  }
}