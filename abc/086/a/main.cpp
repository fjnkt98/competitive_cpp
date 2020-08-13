#include <iostream>

using namespace std;

int main(void) {
  string s;
  cin >> s;

  int count = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') count++;
  }
  cout << count << endl;
}