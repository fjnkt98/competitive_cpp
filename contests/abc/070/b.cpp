#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C, D;
  std::cin >> A >> B >> C >> D;

  std::vector<int64_t> time(101, 0);

  for (int64_t i = A; i < B; i++) {
    time.at(i)++;
  }
  for (int64_t i = C; i < D; i++) {
    time.at(i)++;
  }

  int64_t answer = std::count(time.begin(), time.end(), 2);

  std::cout << answer << std::endl;


  return 0;
}
