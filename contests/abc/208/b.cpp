#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  std::vector<int64_t> coins(10);
  int64_t prod = 1;
  for (int64_t i = 1; i <= coins.size(); i++) {
    coins.at(i - 1) = prod;
    prod *= i + 1;
  }

  int64_t P = 0;
  std::cin >> P;

  int64_t count = 0;
  for (int64_t i = coins.size() - 1; i >= 0; i--) {
    if (P < coins.at(i)) {
      continue;
    }
    while (P >= coins.at(i)) {
      P -= coins.at(i);
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
