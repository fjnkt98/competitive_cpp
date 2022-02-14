#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<int64_t, int64_t>> points(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> points.at(i).first >> points.at(i).second;
  }

  std::sort(points.begin(), points.end());

  std::map<std::pair<int64_t, int64_t>, int> count;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      auto [xi, yi] = points.at(i);
      auto [xj, yj] = points.at(j);

      int64_t dx = xj - xi;
      int64_t dy = yj - yi;

      count[{dx, dy}] += 1;
    }
  }

  int64_t profit = 0;
  for (auto iter = count.begin(); iter != count.end(); ++iter) {
    int64_t quantity = iter->second;
    profit = std::max(profit, quantity);
  }

  std::cout << N - profit << std::endl;

  return 0;
}