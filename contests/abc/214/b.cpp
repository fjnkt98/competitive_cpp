#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t S, T;
  std::cin >> S >> T;

  std::vector<std::vector<int64_t>> pre_satisfied;
  
  for (int64_t i = 0; i <= 100; i++) {
    for (int64_t j = 0; j <= 100; j++) {
      for (int64_t k = 0; k <= 100; k++) {
        if (i + j + k <= S) {
          pre_satisfied.push_back({i, j, k});
        }
      }
    }
  }

  int64_t count = 0;
  for (auto& p : pre_satisfied) {
    if (p.at(0) * p.at(1) * p.at(2) <= T) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
