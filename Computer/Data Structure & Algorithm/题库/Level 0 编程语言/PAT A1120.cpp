#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  int n;
  string s;
  set<int> st;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> s;

    int sum = 0;
    for (auto &e : s) sum += e - '0';

    st.insert(sum);
  }

  auto i = st.begin();
  cout << st.size() << "\n" << *i;
  for (++i; i != st.end(); ++i) cout << " " << *i;
}