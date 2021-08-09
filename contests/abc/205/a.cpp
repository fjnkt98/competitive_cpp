#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  double result = static_cast<double>(A * B) / 100;

  std::cout << std::fixed << std::setprecision(10) << result << std::endl;

  return 0;
}
