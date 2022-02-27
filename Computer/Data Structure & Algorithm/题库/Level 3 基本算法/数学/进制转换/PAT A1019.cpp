#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  vector<int> num;
  for (; n != 0; n /= b) num.push_back(n % b);
  vector<int> front(num.begin(), num.begin() + num.size() / 2);
  vector<int> back(num.rbegin(), num.rbegin() + num.size() / 2);
  cout << (front == back ? "Yes\n" : "No\n");
  for (auto i = num.rbegin(); i != num.rend(); ++i)
    cout << *i << (i + 1 == num.rend() ? "" : " ");
}
