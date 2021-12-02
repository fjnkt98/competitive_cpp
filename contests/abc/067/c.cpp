#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> cumsum(N + 1);
  std::partial_sum(A.begin(), A.end(), std::next(cumsum.begin()));

  /* for (auto c : cumsum) { */
  /*   std::cout << c << " "; */
  /* } */
  /* std::cout << std::endl; */

  int64_t answer = 1LL << 60;
  for (int64_t i = 1; i < N; i++) {
    int64_t snuke_sum = cumsum.at(i) - cumsum.at(0);
    int64_t arai_sum = cumsum.at(N) - cumsum.at(i);

    answer = std::min(answer, std::abs(arai_sum - snuke_sum));
  }

  std::cout << answer << std::endl;

  return 0;
}
