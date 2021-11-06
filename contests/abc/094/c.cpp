#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i);
  }
  std::vector<std::pair<int64_t, int64_t>> Y(N);
  for (int64_t i = 0; i < N; i++) {
    Y.at(i) = std::make_pair(X.at(i), i);
  }
  std::sort(Y.begin(), Y.end());
  std::sort(X.begin(), X.end());

  std::vector<int64_t> answer(N);
  for (int64_t i = 0; i < N; i++) {
    if (i < N / 2) {
      answer.at(Y.at(i).second) = X.at(N / 2);
    } else {
      answer.at(Y.at(i).second) = X.at(N / 2 - 1);
    }
  }

  for (int64_t a : answer) {
    std::cout << a << std::endl;
  }


  return 0;
}
