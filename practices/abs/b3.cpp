#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t N, A, B;
  std::cin >> N >> A >> B;

  int64_t sum = 0;
  for (int64_t i = 1; i <= N; i++) {
    std::string N_str = std::to_string(i);


    int64_t local_sum = 0;
    for (auto digit : N_str) {
      local_sum += static_cast<int64_t>(digit - '0');
    }

    if (A <= local_sum && local_sum <= B) {
      sum += i;
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
