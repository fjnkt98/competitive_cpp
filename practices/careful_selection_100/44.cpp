#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int64_t reg_tetra(int64_t n) { return (n * (n + 1) * (n + 2)) / 6; }

int main() {
  std::vector<int64_t> A;
  while (true) {
    int64_t N;
    std::cin >> N;

    if (N == 0) break;

    A.push_back(N);
  }

  int64_t M = *std::max_element(A.begin(), A.end());
  std::vector<int64_t> B;
  for (int64_t i = 1; i < M; i++) {
    int64_t R = reg_tetra(i);
    if (R > M) break;

    B.push_back(R);
  }
  std::vector<int64_t> C;
  for (int64_t i = 1; i < M; i++) {
    int64_t R = reg_tetra(i);
    if (R > M) break;

    if (R % 2 == 1) C.push_back(R);
  }

  std::vector<int64_t> dp1_c(M + 1, 1LL << 60);
  std::vector<int64_t> dp1_p(M + 1, 1LL << 60);
  dp1_p.at(0) = 0;
  for (int64_t b : B) {
    for (int64_t j = 0; j <= M; j++) {
      dp1_c.at(j) = dp1_p.at(j);

      if (j - b >= 0) {
        dp1_c.at(j) = std::min(dp1_c.at(j), dp1_c.at(j - b) + 1);
      }
    }

    std::copy(dp1_c.begin(), dp1_c.end(), dp1_p.begin());
  }

  std::vector<int64_t> dp2_c(M + 1, 1LL << 60);
  std::vector<int64_t> dp2_p(M + 1, 1LL << 60);
  dp2_p.at(0) = 0;
  for (int64_t c : C) {
    for (int64_t j = 0; j <= M; j++) {
      dp2_c.at(j) = dp2_p.at(j);

      if (j - c >= 0) {
        dp2_c.at(j) = std::min(dp2_c.at(j), dp2_c.at(j - c) + 1);
      }
    }

    std::copy(dp2_c.begin(), dp2_c.end(), dp2_p.begin());
  }

  for (int64_t a : A) {
    std::cout << dp1_c.at(a) << " " << dp2_c.at(a) << std::endl;
  }

  return 0;
}