#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t count_inversion(std::vector<int64_t>& A) {
  int64_t N = static_cast<int64_t>(A.size());

  if (N < 2) return 0;

  int64_t count = 0;
  std::vector<int64_t> left(A.begin(), A.begin() + N / 2);
  std::vector<int64_t> right(A.begin() + N / 2, A.end());

  count += count_inversion(left);
  count += count_inversion(right);

  int64_t i = 0;
  int64_t j = 0;
  int64_t k = 0;
  while (i < N) {
    if (j < static_cast<int64_t>(left.size())
        && (k == static_cast<int64_t>(right.size()) || left.at(j) <= right.at(k)))
    {
      A.at(i) = left.at(j);
      i++;
      j++;
    } else {
      count += N / 2 - j;
      A.at(i) = right.at(k);
      i++;
      k++;
    }
  }

  return count;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::cout << count_inversion(A) << std::endl;

  return 0;
}
