#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

class BinarySearchTreeElement {
  public:
    int64_t key;
    std::shared_ptr<BinarySearchTreeElement> parent;
    std::shared_ptr<BinarySearchTreeElement> left;
    std::shared_ptr<BinarySearchTreeElement> right;

    BinarySearchTreeElement (int64_t key,
      std::shared_ptr<BinarySearchTreeElement> parent = nullptr,
      std::shared_ptr<BinarySearchTreeElement> left = nullptr,
      std::shared_ptr<BinarySearchTreeElement> right = nullptr)
      : key(key)
    {
      this->parent = std::move(parent);
      this->left = std::move(left);
      this->right = std::move(right);
    }
};

/*
 * Implement of Binary Search Tree
 * This class holds a single binary search tree, and handles the insertion, search, and deletion operations.
 * In fact, this class holds only the root of the tree.
 */
class BinarySearchTree {
  public:
    std::shared_ptr<BinarySearchTreeElement> root;

    BinarySearchTree() {
      this->root = nullptr;
    }
    BinarySearchTree (int64_t key) {
      this->root = std::make_shared<BinarySearchTreeElement>(key);
    }

    /* Insert the key into the tree. */
    void insert(int64_t key) {
      std::shared_ptr<BinarySearchTreeElement> x = this->root;
      std::shared_ptr<BinarySearchTreeElement> y = nullptr;
      std::shared_ptr<BinarySearchTreeElement> z = std::make_shared<BinarySearchTreeElement>(key);

      while (x != nullptr) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
      }

      z->parent = y;
      if (y == nullptr) {
        this->root = z;
      } else {
        if (z->key < y->key) {
          y->left = z;
        } else {
          y->right = z;
        }
      }
    }

    /* Determine if the key is in the tree.
     * The function returns a shared-pointer to the node with the key.
     * If the key doesn't exist in the tree, if returns nullptr.
     */
    std::shared_ptr<BinarySearchTreeElement> find(int64_t key) {
      std::shared_ptr<BinarySearchTreeElement> x = this->root;
      while (x != nullptr && x->key != key) {
        if (key < x->key)x = x->left;
        else x = x->right;
      }

      return x;
    }

    void erase(int64_t key) {
      std::shared_ptr<BinarySearchTreeElement> x = this->find(key);
      if (x != nullptr) {
        std::shared_ptr<BinarySearchTreeElement> target;
        std::shared_ptr<BinarySearchTreeElement> target_child;

        if (x->left == nullptr || x->right == nullptr) target = x;
        else target = this->get_successor(x);

        if (target->left != nullptr) target_child = target->left;
        else target_child = target->right;

        if (target_child != nullptr) target_child->parent = target->parent;

        if (target->parent == nullptr) {
          this->root = target_child;
        } else {
          if (target == target->parent->left) {
            target->parent->left = target_child;
          } else {
            target->parent->right = target_child;
          }
        }

        if (target != x) x->key = target->key;

        target.reset();
      }
    }

  private:
    std::shared_ptr<BinarySearchTreeElement> get_minimum(std::shared_ptr<BinarySearchTreeElement> x) {
      while (x->left != nullptr) {
        x = x->left;
      }
      return x;
    }

    std::shared_ptr<BinarySearchTreeElement> get_successor(std::shared_ptr<BinarySearchTreeElement> x) {
      if (x->right != nullptr) {
        return get_minimum(x->right);
      }

      std::shared_ptr<BinarySearchTreeElement> y = x->parent;
      while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
      }
      return y;
    }
};

void preorder_explore(std::vector<int64_t>& order,
    std::shared_ptr<BinarySearchTreeElement> node)
{
  if (node == nullptr) return;
  order.push_back(node->key);

  preorder_explore(order, node->left);
  preorder_explore(order, node->right);
}

void inorder_explore(std::vector<int64_t>& order,
    std::shared_ptr<BinarySearchTreeElement> node)
{
  if (node == nullptr) return;
  inorder_explore(order, node->left);
  order.push_back(node->key);
  inorder_explore(order, node->right);
}

int main() {
  int64_t N;
  std::cin >> N;

  BinarySearchTree tree;

  std::vector<std::pair<std::string, int64_t>> query(N);
  for (int64_t i = 0; i < N; i++) {
    std::string command;
    std::cin >> command;

    if (command == "print") {
      query.at(i) = std::make_pair(command, 0);
    } else {
      int64_t value;
      std::cin >> value;
      query.at(i) = std::make_pair(command, value);
    }

  }

  for (int64_t i = 0; i < N; i++) {
    std::string command = query.at(i).first;
    int64_t value = query.at(i).second;

    if (command == "insert") {
      tree.insert(value);
    } else if (command == "find") {
      if (tree.find(value) == nullptr) std::cout << "no" << std::endl;
      else std::cout << "yes" << std::endl;
    } else if (command == "delete"){
      tree.erase(value);
    } else if (command == "print") {
      std::vector<int64_t> inorder;
      inorder_explore(inorder, tree.root);

      for (size_t j = 0; j < inorder.size(); j++) {
        std::cout << " " << inorder.at(j);
      }
      std::cout << std::endl;

      std::vector<int64_t> preorder;
      preorder_explore(preorder, tree.root);

      for (size_t j = 0; j < preorder.size(); j++) {
        std::cout << " " << preorder.at(j);
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
