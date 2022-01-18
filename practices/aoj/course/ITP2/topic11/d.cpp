#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N, k;
  std::cin >> N >> k;

  for (int64_t bit = 0; bit < (1LL << N); bit++) {
    std::vector<int64_t> elements;

    std::bitset<64> s(bit);
    if (s.count() != k) continue;

    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        elements.push_back(i);
      }
    }

    std::cout << s.to_ullong() << ":";
    for (int64_t e : elements) {
      std::cout << " " << e;
    }
    std::cout << std::endl;
  }

  return 0;
}