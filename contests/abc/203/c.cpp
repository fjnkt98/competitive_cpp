#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<std::pair<int64_t, int64_t>> array(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    array.at(i) = std::make_pair(a, b);
  }

  int64_t money = K;
  std::sort(array.begin(), array.end());
  for (int64_t i = 0; i < N; i++) {
    if (array.at(i).first > money) {
      break;
    }
    money += array.at(i).second;
  }

  std::cout << money << std::endl;

  return 0;
}
