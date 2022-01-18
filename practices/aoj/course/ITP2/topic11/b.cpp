#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  int64_t k;
  std::cin >> k;
  std::bitset<64> T(0);
  for (int64_t i = 0; i < k; i++) {
    int64_t b;
    std::cin >> b;
    T.set(b);
  }

  for (int64_t bit = 0; bit < (1 << N); bit++) {
    std::bitset<64> X = T & std::bitset<64>(bit);

    if (X.to_ullong() != T.to_ullong()) {
      continue;
    }

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