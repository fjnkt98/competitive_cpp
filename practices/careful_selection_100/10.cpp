/*
 * https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  int64_t M;
  std::cin >> M;
  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }

  std::vector<bool> answer(M, false);
  for (int64_t bit = 0; bit < (1 << N); bit++) {
    int64_t sum = 0;
    for (int64_t i = 0; i < N; i++) {
      if (bit & (1 << i)) {
        sum += A.at(i);
      }
    }

    auto iter = std::find(B.begin(), B.end(), sum);
    if (iter != B.end()) {
      answer.at(std::distance(B.begin(), iter)) = true;
    }
  }

  for (auto p : answer) {
    if (p) {
      std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }

}
