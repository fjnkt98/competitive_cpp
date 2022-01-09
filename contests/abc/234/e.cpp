#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

std::set<int64_t> generate_alithmetric(void) {
  std::set<int64_t> result;

  for (int64_t first = 1; first <= 9; first++) {
    for (int64_t diff = -9; diff <= 8; diff++) {
      std::string S = "";
      int64_t digit = first;
      for (int64_t i = 0; i < 18; i++) {
        S.push_back(digit + '0');
        result.insert(std::stoll(S));

        digit += diff;

        if (!(digit >= 0 && digit <= 9)) {
          break;
        }
      }
    }
  }

  return result;
}

int main() {
  int64_t X;
  std::cin >> X;

  auto arithmetric = generate_alithmetric();
  std::cout << *arithmetric.lower_bound(X) << std::endl;

  return 0;
}
