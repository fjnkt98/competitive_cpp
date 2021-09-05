#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t A, B, W;
  std::cin >> A >> B >> W;

  W *= 1000;
  int64_t minimum_amount = 1LL << 60;
  int64_t maximum_amount = 0;

  for (int64_t i = 1; i <= 1000000; i++) {
    if (A * i <= W && W <= B * i) {
      minimum_amount = std::min(minimum_amount, i);
      maximum_amount = std::max(maximum_amount, i);
    }
  }

  if (maximum_amount == 0) {
    std::cout << "UNSATISFIABLE" << std::endl;
  } else {
    std::cout << minimum_amount << " " << maximum_amount << std::endl;
  }
  return 0;
}
