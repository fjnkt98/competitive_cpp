#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, X;
  std::cin >> N >> X;
  std::vector<int64_t> V(N);
  std::vector<int64_t> P(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> V.at(i) >> P.at(i);
  }

  int64_t answer = -1;
  int64_t alcohol = 0;
  for (int64_t i = 0; i < N; i++ ){
    alcohol += V.at(i) * P.at(i);
    if (alcohol > X * 100) {
      answer = i + 1;
      break;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
