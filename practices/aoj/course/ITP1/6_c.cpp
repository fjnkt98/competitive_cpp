#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::vector<int64_t>> input_data(N, std::vector<int64_t>(4));
  for (int64_t i = 0; i < N; i++) {
    std::cin >> input_data.at(i).at(0) >> input_data.at(i).at(1) >>
      input_data.at(i).at(2) >> input_data.at(i).at(3);
  }

  // Building, Floor, and Room
  std::vector<std::vector<std::vector<int64_t>>> house(4, std::vector<std::vector<int64_t>>(3, std::vector<int64_t>(10)));

  for (int64_t i = 0; i < N; i++) {
    house.at(input_data.at(i).at(0) - 1).at(input_data.at(i).at(1) - 1).at(input_data.at(i).at(2) - 1) += input_data.at(i).at(3);
  }

  for (int64_t b = 0; b < 4; b++) {
    for (int64_t f = 0; f < 3; f++) {
      for (int64_t r = 0; r < 10; r++) {
        std::cout << " " << house.at(b).at(f).at(r);
      }
      std::cout << std::endl;
    }

    if (b != 3) {
      std::cout << "####################" << std::endl;
    }
  }

  return 0;
}
