#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

  for (int64_t i = 0; i < N; i++) {
    std::cout << graph.at(i).size() << std::endl;
  }

  return 0;
}
