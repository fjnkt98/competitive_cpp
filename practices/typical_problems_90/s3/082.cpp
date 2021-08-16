#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

const int64_t mod = 1000000007;

int64_t counting_numbers(uint64_t x) {
  if (x % 2 == 0) {
    return (((x / 2) % mod) * ((x + 1) % mod)) % mod;
  } else {
    return ((((x + 1) / 2) % mod) * ((x % mod) % mod)) % mod;
  }
}

int main() {
  uint64_t L, R;
  std::cin >> L >> R;

  std::vector<uint64_t> power_10_x(20, 1);
  for (int64_t i = 1; i < 20; i++) {
    const uint64_t coeff = 10;
    power_10_x.at(i) = power_10_x.at(i - 1) * coeff;
  }

  int64_t answer = 0;
  for (int64_t i = 1; i < 20; i++) {
    uint64_t left = std::max(L, power_10_x.at(i - 1));
    uint64_t right = std::min(R, power_10_x.at(i) - 1);

    if (left > right) continue;

    answer += i * (counting_numbers(right) - counting_numbers(left - 1) + mod) % mod;
    answer = answer % mod;
  }

  std::cout << answer << std::endl;
  return 0;
}
