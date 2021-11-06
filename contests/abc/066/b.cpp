#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_even_string(std::string S) {
  if (S.size() % 2 == 1) {
    return false;
  }

  for (size_t i = 0; i < S.size() / 2; i++) {
    if (S.at(i) != S.at(i + S.size() / 2)) {
      return false;
    }
  }

  return true;
}

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size());

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    S.pop_back();
    if (is_even_string(S)) {
      answer = S.size();
      break;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
