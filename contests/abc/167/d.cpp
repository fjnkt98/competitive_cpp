#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  std::vector<int64_t> graph(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
    graph.at(i) = A.at(i) - 1;
  }

  int64_t distance_to_loop_begin = 0;
  int64_t loop_distance = 0;
  std::vector<int64_t> teleport_count(N, -1);

  int64_t distance = 0;
  int64_t current_node = 0;
  teleport_count.at(0) = 0;
  for (int64_t i = 0; i < N; i++) {
    current_node = graph.at(current_node);
    distance++;

    if (teleport_count.at(current_node) == -1) {
      teleport_count.at(current_node) = distance;
    } else {
      distance_to_loop_begin = teleport_count.at(current_node);
      loop_distance = distance - distance_to_loop_begin;
      break;
    }
  }

  if (distance_to_loop_begin <= K) {
    /* std::cout << distance_to_loop_begin << std::endl; */
    /* std::cout << loop_distance << std::endl; */
    /* std::cout << current_node + 1 << std::endl; */

    int64_t residue = (K - distance_to_loop_begin) % loop_distance;
    for (int64_t i = 0; i < residue; i++) {
      current_node = graph.at(current_node);
    }

    std::cout << current_node + 1 << std::endl;
  } else {
    current_node = 0;
    for (int64_t i = 0; i < K; i++) {
      current_node = graph.at(current_node);
    }

    std::cout << current_node + 1 << std::endl;
  }


  return 0;
}
