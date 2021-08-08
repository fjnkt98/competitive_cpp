#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t count = 0;

void merge(std::vector<int64_t>& A, int64_t left, int64_t mid, int64_t right) {
  int64_t N1 = mid - left;
  int64_t N2 = right - mid;

  std::vector<int64_t> L(N1 + 1);
  std::vector<int64_t> R(N2 + 1);

  for (int64_t i = 0; i < N1; i++) {
    L.at(i) = A.at(left + i);
  }
  for (int64_t i = 0; i < N2; i++) {
    R.at(i) = A.at(mid + i);
  }

  L.at(N1) = 1LL << 60;
  R.at(N2) = 1LL << 60;

  int64_t i = 0;
  int64_t j = 0;
  for (int64_t k = left; k < right; k++) {
    if (L.at(i) <= R.at(j)) {
      A.at(k) = L.at(i);
      i++;
    } else {
      A.at(k) = R.at(j);
      j++;
    }
    count++;
  }
}

void merge_sort(std::vector<int64_t>& A, int64_t left, int64_t right) {
  if (right - left > 1) {
    int64_t mid = (right + left) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t& a : A) {
    std::cin >> a;
  }

  merge_sort(A, 0, A.size());

  for (int64_t i = 0; i < N; i++) {
    if (i) {
      std::cout << " ";
    }
    std::cout << A.at(i);
  }
  std::cout << std::endl << count << std::endl;

  return 0;
}
