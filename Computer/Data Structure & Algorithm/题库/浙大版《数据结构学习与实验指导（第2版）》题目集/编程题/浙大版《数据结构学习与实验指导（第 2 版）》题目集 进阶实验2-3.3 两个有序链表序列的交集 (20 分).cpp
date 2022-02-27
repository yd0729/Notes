#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a;
  vector<int> A, B, C;
  while (cin >> a and a != -1) {
    A.push_back(a);
  }
  while (cin >> a and a != -1) {
    B.push_back(a);
  }
  for (int i = 0, j = 0; i < A.size() and j < B.size();) {
    while (i < A.size() and A[i] < B[j]) i++;
    while (j < B.size() and A[i] > B[j]) j++;
    if (A[i] == B[j]) {
      C.push_back(A[i]);
      i++, j++;
    }
  }
  if (C.empty())
    cout << "NULL";
  else {
    for (int i = 0; i < C.size(); i++) {
      cout << C[i] << (i == C.size() - 1 ? "" : " ");
    }
  }
}