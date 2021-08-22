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

  std::vector<int64_t> residue_count(200);
  for (int64_t i = 0; i < N; i++) {
    residue_count.at(A.at(i) % 200)++;
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    residue_count.at(A.at(i) % 200)--;
    answer += residue_count.at(A.at(i) % 200);
  }

  std::cout << answer << std::endl;

  return 0;
}
