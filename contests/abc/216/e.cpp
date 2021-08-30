#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t sum_of_arithmetic_progression(int64_t initial_term, int64_t difference, int64_t number_of_terms) {
  int64_t sum = number_of_terms * initial_term;
  if (number_of_terms % 2 == 0) {
    sum += (number_of_terms / 2) * (number_of_terms - 1) * difference;
  } else {
    sum += ((number_of_terms - 1) / 2) * number_of_terms * difference;
  }
  return sum;
}

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N + 1, 0);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::sort(A.begin(), A.end(), std::greater<int64_t>{});

  int64_t satisfication = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t diff = A.at(i) - A.at(i + 1);
    if ((diff * (i + 1)) <= K) {
      int64_t sum = sum_of_arithmetic_progression(A.at(i), -1, diff);
      satisfication += sum * (i + 1);
      K -= diff * (i + 1);
    } else {
      int64_t quotient = K / (i + 1);
      int64_t residue = K % (i + 1);
      satisfication += sum_of_arithmetic_progression(A.at(i), -1, quotient) * (i + 1);
      satisfication += (A.at(i) - quotient) * residue;
      K = 0;
    }
    if (K <= 0) break;
  }

  std::cout << satisfication << std::endl;

  return 0;
}
