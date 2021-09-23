#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<double> p(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> p.at(i);
  }

  std::vector<std::vector<double>> dp(N + 1, std::vector<double>(N + 1));
  dp.at(0).at(0) = 1.0;
  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= N; j++) {
      if (j == 0) dp.at(i).at(j) = dp.at(i - 1).at(j) * (1 - p.at(i));
      else dp.at(i).at(j) = dp.at(i - 1).at(j) * (1 - p.at(i)) + dp.at(i - 1).at(j - 1) * p.at(i);
    }
  }

  double answer = 0;
  for (int64_t i = N / 2 + 1; i <= N; i++) {
    answer += dp.at(N).at(i);
  }

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
