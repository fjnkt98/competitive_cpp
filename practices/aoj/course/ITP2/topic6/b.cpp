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
  int64_t M;
  std::cin >> M;
  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }

  bool ok = true;
  for (int64_t i = 0; i < M; i++) {
    if (!std::binary_search(A.begin(), A.end(), B.at(i))) {
      ok = false;
    }
  }

  if (ok) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }

  return 0;
}