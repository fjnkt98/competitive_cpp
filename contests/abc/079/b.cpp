#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> lucas(N + 1);
  lucas.at(0) = 2;
  lucas.at(1) = 1;
  for (int64_t i = 2; i <= N; i++) {
    lucas.at(i) = lucas.at(i - 1) + lucas.at(i - 2);
  }

  std::cout << lucas.at(N) << std::endl;

  return 0;
}
