#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> v(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> v.at(i);
  }

  std::sort(v.begin(), v.end());
  double answer = v.at(0);
  for (int64_t i = 1; i < N; i++) {
    answer = static_cast<double>(v.at(i) + answer) / 2;
  }

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
