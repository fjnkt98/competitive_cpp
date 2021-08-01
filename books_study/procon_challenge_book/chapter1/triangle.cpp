#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> array(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> array.at(i);
  }

  int64_t max_perimeter = 0;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      for (int64_t k = j + 1; k < N; k++) {
        if (array.at(i) + array.at(j) < array.at(k) ||
            array.at(j) + array.at(k) < array.at(i) ||
            array.at(i) + array.at(k) < array.at(j)) {
          continue;
        } else {
          if (max_perimeter < array.at(i) + array.at(j) + array.at(k)) {
            max_perimeter = array.at(i) + array.at(j) + array.at(k);
          }
        }
      }
    }
  }

  std::cout << max_perimeter << std::endl;

  return 0;
}
