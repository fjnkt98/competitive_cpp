#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<int64_t> A(N + 1);
  std::vector<int64_t> B(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  std::vector<std::vector<bool>> dp(N + 1, std::vector<bool>(10001, 0));
  dp.at(0).at(0) = true;
  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= 10000; j++) {
      if (j - A.at(i) >= 0) {
        dp.at(i).at(j) = dp.at(i).at(j) || dp.at(i - 1).at(j - A.at(i));
      }
      if (j - B.at(i) >= 0) {
        dp.at(i).at(j) = dp.at(i).at(j) || dp.at(i - 1).at(j - B.at(i));
      }
    }
  }

  if (dp.at(N).at(X) == 1) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
