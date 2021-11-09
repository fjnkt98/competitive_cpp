#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(N));
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = 0; j < N; j++) {
      std::cin >> A.at(i).at(j);
    }
  }

  std::vector<int64_t> route(N - 1);
  std::iota(route.begin(), route.end(), 1);

  int64_t count = 0;
  do {
    int64_t distance = A.at(0).at(route.at(0));
    for (size_t i = 1; i < route.size(); i++) {
      distance += A.at(route.at(i - 1)).at(route.at(i));
    }
    distance += A.at(route.back()).at(0);

    if (distance == K) count++;
  } while (std::next_permutation(route.begin(), route.end()));

  std::cout << count << std::endl;

  return 0;
}
