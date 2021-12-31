#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

void output_vector(std::vector<int64_t> X) {
  for (size_t i = 0; i < X.size(); i++) {
    if (i) std::cout << " ";
    std::cout << X.at(i);
  }
  std::cout << std::endl;
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> A(N);
  std::iota(A.begin(), A.end(), 1);

  do {
    output_vector(A);
  } while (std::next_permutation(A.begin(), A.end()));

  return 0;
}
