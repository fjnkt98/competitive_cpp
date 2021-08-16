#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(2 * N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  int64_t init = 0;
  int64_t sum = std::accumulate(A.begin(), A.end(), std::move(init));

  if (sum / 10 == 0) {
    std::cout << "No" << std::endl;
    return 0;
  }

  for (int64_t i = N; i < 2 * N; i++) {
    A.at(i) = A.at(i - N);
  }

  std::vector<int64_t> partial_sum(2 * N);
  std::partial_sum(A.begin(), A.end(), partial_sum.begin());

  bool ok = false;
  for (int64_t i = 1; i < 2 * N; i++) {
    auto iter = std::lower_bound(partial_sum.begin(),
                                 partial_sum.end(),
                                 partial_sum.at(i) + sum / 10);
    if (iter == partial_sum.end()) {
      continue;
    }
    int64_t index = std::distance(partial_sum.begin(), iter);
    if (partial_sum.at(index - 1) - partial_sum.at(i - 1) == sum / 10) {
      ok = true;
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
