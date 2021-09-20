#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t v, k;
    std::cin >> v >> k;
    for (int64_t j = 0; j < k; j++) {
      int64_t p;
      std::cin >> p;
      graph.at(i).push_back(p);
    }
  }

  std::vector<std::vector<int64_t>> adjacency_matrix(N, std::vector<int64_t>(N));
  for (int64_t i = 0; i < N; i++) {
    for (auto p : graph.at(i)) {
      adjacency_matrix.at(i).at(p - 1) = 1;
    }
  }

  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      if (j) std::cout << " ";
      std::cout << adjacency_matrix.at(i).at(j);
    }
    std::cout << std::endl;
  }

  return 0;
}
