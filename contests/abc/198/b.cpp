#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  if (N == 0) {
    std::cout << "Yes" << std::endl;
    return 0;
  }

  while (N % 10 == 0) {
    N /= 10;
  }

  std::string S = std::to_string(N);
  int64_t i = 0;
  int64_t j = static_cast<int64_t>(S.size() - 1);
  bool is_palindrome = true;
  while (i < j) {
    if (S.at(i) != S.at(j)) is_palindrome = false;
    i++;
    j--;
  }

  if (is_palindrome) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
