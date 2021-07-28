#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> bubble_sort(std::vector<std::string> cards) {
  for (int64_t i = 0; i < cards.size(); i++) {
    for (int64_t j = cards.size() - 1; j > i; j--) {
      if (cards.at(j).at(1) - '0' < cards.at(j - 1).at(1) - '0') {
        std::swap(cards.at(j), cards.at(j - 1));
      }
    }
  }

  return cards;
}

std::vector<std::string> selection_sort(std::vector<std::string> cards) {
  for (int64_t i = 0; i < cards.size(); i++) {
    int64_t minimum_value_index = i;
    for (int64_t j = i; j < cards.size(); j++) {
      if (cards.at(j).at(1) - '0' < cards.at(minimum_value_index).at(1) - '0') {
        minimum_value_index = j;
      }
    }
    std::swap(cards.at(i), cards.at(minimum_value_index));
  }

  return cards;
}

int main() {
  int64_t N;
  std::cin >> N;
  std::vector<std::string> cards(N);
  for (int64_t i = 0; i < N; i++) {
    std::cin >> cards.at(i);
  }

  auto bubble_sorted_cards = bubble_sort(cards);
  auto selection_sorted_cards = selection_sort(cards);

  for (int64_t i = 0; i < N; i++) {
    auto v = cards.at(i);

    int64_t j = i;
    while (j > 0) {
      if (cards.at(j - 1).at(1) - '0' > v.at(1) - '0') {
        cards.at(j) = cards.at(j - 1);
      } else {
        break;
      }
      j--;
    }
    cards.at(j) = v;
  }

  bool is_stable = true;
  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << bubble_sorted_cards.at(i);

    if (bubble_sorted_cards.at(i) != cards.at(i)) {
      is_stable = false;
    }
  }
  std::cout << std::endl;
  if (is_stable) {
    std::cout << "Stable" << std::endl;
  } else {
    std::cout << "Not stable" << std::endl;
  }

  is_stable = true;
  for (int64_t i = 0; i < N; i++) {
    if (i) std::cout << " ";
    std::cout << selection_sorted_cards.at(i);

    if (selection_sorted_cards.at(i) != cards.at(i)) {
      is_stable = false;
    }
  }
  std::cout << std::endl;
  if (is_stable) {
    std::cout << "Stable" << std::endl;
  } else {
    std::cout << "Not stable" << std::endl;
  }

  return 0;
}
