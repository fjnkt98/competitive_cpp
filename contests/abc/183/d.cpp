#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N ,W;
  std::cin >> N >> W;
  std::vector<int64_t> S(N);
  std::vector<int64_t> T(N);
  std::vector<int64_t> P(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i) >> T.at(i) >> P.at(i);
  }

  int64_t maximum_time = *std::max_element(T.begin(), T.end());

  std::vector<int64_t> usage(maximum_time + 1, 0);
  for (int64_t i = 0; i < N; i++) {
    usage.at(S.at(i)) += P.at(i);
    usage.at(T.at(i)) -= P.at(i);
  }

  for (int64_t i = 1; i <= maximum_time; i++) {
    usage.at(i) += usage.at(i - 1);
  }

  bool ok = true;
  for (int64_t i = 0; i <= maximum_time; i++) {
    if (usage.at(i) > W) ok = false;
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
