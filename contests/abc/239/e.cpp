#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

  std::vector<std::pair<int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t v, k;
    std::cin >> v >> k;
    query.at(i) = {v - 1, k};
  }

  return 0;
}
