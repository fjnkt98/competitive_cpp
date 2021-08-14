#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void dfs(std::vector<std::vector<int64_t>>& graph,
         std::vector<int64_t>& depth,
         int64_t current_node,
         /* int64_t parent_node = -1, */
         int64_t current_depth = 0)
{
  depth.at(current_node) = current_depth;
  for (auto c : graph.at(current_node)) {
    /* if (c == parent_node) continue; */
    dfs(graph, depth, c, current_depth + 1);
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> graph(N);
  std::vector<int64_t> parent(N, -1);
  for (int64_t i = 0; i < N; i++) {
    int64_t id, k;
    std::cin >> id >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t c;
      std::cin >> c;
      parent.at(c) = id;
      graph.at(id).push_back(c);
    }
  }

  auto predicate = [](int64_t x) { return (x == -1); };
  auto iter = std::find_if(parent.begin(), parent.end(), predicate);
  int64_t root = std::distance(parent.begin(), iter);

  std::vector<int64_t> depth(N, 0);
  dfs(graph, depth, root);

  for (int64_t i = 0; i < N; i++) {
    std::cout << "node " << i << ": parent = " << parent.at(i) << ", depth = "
              << depth.at(i) << ", ";
    if (i == root) std::cout << "root, ";
    else if (graph.at(i).empty()) std::cout << "leaf, ";
    else std::cout << "internal node, ";

    std::cout << "[";
    for (size_t j = 0; j < graph.at(i).size(); j++) {
      if (j) std::cout << ", ";
      std::cout << graph.at(i).at(j);
    }
    std::cout << "]";
    std::cout << std::endl;
  }

  return 0;
}
