#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template <class T> std::vector<T> coordinate_compress(std::vector<T> input) {
  std::vector<T> output(input.size());

  std::vector<T> copy = input;
  std::sort(copy.begin(), copy.end());

  copy.erase(std::unique(copy.begin(), copy.end()), copy.end());
  for (size_t i = 0; i < input.size(); i++) {
    output.at(i) = std::distance(copy.begin(),
                      std::lower_bound(copy.begin(), copy.end(), input.at(i)));
  }

  return output;
}

int main() {
  int64_t H, W, N;
  std::cin >> H >> W >> N;

  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  auto row = coordinate_compress(A);
  auto column = coordinate_compress(B);

  for (int64_t i = 0; i < N; i++) {
    std::cout << row.at(i) + 1 << " " << column.at(i) + 1 << std::endl;
  }

  return 0;
}
