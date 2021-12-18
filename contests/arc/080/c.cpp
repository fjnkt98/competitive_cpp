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

  int64_t multiplication2 = 0;
  int64_t multiplication4 = 0;
  for (int64_t i = 0; i < N; i++) {
    if (A.at(i) % 4 == 0) multiplication4++;
    else if (A.at(i) % 2 == 0) multiplication2++;
  }

  bool ok = false;
  if (multiplication4 + multiplication2 / 2 >= N / 2) {
    ok = true;
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
