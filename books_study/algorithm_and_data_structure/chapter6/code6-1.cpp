/*
 * Fundamental Binary Search
 *
 * Finding target value from sorted array
 */
#include <iostream>
#include <vector>
#include <algorithm>

int64_t binary_search(int64_t key, std::vector<int64_t> a) {
  int64_t left = 0;
  int64_t right = static_cast<int64_t>(a.size() - 1);

  while (right >= left) {
    int64_t mid = left + (right - left) / 2;

    if (a.at(mid) == key) {
      return mid;
    } else if (a.at(mid) > key) {
      right = mid - 1;
    } else if (a.at(mid) < key) {
      left = mid + 1;
    }
  }

  return -1;
}

int main() {
  std::vector<int64_t> a = {3, 5, 8, 10, 14, 17, 21, 39};

  std::cout << binary_search(10, a) << std::endl;
  std::cout << binary_search(3, a) << std::endl;
  std::cout << binary_search(39, a) << std::endl;
  std::cout << binary_search(-100, a) << std::endl;
  std::cout << binary_search(9, a) << std::endl;
  std::cout << binary_search(100, a) << std::endl;
}
