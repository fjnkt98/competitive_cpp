#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t degree = 0;
  std::vector<int64_t> split = {0, 360};
  for (int64_t i = 0; i < N; i++) {
    degree += A.at(i);

    split.push_back(degree % 360);
  }

  std::sort(split.begin(), split.end());

  int64_t answer = 0;
  for (int64_t i = 1; i < split.size(); i++) {
    answer = std::max(answer, split.at(i) - split.at(i - 1));
  }

  std::cout << answer << std::endl;

  return 0;
}
