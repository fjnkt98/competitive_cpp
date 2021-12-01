#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, B, C, D, E;
  std::cin >> N >> A >> B >> C >> D >> E;

  std::vector<int64_t> X = {A, B, C, D, E};

  int64_t bottleneck = *std::min_element(X.begin(), X.end());

  int64_t group = (N + bottleneck - 1) / bottleneck;

  std::cout << group + 4 << std::endl;

  return 0;
}
