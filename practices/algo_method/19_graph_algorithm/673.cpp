#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < M; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  for (int64_t i = 0; i < N; i++) {
    std::sort(graph.at(i).begin(), graph.at(i).end());
  }

  int64_t most_popular = 1LL << 60;
  int64_t friend_amount = 0;
  for (int64_t i = N - 1; i >= 0; i--) {
    if (friend_amount <= graph.at(i).size()) {
      friend_amount = graph.at(i).size();
      most_popular = i;
    }
  }

  for (size_t i = 0; i < graph.at(most_popular).size(); i++) {
    if (i) std::cout << " ";
    std::cout << graph.at(most_popular).at(i);
  }

  std::cout << std::endl;

  return 0;
}