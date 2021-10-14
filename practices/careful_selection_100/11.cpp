#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> S(M);
  for (int64_t i = 0; i < M; i++) {
    int64_t k;
    std::cin >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t s;
      std::cin >> s;
      S.at(i).push_back(s - 1);
    }
  }
  std::vector<int64_t> P(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> P.at(i);
  }

  int64_t count = 0;
  for (int64_t bit; bit < (1 << N); bit++) {
    bool ok = true;
    for (int64_t i = 0; i < M; i++) {
      int64_t activated_switch = 0;
      for (auto p : S.at(i)) {
        if (bit & (1 << p)) activated_switch++;
      }
      if (activated_switch % 2 != P.at(i)) {
        ok = false;
      }
    }
    if (ok) count++;
  }

  std::cout << count << std::endl;
}
