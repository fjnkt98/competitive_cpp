#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> d(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> d.at(i);
  }

  std::sort(d.begin(), d.end());

  std::cout << d.at(N / 2) - d.at(N / 2 - 1) << std::endl;

  return 0;
}
