#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  int64_t count = 0;
  int64_t open = 0;
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) == '(') {
      count++;
    } else {
      count--;
      if (count < 0) {
        open = std::max(open, -count);
      }
    }
  }

  for (int64_t i = 0; i < open; i++) {
    S = "(" + S;
  }
  N += open;

  count = 0;
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) == '(') {
      count++;
    } else {
      count--;
    }
  }

  for (int64_t i = 0; i < count; i++) {
    S.push_back(')');
  }

  std::cout << S << std::endl;

  return 0;
}
