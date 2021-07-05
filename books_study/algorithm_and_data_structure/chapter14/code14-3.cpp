/*
 * Implementation of Djikstra Method 1
 */

#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>

template<class T> bool choose_min(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  int64_t N, M, s;
  std::cin >> N >> M >> s;

  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t from, to, weight;
    std::cin >> from >> to >> weight;

    graph.at(from).push_back(std::make_pair(to, weight));
  }

  // Dijkstra Method
  std::vector<bool> used(N, false);
  std::vector<int64_t> distance(N, INT64_MAX);

  // Initial condition
  distance.at(s) = 0;

  for (int64_t i = 0; i < N; i++) {
    int64_t minimum_distance = INT64_MAX;
    int64_t minimum_node = -1;

    // Search the node with the shortest distance from the s amoung the "unused" nodes
    for (int64_t j = 0; j < N; j++) {
      if (!used.at(j) && distance.at(j) < minimum_distance) {
        minimum_distance = distance.at(j);
        minimum_node = j;
      }
    }

    // if there is no such node, terminate loop
    if (minimum_node == -1) {
      break;
    }

    // Relax each edge starting from minimum_node
    for (auto e : graph.at(minimum_node)) {
      choose_min(distance.at(e.first), distance.at(minimum_node) + e.second);
    }
    used.at(minimum_node) = true;
  }

  // Output calculation result
  for (int64_t i = 0; i < N; i++) {
    if (distance.at(i) < INT64_MAX) {
      std::cout << distance.at(i) << std::endl;
    } else {
      std::cout << "INT" << std::endl;
    }
  }
}
