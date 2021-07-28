#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> array(N);
  for(int64_t i = 0; i < N; i++) {
    std::cin >> array.at(i);
  }

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t minimum_value_index = i;

    for (int64_t j = i; j < N; j++) {
      if (array.at(j) < array.at(minimum_value_index)) {
        minimum_value_index = j;
      }
    }
    if (i != minimum_value_index) {
      std::swap(array.at(i), array.at(minimum_value_index));
      count++;
    }
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << array.at(i);
  }
  std::cout << std::endl << count << std::endl;

  return 0;
}
