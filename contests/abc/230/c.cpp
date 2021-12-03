#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;
  int64_t P, Q, R, S;
  std::cin >> P >> Q >> R >> S;

  A--;
  B--;
  P--;
  Q--;
  R--;
  S--;

  int64_t H = Q - P + 1;
  int64_t W = S - R + 1;

  std::vector<std::string> answer(H, std::string(W, '.'));
  for (int64_t i = 0; i < H; i++) {
    for (int64_t j = 0; j < W; j++) {
      if (std::abs((i + P) - A) == std::abs((j + R) - B)) {
        answer.at(i).at(j) = '#';
      }
    }
  }

  for (int64_t i = 0; i < H; i++) {
    std::cout << answer.at(i) << std::endl;
  }

  return 0;
}
