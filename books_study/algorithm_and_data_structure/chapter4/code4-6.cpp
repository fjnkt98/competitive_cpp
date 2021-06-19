/*
 * Fibonacci number
 *
 * calculate fibonacci by recursive function.
 *
 */

#include <iostream>

int64_t fibo(int64_t N) {
  std::cout << "fibo(" << N << ") was called." << std::endl;

  // Base cases
  if (N == 0) {
    return 0;
  }
  if (N == 1) {
    return 1;
  }
  
  int64_t result = fibo(N - 1) + fibo(N - 2);
  std::cout << N << " nd = " << result << std::endl;

  return result;
}

int main() {
  int64_t N;
  std::cin >> N;

  fibo(N);
}
