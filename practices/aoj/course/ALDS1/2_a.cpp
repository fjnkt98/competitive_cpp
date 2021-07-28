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

  int64_t count = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int64_t i = N - 1; i > 0; i--) {
      if (array.at(i) < array.at(i - 1)) {
        std::swap(array.at(i), array.at(i - 1));
        flag = true;
        count++;
      }
    }
  }

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << array.at(i);
    if (i == N - 1) std::cout << std::endl;
  }

  std::cout << count << std::endl;
}
