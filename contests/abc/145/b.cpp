#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  if (N % 2 == 1) {
    std::cout << "No" << std::endl;
    return 0;
  }

  std::string S;
  std::cin >> S;

  std::string T = S.substr(0, N / 2);

  if (S == T + T) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}