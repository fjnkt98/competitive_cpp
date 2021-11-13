#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, M, R;
  std::cin >> N >> M >> R;
  std::vector<int64_t> r(R);
  for (int64_t i = 0; i < R; i++) {
    std::cin >> r.at(i);
    r.at(i)--;
  }

  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  std::vector<std::vector<int64_t>> dp(N, std::vector<int64_t>(N, 1LL << 60));
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b, c;
    std::cin >> a >> b >> c;

    graph.at(a - 1).push_back(std::make_pair(b - 1, c));
    graph.at(b - 1).push_back(std::make_pair(a - 1, c));

    dp.at(a - 1).at(b - 1) = c;
    dp.at(b - 1).at(a - 1) = c;
  }


  for (int64_t k = 0; k < N; k++) {
    for (int64_t i = 0; i < N; i++) {
      for (int64_t j = 0; j < N; j++) {
        dp.at(i).at(j) = std::min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }

  int64_t answer = 1LL << 60;
  std::sort(r.begin(), r.end());
  do {
    int64_t distance = 0;
    for (int64_t i = 1; i < R; i++) {
      distance += dp.at(r.at(i - 1)).at(r.at(i));
    }

    answer = std::min(answer, distance);
  } while (std::next_permutation(r.begin(), r.end()));

  std::cout << answer << std::endl;

  return 0;
}
