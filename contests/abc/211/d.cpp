#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  const int64_t mod = 1000000007;

  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    // Make into 0-index
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  // Distance from node 0 to each nodes
  std::vector<int64_t> distance(N, -1);
  // Number of routes to reach each nodes from node 0 in the shortest time
  std::vector<int64_t> count(N, 0);

  distance.at(0) = 0;
  count.at(0) = 1;
  std::queue<int64_t> candidate;
  candidate.push(0);

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (int64_t x : graph.at(node)) {
      // When the node x has not been explored
      if (distance.at(x) == -1) {
        distance.at(x) = distance.at(node) + 1;
        count.at(x) = count.at(node);
        count.at(x) = count.at(x) % mod;
        candidate.push(x);
      } else { // When the node x has been explored
        if (distance.at(x) == distance.at(node) + 1) {
          count.at(x) += count.at(node);
          count.at(x) = count.at(x) % mod;
        }
      }
    }
  }

  std::cout << count.at(N - 1) << std::endl;

  return 0;
}
