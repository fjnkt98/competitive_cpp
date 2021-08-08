#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <utility>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::pair<std::string, int64_t>> query(N);
  for (int64_t i = 0; i < N; i++) {
    std::string command;
    int64_t value;
    std::cin >> command;
    if (command == "insert" || command == "delete") {
      std::cin >> value;
      query.at(i) = std::make_pair(command, value);
    } else {
      query.at(i) = std::make_pair(command, 0);
    }
  }

  std::list<int64_t> l;
  for (int64_t i = 0; i < N; i++) {
    if (query.at(i).first == "insert") {
      l.push_front(query.at(i).second);
    }
    if (query.at(i).first == "delete") {
      auto iter = std::find(l.begin(), l.end(), query.at(i).second);
      if (iter != l.end()) {
        l.erase(iter);
      }
    }
    if (query.at(i).first == "deleteFirst") {
      l.pop_front();
    }
    if (query.at(i).first == "deleteLast") {
      l.pop_back();
    }
  }

  for (auto i = l.begin(); i != l.end(); i++) {
    if (i != l.begin()) {
      std::cout << " ";
    }
    std::cout << *i;
  }
  std::cout << std::endl;

  return 0;
}
