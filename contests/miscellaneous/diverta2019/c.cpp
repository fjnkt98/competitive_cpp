#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> S(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> S.at(i);
  }

  int64_t answer = 0;
  for (int64_t i = 0; i < N; i++) {
    for (size_t j = 1; j < S.at(i).size(); j++) {
      if (S.at(i).at(j - 1) == 'A' && S.at(i).at(j) == 'B') {
        answer++;
      }
    }
  }

  int64_t A = 0;
  int64_t B = 0;
  int64_t BA = 0;
  for (int64_t i = 0; i < N; i++) {
    if (S.at(i).at(0) == 'B' && S.at(i).back() == 'A') {
      BA++;
    } else if (S.at(i).at(0) == 'B') {
      B++;
    } else if (S.at(i).back() == 'A') {
      A++;
    }
  }

  /* std::cout << answer << " " << A << " " << B << " " << BA << std::endl; */

  if (BA == 0) {
    answer += std::min(A, B);
  } else {
    if (A + B > 0) {
      answer += BA + std::min(A, B);
    } else {
      answer += BA - 1;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
