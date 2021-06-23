/*
 * Graph Tutorial
 *
 * Reading weighted directional graph
 */

#include <iostream>
#include <utility>
#include <vector>

int main() {
  int64_t N;
  int64_t M;
  std::cin >> N >> M;

  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    int64_t b;
    int64_t weight;
    std::cin >> a >> b >> weight;
    graph.at(a).push_back(std::make_pair(b, weight));
  }
}
