#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, array<array<char, 5>, 7>> matrix;

void print_word(string &s) {
  for (int i = 0; i < 7; ++i) {
    for (int j = 0; j < s.length(); ++j) {
      for (int k = 0; k < 5; ++k) {
        cout << matrix[s[j]][i][k];
      }
      if (j != s.length() - 1) cout << " ";
    }
    cout << "\n";
  }
}

int main() {
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 7; ++j) {
      for (int k = 0; k < 5; ++k) {
        cin >> matrix['A' + i][j][k];
      }
    }
  }

  cin.get();  // 吃掉回车
  string sentence;
  getline(cin, sentence);

  vector<string> word;

  for (int i = 0; i < sentence.length();) {
    while (i < sentence.length() and
           !(sentence[i] >= 'A' and sentence[i] <= 'Z'))
      ++i;  // 找到单词的第一个字母
    int j = i;
    for (;
         j < sentence.length() and (sentence[j] >= 'A' and sentence[j] <= 'Z');
         ++j)
      ;
    if (i < j)  // [i, j) 是一个单词
      word.push_back(sentence.substr(i, j - i));
    i = j + 1;  // j 此时一定不是字母，所以 +1
  }

  for (int i = 0; i < word.size(); ++i) {
    print_word(word[i]);
    if (i < word.size() - 1) cout << "\n";
  }
}
