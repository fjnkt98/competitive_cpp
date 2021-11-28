#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K, S;
  std::cin >> N >> K >> S;

  std::vector<int64_t> A(N);
  if (S == 10e9) {
    for (int64_t i = 0; i < N; i++) {
      if (i < K) A.at(i) = S;
      else A.at(i) = 1;
    }
  } else {
    for (int64_t i = 0; i < N; i++) {
      if (i < K) A.at(i) = S;
      else A.at(i) = S + 1;
    }
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << A.at(i);
  }
  std::cout << std::endl;

  return 0;
}
