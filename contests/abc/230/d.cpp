#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_cross(int64_t L1, int64_t R1, int64_t L2, int64_t R2) {
  if (std::max(L1, L2) < std::min(R1, R2)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int64_t N, D;
  std::cin >> N >> D;
  std::vector<std::pair<int64_t, int64_t>> segment(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t L, R;
    std::cin >> L >> R;

    segment.at(i) = std::make_pair(R, L);
  }

  std::sort(segment.begin(), segment.end());

  int64_t punch_count = 0;
  int64_t x = -(1LL << 60);

  for (int64_t i = 0; i < N; i++) {
    int64_t L = segment.at(i).second;
    int64_t R = segment.at(i).first;

    if (x + D - 1 < L) {
      punch_count++;
      x = R;
    }
  }

  std::cout << punch_count << std::endl;

  return 0;
}
