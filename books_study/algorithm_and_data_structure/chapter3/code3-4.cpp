#include <iostream>
#include <vector>
#include <climits>

int main() {
  int64_t N;
  int64_t K;

  std::cin >> N >> K;

  std::vector<int64_t> a(N);
  std::vector<int64_t> b(N);

  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }
  for (int64_t i = 0; i < N; i++) {
    std::cin >> b.at(i);
  }
  
  int64_t min_value = INT_MAX;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (a.at(i) + b.at(j) < K) {
        continue;
      }

      if (a.at(i) + b.at(j) < min_value) {
        min_value = a.at(i) + b.at(j);
      }
    }
  }

  std::cout << min_value << std::endl;
  return 0;
}
