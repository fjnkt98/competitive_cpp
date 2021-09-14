#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t f(int64_t x) {
  std::string S = std::to_string(x);
  std::string g1 = S;
  std::string g2 = S;
  std::sort(g1.begin(), g1.end(), std::greater<char>{});
  std::sort(g2.begin(), g2.end());

  return static_cast<int64_t>(std::stol(g1) - std::stol(g2));
}

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  std::vector<int64_t> a(K + 1);
  a.at(0) = N;

  for (int64_t i = 1; i <= K; i++) {
    a.at(i) = f(a.at(i - 1));
  }

  std::cout << a.at(K) << std::endl;

  return 0;
}
