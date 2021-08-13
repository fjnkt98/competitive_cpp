#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<int64_t> A(N);
  for (auto& a : A) {
    std::cin >> a;
  }
  std::vector<int64_t> L(Q);
  std::vector<int64_t> R(Q);
  std::vector<int64_t> V(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> L.at(i) >> R.at(i) >> V.at(i);
    L.at(i)--;
    R.at(i)--;
  }

  std::vector<int64_t> diff(N);
  for (int64_t i = 1; i < N; i++) {
    diff.at(i) = A.at(i) - A.at(i - 1);
  }
  diff.push_back(0);

  int64_t inconvenience = 0;
  for (const auto& d : diff) {
    inconvenience += std::abs(d);
  }
  for (int64_t i = 0; i < Q; i++) {
    inconvenience -= std::abs(diff.at(L.at(i)));
    inconvenience -= std::abs(diff.at(R.at(i) + 1));
    if (L.at(i) > 0) diff.at(L.at(i)) += V.at(i);
    if (R.at(i) < N - 1) diff.at(R.at(i) + 1) -= V.at(i);

    inconvenience += std::abs(diff.at(L.at(i)));
    inconvenience += std::abs(diff.at(R.at(i) + 1));

    std::cout << inconvenience << std::endl;
  }

  return 0;
}
