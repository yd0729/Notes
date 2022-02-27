#include <iostream>

using namespace std;

bool is_prime(int x) {
  if (x <= 1) return false;
  if (x == 2) return true;
  if (x % 2 == 0) return false;
  for (int i = 3; i * i <= x; i += 2)
    if (x % i == 0) return false;
  return true;
}

int hash_table[100000];

int main() {
  int m_size, n, m, x, ans = 0;

  cin >> m_size >> n >> m;

  while (!is_prime(m_size)) ++m_size;

  for (int i = 0; i < n; ++i) {
    cin >> x;

    bool insert = false;
    for (int j = 0; j < m_size; ++j) {
      int pos = (x + j * j) % m_size;
      if (hash_table[pos] == 0) {  // 因为输入的都是正数
        hash_table[pos] = x;
        insert = true;
        break;
      }
    }
    if (!insert) cout << x << " cannot be inserted.\n";
  }

  for (int i = 0; i < m; ++i) {
    cin >> x;

    int j = 0;
    for (; j < m_size; ++j) {
      int pos = (x + j * j) % m_size;
      if (hash_table[pos] == 0 or hash_table[pos] == x) break;
    }
    // 还有一种不是 break 出来的情况
    ans += j + 1;
  }

  printf("%.1f", ans * 1.0 / m);
}