#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool is_prime(int64_t value) {
  if (value == 1) {
    return false;
  } else if (value == 2) {
    return true;
  } else {
    for (int64_t i = 2; i * i <= value; i++) {
      if (value % i == 0) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int64_t N;
  std::cin >> N;

  int64_t count = 0;
  for (int64_t i = 0; i < N; i++) {
    int64_t value;
    std::cin >> value;

    if (is_prime(value)) {
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}
