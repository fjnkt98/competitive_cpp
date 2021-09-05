#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  int64_t Q;
  std::cin >> Q;

  std::queue<int64_t> queue;
  std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> heap;

  for (int64_t i = 0; i < Q; i++) {
    int64_t c;
    std::cin >> c;

    switch (c) {
      case 1:
        int64_t x;
        std::cin >> x;

        queue.push(x);
        break;

      case 2:
        if (!heap.empty()) {
          std::cout << heap.top() << std::endl;
          heap.pop();
        } else {
          std::cout << queue.front() << std::endl;
          queue.pop();
        }
        break;

      case 3:
        while (!queue.empty()) {
          heap.push(queue.front());
          queue.pop();
        }
        break;
    }
  }

  return 0;
}
