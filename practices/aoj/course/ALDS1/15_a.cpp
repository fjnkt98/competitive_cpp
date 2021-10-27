#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <array>

int main() {
  int64_t N;
  std::cin >> N;

  std::array<int64_t, 4> coins = {25, 10, 5, 1};

  int64_t count = 0;
  for (int64_t i = 0; i < 4; i++) {
    while (N - coins.at(i) >= 0){
      N -= coins.at(i);
      count++;
    }
  }

  std::cout << count + N << std::endl;
}
