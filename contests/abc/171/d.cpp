#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <numeric>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  std::map<int64_t, int64_t> count;
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
    count[A.at(i)]++;
  }

  int64_t Q;
  std::cin >> Q;
  std::vector<int64_t> B(Q);
  std::vector<int64_t> C(Q);
  for (int64_t i = 0; i < Q; i++) {
    std::cin >> B.at(i) >> C.at(i);
  }

  int64_t sum = std::accumulate(A.begin(), A.end(), static_cast<int64_t>(0));
  for (int64_t i = 0; i < Q; i++) {
    sum += (C.at(i) - B.at(i)) * count[B.at(i)];
    count[C.at(i)] += count[B.at(i)];
    count[B.at(i)] = 0;
    std::cout << sum << std::endl;
  }

  return 0;
}
