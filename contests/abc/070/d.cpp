#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<std::pair<int64_t, int64_t>>>& graph,
         std::vector<int64_t>& distance,
         int64_t previous_node,
         int64_t current_node)
{
  for (auto n : graph.at(current_node)) {
    int64_t next_node = n.first;
    int64_t weight = n.second;

    if (next_node != previous_node && distance.at(next_node) == -1) {
      distance.at(next_node) = distance.at(current_node) + weight;
      dfs(graph, distance, current_node, next_node);
    }
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b, c;
    std::cin >> a >> b >> c;
    graph.at(a - 1).push_back(std::make_pair(b - 1, c));
    graph.at(b - 1).push_back(std::make_pair(a - 1, c));
  }

  int64_t Q, K;
  std::cin >> Q >> K;
  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t x, y;
    std::cin >> x >> y;
    query.at(i) = std::make_pair(x - 1, y - 1);
  }

  std::vector<int64_t> distance(N, -1);
  distance.at(K - 1) = 0;
  dfs(graph, distance, -1, K - 1);

  for (int64_t i = 0; i < Q; i++) {
    int64_t x = query.at(i).first;
    int64_t y = query.at(i).second;

    /* std::cout << distance.at(x) << " " << distance.at(y) << std::endl; */
    std::cout << distance.at(x) + distance.at(y) << std::endl;
  }

  return 0;
}
