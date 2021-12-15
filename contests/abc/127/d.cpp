#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t N, M;
  std::cin >> N >> M;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<std::pair<int64_t, int64_t>> BC(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> BC.at(i).second >> BC.at(i).first;
  }

  std::sort(BC.begin(), BC.end(), std::greater<std::pair<int64_t, int64_t>>{});

  std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> heap;
  for (int64_t i = 0; i < N; i++) {
    heap.push(A.at(i));
  }

  for (int64_t i = 0; i < M; i++) {
    int64_t B = BC.at(i).second;
    int64_t C = BC.at(i).first;
    for (int64_t j = 0; j < B; j++) {
      if (heap.top() >= C) {
        break;
      }
      heap.pop();
      heap.push(C);
    }
  }

  int64_t answer = 0;
  while (!heap.empty()) {
    answer += heap.top();
    heap.pop();
  }

  std::cout << answer << std::endl;

  return 0;
}
