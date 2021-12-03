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

  std::priority_queue<int64_t> heap;
  for (int64_t i = 0; i < N; i++) {
    heap.push(A.at(i));
  }

  for (int64_t i = 0; i < M; i++) {
    int64_t target = heap.top();
    heap.pop();
    heap.push(target / 2);
  }

  int64_t answer = 0;
  while (!heap.empty()) {
    answer += heap.top();
    heap.pop();
  }

  std::cout << answer << std::endl;

  return 0;
}
