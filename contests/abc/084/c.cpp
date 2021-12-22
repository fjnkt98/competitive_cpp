#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> C(N);
  std::vector<int64_t> S(N);
  std::vector<int64_t> F(N);
  for (int64_t i = 0; i < N - 1; i++) {
    std::cin >> C.at(i) >> S.at(i) >> F.at(i);
  }

  std::vector<int64_t> answer(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t time = 0;
    for (int64_t j = i; j < N - 1; j++) {
      time = std::max(time, S.at(j));

      int64_t elapsed_time = time - S.at(j);
      if (elapsed_time % F.at(j) != 0) {
        elapsed_time = F.at(j) - (elapsed_time % F.at(j));
      } else {
        elapsed_time = 0;
      }

      time += elapsed_time + C.at(j);
    }

    answer.at(i) = time;
  }

  for (auto a : answer) {
    std::cout << a << std::endl;
  }

  return 0;
}
