#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t a, b, c;
  std::cin >> a >> b >> c;

  std::cout << std::min(a, std::min(b, c)) << " " << std::max(a, std::max(b, c)) << std::endl;

  return 0;
}
