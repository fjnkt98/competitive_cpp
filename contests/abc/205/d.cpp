#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  std::vector<int64_t> K(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> K.at(i);
  }

  std::vector<int64_t> number_of_remain_number(N);
  for (int64_t i = 0; i < N; i++) {
    number_of_remain_number.at(i) = A.at(i) - (i + 1);
  }

  for (int64_t i = 0; i < Q; i++) {
    int64_t index = (std::lower_bound(number_of_remain_number.begin(), number_of_remain_number.end(), K.at(i)) - number_of_remain_number.begin());
    if (index == N) {
      std::cout << A.at(index - 1) + (K.at(i) - number_of_remain_number.at(index - 1)) << std::endl;
    } else {
      std::cout << (A.at(index) - 1) - (number_of_remain_number.at(index) - K.at(i)) << std::endl;
    }
  }

  return 0;
}
