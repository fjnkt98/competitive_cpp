/*
 * Graph search algorithm
 *
 * Breadth-First Search(BFS) and Depth-First Search(DFS)
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <stack>

void search_graph(const std::vector<std::vector<int64_t>>& graph, int64_t start) {
  int64_t N = static_cast<int64_t>(graph.size());

  // Array which stores the explored node
  std::vector<bool> explored(N, false);
  // Breadth-First Search
  std::queue<int64_t> candidate;
  // Depth-First Search
  // std::stack<int64_t> candidate;

  // Initial condition
  explored.at(start) = true;
  candidate.push(start);

  while (!candidate.empty()) {
    int64_t v = candidate.front();
    candidate.pop();

    for (int64_t x : graph.at(v)) {
      if (explored.at(x)) {
        continue;
      }

      explored.at(x) = true;
      candidate.push(x);
    }
  }
}
