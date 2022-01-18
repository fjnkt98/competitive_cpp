#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  for (int64_t bit = 0; bit < (1 << N); bit++) {
    std::vector<int64_t> element;

    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        element.push_back(i);
      }
    }

    if (element.empty()) {
      std::cout << "0:" << std::endl;
      continue;
    }

    std::cout << bit << ":";
    for (auto e : element) {
      std::cout << " " << e;
    }
    std::cout << std::endl;
  }

  return 0;
}