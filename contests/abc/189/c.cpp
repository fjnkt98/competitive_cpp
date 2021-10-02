#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t min = A.at(i);
    for (int64_t j = i; j < N; j++) {
      min = std::min(min, A.at(j));
      answer = std::max(answer, min * (j - i + 1));
      /* std::cout << i << " " << j << " " << min << std::endl; */
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
