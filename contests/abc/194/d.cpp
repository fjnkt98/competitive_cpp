#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t N;
  std::cin >> N;

  double E = 0;
  for (int64_t i = 1; i < N; i++) {
    E += static_cast<double>(N) / (N - i);
  }

  std::cout << std::fixed << std::setprecision(10) << E << std::endl;

  return 0;
}
