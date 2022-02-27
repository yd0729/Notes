#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  int val, depth;
  Node *parent = nullptr, *l_child = nullptr, *r_child = nullptr;
};

int post_order[35], in_order[35];
bool is_full = true;

Node *create(int in, int post, int len, int depth, Node *parent) {
  if (len <= 0) return nullptr;

  int root_val = post_order[post + len - 1];

  Node *root = new Node{root_val, depth, parent};

  int pos_root = in;
  while (in_order[pos_root] != root_val) ++pos_root;

  int l_len = pos_root - in;
  int r_len = len - l_len - 1;

  root->l_child = create(in, post, l_len, depth + 1, root);
  root->r_child = create(in + l_len + 1, post + l_len, r_len, depth + 1, root);

  if ((root->l_child == nullptr and root->r_child != nullptr) or
      (root->l_child != nullptr and root->r_child == nullptr)) {
    is_full = false;
  }

  return root;
}

Node *search(Node *root, int target) {
  if (root == nullptr or root->val == target) {
    return root;
  }

  Node *ret = search(root->l_child, target);
  if (ret and ret->val == target) {
    return ret;
  }
  return search(root->r_child, target);
}

void del_tree(Node *root) {  // clang-tidy
  if (root == nullptr) return;
  del_tree(root->l_child);
  del_tree(root->r_child);
  delete root;
}

int main() {
  //    freopen("in.txt", "r", stdin);
  //    freopen("out.txt", "w", stdout);

  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) cin >> post_order[i];
  for (int i = 0; i < n; ++i) cin >> in_order[i];

  Node *root = create(0, 0, n, 0, nullptr);

  cin >> n;
  cin.get();  // !
  for (int i = 0; i < n; ++i) {
    bool ok;
    string s;
    int a, b;

    getline(cin, s);

    if (*s.rbegin() == 't') {
      sscanf(s.c_str(), "%d", &a);
      ok = a == root->val;
    } else if (*s.rbegin() == 'e') {
      ok = is_full;
    } else if (*s.rbegin() == 's') {
      sscanf(s.c_str(), "%d and %d", &a, &b);
      Node *root_a = search(root, a);
      Node *root_b = search(root, b);
      ok = root_a and root_b and root_a->parent == root_b->parent;
    } else if (*s.rbegin() == 'l') {
      sscanf(s.c_str(), "%d and %d", &a, &b);
      Node *root_a = search(root, a);
      Node *root_b = search(root, b);
      ok = root_a and root_b and root_a->depth == root_b->depth;
    } else if (s.find("parent") != string::npos) {
      sscanf(s.c_str(), "%d is the parent of %d", &a, &b);
      Node *root_a = search(root, a);
      ok = root_a and ((root_a->l_child and root_a->l_child->val == b) or
                       (root_a->r_child and root_a->r_child->val == b));
    } else if (s.find("left") != string::npos) {
      sscanf(s.c_str(), "%d is the left child of %d", &a, &b);
      Node *root_b = search(root, b);
      ok = root_b and root_b->l_child and root_b->l_child->val == a;
    } else {
      sscanf(s.c_str(), "%d is the right child of %d", &a, &b);
      Node *root_b = search(root, b);
      ok = root_b and root_b->r_child and root_b->r_child->val == a;
    }
    cout << (ok ? "Yes\n" : "No\n");
  }

  del_tree(root);
}