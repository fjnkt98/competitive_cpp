/*
 * Implementation of Bellman-Ford Method
 */

#include <iostream>
#include <utility>
#include <vector>
#include <cstdint>

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

  // Weighted directional graph
  std::vector<std::vector<std::pair<int64_t, int64_t>>> graph(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t from, to, weight;
    std::cin >> from >> to >> weight;
    graph.at(i).push_back(std::make_pair(to, weight));
  }

  bool exist_negative_cycle = false; // if the graph has negative cycle or not
  std::vector<int64_t> distance(N, INT64_MAX);

  // Initial condition
  distance.at(s) = 0;
  for (int64_t i= 0; i < N; i++) {
    bool update = false; // Flag variable that if the update was occured or not
    for (int64_t j = 0; j < N; j++) {
      // If the distance of j-th node is infinity, don't relax from j-th node
      if (distance.at(j) == INT64_MAX) {
        continue;
      }

      for (auto e : graph.at(j)) {
        // Do relax process, and renew the flag variable if distance update was occured
        if (choose_min(distance.at(e.first), distance.at(j) + e.second)) {
          update = true;
        }
      }
    }

    // if the update doesn't conduct, the shortest walk has already got
    if (!update) {
      break;
    }

    // The graph has negative cycle if update was occured in N times iteration
    if (i == N - 1 && update) {
      exist_negative_cycle = true;
    }
  }

  // Output calculation result
  if (exist_negative_cycle) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int64_t i = 0; i < N; i++) {
      if (distance.at(i) < INT64_MAX) {
        std::cout << distance.at(i) << std::endl;
      } else {
        std::cout << "INT" << std::endl;
      }
    }
  }
}
