#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::deque<int64_t> B;
  bool inversed = false;

  for (int64_t i = 0; i < N; i++) {
    if (inversed) {
      B.push_front(A.at(i));
    } else {
      B.push_back(A.at(i));
    }

    inversed = !inversed;
  }

  if (inversed) {
    std::reverse(B.begin(), B.end());
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << B.at(i);
  }
  std::cout << std::endl;

  return 0;
}
