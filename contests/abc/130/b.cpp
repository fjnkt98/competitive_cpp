#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<int64_t> L(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> L.at(i);
  }

  std::vector<int64_t> D(N + 1);
  for (int64_t i = 0; i < N; i++) {
    D.at(i + 1) = D.at(i) + L.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i <= N; i++) {
    if (D.at(i) <= X) answer++;
  }

  std::cout << answer << std::endl;

  return 0;
}
