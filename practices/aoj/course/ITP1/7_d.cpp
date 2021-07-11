#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t n, m, l;
  std::cin >> n >> m >> l;
  std::vector<std::vector<int64_t>> A(n, std::vector<int64_t>(m));
  std::vector<std::vector<int64_t>> B(m, std::vector<int64_t>(l));
  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = 0; j < m; j++) {
      std::cin >> A.at(i).at(j);
    }
  }
  for (int64_t i = 0; i < m; i++) {
    for (int64_t j = 0; j < l; j++) {
      std::cin >> B.at(i).at(j);
    }
  }

  std::vector<std::vector<int64_t>> C(n, std::vector<int64_t>(l));
  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = 0; j < l; j++) {
      for (int64_t k = 0; k < m; k++) {
        C.at(i).at(j) += A.at(i).at(k) * B.at(k).at(j);
      }
    }
  }

  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = 0; j < l; j++) {
      std::cout << C.at(i).at(j);
      if (j != l - 1) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }

  return 0;
}
