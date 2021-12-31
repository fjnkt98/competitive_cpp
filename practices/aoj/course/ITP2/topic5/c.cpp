#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> B(N);
  std::copy(A.begin(), A.end(), B.begin());
  std::vector<int64_t> C(N);
  std::copy(A.begin(), A.end(), C.begin());

  if (std::prev_permutation(B.begin(), B.end())) {
    output_vector(B);
  }
  output_vector(A);
  if (std::next_permutation(C.begin(), C.end())) {
    output_vector(C);
  }
  return 0;
}
