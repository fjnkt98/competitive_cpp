#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> H(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> H.at(i);
  }

  int64_t answer = H.at(0);
  for (int64_t i = 1; i < N; i++) {
    if (answer < H.at(i)) {
      answer = H.at(i);
    } else {
      break;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
