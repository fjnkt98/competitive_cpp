#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::pair<int64_t, std::string>> mountain(N);
  for (int64_t i = 0; i < N; i++) {
    std::string S;
    int64_t T;
    std::cin >> S >> T;
    mountain.at(i) = std::make_pair(T, S);
  }

  std::sort(mountain.begin(), mountain.end());

  std::cout << mountain.at(N - 2).second << std::endl;

  return 0;
}
