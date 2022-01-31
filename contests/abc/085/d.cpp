#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N, H;
  std::cin >> N >> H;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  int64_t max_damage = *std::max_element(A.begin(), A.end());
  int64_t answer = 0;

  std::vector<int64_t> threw_katana;
  for (int64_t i = 0; i < N; i++) {
    if (max_damage < B.at(i)) {
      threw_katana.push_back(B.at(i));
    }
  }
  std::sort(threw_katana.begin(), threw_katana.end(), std::greater<int64_t>());
  for (int64_t d : threw_katana) {
    answer++;
    H -= d;

    if (H <= 0) {
      std::cout << answer << std::endl;
      return 0;
    }
  }

  answer += (H + max_damage - 1) / max_damage;
  std::cout << answer << std::endl;

  return 0;
}