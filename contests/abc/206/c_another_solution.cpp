#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<int64_t> a(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> a.at(i);
  }

  std::map<int64_t, int64_t> complementary_elements;
  int64_t answer = 0;

  for (int64_t j = 0; j < N; j++) {
    answer += (j - complementary_elements[a.at(j)]);
    complementary_elements[a.at(j)]++;
  }

  std::cout << answer << std::endl;

  return 0;
}
