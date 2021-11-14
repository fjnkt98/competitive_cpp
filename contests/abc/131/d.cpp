#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::vector<int64_t> B(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i) >> B.at(i);
  }

  std::vector<std::pair<int64_t, int64_t>> C(N);
  for (int64_t i = 0; i < N; i++) {
    C.at(i) = std::make_pair(B.at(i), A.at(i));
  }

  std::sort(C.begin(), C.end());

  bool capable = true;
  int64_t current_time = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t deadline = C.at(i).first;
    int64_t duration = C.at(i).second;

    current_time += duration;
    if (current_time > deadline) {
      capable = false;
    }
  }

  if (capable) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;

  return 0;
}
