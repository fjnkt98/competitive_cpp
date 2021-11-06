#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  std::vector<int64_t> E(N);
  std::vector<int64_t> W(N);
  for (int64_t i = 0; i < N - 1; i++) {
    if (S.at(i) == 'W') {
      W.at(i + 1) = W.at(i) + 1;
    } else {
      W.at(i + 1) = W.at(i);
    }
 }

  for (int64_t i = N - 1; i >= 1; i--) {
    if (S.at(i) == 'E') {
      E.at(i - 1) = E.at(i) + 1;
    } else {
      E.at(i - 1) = E.at(i);
    }
  }

  int64_t answer = 1LL << 60;
  for (int64_t i = 0; i < N; i++) {
    answer = std::min(answer, W.at(i) + E.at(i));
  }

  std::cout << answer << std::endl;

  return 0;
}
