#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::queue<std::pair<std::string, int64_t>> process_queue;
  for (int64_t i = 0; i < N; i++) {
    std::string name;
    int64_t time;
    std::cin >> name >> time;
    process_queue.push(std::make_pair(name, time));
  }

  std::vector<std::pair<std::string, int64_t>> result;
  int64_t elapsed_time = 0;
  while (!process_queue.empty()) {
    std::pair<std::string, int64_t> work = process_queue.front();
    process_queue.pop();

    if (work.second > Q) {
      process_queue.push(std::make_pair(work.first, work.second - Q));
      elapsed_time += Q;
    } else {
      elapsed_time += work.second;
      result.push_back(std::make_pair(work.first, elapsed_time));
    }
  }

  for (auto r : result) {
    std::cout << r.first << " " << r.second << std::endl;
  }

  return 0;
}