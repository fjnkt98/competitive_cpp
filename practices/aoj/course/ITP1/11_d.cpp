#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

class Dice {
  public:
    Dice(int64_t top, int64_t front, int64_t right, int64_t left, int64_t back, int64_t bottom, std::string command = "") {
      this->top = top;
      this->front = front;
      this->right = right;
      this->left = left;
      this->back = back;
      this->bottom = bottom;
      this->command = command;
    }

    Dice()
      : top(0), front(0), right(0), left(0), back(0), bottom(0), command("") {

      }

  int64_t simulate() {
    for (char c : this->command) {
      this->rotate(c);
    }

    return this->top;
  }

  void rotate(char direction) {
    if (direction == 'N') {
      int64_t tmp = this->top;
      this->top =  this->front;
      this->front = this->bottom;
      this->bottom = this->back;
      this->back = tmp;
    }
    if (direction == 'E') {
      int64_t tmp = this->top;
      this->top = this->left;
      this->left = this->bottom;
      this->bottom = this->right;
      this->right = tmp;
    }
    if (direction == 'W') {
      int64_t tmp = this->top;
      this->top = this->right;
      this->right = this->bottom;
      this->bottom = this->left;
      this->left = tmp;
    }
    if (direction == 'S') {
      int64_t tmp = this->top;
      this->top = this->back;
      this->back = this->bottom;
      this->bottom = this->front;
      this->front = tmp;
    }
  }

  int64_t top;
  int64_t front;
  int64_t right;
  int64_t left;
  int64_t back;
  int64_t bottom;
  std::string command;
};

bool is_same(Dice d1, Dice d2) {
  bool same = false;
  for (int64_t i = 0; i < 4; i++) {
    for (int64_t j = 0; j < 4; j++) {
      d2.rotate('N');
      if (d1.top == d2.top &&
          d1.front == d2.front &&
          d1.right == d2.right &&
          d1.left == d2.left &&
          d1.back == d2.back &&
          d1.bottom == d2.bottom)
      {
        same = true;
      }
    }
    d2.rotate('E');
    if (d1.top == d2.top &&
        d1.front == d2.front &&
        d1.right == d2.right &&
        d1.left == d2.left &&
        d1.back == d2.back &&
        d1.bottom == d2.bottom)
    {
      same = true;
    }
  }
  d2.rotate('N');
  for (int64_t i = 0; i < 4; i++) {
    for (int64_t j = 0; j < 4; j++) {
      d2.rotate('N');
      if (d1.top == d2.top &&
          d1.front == d2.front &&
          d1.right == d2.right &&
          d1.left == d2.left &&
          d1.back == d2.back &&
          d1.bottom == d2.bottom)
      {
        same = true;
      }
    }
    d2.rotate('E');
    if (d1.top == d2.top &&
        d1.front == d2.front &&
        d1.right == d2.right &&
        d1.left == d2.left &&
        d1.back == d2.back &&
        d1.bottom == d2.bottom)
    {
      same = true;
    }
  }

  return same;
}

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<Dice> dices;
  for (int64_t i = 0; i < N; i++) {
    int64_t top, front, right, left, back, bottom;
    std::cin >> top >> front >> right >> left >> back >> bottom;

    dices.push_back(Dice(top, front, right, left, back, bottom));
  }

  bool ok = true;
  for (int64_t i = 0; i < N; i++) {
    for (int64_t j = i + 1; j < N; j++) {
      if (is_same(dices.at(i), dices.at(j))) {
        ok = false;
      }
    }
  }

  if (ok) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
