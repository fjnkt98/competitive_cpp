#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

void dfs(std::vector<std::vector<int64_t>>& graph,
         std::vector<bool>& preorder,
         std::vector<bool>& postorder,
         std::vector<bool>& explored,
         std::stack<int64_t>& history,
         int64_t current_node,
         int64_t previous_node,
         int64_t& cycle_start_point)
{
  preorder.at(current_node) = true;
  explored.at(current_node) = true;
  history.push(current_node);

  for (int64_t next_node : graph.at(current_node)) {
    if (next_node == previous_node) continue;

    if (postorder.at(next_node)) continue;

    if (preorder.at(next_node) && !postorder.at(next_node)) {
      cycle_start_point = next_node;
      return;
    }

    dfs(graph, preorder, postorder, explored, history, next_node, current_node, cycle_start_point);

    if (cycle_start_point != -1) return;
  }

  history.pop();
  postorder.at(current_node) = true;
}

bool check(std::vector<std::vector<int64_t>>& graph,
           std::vector<bool>& explored,
           int64_t node)
{
  int64_t N = static_cast<int64_t>(graph.size());
  std::vector<bool> preorder(N, false);
  std::vector<bool> postorder(N, false);
  std::stack<int64_t> history;
  int64_t cycle_start_point = -1;

  dfs(graph, preorder, postorder, explored, history, node, -1, cycle_start_point);

  bool ok = true;

  if (!history.empty()) {
    ok = false;
  }

  return ok;
}

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }


  bool ok = true;
  std::vector<bool> explored(N, false);
  for (int64_t i = 0; i < N; i++) {
    if (graph.at(i).size() > 2) {
      ok = false;
    }

    if (explored.at(i)) continue;
    if (check(graph, explored, i) == false) {
      ok = false;
    }

  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
