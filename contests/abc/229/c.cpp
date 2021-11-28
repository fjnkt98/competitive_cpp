#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, W;
  std::cin >> N >> W;
  std::vector<std::pair<int64_t, int64_t>> input(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    input.at(i) = std::make_pair(a, b);
  }

  std::sort(input.begin(), input.end(), std::greater<std::pair<int64_t, int64_t>>{});

  int64_t i = 0;
  int64_t answer = 0;
  while (W > 0 && i < N) {
    int64_t A = input.at(i).first;
    int64_t B = input.at(i).second;

    if (W >= B) {
      W -= B;
      answer += A * B;
    } else {
      answer += A * W;
      W = 0;
      break;
    }

    i++;
  }

  std::cout << answer << std::endl;

  return 0;
}
