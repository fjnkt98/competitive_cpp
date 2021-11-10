#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, T;
  std::cin >> N >> T;
  std::vector<int64_t> t(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> t.at(i);
  }

  int64_t X = 0;
  int64_t Y = 0;
  for (int64_t i = 0; i < N - 1; i++) {
    if (t.at(i + 1) - t.at(i) > T) {
      X += Y + T;
      Y = 0;
    } else {
      Y += t.at(i + 1) - t.at(i);
    }
  }
  X += Y + T;

  std::cout << X << std::endl;

  return 0;
}
