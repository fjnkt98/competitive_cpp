#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void max_heapify(std::vector<int64_t>& A, int64_t H, int64_t i) {
  int64_t left = i * 2;
  int64_t right = i * 2 + 1;

  int64_t largest;
  if (left <= H && A.at(left) > A.at(i)) {
    largest = i * 2;
  } else {
    largest = i;
  }
  if (right <= H && A.at(right) > A.at(largest)) {
    largest = i * 2 + 1;
  }

  if (largest != i) {
    std::swap(A.at(i), A.at(largest));
    max_heapify(A, H, largest);
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N + 1);
  for (int64_t i = 1; i <= N; i++) {
    std::cin >> A.at(i);
  }

  for (int64_t i = N / 2; i > 0; i--) {
    max_heapify(A, N, i);
  }

  for (int64_t i = 1; i <= N; i++) {
    std::cout << " " << A.at(i);
  }
  std::cout << std::endl;

  return 0;
}
