#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include <cassert>

template <int64_t mod>
class ModInt {
 public:
  // Default constructor
  ModInt() : value_(0) {}

  // Converting constructor
  ModInt(int64_t n) {
    // Error when n is a multiple of mod
    assert(n == 0 || n % mod != 0);

    int64_t x = n % mod;
    if (x < 0) x += mod;
    value_ = x;
  }

  int64_t value() const { return value_; }

  // Return the N-th power of the value.
  ModInt power(int64_t n) const {
    assert(n >= 0);

    ModInt x = *this;
    ModInt r = 1;

    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }

    return r;
  }

  // Return the inverse of the value.
  ModInt inverse() const { return this->power(mod - 2); }

  // Overload prefix increment operator
  ModInt& operator++() {
    value_++;
    if (value_ == mod) value_ = 0;

    return *this;
  }

  // Overload prefix decrement operator
  ModInt& operator--() {
    if (value_ == 0) value_ = mod;
    value_--;
    return *this;
  }

  // Overload postfix increment operator
  ModInt operator++(int) {
    ModInt result = *this;
    ++*this;
    return result;
  }

  // Overload postfix decrement operator
  ModInt operator--(int) {
    ModInt result = *this;
    --*this;
    return result;
  }

  // Overload assignment operator `+=`
  ModInt& operator+=(const ModInt& rhs) {
    value_ += rhs.value_;
    if (value_ >= mod) value_ -= mod;
    return *this;
  }

  // Overload assignment operator `-=`
  ModInt& operator-=(const ModInt& rhs) {
    if (value_ < rhs.value_) value_ += mod;
    value_ -= rhs.value_;
    return *this;
  }

  // Overload assignment operator `*=`
  ModInt& operator*=(const ModInt& rhs) {
    value_ = value_ * rhs.value_ % mod;
    return *this;
  }

  // Overload assignment operator `/=`
  ModInt& operator/=(const ModInt& rhs) {
    return *this = *this * rhs.inverse();
  }

  // Overload plus operator
  ModInt operator+() const { return *this; }

  // Overload minus operator
  ModInt operator-() const { return ModInt() - *this; }

  // Overload addition operator
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) += rhs;
  }

  // Overload subtraction operator
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) -= rhs;
  }

  // Overload multiplication operator
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) *= rhs;
  }

  // Overload division operator
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    return ModInt(lhs) /= rhs;
  }

  // Overload equal operator
  friend bool operator==(const ModInt& lhs, const ModInt& rhs) {
    return lhs.value_ == rhs.value_;
  }

  // Overload not-equal operator
  friend bool operator!=(const ModInt& lhs, const ModInt& rhs) {
    return lhs.value_ != rhs.value_;
  }

  // Overload comparison operator `<`
  friend bool operator<(const ModInt& lhs, const ModInt& rhs) {
    return lhs.value_ < rhs.value_;
  }

  // Overload comparison operator `<`
  friend bool operator>(const ModInt& lhs, const ModInt& rhs) {
    return lhs.value_ > rhs.value_;
  }

  // Overload comparison operator `<`
  friend bool operator<=(const ModInt& lhs, const ModInt& rhs) {
    return lhs.value_ <= rhs.value_;
  }

  // Overload comparison operator `<`
  friend bool operator>=(const ModInt& lhs, const ModInt& rhs) {
    return lhs.value_ >= rhs.value_;
  }

  // Overload stream operator
  friend std::ostream& operator<<(std::ostream& os, const ModInt<mod>& x) {
    return os << x.value_;
  }

 private:
  int64_t value_;
};

int main() {
  int64_t N;
  std::cin >> N;

  std::vector<std::vector<ModInt<998244353>>> dp(
      N + 1, std::vector<ModInt<998244353>>(10, 0));
  for (int64_t i = 1; i <= 9; i++) {
    dp.at(1).at(i) = 1;
  }

  for (int64_t d = 2; d <= N; d++) {
    for (int64_t i = 1; i <= 9; i++) {
      for (int64_t j = std::max(1L, i - 1); j <= std::min(9L, i + 1); j++) {
        dp.at(d).at(j) += dp.at(d - 1).at(i);
      }
    }
  }

  ModInt<998244353> answer(0);
  for (int64_t i = 1; i <= 9; i++) {
    answer += dp.at(N).at(i);
  }

  std::cout << answer << std::endl;

  return 0;
}
