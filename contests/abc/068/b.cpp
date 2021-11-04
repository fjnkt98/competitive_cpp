#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

template<class T> bool choose_maximum(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  } else {
    return false;
  }
}

int main() {
  int64_t N;
  std::cin >> N;

  if (N == 1) {
    std::cout << 1 << std::endl;
    return 0;
  }

  int64_t answer = 0;
  int64_t max_count = 0;
  for (int64_t i = N; i > 0; i--) {
    int64_t X = i;

    int64_t count = 0;
    while (true) {
      if (X % 2 == 0) {
        X /= 2;
        count++;
      } else {
        break;
      }
    }

    if (choose_maximum(max_count, count)) {
      answer = i;
    }
  }

  std::cout << answer << std::endl;

  return 0;
}
