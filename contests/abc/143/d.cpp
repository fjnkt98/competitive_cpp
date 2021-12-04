#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> L(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> L.at(i);
  }

  std::sort(L.begin(), L.end());

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      for (int64_t k = j + 1; k < N; k++) {
        if (L.at(i) + L.at(j) > L.at(k)) answer++;
      }
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
