#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <queue>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  std::vector<int64_t> P(N - 1);
  std::iota(P.begin(), P.end(), 1);

  int64_t answer = 0;
  do {
    bool ok = true;
    std::vector<int64_t> route(N, 0);
    std::copy(P.begin(), P.end(), route.begin() + 1);

    for (int64_t i = 0; i < N - 1; i++) {
      auto iter = std::find(graph.at(route.at(i)).begin(), graph.at(route.at(i)).end(), route.at(i + 1));
      if (iter == graph.at(route.at(i)).end()) {
        ok = false;
      }
    }

    if (ok) answer++;

  } while (std::next_permutation(P.begin(), P.end()));

  std::cout << answer << std::endl;

  return 0;
}
