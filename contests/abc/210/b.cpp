#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::string deck;
  std::cin >> N >> deck;

  for (int64_t i = 0; i < N; i++) {
    if (deck.at(i) == '1') {
      if (i % 2 == 0) {
        std::cout << "Takahashi" << std::endl;
      } else {
        std::cout << "Aoki" << std::endl;
      }
      break;
    }
  }

  return 0;
}
