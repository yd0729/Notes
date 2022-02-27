#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  char str1[70], str2[70], str3[70], str4[70];
  cin.getline(str1, 70);
  cin.getline(str2, 70);
  cin.getline(str3, 70);
  cin.getline(str4, 70);
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  int len3 = strlen(str3);
  int len4 = strlen(str4);
  int i;
  // 寻找str1和str2中第一对相同位置的A~G的大写字母
  for (i = 0; i < len1 and i < len2; ++i)
    if (str1[i] == str2[i] and str1[i] >= 'A' and str1[i] <= 'G') {
      printf("%s ", week[str1[i] - 'A']);
      break;
    }
  // 在上面的基础上，往后寻找相同位置的0~9或A~N的字符
  for (i++; i < len1 and i < len2; ++i)
    if (str1[i] == str2[i]) {
      if (str1[i] >= '0' and str1[i] <= '9') {
        printf("%02d:", str1[i] - '0');  // 输出0~9
        break;
      } else if (str1[i] >= 'A' and str1[i] <= 'N') {
        printf("%02d:", str1[i] - 'A' + 10);  // 输出10~23
        break;
      }
    }
  // 寻找str3和str4中第一对相同位置的A~Z或a~z的英文字符
  for (i = 0; i < len3 and i < len4; ++i)
    if (str3[i] == str4[i])
      if ((str3[i] >= 'A' and str3[i] <= 'Z') or
          (str3[i] >= 'a' and str3[i] <= 'z')) {
        printf("%02d", i);  // 注意输出格式
        break;
      }
}