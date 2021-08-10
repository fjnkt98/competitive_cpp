#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

int main() {
  int64_t A, B, C;
  std::cin >> A >> B >> C;

  int64_t gcd = std::gcd(A, std::gcd(B, C));

  int64_t answer = 0;
  answer += A / gcd - 1;
  answer += B / gcd - 1;
  answer += C / gcd - 1;

  std::cout << answer << std::endl;
  
  return 0;
}
