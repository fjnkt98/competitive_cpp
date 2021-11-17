#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void solve(int64_t L, int64_t R, int64_t& answer, std::vector<int64_t>& h) {
  if (L >= R) return;

  int64_t minimum_height = 1LL << 60;
  for (int64_t i = L; i < R; i++) {
    minimum_height = std::min(minimum_height, h.at(i));
  }

  answer += minimum_height;
  for (int64_t i = L; i < R; i++) {
    h.at(i) -= minimum_height;
  }

  std::vector<int64_t> zero_heights;
  zero_heights.push_back(-1);
  for (int64_t i = L; i < R; i++) {
    if (h.at(i) == 0) {
      zero_heights.push_back(i);
    }
  }
  zero_heights.push_back(R);

  for (int64_t i = 0; i < (static_cast<int64_t>(zero_heights.size()) - 1); i++) {
    solve(zero_heights.at(i) + 1, zero_heights.at(i + 1), answer, h);
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> h(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> h.at(i);
  }

  int64_t answer = 0;
  solve(0, N, answer, h);

  std::cout << answer << std::endl;

  return 0;
}
