#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> taro(N);
  std::vector<std::string> hanako(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> taro.at(i) >> hanako.at(i);
  }

  int64_t taro_point = 0;
  int64_t hanako_point = 0;
  for (int64_t i = 0; i < N; i++) {
    if (taro.at(i) == hanako.at(i)) {
      taro_point++;
      hanako_point++;
    } else if (taro.at(i) < hanako.at(i)) {
      hanako_point += 3;
    } else {
      taro_point += 3;
    }
  }

  std::cout << taro_point << " " << hanako_point << std::endl;

  return 0;
}
