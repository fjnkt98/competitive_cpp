#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t the_day = static_cast<int64_t>(
      std::ceil(
        std::sqrt(2 * N + 0.25) - 0.5
        )
      );

  std::cout << the_day << std::endl;

  return 0;
}
