#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t N;
  std::cin >> N;

  double answer = 0;
  for (int64_t i = 0; i < N; i++) {
    double x;
    std::string u;
    std::cin >> x >> u;

    if (u == "JPY") {
      answer += static_cast<double>(x);
    }
    if (u == "BTC") {
      answer += x * 380000.0;
    }
  }

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
