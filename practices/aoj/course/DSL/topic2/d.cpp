#include <cassert>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

template <class S, S op(S, S), S e(), class F, S mapping(F, S),
          F composition(F, F), F id()>
class LazySegmentTree {
 private:
  int64_t N;
  int64_t log;
  int64_t size;
  std::vector<S> data;
  std::vector<F> lazy;

  int64_t get_log(int64_t n) {
    int64_t x = 0;
    while ((1 << x) < n) {
      ++x;
    }

    return x;
  }

  void reflect(int64_t k, F f) {
    data.at(k) = mapping(f, data.at(k));

    if (k < size) {
      lazy.at(k) = composition(f, lazy.at(k));
    }
  }

  void propagate(int64_t k) {
    reflect(2 * k, lazy.at(k));
    reflect(2 * k + 1, lazy.at(k));

    lazy.at(k) = id();
  }

  void update(int64_t k) {
    data.at(k) = op(data.at(2 * k), data.at(2 * k + 1));
  }

 public:
  explicit LazySegmentTree(std::vector<S> A)
      : N(static_cast<int64_t>(A.size())),
        log(get_log(N)),
        size(1 << log),
        data(2 * size, e()),
        lazy(size, id()) {
    for (int64_t i = 0; i < N; i++) {
      data.at(i + size) = A.at(i);
    }

    for (int64_t i = size - 1; i > 0; i--) {
      update(i);
    }
  }

  void set(int64_t k, S x) {
    k += size;

    for (int64_t i = log; i > 0; i--) {
      propagate(k >> i);
    }

    for (int64_t i = 1; i <= log; i++) {
      update(k >> i);
    }
  }

  S get(int64_t k) {
    k += size;
    for (int64_t i = log; i > 0; i--) {
      propagate(k >> i);
    }

    return data.at(k);
  }

  S prod(int64_t l, int64_t r) {
    if (l >= r) {
      return e();
    }

    l += size;
    r += size;

    S left_result = e();
    S right_result = e();

    for (int64_t i = log; i > 0; i--) {
      if (((l >> i) << i) != l) {
        propagate(l >> i);
      }

      if (((r >> i) << i) != r) {
        propagate((r - 1) >> i);
      }
    }

    while (l < r) {
      if (l & 1) {
        left_result = op(left_result, data.at(l));
        l += 1;
      }

      if (r & 1) {
        r -= 1;
        right_result = op(right_result, data.at(r));
      }

      l >>= 1;
      r >>= 1;
    }

    return op(left_result, right_result);
  }

  S prod_all() { return data.at(1); }

  void apply(int64_t k, F f) {
    k += size;

    for (int64_t i = log; i > 0; i--) {
      propagate(k >> i);
    }

    data.at(k) = mapping(f, data.at(k));

    for (int64_t i = 1; i <= log; i++) {
      update(k >> i);
    }
  }

  void apply(int64_t l, int64_t r, F f) {
    if (l >= r) {
      return;
    }

    l += size;
    r += size;

    for (int64_t i = log; i > 0; i--) {
      if (((l >> i) << i) != l) {
        propagate(l >> i);
      }

      if (((r >> i) << i) != r) {
        propagate((r - 1) >> i);
      }
    }

    {
      int64_t left = l;
      int64_t right = r;

      while (left < right) {
        if (left & 1) {
          reflect(left, f);
          left += 1;
        }

        if (right & 1) {
          right -= 1;
          reflect(right, f);
        }

        left >>= 1;
        right >>= 1;
      }
    }

    for (int64_t i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) {
        update(l >> i);
      }

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
      int64_t k;
      std::cin >> k;
      query.at(i) = std::make_tuple(c, k, -1, -1);
    }
  }

  LazySegmentTree<int64_t, op, e, int64_t, mapping, composition, id> seg(
      std::vector<int64_t>(N, (1LL << 31) - 1));

  for (auto q : query) {
    int64_t c = std::get<0>(q);

    if (c == 0) {
      auto [_1, s, t, x] = q;

      seg.apply(s, t + 1, x);
    } else {
      auto [_1, i, _2, _3] = q;

      std::cout << seg.get(i) << std::endl;
    }
  }
}