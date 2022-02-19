#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t X, Y;
  std::cin >> X >> Y;

  if (std::gcd(X, Y) == Y) {
    std::cout << -1 << std::endl;
    return 0;
  }

  std::cout << X << std::endl;

  return 0;
}