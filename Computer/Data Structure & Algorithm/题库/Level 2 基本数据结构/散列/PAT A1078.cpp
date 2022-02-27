#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) return false;
  return true;
}

bool hash_table[10005];

void insert(int key, int size) {
  for (int step = 0; step < size; ++step) {
    int pos = (key + step * step) % size;
    if (not hash_table[pos]) {
      hash_table[pos] = true;
      cout << pos;
      return;
    }
  }
  cout << "-";
}

int main() {
  int n, size, key;
  cin >> size >> n;
  while (not is_prime(size)) ++size;
  for (int i = 0; i < n; ++i) {
    cin >> key;
    if (i != 0) cout << " ";
    insert(key, size);
  }
}