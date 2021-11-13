#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
  int64_t A, B, C, N;
  std::cin >> A >> B >> C >> N;

  int64_t count = 0;
  for (int64_t i = 0; i <= 3000; i++) {
    for (int64_t j = 0; j <= 3000; j++) {
      int64_t red = i * A;
      int64_t green = j * B;
      int64_t blue = N - red - green;

      if (blue >= 0 && blue % C == 0) {
        count++;
      }
    }
  }

  std::cout << count << std::endl;
  return 0;
}
