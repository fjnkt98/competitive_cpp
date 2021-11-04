#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int64_t gcd(int64_t x, int64_t y) {
 if (x < 0 || x < 0) return -1;

 if (y == 0) return x;
  else return gcd(y, x % y);
}

std::vector<int64_t> enumerate_dividers(int64_t N) {
  std::vector<int64_t> dividers;

  for (int64_t i = 1; i * i <= N; i++) {
    if (N % i == 0) {
      dividers.push_back(i);

      if (N / i != i) {
        dividers.push_back(N / i);
      }
    }
  }

  std::sort(dividers.begin(), dividers.end());
  return dividers;
}

int main() {
  int64_t A, B;
  std::cin >> A >> B;

  auto a_divider = enumerate_dividers(A);
  auto b_divider = enumerate_dividers(B);

  std::sort(a_divider.begin(), a_divider.end());
  std::sort(b_divider.begin(), b_divider.end());

  std::vector<int64_t> intersection;
  std::set_intersection(a_divider.begin(), a_divider.end(),
                        b_divider.begin(), b_divider.end(),
                        std::inserter(intersection, intersection.end()));

  /* for (auto i : intersection) { */
  /*   std::cout << i << " "; */
  /* } */
  /* std::cout << std::endl; */

  int64_t count = 1;
  int64_t N = intersection.size();
  std::vector<bool> eliminated(N, false);
  for (int64_t i = 1; i < N; i++) {
    if (eliminated.at(i) == false) {
      count++;
      for (int64_t j = i + 1; j < N; j++) {
        if (intersection.at(j) % intersection.at(i) == 0) {
          eliminated.at(j) = true;
        }
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}
