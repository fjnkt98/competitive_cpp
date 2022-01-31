#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  std::list<int64_t> L;
  L.push_front(0);

  auto iter = L.begin();

  for (int64_t i = 0; i < N; i++) {
    if (S.at(i) == 'L') {
      iter = L.insert(iter, i + 1);
    }
    if (S.at(i) == 'R') {
      iter = L.insert(std::next(iter, 1), i + 1);
    }
  }

  for (auto iter = L.begin(); iter != L.end(); iter++) {
    if (iter != L.begin()) std::cout << " ";
    std::cout << *iter;
  }
  std::cout << std::endl;

  return 0;
}
