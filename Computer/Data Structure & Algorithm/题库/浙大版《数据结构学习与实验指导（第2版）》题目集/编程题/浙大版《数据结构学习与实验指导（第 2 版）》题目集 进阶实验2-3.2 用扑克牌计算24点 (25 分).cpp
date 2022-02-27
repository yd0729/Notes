/**
 * @file 进阶实验2-3.2 用扑克牌计算24点.cpp
 * @author 杨东
 * @brief
 * 1. 生成一个数字排列
 * 2. 生成一个运算符排列
 * 3. 生成一个运算顺序
 * 4. 生成一棵树
 * 5. 计算这棵树的值是否是目标值
 * 6. 输出
 * @version 0.1
 * @date 2021-03-01
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define M 24  // 目标点数
#define N 4   // 扑克牌数量

void op_permutation(int start, vector<char> &tmp, vector<vector<char>> &ops) {
  static const vector<char> op = {'+', '-', '*', '/'};
  if (start == N - 1) {
    ops.push_back(tmp);
    return;
  }
  for (int i = 0; i < 4; i++) {
    tmp.push_back(op[i]);
    op_permutation(start + 1, tmp, ops);
    tmp.pop_back();
  }
}

struct Node {
  int isLeaf = false;
  union {
    double val;
    char op;
  } uReigon;

  Node *left = nullptr, *right = nullptr, *parent = nullptr;
};

double calculate(Node *root) {
  if (root->isLeaf) {
    return root->uReigon.val;
  } else {
    switch (root->uReigon.op) {
      case '+':
        return calculate(root->left) + calculate(root->right);
        break;
      case '-':
        return calculate(root->left) - calculate(root->right);
        break;
      case '*':
        return calculate(root->left) * calculate(root->right);
        break;
      case '/':
        return calculate(root->left) / calculate(root->right);
        break;
    }
  }
  return 0;
}

void print(Node *root, bool out) {
  if (root->isLeaf) {
    cout << root->uReigon.val;
  } else {
    if (!out) cout << "(";
    print(root->left, false);
    cout << root->uReigon.op;
    print(root->right, false);
    if (!out) cout << ")";
  }
}

int main() {
  // 生成所有运算符排列
  vector<char> tmp;
  vector<vector<char>> op_permutations;
  op_permutation(0, tmp, op_permutations);

  // 初始化数字排列
  vector<double> numbers(N);
  for (int i = 0; i < N; i++) {
    cin >> numbers[i];
  }

  // 初始化运算优先级
  vector<int> order;
  for (int i = 0; i < N - 1; i++) {
    order.push_back(i);
  }

  do {
    // 生成所有的叶子节点
    vector<Node> leafs(N);
    for (int i = 0; i < N; i++) {
      leafs[i].isLeaf = true;
      leafs[i].uReigon.val = numbers[i];
    }

    for (int i = 0; i < op_permutations.size(); i++) {
      vector<char> &op_permutation = op_permutations[i];
      // 生成所有的非终端节点
      vector<Node> ops(N - 1);
      for (int j = 0; j < N - 1; j++) {
        ops[j].isLeaf = false;
        ops[j].uReigon.op = op_permutation[j];
      }
      do {
        // 生成运算符的优先级
        vector<pair<int, int>> priority;
        for (int i = 0; i < N - 1; i++) {
          priority.emplace_back(order[i], i);
        }
        sort(priority.begin(), priority.end());
        // 根据优先级生成树
        for (int i = 0; i < N - 1; i++) {
          int pos = priority[i].second;
          Node *l_child = &leafs[pos];
          Node *r_child = &leafs[pos + 1];
          while (l_child->parent != nullptr) l_child = l_child->parent;
          while (r_child->parent != nullptr) r_child = r_child->parent;
          l_child->parent = &ops[pos];
          r_child->parent = &ops[pos];
          ops[pos].left = l_child;
          ops[pos].right = r_child;
        }
        Node *root = &ops[priority.back().second];
        // 计算这棵树
        if (calculate(root) == M) {
          print(root, true);
          return 0;
        } else {
          // 清空
          for (int i = 0; i < N - 1; i++) {
            leafs[i].parent = nullptr;
            ops[i].left = nullptr;
            ops[i].right = nullptr;
            ops[i].parent = nullptr;
          }
          leafs[N - 1].parent = nullptr;
        }
      } while (next_permutation(order.begin(), order.end()));
    }
  } while (next_permutation(numbers.begin(), numbers.end()));
  cout << -1;
}