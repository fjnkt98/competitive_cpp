#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int Q;
  std::cin >> Q;

  for (int q = 0; q < Q; q++) {
    int L;
    int N;
    std::cin >> L >> N;

    std::vector<int> X(N);
    for (int i = 0; i < N; i++) {
      std::cin >> X.at(i);
    }

    int max = 0;
    int min = 0;

    for (int i = 0; i < N; i++) {
      min = std::max(min, std::min(X.at(i), L - X.at(i)));
      max = std::max(max, std::max(X.at(i), L - X.at(i)));
    }

    std::cout << min << " " << max << std::endl;
  }

  return 0;
}