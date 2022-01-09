#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int64_t f(int64_t x) { return x * x + 2 * x + 3; }

int main() {
  int64_t t;
  std::cin >> t;

  std::cout << f(f(f(t) + t) + f(f(t))) << std::endl;

  return 0;
}
