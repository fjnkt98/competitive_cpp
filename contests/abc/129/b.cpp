#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> W(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> W.at(i);
  }

  int64_t answer = 1LL << 60;
  for (int64_t T = 0; T < N; T++) {
    int64_t S1 = 0;
    int64_t S2 = 0;

    for (int64_t i = 0; i <= T; i++) {
      S1 += W.at(i);
    }

    for (int64_t i = T + 1; i < N; i++) {
      S2 += W.at(i);
    }

    answer = std::min(answer, std::abs(S1 - S2));
  }

  std::cout << answer << std::endl;

  return 0;
}
