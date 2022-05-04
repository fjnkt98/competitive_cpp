#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

/**
 * @brief Non-recursive, and abstracted segment tree implementation.
 *
 * @tparam S Type of the element of segment tree. The pair (S, op, e) is a
 * monoid.
 * @tparam op(S, S) A function representing the binary operator.
 * @tparam e() A function which returns identity element.
 *
 */
template <class S, S op(S, S), S e()>
class SegmentTree {
 private:
  // Number of the elements managed by segment tree.
  int64_t N;
  // The logarithm of size of the segment tree base 2.
  int64_t log;
  // Size of the vector that representing binary tree object.
  int64_t size;
  // A vector of the entities representing segment tree (1-indexed).
  std::vector<S> data;

  /**
   * @brief Calculate smallest power of 2 over n.
   *
   * @param n
   * @return Exponent of the smallest power of 2 over n.
   */
  int64_t get_log(int64_t n) {
    int64_t x = 0;
    while ((1 << x) < n) {
      ++x;
    }

    return x;
  }
  /**
   * @brief Update value of the element with the value of the child node.
   *
   * @param k The index of the node(0-indexed).
   */
  void update(int64_t k) {
    // Apply the binary operator to each child and substitute the result.
    data.at(k) = op(data.at(2 * k), data.at(2 * k + 1));
  }

 public:
  /**
   * @brief Construct a new Segment Tree object
   *
   * @param A The initial values.
   */
  explicit SegmentTree(std::vector<S> A)
      : N(static_cast<int64_t>(A.size())),
        log(get_log(N)),
        size(1 << log),
        data(2 * size, e()) {
    // Initialize leaves with given vector.
    for (int64_t i = 0; i < N; i++) {
      data.at(i + size) = A.at(i);
    }

    // Update all nodes (not leaf).
    for (int64_t i = size - 1; i > 0; i--) {
      update(i);
    }
  }

  /**
   * @brief Returns the value of the specified leaf.
   *
   * @param k The index of the leaf(0-indexed).
   * @return Value of the specified leaf.
   */
  S get(int64_t k) { return data.at(k + size); }

  /**
   * @brief Set x into the specified leaf.
   *
   * @param k The index of the leaf(0-indexed).
   * @param x The value.
   */
  void set(int64_t k, S x) {
    // Move to the leaf.
    k += size;

    // Set the value to the leaf.
    data.at(k) = x;

    // Update value of the element from the leaf to the root.
    for (int64_t i = 1; i <= log; i++) {
      update(k >> i);
    }
  }

  /**
   * @brief Returns the result of applying the binary operator to the interval
   * [l, r).
   *
   * @param l Left end of the given interval.
   * @param r Right end of the given interval. it doesn't not include the right
   * end.
   * @return The result.
   */
  S prod(int64_t l, int64_t r) {
    // When invalid interval was given, return the identity element instead.
    if (l >= r) {
      return e();
    }

    // Move to leaf.
    l += size;
    r += size;

    // Variable to hold the left side result.
    S left_result = e();
    // Variable to hold the right side result.
    S right_result = e();

    // Find all nodes covering the given interval.
    while (l < r) {
      // If l is right child:
      if (l & 1) {
        // Calculate result.
        left_result = op(left_result, data.at(l));
        // Move to elder brother.
        l += 1;
      }

      // If r is right child.
      if (r & 1) {
        // Move to little brother.
        r -= 1;
        // Calculate result.
        right_result = op(right_result, data.at(r));
      }

      // Move to parent.
      l >>= 1;
      r >>= 1;
    }

    // Return the result.
    return op(left_result, right_result);
  }

  /**
   * @brief Returns op(A[0], A[1], ..., A[N - 1]).
   *
   * @return The result.
   */
  S prod_all() { return data.at(1); }
};

int64_t op(int64_t a, int64_t b) { return std::min(a, b); }

int64_t e() { return (1LL << 31) - 1; }

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<std::tuple<int64_t, int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t t, x, y;
    std::cin >> t >> x >> y;
    query.at(i) = std::make_tuple(t, x, y);
  }

  SegmentTree<int64_t, op, e> seg(std::vector<int64_t>(N, (1LL << 31) - 1));
  for (int64_t i = 0; i < Q; i++) {
    auto [t, x, y] = query.at(i);

    if (t == 0) {
      seg.set(x, y);
    } else {
      std::cout << seg.prod(x, y + 1) << std::endl;
    }
  }

  return 0;
}