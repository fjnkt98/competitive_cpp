/*
 * Minimum value which greeter than or equal to K in the pair sum.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
  int64_t N;
  int64_t K;
  std::cin >> N >> K;

  std::vector<int64_t> a(N);
  std::vector<int64_t> b(N);

  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> b.at(i);
  }

  int64_t minimum_value = INT_MAX;

  std::sort(b.begin(), b.end());

  b.push_back(INT_MAX);
  
  for (int64_t i = 0; i < N; i++) {
    auto iter = std::lower_bound(b.begin(), b.end(), K - a.at(i));

    int64_t value = *iter;

    if (a.at(i) + value < minimum_value) {
      minimum_value = a.at(i) + value;
    }
  }

  std::cout << minimum_value << std::endl;

  return 0;
}
