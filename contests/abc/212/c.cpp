#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<class T> void choose_min(T& a, T b) {
  if (a > b) {
    a = b;
  }
}

int main() {
  int64_t N, M;
  std::cin >> N >> M;

  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }

  std::sort(A.begin(), A.end());
  std::sort(B.begin(), B.end());

  int64_t minimum_difference = 1LL << 60;
  for (int64_t i = 0; i < N; i++) {
    auto iter = std::lower_bound(B.begin(), B.end(), A.at(i));
    int64_t index = std::distance(B.begin(), iter);

    int64_t diff_a;
    if (index >= M) {
      diff_a = std::abs(A.at(i) - *iter);
    } else {
      diff_a = std::abs(A.at(i) - B.at(index));
    }
    int64_t diff_b;
    if (index - 1 >= 0) {
      diff_b = std::abs(A.at(i) - B.at(index - 1));
    } else {
      diff_b = 1LL << 60;
    }

    if (minimum_difference > diff_a) {
      minimum_difference = diff_a;
    }
    if (minimum_difference > diff_b) {
      minimum_difference = diff_b;
    }
  }

  std::cout << minimum_difference << std::endl;

  return 0;
}
