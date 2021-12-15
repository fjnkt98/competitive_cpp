#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> L(M);
  std::vector<int64_t> R(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> L.at(i) >> R.at(i);
  }

  int64_t r = *std::min_element(R.begin(), R.end());
  int64_t l = *std::max_element(L.begin(), L.end());

  int64_t answer = r - l + 1;
  if (answer > 0) {
    std::cout << answer << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}
