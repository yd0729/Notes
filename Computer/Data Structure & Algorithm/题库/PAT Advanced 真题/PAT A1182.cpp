#include <iostream>
#include <string>

using namespace std;

int last = 0;
int heap[1005];

void insert(int val) {
  int p = ++last;
  heap[p] = val;

  for (; p / 2 >= 1; p /= 2) {
    if (heap[p] > heap[p / 2]) {
      swap(heap[p], heap[p / 2]);
    }
  }
}

int find(int x) {
  int i = 1;
  for (; i <= last; i++) {
    if (heap[i] == x) return i;
  }
  return -1;
}

int main() {
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    insert(x);
  }
  cin.get();

  // for (int i = 1; i <= last; i++) {
  //	cout << heap[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i < M; i++) {
    string str;
    getline(cin, str);

    bool result = false;
    if (str.back() == 't') {
      int x;
      sscanf(str.c_str(), "%d is the root", &x);
      result = heap[1] == x;
    } else if (str.back() == 's') {
      int a, b;
      sscanf(str.c_str(), "%d and %d are siblings", &a, &b);
      int pos_a = find(a);
      int pos_b = find(b);
      result = pos_a != -1 && pos_b != -1 && pos_a / 2 == pos_b / 2;
    } else if (str.find("parent") != string::npos) {
      int a, b;
      sscanf(str.c_str(), "%d is the parent of %d", &a, &b);
      int pos_a = find(a);
      int pos_b = find(b);
      result = pos_a != -1 && pos_b != -1 && pos_b / 2 == pos_a;
    } else if (str.find("left") != string::npos) {
      int a, b;
      sscanf(str.c_str(), "%d is the left child of %d", &a, &b);
      int pos_a = find(a);
      int pos_b = find(b);
      result = pos_a != -1 && pos_b != -1 && pos_a == pos_b * 2;
    } else if (str.find("right") != string::npos) {
      int a, b;
      sscanf(str.c_str(), "%d is the right child of %d", &a, &b);
      int pos_a = find(a);
      int pos_b = find(b);
      result = pos_a != -1 && pos_b != -1 && pos_a == pos_b * 2 + 1;
    }
    if (result)
      cout << 1;
    else
      cout << 0;
  }
}