#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

int main() {
  std::vector<std::pair<std::string, int64_t>> query;
  while (true) {
    std::string command;
    std::cin >> command;

    if (command == "insert") {
      int64_t key;
      std::cin >> key;
      query.push_back(std::make_pair(command, key));
    } else if (command == "extract") {
      query.push_back(std::make_pair(command, 0));
    } else if (command == "end") {
      break;
    }
  }

  std::priority_queue<int64_t> heap;

  for (auto& q : query) {
    std::string command = q.first;
    int64_t key = q.second;

    if (command == "insert") {
      heap.push(key);
    } else if (command == "extract") {
      std::cout << heap.top() << std::endl;
      heap.pop();
    }
  }

  return 0;
}
