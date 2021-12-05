#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t minimum_practice_amount(int64_t target_time, int64_t time, int64_t cost) {
  int64_t left = -1;
  int64_t right = time + 1;

  while (right - left > 1) {
    int64_t mid = (right + left) / 2;

    if ((time - mid) * cost <= target_time) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return right;
}

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  std::vector<int64_t> F(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> F.at(i);
  }

  std::sort(A.begin(), A.end());
  std::sort(F.begin(), F.end(), std::greater<int64_t>{});

  std::vector<int64_t> time(N);
  for (int64_t i = 0; i < N; i++) {
    time.at(i) = A.at(i) * F.at(i);
  }

  int64_t left = -1;
  int64_t right = *std::max_element(time.begin(), time.end()) + 1;

  while (right - left > 1) {
    int64_t mid = (right + left) / 2;

    int64_t practice = 0;

    for (int64_t i = 0; i < N; i++) {
      practice += minimum_practice_amount(mid, A.at(i), F.at(i));
    }

    if (practice <= K) {
      right = mid;
    } else {
      left = mid;
    }
  }

  std::cout << right << std::endl;

  return 0;
}
