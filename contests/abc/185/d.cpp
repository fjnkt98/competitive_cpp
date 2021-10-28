#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(M + 2);
  A.at(0) = 0;
  A.at(M + 1) = N + 1;
  for (int64_t i = 1; i <= M; i++) {
    std::cin >> A.at(i);
  }
  std::sort(A.begin(), A.end());

  if (M == 0) {
    std::cout << 1 << std::endl;
    return 0;
  }

  std::vector<int64_t> widths;
  for (int64_t i = 0; i < static_cast<int64_t>(A.size()) - 1; i++) {
    int64_t width = A.at(i + 1) - A.at(i) - 1;
    if (width != 0) {
      widths.push_back(width);
    }
  }

  if (widths.size() == 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  int64_t stamp_size = *std::min_element(widths.begin(), widths.end());

  int64_t answer = 0;
  for (int64_t w : widths) {
    answer += std::ceil(static_cast<double>(w) / stamp_size);
  }

  std::cout << answer << std::endl;

  return 0;
}
