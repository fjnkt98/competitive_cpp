#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int64_t gcd(int64_t x, int64_t y) {
  if (x < 0 || y < 0) return -1;

  if (y == 0) return x;
  else return gcd(y, x % y);
}

int main() {
  int64_t N, K;
  std::cin >> N >> K;
  std::vector<int64_t> A(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> A.at(i);
  }

  std::sort(A.begin(), A.end());
  int64_t common_gcd = A.at(0);
  for (int64_t i = 1; i < N; i++) {
    common_gcd = gcd(common_gcd, A.at(i));
  }

  std::string answer = "";
  if (K > *std::max_element(A.begin(), A.end())) {
    answer = "IMPOSSIBLE";
  } else if (std::find(A.begin(), A.end(), K) != A.end()){
    answer = "POSSIBLE";
  } else {

    if (K % common_gcd != 0) {
      answer = "IMPOSSIBLE";
    } else {
      answer = "POSSIBLE";
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
