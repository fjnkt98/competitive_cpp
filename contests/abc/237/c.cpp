#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  int64_t N = static_cast<int64_t>(S.size());
  int64_t left = 0;
  int64_t right = N;
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) != 'a') {
      left = i;
      break;
    }
  }
  for (int64_t i = N - 1; i >= 0; i--) {
    if (S.at(i) != 'a') {
      right = i + 1;
      break;
    }
  }

  if (left > N - right) {
    std::cout << "No" << std::endl;
    return 0;
  }

  std::string T = S.substr(left, right - left);

  std::string U = T;
  std::reverse(U.begin(), U.end());

  if (T == U) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
