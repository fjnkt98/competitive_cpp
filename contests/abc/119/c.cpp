#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int64_t INF = 1LL << 60;

int64_t dfs(int64_t i, int64_t a, int64_t b, int64_t c,
            int64_t A, int64_t B, int64_t C, int64_t cost,
            std::vector<int64_t>& bamboo) {
  if (i == static_cast<int64_t>(bamboo.size())) {
    if (a == 0 || b == 0 || c == 0) {
      return INF;
    }

    return (std::abs(A - a) + std::abs(B - b) + std::abs(C - c)) + cost;
  }

  int64_t result;
  result = dfs(i + 1, a, b, c, A, B, C, cost, bamboo);
  result = std::min(result, dfs(i + 1, a + bamboo.at(i), b, c, A, B, C, cost + (a ? 10 : 0), bamboo));
  result = std::min(result, dfs(i + 1, a, b + bamboo.at(i), c, A, B, C, cost + (b ? 10 : 0), bamboo));
  result = std::min(result, dfs(i + 1, a, b, c + bamboo.at(i), A, B, C, cost + (c ? 10 : 0), bamboo));

  return result;
}

int main() {
  int64_t N, A, B, C;;
  std::cin >> N >> A >> B >> C;

  std::vector<int64_t> bamboo(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> bamboo.at(i);
  }

  std::cout << dfs(0, 0, 0, 0, A, B, C, 0, bamboo) << std::endl;

  return 0;
}
