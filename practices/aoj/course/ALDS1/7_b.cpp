#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>

std::vector<int64_t> bfs(std::vector<std::pair<int64_t, int64_t>>& graph,
                         int64_t root)
{
  std::vector<int64_t> depth(graph.size(), -1);
  std::queue<int64_t> candidate;

  depth.at(root) = 0;
  candidate.push(root);

  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    if (graph.at(node).first != -1) {
      depth.at(graph.at(node).first) = depth.at(node) + 1;
      candidate.push(graph.at(node).first);
    }
    if (graph.at(node).second != -1) {
      depth.at(graph.at(node).second) = depth.at(node) + 1;
      candidate.push(graph.at(node).second);
    }
  }

  return depth;
}

int64_t dfs(std::vector<std::pair<int64_t, int64_t>>& graph,
                         std::vector<int64_t>& height,
                         int64_t node)
{
  int64_t left_height = 0;
  int64_t right_height = 0;

  if (graph.at(node).first != -1) left_height = dfs(graph, height, graph.at(node).first) + 1;
  if (graph.at(node).second != -1) right_height = dfs(graph, height, graph.at(node).second) + 1;

  return height.at(node) = std::max(left_height, right_height);
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::pair<int64_t, int64_t>> binary_tree(N);
  std::vector<int64_t> parent(N, -1);
  for (int64_t i = 0; i < N; i++) {
    int64_t id, left, right;
    std::cin >> id >> left >> right;
    binary_tree.at(id) = std::make_pair(left, right);
    if (left != -1) parent.at(left) = id;
    if (right != -1) parent.at(right) = id;
  }

  int64_t root = std::distance(parent.begin(), std::find(parent.begin(), parent.end(), -1));
  std::vector<int64_t> depth = bfs(binary_tree, root);

  std::vector<int64_t> height(N);
  dfs(binary_tree, height, root);

  for (int64_t i = 0; i < N; i++) {
    int64_t degree = 0;
    if (binary_tree.at(i).first != -1) degree++;
    if (binary_tree.at(i).second != -1) degree++;

    int64_t sibling = -1;
    if (i != root) {
      if (binary_tree.at(parent.at(i)).first == i)
        sibling = binary_tree.at(parent.at(i)).second;
      else
        sibling = binary_tree.at(parent.at(i)).first;
    }

    std::string type;
    if (i == root) type = "root";
    else if (binary_tree.at(i).first == -1 && binary_tree.at(i).second == -1) type = "leaf";
    else type = "internal node";

    std::cout << "node " << i << ": parent = " << parent.at(i) << ", sibling = " << sibling << ", degree = "
      << degree << ", depth = " << depth.at(i) << ", height = " << height.at(i) << ", " << type << std::endl;
  }

  return 0;
}
