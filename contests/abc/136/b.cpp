#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  int64_t answer = 0;
  for (int64_t i = 1; i <= N; i++) {
    if (static_cast<int64_t>(std::to_string(i).size()) % 2 == 1) {
      answer++;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
