#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int64_t count_primes(int64_t N) {
  int64_t count = 0;
  while (N % 2 == 0) {
    count++;
    N /= 2;
  }

  return count;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    answer += count_primes(A.at(i));
  }

  std::cout << answer << std::endl;

  return 0;
}
