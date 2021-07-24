#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Dice {
  public:
    Dice(int64_t top, int64_t front, int64_t right, int64_t left, int64_t back, int64_t bottom, std::string command) {
      this->top = top;
      this->front = front;
      this->right = right;
      this->left = left;
      this->back = back;
      this->bottom = bottom;
      this->command = command;
    }

  int64_t simulate() {
    for (char c : this->command) {
      this->rotate(c);
    }

    return this->top;
  }

  private:
    int64_t top;
    int64_t front;
    int64_t right;
    int64_t left;
    int64_t back;
    int64_t bottom;
    std::string command;

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
};

int main() {
  int64_t top, front, right, left, back, bottom;
  std::cin >> top >> front >> right >> left >> back >> bottom;
  std::string command;
  std::cin >> command;

  Dice d(top, front, right, left, back, bottom, command);

  std::cout << d.simulate() << std::endl;

  return 0;
}
