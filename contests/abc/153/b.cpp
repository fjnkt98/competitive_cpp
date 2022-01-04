#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t H, N;
  std::cin >> H >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  if (H > std::accumulate(A.begin(), A.end(), 0LL)) {
    std::cout << "No" << std::endl;
  } else {
    std::cout << "Yes" << std::endl;
  }

  return 0;
}
