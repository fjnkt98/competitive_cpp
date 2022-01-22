#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t V, E;
  std::cin >> V >> E;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(V);
  std::vector<std::vector<int64_t>> dp(V, std::vector<int64_t>(V, 1LL << 60));
  for (int64_t i = 0; i < E; i++) {
    int64_t s, t, d;
    std::cin >> s >> t >> d;

    graph.at(s).push_back(std::make_pair(t, d));
    dp.at(s).at(t) = d;
  }

  for (int64_t i = 0; i < V; i++) {
    dp.at(i).at(i) = 0;
  }

  for (int64_t k = 0; k < V; k++) {
    for (int64_t i = 0; i < V; i++) {
      for (int64_t j = 0; j < V; j++) {
        dp.at(i).at(j) =
            std::min(dp.at(i).at(j), dp.at(i).at(k) + dp.at(k).at(j));
      }
    }
  }

  for (int64_t i = 0; i < V; i++) {
    if (dp.at(i).at(i) < 0) {
      std::cout << "NEGATIVE CYCLE" << std::endl;
      return 0;
    }
  }

  for (int64_t i = 0; i < V; i++) {
    for (int64_t j = 0; j < V; j++) {
      if (j) std::cout << " ";
      if (dp.at(i).at(j) >= 1LL << 59) {
        std::cout << "INF";
      } else {
        std::cout << dp.at(i).at(j);
      }
    }
    std::cout << std::endl;
  }

  return 0;
}