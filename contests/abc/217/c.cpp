#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> p(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> p.at(i);
  }

  std::vector<int64_t> q(N);
  for (int64_t i = 0; i < N; i++) {
    q.at(p.at(i) - 1) = i + 1;
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << q.at(i);
  }
  std::cout << std::endl;

  return 0;
}
