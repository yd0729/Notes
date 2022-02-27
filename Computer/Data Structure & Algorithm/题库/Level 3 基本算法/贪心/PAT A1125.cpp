#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n;

  priority_queue<double, vector<double>, greater<double>> pq;

  for (int i = 0; i < n; ++i) {
    cin >> x;
    pq.push(x);
  }

  while (pq.size() > 1) {
    double a = pq.top();
    pq.pop();
    double b = pq.top();
    pq.pop();
    pq.push((a + b) / 2);
  }

  cout << int(pq.top());
}