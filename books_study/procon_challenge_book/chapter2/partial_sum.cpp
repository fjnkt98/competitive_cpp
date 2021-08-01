#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  std::vector<std::vector<bool>> dp(K + 1, std::vector<bool>(N + 1, false));
  dp.at(0).assign(N + 1, true);
  
  for (int64_t i = 1; i <= K; i++) {
    for (int64_t j = 1; j <= N; j++) {
      if (i - a.at(j - 1) >= 0) {
        dp.at(i).at(j) = 
          dp.at(i).at(j - 1) || dp.at(i - a.at(j - 1)).at(j - 1);
      } else {
        dp.at(i).at(j) = dp.at(i).at(j - 1);
      }
    }
  }

  if (dp.at(K).at(N)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
