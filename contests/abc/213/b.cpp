#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<int64_t, int64_t>> A(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    std::cin >> a;

    A.at(i) = std::make_pair(a, i);
  }

  std::sort(A.begin(), A.end());

  std::cout << (*(A.end() - 2)).second + 1 << std::endl;

  return 0;
}
