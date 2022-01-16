#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }
  int64_t M;
  std::cin >> M;
  std::vector<int64_t> B(M);
  for (int64_t i = 0; i < M; i++) {
    std::cin >> B.at(i);
  }

  std::vector<int64_t> union_set;
  std::set_union(A.begin(), A.end(), B.begin(), B.end(),
                 std::back_inserter(union_set));

  std::vector<int64_t> intersect;
  std::set_intersection(A.begin(), A.end(), B.begin(), B.end(),
                        std::back_inserter(intersect));

  std::vector<int64_t> result;
  std::set_difference(union_set.begin(), union_set.end(), intersect.begin(),
                      intersect.end(), std::back_inserter(result));

  for (auto r : result) {
    std::cout << r << std::endl;
  }

  return 0;
}