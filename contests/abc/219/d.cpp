#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, X, Y;
  std::cin >> N >> X >> Y;
  std::vector<int64_t> A(N + 1);
  std::vector<int64_t> B(N + 1);
  for (int64_t i = 1; i <= N ; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  std::vector<std::vector<std::vector<int64_t>>> dp(N + 1,
      std::vector<std::vector<int64_t>>(X + 1, std::vector<int64_t>(Y + 1, 1LL << 60)));
  dp.at(0).at(0).at(0) = 0;
  for (int64_t i = 1; i <= N; i++) {
    for (int64_t j = 0; j <= X; j++) {
      for (int64_t k = 0; k <= Y; k++) {
        // don't choose i-th box
        dp.at(i).at(j).at(k) = std::min(dp.at(i).at(j).at(k), dp.at(i - 1).at(j).at(k));

        // choose i-th box
        dp.at(i).at(std::min(j + A.at(i), X)).at(std::min(k + B.at(i), Y)) = std::min(
            dp.at(i).at(std::min(j + A.at(i), X)).at(std::min(k + B.at(i), Y)),
            dp.at(i - 1).at(j).at(k) + 1);
      }
    }
  }

  if (dp.at(N).at(X).at(Y) == 1LL << 60) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << dp.at(N).at(X).at(Y) << std::endl;
  }

  return 0;
}
