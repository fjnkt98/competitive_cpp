#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  int64_t T, A;
  std::cin >> T >> A;
  std::vector<int64_t> H(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> H.at(i);
  }

  std::vector<int64_t> average_temperature(N);
  for (int64_t i = 0; i < N; i++) {
    average_temperature.at(i) = 1000 * T - H.at(i) * 6;
  }

  std::vector<int64_t> deviation(N);
  for (int64_t i = 0; i < N; i++) {
    deviation.at(i) = std::abs(1000 * A - average_temperature.at(i));
  }

  std::cout << std::distance(deviation.begin(), std::min_element(deviation.begin(), deviation.end())) + 1 << std::endl;

  return 0;
}
