#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<int64_t, int64_t>> input(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t x, y;
    std::cin >> x >> y;

    input.at(i) = std::make_pair(x, y);
  }

  std::sort(input.begin(), input.end());

  for (int64_t i = 0; i < N; i++) {
    std::cout << input.at(i).first << " " << input.at(i).second << std::endl;
  }

  return 0;
}
