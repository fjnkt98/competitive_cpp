#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <tuple>

class Treap {
  private:
    /* Implementation of node of binary-search tree */
    class TreapElement {
      public:
        int64_t key;
        int64_t priority;
        std::shared_ptr<TreapElement> parent;
        std::shared_ptr<TreapElement> left;
        std::shared_ptr<TreapElement> right;

        TreapElement (int64_t k, int64_t p,
            std::shared_ptr<TreapElement> parent = nullptr,
            std::shared_ptr<TreapElement> left = nullptr,
            std::shared_ptr<TreapElement> right = nullptr)
          : key(k), priority(p)
        {
          this->parent = std::move(parent);
          this->left = std::move(left);
          this->right = std::move(right);
        }
    };

    /* Recursive function for preorder explore */
    void preorder_explore(std::vector<int64_t>& order, std::shared_ptr<TreapElement> node) {
      if (node == nullptr) return;
      order.push_back(node->key);
      preorder_explore(order, node->left);
      preorder_explore(order, node->right);
    }

    /* Recursive function for inorder explore */
    void inorder_explorer(std::vector<int64_t>& order, std::shared_ptr<TreapElement> node) {
      if (node == nullptr) return;
      inorder_explorer(order, node->left);
      order.push_back(node->key);
      inorder_explorer(order, node->right);
    }

  public:
    /* The root node of tree */
    std::shared_ptr<TreapElement> root;

    /* Default Constructor */
    Treap() {
      this->root = nullptr;
    }

    /* Constructor */
    Treap(int64_t key, int64_t priority) {
      this->root = std::make_shared<TreapElement>(key, priority);
    }

    /* Determine if the key is in the tree.
     * The function returns a shared-pointer to the node with the key.
     * If the key doesn't exist in the tree, it returns nullptr.
     */
    std::shared_ptr<TreapElement> find(int64_t key) {
      std::shared_ptr<TreapElement> x = this->root;
      while (x != nullptr && x->key != key) {
        if (key < x->key) x = x->left;
        else x = x->right;
      }

      return x;
    }

    /* Insert the key into the tree. */
    std::shared_ptr<TreapElement> insert(std::shared_ptr<TreapElement> t, int64_t key, int64_t priority) {
      if (t == nullptr) {
        return std::make_shared<TreapElement>(key, priority);
      }
      if (key == t->key) {
        return t;
      }

      if (key < t->key) {
        t->left = insert(t->left, key, priority);
        if (t->priority < t->left->priority) {
          t = rotate_right(t);
        }
      } else {
        t->right = insert(t->right, key, priority);
        if (t->priority < t->right->priority) {
          t = rotate_left(t);
        }
      }

      return t;
    }

    void insert(int64_t key, int64_t priority) {
      this->root = insert(this->root, key, priority);
    }

    std::shared_ptr<TreapElement> erase(std::shared_ptr<TreapElement> t, int64_t key) {
      if (t == nullptr) return nullptr;
      if (key < t->key) {
        t->left = erase(t->left, key);
      } else if (key > t->key) {
        t->right = erase(t->right, key);
      } else {
        return erase_node(t, key);
      }

      return t;
    }

    std::shared_ptr<TreapElement> erase_node (std::shared_ptr<TreapElement> t, int64_t key) {
      if (t->left == nullptr && t->right == nullptr) {
        return nullptr;
      } else if (t->left == nullptr) {
        t = rotate_left(t);
      } else if (t->right == nullptr) {
        t = rotate_right(t);
      } else {
        if (t->left->priority > t->right->priority) {
          t = rotate_right(t);
        } else {
          t = rotate_left(t);
        }
      }

      return erase(t, key);
    }

    void erase(int64_t key) {
      this->root = erase(this->root, key);
    }

    /* Rotate tree in the right*/
    std::shared_ptr<TreapElement> rotate_right(std::shared_ptr<TreapElement> t) {
      std::shared_ptr<TreapElement> s = t->left;
      t->left = s->right;
      s->right = t;

      return s;
    }

    /* Rotate tree in the left */
    std::shared_ptr<TreapElement>  rotate_left(std::shared_ptr<TreapElement> t) {
      std::shared_ptr<TreapElement> s = t->right;
      t->right = s->left;
      s->left = t;

      return s;
    }

    /* Get the order of preorder explore */
    std::vector<int64_t> get_preorder() {
      std::vector<int64_t> order;

      this->preorder_explore(order, this->root);

      return order;
    }

    /* Get the order of inorder explore */
    std::vector<int64_t> get_inorder() {
      std::vector<int64_t> order;

      this->inorder_explorer(order, this->root);

      return order;
    }
};

int main() {
  int64_t N;
  std::cin >> N;

  Treap tree;

  std::vector<std::tuple<std::string, int64_t, int64_t>> query(N);
  for (int64_t i = 0; i < N; i++) {
    std::string command;
    std::cin >> command;

    if (command == "print") {
      query.at(i) = std::make_tuple(command, 0, 0);
    } else if (command == "insert") {
      int64_t key;
      int64_t priority;
      std::cin >> key >> priority;
      query.at(i) = std::make_tuple(command, key, priority);
    } else {
      int64_t key;
      std::cin >> key;
      query.at(i) = std::make_tuple(command, key, 0);
    }

  }

  for (int64_t i = 0; i < N; i++) {
    std::string command = std::get<0>(query.at(i));
    int64_t key = std::get<1>(query.at(i));
    int64_t priority = std::get<2>(query.at(i));

    if (command == "insert") {
      tree.insert(key, priority);
    } else if (command == "find") {
      if (tree.find(key) == nullptr) std::cout << "no" << std::endl;
      else std::cout << "yes" << std::endl;
    } else if (command == "delete"){
      tree.erase(key);
    } else if (command == "print") {
      std::vector<int64_t> inorder = tree.get_inorder();

      for (size_t j = 0; j < inorder.size(); j++) {
        std::cout << " " << inorder.at(j);
      }
      std::cout << std::endl;

      std::vector<int64_t> preorder = tree.get_preorder();

      for (size_t j = 0; j < preorder.size(); j++) {
        std::cout << " " << preorder.at(j);
      }
      std::cout << std::endl;
    }
  }
}
