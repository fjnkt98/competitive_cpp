#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> A(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<int64_t> B(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> B.at(i);
  }
  std::vector<int64_t> C(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> C.at(i);
  }

  std::vector<int64_t> reference_array(100001, 0);
  for (int64_t i = 1; i <= N; i++) {
    reference_array.at(B.at(C.at(i)))++;
  }

  int64_t result = 0;
  for (int64_t i = 1; i <= N; i++) {
    result += reference_array.at(A.at(i));
  }

  std::cout << result << std::endl;

  return 0;
}
