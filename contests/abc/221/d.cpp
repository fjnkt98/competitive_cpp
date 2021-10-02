#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<int64_t, int64_t>> X(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    X.at(i) = std::make_pair(a + b, a);
  }

  std::sort(X.begin(), X.end());

  std::vector<int64_t> answer(N + 1, 0);
  for (int64_t i = 0; i < N; i++) {
  }


  return 0;
}
