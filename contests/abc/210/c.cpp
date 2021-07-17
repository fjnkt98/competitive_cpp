#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> c(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> c.at(i);
  }

  std::map<int64_t, int64_t> candies;
  int64_t maximum_variety = 0;

  for (int64_t k = 0; k < K; k++) {
    candies[c.at(k)]++;
  }
  maximum_variety = candies.size();

  for (int64_t i = 1; i <= N - K; i++) {
    candies[c.at(i - 1)]--;
    if (candies[c.at(i - 1)] <= 0) {
      candies.erase(c.at(i - 1));
    }
    candies[c.at(i + K - 1)]++;

    if (candies.size() > maximum_variety) {
      maximum_variety = candies.size();
    }
  }

  std::cout << maximum_variety << std::endl;

  return 0;
}
