#include <iostream>

int64_t recursive_function(int64_t N) {
  std::cout << "recursive_function(" << N << ") was called." << std::endl;

  if (N == 0) {
    return 0;
  }

  int64_t result = N + recursive_function(N - 1);
  std::cout << "Sum up to " << N << " = " << result << std::endl;

  return result;
}

int main() {
  int64_t N;

  std::cin >> N;

  recursive_function(N);

  return 0;
}
