#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  for (int i = 0; i < N; ++i) cin >> B[i];

  int LA = 0, RA = N - 1;
  int LB = 0, RB = N - 1;
  int Mid_A, Mid_B;

  while (RA - LA > 1) {
    Mid_A = A[(LA + RA) / 2];
    Mid_B = B[(LB + RB) / 2];

    if (Mid_A == Mid_B) {
      break;
    } else if (Mid_A < Mid_B) {
      LA += (RA - LA) / 2;
      RB -= (RB - LB) / 2;
    } else if (Mid_A > Mid_B) {
      RA -= (RA - LA) / 2;
      LB += (RB - LB) / 2;
    }
  }

  int C[4] = {A[LA], A[RA], B[LB], B[RB]};
  nth_element(C, C + 1, C + 4);

  cout << C[1];
}