#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::pair<int64_t, int64_t>> input(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    input.at(i) = std::make_pair(a, b);
  }

  std::sort(input.begin(), input.end());

  int64_t i = 0;
  int64_t answer = 0;
  while (M > 0) {
    int64_t A = input.at(i).first;
    int64_t B = input.at(i).second;

    if (M < B) {
      answer += A * M;
      break;
    } else {
      answer += A * B;
      M -= B;
    }

    i++;
  }

  std::cout << answer << std::endl;

  return 0;
}
