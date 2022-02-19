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
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> B.at(i);
  }

  int64_t sum_a = std::accumulate(A.begin(), A.end(), 0LL);
  int64_t sum_b = std::accumulate(B.begin(), B.end(), 0LL);

  int64_t operation_count = sum_b - sum_a;
  if (operation_count == 0) {
    if (A == B) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
    return 0;
  } else if (operation_count < 0) {
    std::cout << "No" << std::endl;
    return 0;
  }

  std::vector<int64_t> diff(N);
  for (int64_t i = 0; i < N; i++) {
    diff.at(i) = A.at(i) - B.at(i);
  }

  bool ok = true;
  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) < B.at(i)) {
      count += (B.at(i) - A.at(i) + 1) / 2;
    }
  }

  if (count > operation_count) ok = false;

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}