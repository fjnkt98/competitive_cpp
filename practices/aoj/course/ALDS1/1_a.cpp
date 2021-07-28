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

  for (int64_t i = 0; i < N; i++) {
    if (i) {
      std::cout << " ";
    }
    std::cout << array.at(i);
  }
  std::cout << std::endl;

  for (int64_t i = 1; i < N; i++) {
    int64_t v = array.at(i);
    int64_t j = i - 1;
    while (j >= 0 && array.at(j) > v) {
      array.at(j + 1) = array.at(j);
      j--;
    }
    array.at(j + 1) = v;

    for (int64_t i = 0; i < N; i++) {
      if (i) {
        std::cout << " ";
      }
      std::cout << array.at(i);
    }
    std::cout << std::endl;
  }

  return 0;
}
