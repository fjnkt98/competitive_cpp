#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

void dfs(std::vector<std::vector<int64_t>>& graph, std::vector<int64_t>& parent,
         std::vector<int64_t>& X, std::vector<std::vector<int64_t>>& P,
         int64_t K, int64_t node) {
  for (int64_t next_node : graph.at(node)) {
    if (next_node == parent.at(node)) continue;

    dfs(graph, parent, X, P, K, next_node);
  }

  std::vector<int64_t> cache;
  cache.push_back(X.at(node));
  for (int64_t next_node : graph.at(node)) {
    std::copy(P.at(next_node).begin(), P.at(next_node).end(),
              std::back_inserter(cache));
  }
  std::sort(cache.begin(), cache.end(), std::greater<int64_t>());

  for (int64_t i = 0; i < std::min(K, static_cast<int64_t>(cache.size()));
       i++) {
    P.at(node).push_back(cache.at(i));
  }

  return;
}

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<int64_t> X(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i);
  }
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  std::vector<int64_t> v(Q);
  std::vector<int64_t> k(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> v.at(i) >> k.at(i);
    --v.at(i);
  }

  std::vector<int64_t> parent(N, -1);
  std::queue<int64_t> candidate;
  candidate.push(0);
  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (int64_t next_node : graph.at(node)) {
      if (next_node == 0) continue;
      if (parent.at(next_node) == -1) {
        parent.at(next_node) = node;
        candidate.push(next_node);
      }
    }
  }

  int64_t K = *std::max_element(k.begin(), k.end());
  std::vector<std::vector<int64_t>> P(N);
  dfs(graph, parent, X, P, K, 0);

  for (int64_t i = 0; i < Q; i++) {
    std::cout << P.at(v.at(i)).at(k.at(i) - 1) << std::endl;
  }

  return 0;
}
