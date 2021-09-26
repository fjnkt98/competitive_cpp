#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  int64_t X;
  std::cin >> X;

  int64_t sum = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
  int64_t quotient = X / sum;
  int64_t residue = X % sum;

  int64_t total = 0;
  int64_t index = 0;
  for (int64_t i = 0; i < N; i++) {
    total += A.at(i);
    index = i + 1;
    if (total > residue) {
      break;
    }
  }

  std::cout << index + quotient * N << std::endl;

  return 0;
}
