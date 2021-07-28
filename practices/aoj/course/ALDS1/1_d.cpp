#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> rate(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> rate.at(i);
  }

  int64_t minimum_rate = rate.at(0);
  int64_t maximum_profit = -(1LL << 60);
  for (int64_t i = 1; i < N; i++) {
    int64_t profit = rate.at(i) - minimum_rate;

    if (profit > maximum_profit) {
      maximum_profit = profit;
    }
    if (rate.at(i) < minimum_rate) {
      minimum_rate = rate.at(i);
    }
  }

  std::cout << maximum_profit << std::endl;

  return 0;
}
