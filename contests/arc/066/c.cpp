#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  const int64_t mod = 1000000007;
  std::vector<int64_t> count(N);
  for (int64_t i = 0; i < N; i++) {
    count.at(A.at(i))++;
  }

  bool ok = true;
  if (N % 2 == 0) {
    for (int64_t i = 1; i < N; i += 2) {
      if (count.at(i) != 2) {
        ok = false;
      }
    }

  } else {
    if (count.at(0) != 1) {
      ok = false;
    }
    for (int64_t i = 2; i < N; i += 2) {
      if (count.at(i) != 2) {
        ok = false;
      }
    }
  }

  if (ok) {
    int64_t answer = 1;
    for (int64_t i = 0; i < N / 2; i++) {
      answer *= 2;
      answer %= mod;
    }

    std::cout << answer << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}