#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
    A.at(i)--;
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(A.at(i)) == i) {
      answer++;
    }
  }

  std::cout << answer / 2 << std::endl;

  return 0;
}