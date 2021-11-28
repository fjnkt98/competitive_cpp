#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> P(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> P.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N - 1; i++) {
    if (P.at(i) == i + 1) {
      std::swap(P.at(i), P.at(i + 1));
      count++;
    }
  }

  if (P.at(N - 1) == N) {
    count++;
  }

  std::cout << count << std::endl;

  return 0;
}
