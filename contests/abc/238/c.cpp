#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t mod = 998244353;
  int64_t N;
  std::cin >> N;

  int64_t digit = std::to_string(N).size();

  int64_t answer = 0;
  int64_t a = 1;
  for (int64_t i = 1; i < digit; i++) {
    answer += ((9 * a) % mod) * ((9 * a + 1) % mod) / 2;
    answer %= mod;
    a *= 10;
  }

  int64_t b = (N + 1) - a;
  b %= mod;
  answer += b * (b + 1) / 2;
  answer %= mod;

  std::cout << answer << std::endl;

  return 0;
}
