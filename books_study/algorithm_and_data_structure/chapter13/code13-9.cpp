/*
 * Calculate depth and size of subtreeof each node when converting the non-rooted tree to the rooted tree
 */

#include <iostream>
#include <vector>

std::vector<int64_t> depth;
std::vector<int64_t> subtree_size;

void dfs(const std::vector<std::vector<int64_t>>& graph,
         int64_t node,
         int64_t parent_node = -1,
         int64_t current_depth = 0)
{
  depth.at(node) = current_depth;  
  for (auto child_node : graph.at(node)) {
    if (child_node == parent_node) {
      continue;
    }
    dfs(graph, child_node, node, current_depth);
  }

  subtree_size.at(node) = 1;
  for (auto child_node : graph.at(node)) {
    if (child_node == parent_node) {
      continue;
    }

    subtree_size.at(node) += subtree_size.at(child_node);
  }
}

int main() {
  int64_t N;
  int64_t M;
  std::cin >> N >> M;

  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a;
    int64_t b;
    std::cin >> a >> b;

    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  // Assume that 0th node is the root
  int64_t root = 0;
  depth.assign(N, 0);
  subtree_size.assign(N, 0);
  dfs(graph, root);

  for (int64_t i = 0; i < N; i++) {
    std::cout << i << ": depth = " << depth.at(i) << ", size of subtree = " << subtree_size.at(i) << std::endl;
  }
}
