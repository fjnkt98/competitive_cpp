#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::vector<int64_t>> graph(N);
  for (int64_t i = 0; i < N - 1; i++) {
    int64_t a, b;
    std::cin >> a >> b;

    graph.at(a - 1).push_back(b - 1);
    graph.at(b - 1).push_back(a - 1);
  }

  std::queue<int64_t> candidate;
  candidate.push(0);
  std::vector<int64_t> fennec_distance(N, -1);
  fennec_distance.at(0) = 0;
  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (int64_t next_node : graph.at(node)) {
      if (fennec_distance.at(next_node) == -1) {
        fennec_distance.at(next_node) = fennec_distance.at(node) + 1;
        candidate.push(next_node);
      }
    }
  }

  candidate.push(N - 1);
  std::vector<int64_t> snuke_distance(N, -1);
  snuke_distance.at(N - 1) = 0;
  while (!candidate.empty()) {
    int64_t node = candidate.front();
    candidate.pop();

    for (int64_t next_node : graph.at(node)) {
      if (snuke_distance.at(next_node) == -1) {
        snuke_distance.at(next_node) = snuke_distance.at(node) + 1;
        candidate.push(next_node);
      }
    }
  }

  std::vector<int8_t> color(N, -1);
  for (int64_t i = 0; i < N; i++) {
    if (fennec_distance.at(i) <= snuke_distance.at(i)) {
      color.at(i) = 0;
    } else {
      color.at(i) = 1;
    }
  }

  int64_t black = std::count(color.begin(), color.end(), 0);
  int64_t white = std::count(color.begin(), color.end(), 1);

  if (black > white) {
    std::cout << "Fennec" << std::endl;
  } else {
    std::cout << "Snuke" << std::endl;
  }

  return 0;
}
