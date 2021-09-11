#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  double answer = static_cast<double>(A - B) * 100 / A;

  std::cout << std::fixed << std::setprecision(10) << answer << std::endl;

  return 0;
}
