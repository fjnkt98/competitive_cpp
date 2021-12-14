#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> H(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> H.at(i);
  }

  bool ok = true;
  int64_t virtual_maximum_height = H.at(0) - 1;
  for (int64_t i = 1; i < N; i++) {
    if (H.at(i) < virtual_maximum_height) {
      ok = false;
    }

    virtual_maximum_height = std::max(virtual_maximum_height, H.at(i) - 1);
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }



  return 0;
}
