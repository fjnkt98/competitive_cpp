#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int64_t>>& graph,
         std::vector<std::pair<int64_t, int64_t>>& segment, int64_t& token,
         int64_t current_node, int64_t previous_node) {
  if (current_node != 0 && graph.at(current_node).size() == 1) {
    segment.at(current_node) = {token, token};
    ++token;

    return;
  }

  for (int64_t next_node : graph.at(current_node)) {
    if (next_node == previous_node) continue;
    dfs(graph, segment, token, next_node, current_node);
  }

  int64_t l = 1LL << 60;
  int64_t r = 0;
  for (int64_t next_node : graph.at(current_node)) {
    if (next_node == previous_node) continue;

    l = std::min(l, segment.at(next_node).first);
    r = std::max(r, segment.at(next_node).second);
  }
  segment.at(current_node) = {l, r};

  return;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t u, v;
    std::cin >> u >> v;
    graph.at(u - 1).push_back(v - 1);
    graph.at(v - 1).push_back(u - 1);
  }

  std::vector<std::pair<int64_t, int64_t>> segment(N);
  int64_t token = 1;

  dfs(graph, segment, token, 0, -1);

  for (auto s : segment) {
    auto [l, r] = s;

    std::cout << l << " " << r << std::endl;
  }

  return 0;
}
