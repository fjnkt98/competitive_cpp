#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, C, K;
  std::cin >> N >> C >> K;
  std::vector<int64_t> T(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> T.at(i);
  }

  std::sort(T.begin(), T.end());

  int64_t answer = 0;
  int64_t i = 0;
  while (i < N) {
    answer++;
    int64_t limit_time = T.at(i) + K;

    int64_t count = 1;
    while (count < C && i + count < N) {
      if (T.at(i + count) <= limit_time) {
        count++;
      } else {
        break;
      }
    }

    i += count;
  }

  std::cout << answer << std::endl;

  return 0;
}
