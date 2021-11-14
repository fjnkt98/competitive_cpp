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

 int64_t minimum_cost = 1LL << 60;
 for (int64_t i = -100; i <= 100; i++) {
   int64_t cost = 0;
   for (int64_t j = 0; j < N; j++) {
     if (i != A.at(j)) {
       cost += (i - A.at(j)) * (i - A.at(j));
     }
   }

   minimum_cost = std::min(minimum_cost, cost);
 }

 std::cout << minimum_cost << std::endl;

  return 0;
}
