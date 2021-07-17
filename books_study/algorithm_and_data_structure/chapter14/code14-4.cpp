/*
 * Implementation of Dijkstra Method 2
 */

#include <iostream>
#include <vector>
#include <cstdint>
#include <utility>
#include <queue>

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

  // Start Dijkstra method
  std::vector<int64_t> distance(N, INT64_MAX);
  
  // Initial condition
  distance.at(s) = 0;

  // Create heap with (distance.at(v) and v) pairs as elements
  std::priority_queue<std::pair<int64_t, int64_t>,
                      std::vector<std::pair<int64_t, int64_t>>,
                      std::greater<std::pair<int64_t, int64_t>>> heap;
  heap.push(std::make_pair(distance.at(s), s));

  // Start loop of Dijkstra method
  while (!heap.empty()) {
    // v: the node which has shortest distance.at(v) among the "unused" nodes
    // d: the key value against node v
    int64_t v = heap.top().second;
    int64_t d = heap.top().first;
    heap.pop();

    // d > distance.at(v) indicates that the pair (d, v) is garbage
    if (d > distance.at(v)) {
      continue;
    }

    // Relaxation each edges starting from node v
    for (auto e : graph.at(v)) {
      if (choose_min(distance.at(e.first), distance.at(v) + e.second)) {
        heap.push(std::make_pair(distance.at(e.first), e.first));
      }
    }
  }

  // Output calculation result
  for (int64_t i = 0; i < N; i++) {
    if (distance.at(i) < INT64_MAX) {
      std::cout << distance.at(i) << std::endl;
    } else {
      std::cout << "INF" << std::endl;
    }
  }
}
