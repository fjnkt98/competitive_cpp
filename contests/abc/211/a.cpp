#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  double C = static_cast<double>(A - B) / 3 + B;

  std::cout << std::fixed << std::setprecision(10) << C << std::endl;

  return 0;
}
