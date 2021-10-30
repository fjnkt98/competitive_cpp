#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>

int main() {
  int64_t N, K;
  std::cin >> N >> K;

  std::vector<std::tuple<int64_t, int64_t>> A(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> a >> b;
    A.at(i) = std::make_tuple(a, b);
  }

  std::sort(A.begin(), A.end());

  for (int64_t i = 0; i < N; i++) {
    int64_t a = std::get<0>(A.at(i));
    int64_t b = std::get<1>(A.at(i));

    if (K - b > 0) {
      K -= b;
    } else {
      std::cout << a << std::endl;
      break;
    }
  }

  return 0;
}
