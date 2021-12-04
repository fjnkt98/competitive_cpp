#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> operation;
  int64_t counter = 0;
  bool operatable = true;
  while (!A.empty()) {
    std::vector<bool> eliminatable(A.size(), false);

    for (size_t i = 0; i < A.size(); i++) {
      if (A.at(i) == i + 1) {
        eliminatable.at(i) = true;
      }
    }

    for (int64_t i = static_cast<int64_t>(A.size()) - 1; i >= 0; i--) {
      if (eliminatable.at(i)) {
        operation.push_back(A.at(i));
        A.erase(A.begin() + i);
        break;
      }
    }

    counter++;

    if (counter > 100) {
      operatable = false;
      break;
    }
  }

  if (operatable) {
    std::reverse(operation.begin(), operation.end());

    for (auto o : operation) {
      std::cout << o << std::endl;
    }
  } else {
    std::cout << -1 << std::endl;
  }

  return 0;
}
