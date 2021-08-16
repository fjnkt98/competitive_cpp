#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, L, K;
  std::cin >> N >> L >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t left = -1;
  int64_t right = L + 1;
  while (right - left > 1) {
    int64_t mid = (left + right) / 2;
    bool ok = false;

    int64_t count = 0;
    int64_t last_split = 0;
    for (int64_t i = 0; i < N; i++) {
      if (A.at(i) - last_split >= mid && L - A.at(i) >= mid) {
        count++;
        last_split = A.at(i);
      }
    }
    if (count >= K) ok = true;

    if (ok) left = mid;
    else right = mid;
  }

  std::cout << left << std::endl;

  return 0;
}
