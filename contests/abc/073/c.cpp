#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::set<int64_t> numbers;
  for (int64_t i = 0; i < N; i++) {
    if (numbers.find(A.at(i)) == numbers.end()) {
      numbers.insert(A.at(i));
    } else {
      numbers.erase(A.at(i));
    }
  }

  std::cout << numbers.size() << std::endl;

  return 0;
}
