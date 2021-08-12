#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t a, b, c;
  std::cin >> a >> b >> c;

  int64_t c_exp_b = 1;
  for (int64_t i = 0; i < b; i++) {
    c_exp_b *= c;
  }

  if (a < c_exp_b) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
