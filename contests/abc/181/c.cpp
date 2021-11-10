#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> X(N);
  std::vector<int64_t> Y(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> X.at(i) >> Y.at(i);
  }

  bool exist = false;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      for (int64_t k = j + 1; k < N; k++) {
        if ((Y.at(k) -Y.at(i)) * (X.at(j) - X.at(i)) == (Y.at(j) - Y.at(i)) * (X.at(k) - X.at(i))) {
          exist = true;
        }
      }
    }
  }

  if (exist) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;

}
