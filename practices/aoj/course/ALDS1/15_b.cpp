#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <iomanip>

int main() {
  int64_t N, W;
  std::cin >> N >> W;

  std::vector<std::tuple<double, int64_t, int64_t>> A(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t v, w;
    std::cin >> v >> w;
    double cost_performance = static_cast<double>(v) / w;

    A.at(i) = std::make_tuple(cost_performance, v, w);
  }

  std::sort(A.begin(), A.end(), std::greater<std::tuple<double, int64_t, int64_t>>{});

  double total_value = 0.0;
  for (int64_t i = 0; i< N; i++) {
    double cost_performance = std::get<0>(A.at(i));
    int64_t value = std::get<1>(A.at(i));
    int64_t weight = std::get<2>(A.at(i));

    if (W - weight > 0) {
      W -= weight;
      total_value += value;
    } else {
      total_value += W * cost_performance;
      break;
    }
  }

  std::cout << std::fixed << std::setprecision(10) << total_value << std::endl;

  return 0;
}
