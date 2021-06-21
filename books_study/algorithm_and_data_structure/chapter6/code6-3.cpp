/*
 * Age Guessing Game
 */

#include <iostream>
#include <vector>

int main() {
  std::cout << "Start Age Guessing Game!!" << std::endl;

  int64_t left = 20;
  int64_t right = 38;

  while (right - left > 1) {
    int64_t mid = (left + right) / 2;

    std::cout << "Is the age less than " << mid << " ? (yes / no)" << std::endl;
    std::string answer;
    std::cin >> answer;

    if (answer == "yes") {
      right = mid;
    } else if (answer == "no") {
      left = mid;
    } else {
      std::cout << "Your input is wrong! Please input valid value." << std::endl;
      continue;
    }
  }

  std::cout << "The age is " << left << "!" << std::endl;
}
