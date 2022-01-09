#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> P(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> P.at(i);
  }

  std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>>
      heap;

  for (int64_t i = 0; i < K; i++) {
    heap.push(P.at(i));
  }

  std::cout << heap.top() << std::endl;

  for (int64_t i = K; i < N; i++) {
    if (heap.top() < P.at(i)) {
      heap.pop();
      heap.push(P.at(i));
    }
    std::cout << heap.top() << std::endl;
  }

  return 0;
}
