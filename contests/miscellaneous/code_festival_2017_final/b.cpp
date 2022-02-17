#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size());

  int64_t a = 0;
  int64_t b = 0;
  int64_t c = 0;
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) == 'a')
      a++;
    else if (S.at(i) == 'b')
      b++;
    else if (S.at(i) == 'c')
      c++;
  }

  bool ok = true;
  if (a == 0) {
    if (b >= 2 || c >= 2) ok = false;
  } else if (b == 0) {
    if (a >= 2 || c >= 2) ok = false;
  } else if (c == 0) {
    if (a >= 2 || b >= 2) ok = false;
  } else {
    int64_t min = std::min(a, std::min(b, c));

    a -= min;
    b -= min;
    c -= min;
    if (a == 0) {
      if (b >= 2 || c >= 2) ok = false;
    } else if (b == 0) {
      if (a >= 2 || c >= 2) ok = false;
    } else if (c == 0) {
      if (a >= 2 || b >= 2) ok = false;
    }
  }

  if (ok) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }

  return 0;
}