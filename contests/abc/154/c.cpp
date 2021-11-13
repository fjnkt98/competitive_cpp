#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::sort(A.begin(), A.end());

  bool ok = true;
  for (int64_t i = 1; i < N; i++) {
    if (A.at(i - 1) == A.at(i)) ok = false;
  }

  if (ok) std::cout << "YES" << std::endl;
  else std::cout << "NO" << std::endl;

  return 0;
}
