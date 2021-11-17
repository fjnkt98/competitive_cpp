#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t K, A, B;
  std::cin >> K >> A >> B;

  if (A >= B) {
    std::cout << K + 1 << std::endl;
  } else if (B - A <= 2) {
    std::cout << K + 1 << std::endl;
  } else {
    int64_t remain_operation = K;
    int64_t answer = 0;
    remain_operation -= A - 1;
    answer = A;

    if (remain_operation % 2 == 0) {
      answer += (remain_operation / 2) * (B - A);
    } else {
      answer += 1;
      remain_operation -= 1;
      answer += (remain_operation / 2) * (B - A);
    }

    std::cout << answer << std::endl;
  }

  return 0;
}
