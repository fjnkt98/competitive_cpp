#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int64_t octal_to_deicmal(std::string x) {
  if (x == "0") {
    return 0;
  }
  int64_t decimal_x = 0;
  int64_t coefficient = 1;
  for (int64_t i = x.size() - 1; i >= 0; i--) {
    decimal_x += static_cast<int64_t>(x.at(i) - '0') * coefficient;
    coefficient *= 8;
  }
  return decimal_x;
}

std::string decimal_to_nonary(int64_t x) {
  if (x == 0) {
    return "0";
  }
  std::string nonary_x;
  while (x > 0) {
    nonary_x = static_cast<char>(x % 9 + '0') + nonary_x;
    x /= 9;
  }
  return nonary_x;
}

int main() {
  std::string N;
  int64_t K;
  std::cin >> N >> K;

  for (int64_t i = 0; i < K; i++) {
    // Convert octary to nonary
    N = decimal_to_nonary(octal_to_deicmal(N));

    // Replace '8' to '5'
    for (auto& digit : N) {
      if (digit == '8') {
        digit = '5';
      }
    }
  }

  std::cout << N << std::endl;
  return 0;
}
