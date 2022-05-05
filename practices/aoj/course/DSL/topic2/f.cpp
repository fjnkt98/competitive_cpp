#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

/**
 * @brief Class implementation of non-recursive and abstracted segment tree with
 * lazy propagation.
 *
 * @tparam S Type of the element of segment tree.
 * @tparam op(S, S) A function representing the binary operator.
 * @tparam e() A function which returns identity element.
 * @tparam F Type of the operator.
 * @tparam mapping(F, S) A function representing the mapping. This takes the
 * operator f and target element s.
 * @tparam composition(F, F) A function representing the composition of maps.
 * This takes two operator, and returns composited operator.
 * @tparam id() A function returns identity mapping.
 */
template <class S, S op(S, S), S e(), class F, S mapping(F, S),
          F composition(F, F), F id()>
class LazySegmentTree {
 private:
  // Number of the element managed by segment tree.
  int64_t N;
  // The logarithm of size of the segment tree base 2.
  int64_t log;
  // Size of the vector that representing binary tree object.
  int64_t size;
  // A vector of the entities representing segment tree (1-indexed).
  std::vector<S> data;
  // A vector for lazy propagation. lazy[k] holds the operation performed in the
  // segment corresponding to the data[k] which haven't yet been applied to the
  // nodes below the data[k].
  std::vector<F> lazy;

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
   * @brief Reflect the operation on the node.
   *
   * @param k The index of the node(0-indexed).
   * @param f The operator.
   */
  void reflect(int64_t k, F f) {
    // Reflect the operator on the node.
    data.at(k) = mapping(f, data.at(k));

    // When k is not leaf:
    if (k < size) {
      // Combine the operator f with lazy[k].
      lazy.at(k) = composition(f, lazy.at(k));
    }
  }

  /**
   * @brief Propagate pending operator lazy[k] to each child, and reset lazy[k].
   *
   * @param k The index of the node(0-indexed).
   */
  void propagate(int64_t k) {
    // Propagate the operator to left child.
    reflect(2 * k, lazy.at(k));
    // Propagate the operator to right child.
    reflect(2 * k + 1, lazy.at(k));

    // Reset lazy[k].
    lazy.at(k) = id();
  }

  /**
   * @brief Update value of the element with the value of the child node.
   *
   * @param k The index of the node(0-indexed).
   */
  void update(int64_t k) {
    data.at(k) = op(data.at(2 * k), data.at(2 * k + 1));
  }

 public:
  /**
   * @brief Construct a new Lazy Segment Tree object
   *
   * @param A The vector of the initial value of the leaves.
   */
  explicit LazySegmentTree(std::vector<S> A)
      : N(static_cast<int64_t>(A.size())),
        log(get_log(N)),
        size(1 << log),
        data(2 * size, e()),
        lazy(size, id()) {
    // Initialize the value of leaves with given vector.
    for (int64_t i = 0; i < N; i++) {
      data.at(i + size) = A.at(i);
    }

    // Update all nodes (not leaf).
    for (int64_t i = size - 1; i > 0; i--) {
      update(i);
    }
  }

  /**
   * @brief Set x into the specified leaf.
   *
   * @param k The index of the node (0-indexed).
   * @param x The value.
   */
  void set(int64_t k, S x) {
    // Move to leaf.
    k += size;

    // Propagate pending operator form the root to the leaf.
    for (int64_t i = log; i > 0; i--) {
      propagate(k >> i);
    }

    // Update value of the element from the leaf to the root.
    for (int64_t i = 1; i <= log; i++) {
      update(k >> i);
    }
  }

  /**
   * @brief Get the value of the specified leaf.
   *
   * @param k The index of the node (0-indexed).
   * @return S The value.
   */
  S get(int64_t k) {
    // Move to leaf.
    k += size;

    // Propagate pending operator from the root to the leaf.
    for (int64_t i = log; i > 0; i--) {
      propagate(k >> i);
    }

    // Return the value.
    return data.at(k);
  }

  /**
   * @brief Calculate the result of applying the binary operator to the interval
   * [l, r).
   *
   * @param l Left end of the given interval.
   * @param r Right end of the given interval. It doesn't include the right end.
   * @return S The result.
   */
  S prod(int64_t l, int64_t r) {
    // WHen invalid interval was given:
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

    // Propagate pending operator from the root to the leaf.
    // for calculate the production.
    for (int64_t i = log; i > 0; i--) {
      // In the subtree containing the l, when the l is the leftmost node, don't
      // have to propagate. Because the root of the subtree has all information
      // of l.
      if (((l >> i) << i) != l) {
        propagate(l >> i);
      }

      // Same to above.
      if (((r >> i) << i) != r) {
        propagate((r - 1) >> i);
      }
    }

    // Find all nodes covering the given interval.
    while (l < r) {
      // If l is right child:
      if (l & 1) {
        // Calculate result.
        left_result = op(left_result, data.at(l));
        // Move to elder brother.
        l += 1;
      }

      // If r is right child:
      if (r & 1) {
        // Move to little brother
        r -= 1;
        // Calculate result.
        right_result = op(right_result, data.at(r));
      }

      // Move to each parent.
      l >>= 1;
      r >>= 1;
    }

    // Return the result.
    return op(left_result, right_result);
  }

  /**
   * @brief Get the result of applying the binary operator to entire interval.
   *
   * @return The result.
   */
  S prod_all() { return data.at(1); }

  /**
   * @brief Apply the mapping to the single leaf with specified index.
   *
   * @param k The index of the node (0-indexed).
   * @param f The operator to apply.
   */
  void apply(int64_t k, F f) {
    // Move to leaf.
    k += size;

    // Propagate pending operator from the root to the leaf.
    for (int64_t i = log; i > 0; i--) {
      propagate(k >> i);
    }

    // Apply the mapping to the specified leaf.
    data.at(k) = mapping(f, data.at(k));

    // Update ancestors.
    for (int64_t i = 1; i <= log; i++) {
      update(k >> i);
    }
  }

  /**
   * @brief Apply the mapping to each leaves of the specified interval [l, r).
   *
   * @param l Left end of the given interval.
   * @param r Right end of the given interval.
   * @param f The operator to be acted on the leabes.
   */
  void apply(int64_t l, int64_t r, F f) {
    // WHen invalid interval was given:
    if (l >= r) {
      return;
    }

    // Move to leaf.
    l += size;
    r += size;

    // Propagate pending operator from the root to the leaf.
    // for calculate the production.
    for (int64_t i = log; i > 0; i--) {
      // In the subtree containing the l, when the l is the leftmost node, don't
      // have to propagate. Because the root of the subtree has all information
      // of l.
      if (((l >> i) << i) != l) {
        propagate(l >> i);
      }

      // Same to above.
      if (((r >> i) << i) != r) {
        propagate((r - 1) >> i);
      }
    }

    {
      // Copy the variable for temporary calculation.
      int64_t left = l;
      int64_t right = r;

      // Find all nodes covering the given interval, and apply the mapping to
      // them.
      while (left < right) {
        // If left is right child.
        if (left & 1) {
          // Apply the mapping.
          reflect(left, f);
          // Move to elder brother.
          left += 1;
        }

        // If right is right child.
        if (right & 1) {
          // Move to little brother.
          right -= 1;
          // Apply the mapping.
          reflect(right, f);
        }

        // Move to each parent.
        left >>= 1;
        right >>= 1;
      }
    }

    // Update value of the ancestors.
    for (int64_t i = 1; i <= log; i++) {
      // In the subtree containing the l, when the l is the leftmost node, don't
      // have to propagate. Because the root of the subtree has all information
      // of l.
      if (((l >> i) << i) != l) {
        update(l >> i);
      }

      // Same to above.
      if (((r >> i) << i) != r) {
        update(r >> i);
      }
    }
  }
};

int64_t op(int64_t a, int64_t b) { return std::min(a, b); }

int64_t e() { return (1LL << 31) - 1; }

int64_t mapping(int64_t f, int64_t s) {
  if (f == -1) {
    return s;
  } else {
    return f;
  }
}

int64_t composition(int64_t f, int64_t g) {
  if (f == -1) {
    return g;
  } else {
    return f;
  }
}

int64_t id() { return -1; }

int main() {
  int64_t N, Q;
  std::cin >> N >> Q;
  std::vector<std::tuple<int64_t, int64_t, int64_t, int64_t>> query(Q);
  for (int64_t i = 0; i < Q; i++) {
    int64_t c;
    std::cin >> c;
    if (c == 0) {
      int64_t s, t, x;
      std::cin >> s >> t >> x;
      query.at(i) = std::make_tuple(c, s, t, x);
    } else {
      int64_t s, t;
      std::cin >> s >> t;
      query.at(i) = std::make_tuple(c, s, t, -1);
    }
  }

  LazySegmentTree<int64_t, op, e, int64_t, mapping, composition, id> seg(
      std::vector<int64_t>(N, (1LL << 31) - 1));

  for (auto q : query) {
    auto [c, s, t, x] = q;

    if (c == 0) {
      seg.apply(s, t + 1, x);
    } else {
      std::cout << seg.prod(s, t + 1) << std::endl;
    }
  }

  return 0;
}