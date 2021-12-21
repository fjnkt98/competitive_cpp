#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

char transform(char x) {
  if (x == 'z') {
    return 'a';
  } else {
    return x + 1;
  }
}

int main() {
  std::string S, T;
  std::cin >> S >> T;

  bool ok = false;
  for (int64_t i = 0; i < 26; i++) {
    if (S == T) ok = true;
    for (char& s : S) {
      s = transform(s);
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
