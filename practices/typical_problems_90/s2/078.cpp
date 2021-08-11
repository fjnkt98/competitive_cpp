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

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    std::sort(graph.at(i).begin(), graph.at(i).end());
    auto iter = std::lower_bound(graph.at(i).begin(), graph.at(i).end(), i);
    if (std::distance(graph.at(i).begin(), iter) == 1) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
