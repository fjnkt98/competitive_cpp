#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  int64_t X = 0;
  std::vector<int64_t> Y(N);
  for (int64_t i = 0; i < N; i++) {
    X -= A.at(i);
    Y.at(i) = 2 * A.at(i) + B.at(i);
  }

  std::sort(Y.begin(), Y.end());

  int64_t count = 0;
  while (X <= 0) {
    X += Y.back();
    Y.pop_back();
    count++;
  }

  std::cout << count << std::endl;

  return 0;
}
