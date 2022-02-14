#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t X, Y, A, B, C;
  std::cin >> X >> Y >> A >> B >> C;

  std::vector<int64_t> P(A);
  for (int64_t i = 0; i < A; i++) {
    std::cin >> P.at(i);
  }
  std::vector<int64_t> Q(B);
  for (int64_t i = 0; i < B; i++) {
    std::cin >> Q.at(i);
  }
  std::vector<int64_t> R(C);
  for (int64_t i = 0; i < C; i++) {
    std::cin >> R.at(i);
  }

  std::sort(P.begin(), P.end(), std::greater<int64_t>());
  std::sort(Q.begin(), Q.end(), std::greater<int64_t>());
  std::sort(R.begin(), R.end(), std::greater<int64_t>());

  std::vector<int64_t> candidate;
  for (int64_t i = 0; i < X; i++) {
    candidate.push_back(P.at(i));
  }
  for (int64_t i = 0; i < Y; i++) {
    candidate.push_back(Q.at(i));
  }
  std::sort(candidate.begin(), candidate.end(), std::greater<int64_t>());
  std::vector<int64_t> cumsum_redgreen(X + Y + 1);
  for (int64_t i = 0; i < X + Y; i++) {
    cumsum_redgreen.at(i + 1) = cumsum_redgreen.at(i) + candidate.at(i);
  }

  std::vector<int64_t> cumsum_colorless(C + 1);
  for (int64_t i = 0; i < C; i++) {
    cumsum_colorless.at(i + 1) = cumsum_colorless.at(i) + R.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < std::min(C, X + Y) + 1; i++) {
    answer = std::max(answer,
                      cumsum_colorless.at(i) + cumsum_redgreen.at(X + Y - i));
  }

  std::cout << answer << std::endl;

  return 0;
}