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

  int64_t Q;
  std::cin >> Q;
  for (int64_t i = 0; i < Q; i++) {
    int64_t b, e, k;
    std::cin >> b >> e >> k;

    int64_t count = 0;
    for (auto iter = std::next(A.begin(), b); iter != std::next(A.begin(), e); iter++) {
      if (*iter == k) {
        count++;
      }
    }

    std::cout << count << std::endl;
  }

  return 0;
}
