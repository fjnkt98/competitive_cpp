#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> C(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> C.at(i);
  }

  std::sort(C.begin(), C.end());

  int64_t answer = C.at(0);
  for (int64_t i = 1; i < N; i++) {
    answer *= C.at(i) - i;
    answer = answer % 1000000007LL;
  }

  std::cout << answer << std::endl;

  return 0;
}
