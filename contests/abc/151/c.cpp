#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> p(M);
  std::vector<std::string> S(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> p.at(i) >> S.at(i);
    p.at(i)--;
  }

  std::vector<int64_t> penalty(N, 0);
  std::vector<bool> solved(N, false);

  for (int64_t i = 0; i < M; i++) {
    if (S.at(i) == "AC") {
      solved.at(p.at(i)) = true;
    } else {
      if (!solved.at(p.at(i))) {
        penalty.at(p.at(i))++;
      }
    }
  }

  int64_t correct = std::count(solved.begin(), solved.end(), true);
  int64_t wrong = 0;
  for (int64_t i = 0; i < N; i++) {
    if (solved.at(i)) {
      wrong += penalty.at(i);
    }
  }

  std::cout << correct << " " << wrong << std::endl;

  return 0;
}
