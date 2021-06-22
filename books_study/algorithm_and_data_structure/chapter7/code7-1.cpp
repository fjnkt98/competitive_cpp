/*
 * Solving "Coin Problem" by using Greedy Algorithm
 */

#include <iostream>
#include <vector>

int main() {
  const std::vector<int64_t> amount_of_coin = {500, 100, 50, 10, 5, 1};

  int64_t X;
  std::vector<int64_t> a(6);

  std::cin >> X;
  for (int64_t i = 0; i < 6; i++) {
    std::cin >> a.at(i);
  }

  // Greedy algorithm
  int64_t result = 0;
  for (int64_t i = 0; i < 6; i++) {
    int64_t add = X / amount_of_coin.at(i);

    if (add > a.at(i)) {
      add = a.at(i);
    }

    X -= amount_of_coin.at(i) * add;
    result += add;
  }

  std::cout << result << std::endl;
}
