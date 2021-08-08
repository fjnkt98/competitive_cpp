#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <class T> void coordinate_compress(std::vector<T>& X) {
  std::vector<T> result = X;
  std::sort(result.begin(), result.end());

  result.erase(std::unique(result.begin(), result.end()), result.end());
  for (auto& x : X) {
    x = std::lower_bound(result.begin(), result.end(), x) - result.begin();
  }
}

int main() {
  int64_t H, W, N;
  std::cin >> H >> W >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    int64_t a, b;
    std::cin >> A.at(i) >> B.at(i);
  }

  coordinate_compress(A);
  coordinate_compress(B);

  for (int64_t i = 0; i < N; i++) {
    std::cout << A.at(i) + 1 << " " << B.at(i) + 1 << std::endl;
  }

  return 0;
}
