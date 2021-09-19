#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  std::vector<int64_t> C(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i) >> C.at(i);
  }

  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(3, 0));
  dp.at(0).at(0) = std::max(B.at(0), C.at(0));
  dp.at(0).at(1) = std::max(A.at(0), C.at(0));
  dp.at(0).at(2) = std::max(A.at(0), B.at(0));

  for (int64_t i = 1; i < N; i++) {
    dp.at(i).at(0) = std::max(dp.at(i - 1).at(1) + A.at(i), dp.at(i - 1).at(2) + A.at(i));
    dp.at(i).at(1) = std::max(dp.at(i - 1).at(0) + B.at(i), dp.at(i - 1).at(2) + B.at(i));
    dp.at(i).at(2) = std::max(dp.at(i - 1).at(0) + C.at(i), dp.at(i - 1).at(1) + C.at(i));
  }

  std::cout << std::max(dp.at(N - 1).at(0), std::max(dp.at(N - 1).at(1), dp.at(N - 1).at(2))) << std::endl;

  return 0;
}
