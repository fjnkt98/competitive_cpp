#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> x(N);
  std::vector<int64_t> y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> x.at(i) >> y.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      for (int64_t k = j + 1; k < N; k++) {
        if ((y.at(k) - y.at(i)) * (x.at(j) - x.at(i)) == (y.at(j) - y.at(i)) * (x.at(k) - x.at(i))) {
          continue;
        } else {
          count++;
        }
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
