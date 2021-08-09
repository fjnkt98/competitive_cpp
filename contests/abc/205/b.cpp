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
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) != i + 1) {
      ok = false;
    }
  }
  
  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
