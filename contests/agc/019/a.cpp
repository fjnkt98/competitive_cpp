#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t Q, H, S, D;
  std::cin >> Q >> H >> S >> D;
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> V = {8 * Q, 4 * H, 2 * S, D};
  std::sort(V.begin(), V.end());

  int64_t answer = 0;
  while (N > 1) {
    N -= 2;
    answer += V.at(0);
  }

  if (N == 1) {
    answer += std::min(4 * Q, std::min(2 * H, S));
  }

  std::cout << answer << std::endl;

  return 0;
}