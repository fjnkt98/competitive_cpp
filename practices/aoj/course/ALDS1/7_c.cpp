#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void preorder_dfs(std::vector<std::vector<int64_t>>& graph,
         std::vector<int64_t>& order,
         int64_t current_node)
{
  if (current_node == -1) {
    return;
  }

  order.push_back(current_node);

  int64_t left_node = graph.at(current_node).at(0);
  preorder_dfs(graph, order, left_node);

  int64_t right_node = graph.at(current_node).at(1);
  preorder_dfs(graph, order, right_node);
}

void inorder_dfs(std::vector<std::vector<int64_t>>& graph,
         std::vector<int64_t>& order,
         int64_t current_node)
{
  if (current_node == -1) {
    return;
  }

  int64_t left_node = graph.at(current_node).at(0);
  inorder_dfs(graph, order, left_node);

  order.push_back(current_node);

  int64_t right_node = graph.at(current_node).at(1);
  inorder_dfs(graph, order, right_node);
}

void postorder_dfs(std::vector<std::vector<int64_t>>& graph,
         std::vector<int64_t>& order,
         int64_t current_node)
{
  if (current_node == -1) {
    return;
  }
  int64_t left_node = graph.at(current_node).at(0);
  postorder_dfs(graph, order, left_node);

  int64_t right_node = graph.at(current_node).at(1);
  postorder_dfs(graph, order, right_node);

  order.push_back(current_node);
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::vector<int64_t>> graph(N);
  std::vector<int64_t> parent(N, -1);
  for (int64_t i = 0; i < N; i++) {
    int64_t id, left, right;
    std::cin >> id >> left >> right;

    graph.at(id).push_back(left);
    graph.at(id).push_back(right);

    if (left != -1) parent.at(left) = id;
    if (right != -1) parent.at(right) = id;
  }

  int64_t root = std::distance(parent.begin(), std::find(parent.begin(), parent.end(), -1));

  std::vector<int64_t> preorder;
  preorder_dfs(graph, preorder, root);
  std::cout << "Preorder" << std::endl;
  for (int64_t i = 0; i < N; i++) {
    std::cout << " " << preorder.at(i);
  }
  std::cout << std::endl;

  std::vector<int64_t> inorder;
  inorder_dfs(graph, inorder, root);
  std::cout << "Inorder" << std::endl;
  for (int64_t i = 0; i < N; i++) {
    std::cout << " " << inorder.at(i);
  }
  std::cout << std::endl;

  std::vector<int64_t> postorder;
  postorder_dfs(graph, postorder, root);
  std::cout << "Postorder" << std::endl;
  for (int64_t i = 0; i < N; i++) {
    std::cout << " " << postorder.at(i);
  }
  std::cout << std::endl;
}
