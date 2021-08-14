#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<int64_t> counting_sort(std::vector<int64_t>& A) {
  int64_t N = static_cast<int64_t>(A.size());
  int64_t K = *std::max_element(A.begin(), A.end());

  std::vector<int64_t> output_array(N);
  std::vector<int64_t> counting_array(K + 1, 0);

  for (const auto& a : A) {
    counting_array.at(a)++;
  }
  for (int64_t i = 1; i <= K; i++) {
    counting_array.at(i) += counting_array.at(i - 1);
  }
  for (int64_t i = N - 1; i >= 0; i--) {
    output_array.at(counting_array.at(A.at(i)) - 1) = A.at(i);
    counting_array.at(A.at(i))--;
  }

  return output_array;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::vector<int64_t> answer = counting_sort(A);

  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << answer.at(i);
  }
  std::cout << std::endl;

  return 0;
}
