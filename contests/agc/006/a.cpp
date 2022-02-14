#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::string s, t;
  std::cin >> s >> t;

  int64_t x = 0;
  for (int64_t i = 0; i <= N; i++) {
    if (s.substr(N - i) == t.substr(0, i)) {
      x = i;
    }
  }

  std::cout << 2 * N - x << std::endl;

  return 0;
}