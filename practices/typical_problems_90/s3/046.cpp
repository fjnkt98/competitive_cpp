#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  std::vector<int64_t> C(N);
  for (int64_t i = 0; i < N; i++) std::cin >> A.at(i);
  for (int64_t i = 0; i < N; i++) std::cin >> B.at(i);
  for (int64_t i = 0; i < N; i++) std::cin >> C.at(i);

  std::vector<int64_t> count_of_residue_A(46, 0);
  std::vector<int64_t> count_of_residue_B(46, 0);
  std::vector<int64_t> count_of_residue_C(46, 0);
  for (int64_t i = 0; i < N; i++) {
    count_of_residue_A.at(A.at(i) % 46)++;
    count_of_residue_B.at(B.at(i) % 46)++;
    count_of_residue_C.at(C.at(i) % 46)++;
  }

  int64_t count = 0;
  for (int64_t i = 0; i < 46; i++) {
    for (int64_t j = 0; j < 46; j++) {
      for (int64_t k = 0; k < 46; k++) {
        if ((i + j + k) % 46 == 0) {
          int64_t local_count = 1;
          local_count *= count_of_residue_A.at(i);
          local_count *= count_of_residue_B.at(j);
          local_count *= count_of_residue_C.at(k);
          count += local_count;
        }
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
