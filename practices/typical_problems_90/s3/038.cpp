#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  int64_t gcd = std::gcd(A, B);
  int64_t limit = 1000000000000000000;

  if ((A / gcd) > (limit / B)) {
    std::cout << "Large" << std::endl;
  } else {
    std::cout << (A / gcd) * B << std::endl;
  }

  return 0;
}
