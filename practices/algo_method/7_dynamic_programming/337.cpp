#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(M + 1, false));
  for (int64_t i = 0; i <= N; i++) {
    dp.at(i).at(0) = true;
  }

  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 1; j <= M; j++) {
      dp.at(i).at(j) = dp.at(i).at(j) || dp.at(i - 1).at(j);

      if (j - A.at(i) >= 0) {
        dp.at(i).at(j) = dp.at(i).at(j) || dp.at(i - 1).at(j - A.at(i));
      }
    }
  }

  if (dp.at(N).at(M)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}