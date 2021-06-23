/*
 * Graph Tutorial
 *
 * Reading non-weighted directional graph
 */

#include <iostream>
#include <vector>

int main() {
  int64_t N;
  int64_t M;
  std::cin >> N >> M;

  // Graph
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a;
    int64_t b;
    std::cin >> a >> b;
    graph.at(a).push_back(b);
  }
}
