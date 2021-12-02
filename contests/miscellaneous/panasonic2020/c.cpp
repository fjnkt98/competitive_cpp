#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t a, b, c;
  std::cin >> a >> b >> c;


  if (c - a - b <= 0) {
    std::cout << "No" << std::endl;
    return 0;
  }

  int64_t left = 4 * a * b;
  int64_t right = (c - a - b) * (c - a - b);

  if (left < right) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
