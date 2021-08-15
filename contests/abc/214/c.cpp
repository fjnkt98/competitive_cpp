#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }
  std::vector<int64_t> T(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> T.at(i);
  }

  std::vector<int64_t> answer(T.begin(), T.end());
  for (int64_t i = 0; i < 2 * N; i++) {
    answer.at((i + 1) % N) = std::min(answer.at((i + 1) % N),
                                      answer.at(i % N) + S.at(i % N));
  }

  for (auto& a : answer) {
    std::cout << a << std::endl;
  }

  return 0;
}
