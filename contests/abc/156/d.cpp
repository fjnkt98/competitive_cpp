#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// Implementation of ModInt
// This class takes one parameter `mod` as template parameter.
// This is the value that will be treated as the modulo.
template <int64_t mod>
class ModInt {
 public:
  // Default constructor
  ModInt() : value_(0) {}

  // Converting constructor
  ModInt(int64_t n) {
    int64_t x = n % mod;
    if (x < 0) x += mod;
    value_ = x;
  }

  int64_t value() const { return value_; }

  // Return the N-th power of the value.
  ModInt power(int64_t n) const {
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

int64_t iterative_power(int64_t a, int64_t n, int64_t p) {
  if (n == 0) return 1;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * iterative_power(a, n - 1, p)) % p;

  int64_t t = iterative_power(a, n / 2, p);
  return (t * t) % p;
}

int64_t n_c_x(int64_t n, int64_t x, int64_t mod) {
  int64_t result = 1;
  for (int64_t i = 0; i < x; i++) {
    result *= (n - i);
  }

  for (int64_t i = 1; i <= x; i++) {
    result /= i;
  }

  return result;
}

ModInt<1000000007> count(int64_t N, int64_t x) {
  ModInt<1000000007> result = 1;
  for (int64_t i = 0; i < x; i++) {
    result *= (N - i);
  }

  for (int64_t i = 1; i <= x; i++) {
    result /= i;
  }

  return result;
}

int main() {
  int64_t N, a, b;
  std::cin >> N >> a >> b;

  int64_t mod = 1000000007;

  ModInt<1000000007> answer = iterative_power(2, N, mod) - 1;
  answer -= count(N, a);
  answer -= count(N, b);

  std::cout << answer << std::endl;

  return 0;
}
