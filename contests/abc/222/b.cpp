#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, P;
  std::cin >> N >> P;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) < P) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
