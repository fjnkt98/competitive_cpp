#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> time(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> time.at(i);
  }

  int64_t sum = 0;
  for (int64_t i = 0; i < N; i++) {
    sum += time.at(i);
  }

  std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(sum + 1, false));
  dp.at(0).at(0) = true;

  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < sum + 1; j++) {
      if (j - time.at(i) >= 0) {
        if (dp.at(i).at(j - time.at(i))) {
          dp.at(i + 1).at(j) = true;
        }
      }
      if (dp.at(i).at(j)) {
        dp.at(i + 1).at(j) = true;
      }
    }
  }

  for (int64_t i = (sum + 1) / 2; i < sum + 1; i++) {
    if (dp.at(N).at(i)) {
      std::cout << i << std::endl;
      break;
    }
  }

  return 0;
}
