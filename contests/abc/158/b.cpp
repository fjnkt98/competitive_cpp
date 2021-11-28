#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;

  int64_t answer = 0;
  answer += A * (N / (A + B));

  if (N % (A + B) <= A) {
    answer += N % (A + B);
  } else {
    answer += A;
  }

  std::cout << answer << std::endl;

  return 0;
}
