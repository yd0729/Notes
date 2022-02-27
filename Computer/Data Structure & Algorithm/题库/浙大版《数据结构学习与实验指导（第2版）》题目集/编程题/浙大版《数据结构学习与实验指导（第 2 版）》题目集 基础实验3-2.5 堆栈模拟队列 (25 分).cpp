#include <iostream>
#include <stack>
using namespace std;

class StackQueue {
 private:
  int N1, N2;
  stack<int> s1, s2;

  void printError(int error_code) {
    cout << "ERROR:";
    if (error_code == 1)
      cout << "Full";
    else
      cout << "Empty";
    cout << "\n";
  }

  void transfer() {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }

 public:
  StackQueue(int N1, int N2) {
    this->N1 = min(N1, N2);
    this->N2 = min(N1, N2);
  }

  bool isEmpty() { return s1.empty() and s2.empty(); }

  bool isFull() { return s1.size() == N1 and !s2.empty(); }

  void push(int x) {
    if (isFull()) {
      printError(1);
    } else {
      if (s1.size() == N1) {
        transfer();
      }
      s1.push(x);
    }
  }

  bool pop(int &x) {
    if (isEmpty()) {
      printError(2);
      return false;
    } else {
      if (s2.empty()) {
        transfer();
      }
      x = s2.top();
      s2.pop();
      return true;
    }
  }
};

int main() {
  int N1, N2;
  cin >> N1 >> N2;
  StackQueue q(N1, N2);

  char op;
  int item;
  while (cin >> op and op != 'T') {
    if (op == 'A') {
      cin >> item;
      q.push(item);
    } else if (op == 'D') {
      if (q.pop(item)) cout << item << "\n";
    }
  }
}
