#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<double> A(n);
  double avg = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
    avg += A[i];
  }
  avg /= n;

  double variance = 0;
  for (int i = 0; i < n; ++i) {
    variance += pow(A[i] - avg, 2);
  }
  variance /= n;
  double mean_variance = sqrt(variance);

  cout << fixed << setprecision(5) << mean_variance;
}