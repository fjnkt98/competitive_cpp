#include <iostream>
#include <numeric>
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

  std::vector<int64_t> B(2 * N + 1, 0);
  for (int64_t i = 0; i < 2 * N; i++) {
    B.at(i + 1) += B.at(i) + A.at(i % N);
  }

  bool ok = false;
  for (int64_t i = 0; i < N; i++) {
    int64_t target_value = B.at(i) + B.at(N) / 10;
    auto iter = std::lower_bound(B.begin(), B.end(), target_value);
    if (iter == B.end()) continue;
    if (*iter == target_value) {
      ok = true;
    }
  }

  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
