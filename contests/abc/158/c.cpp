#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  for (int64_t price = 1; price <= 10000; price++) {
    int64_t tax8 = price * 108 / 100;
    int64_t tax10 = price * 110 / 100;

    if (price + A == tax8 && price + B == tax10) {
      std::cout << price << std::endl;
      return 0;
    }
  }

  std::cout << -1 << std::endl;

  return 0;
}
