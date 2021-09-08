#include <iostream>
#include <vector>
#include <memory>

template <class T>
class BinarySearchTree {
  private:
    /* Implementation of node of binary-search tree */
    class BinarySearchTreeElement {
      public:
        T key;
        std::shared_ptr<BinarySearchTreeElement> parent;
        std::shared_ptr<BinarySearchTreeElement> left;
        std::shared_ptr<BinarySearchTreeElement> right;

        BinarySearchTreeElement (T key,
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

    /* Recursive function for preorder explore */
    void preorder_explore(std::vector<T>& order, std::shared_ptr<BinarySearchTreeElement> node) {
      if (node == nullptr) return;
      order.push_back(node->key);
      preorder_explore(order, node->left);
      preorder_explore(order, node->right);
    }

    /* Recursive function for inorder explore */
    void inorder_explorer(std::vector<T>& order, std::shared_ptr<BinarySearchTreeElement> node) {
      if (node == nullptr) return;
      inorder_explorer(order, node->left);
      order.push_back(node->key);
      inorder_explorer(order, node->right);
    }

  public:
    /* The root node of tree */
    std::shared_ptr<BinarySearchTreeElement> root;

    /* Default Constructor */
    BinarySearchTree() {
      this->root = nullptr;
    }

    /* Constructor */
    BinarySearchTree(T key) {
      this->root = std::make_shared<BinarySearchTreeElement>(key);
    }

    /* Determine if the key is in the tree.
     * The function returns a shared-pointer to the node with the key.
     * If the key doesn't exist in the tree, it returns nullptr.
     */
    std::shared_ptr<BinarySearchTreeElement> find(T key) {
      std::shared_ptr<BinarySearchTreeElement> x = this->root;
      while (x != nullptr && x->key != key) {
        if (key < x->key) x = x->left;
        else x = x->right;
      }

      return x;
    }

    /* Insert the key into the tree. */
    void insert(T key) {
      /* Node to insert into the tree*/
      std::shared_ptr<BinarySearchTreeElement> insert_node = std::make_shared<BinarySearchTreeElement>(key);
      /* The node we are currently watching in the search */
      std::shared_ptr<BinarySearchTreeElement> current_node = this->root;
      /* The node visited before in the search. this node will be the parent of the node to be inserted. */
      std::shared_ptr<BinarySearchTreeElement> previous_node = nullptr;

      /* Find a place to insert */
      while (current_node != nullptr) {
        previous_node = current_node;
        if (key < current_node->key) current_node = current_node->left;
        else current_node = current_node->right;
      }

      /* When the tree was empty before inserting the node */
      if (previous_node == nullptr) {
        this->root = insert_node;
      } else {
        /* Register the property of the inserted node */
        insert_node->parent = previous_node;
        /* Update the property of the parent node */
        if (key < insert_node->parent->key) insert_node->parent->left = insert_node;
        else insert_node->parent->right = insert_node;
      }
    }

    void erase(T key) {
      /* Node to be deleted */
      std::shared_ptr<BinarySearchTreeElement> x = this->find(key);
      /* Do nothing if a non-existent key is specified. */
      if (x == nullptr) return;

      /* If the node to be deleted has no child */
      if (x->left == nullptr && x->right == nullptr) {
        /* When x is the root of tree, delete the root. */
        if (x->parent == nullptr) {
          this->root = nullptr;
        } else {
          /* When x is the "left child", delete left node of the parent of x. */
          if (x->parent->left == x) x->parent->left = nullptr;
          /* Whe x is the "right child", delete right node of the parent of x. */
          else x->parent->right = nullptr;
        }
        x.reset();
        return;
      }

      /* If the node to be deleted has two child */
      /* Instead of deleting x, delete the inorder-successor of x */
      if (x->left != nullptr && x->right != nullptr) {
        /* Find inorder-successor of x */
        std::shared_ptr<BinarySearchTreeElement> successor = x->right;
        while (successor->left != nullptr) successor = successor->left;

        /* Override the key of x with the key of the successor of x. */
        x->key = successor->key;
        /* Delete successor of x */
        if (successor->right != nullptr) {
          successor->parent->left = successor->right;
          successor->right->parent = successor->parent;
        } else {
          if (successor->parent == x) x->right = nullptr;
          else successor->parent->left = nullptr;
        }
        successor.reset();
        return;
      }

      /* If the node to be deleted has only left child */
      if (x->left != nullptr) {
        if (x->parent->left == x) x->parent->left = x->left;
        else x->parent->right = x->left;
        x->left->parent = x->parent;
        x.reset();
        return;
      }

      /* If the node to be deleted has only right child */
      if (x->right != nullptr) {
        if (x->parent->left == x) x->parent->left = x->right;
        else x->parent->right = x->right;
        x->right->parent = x->parent;
        x.reset();
        return;
      }
    }

    /* Get the order of preorder explore */
    std::vector<T> get_preorder() {
      std::vector<T> order;

      this->preorder_explore(order, this->root);

      return order;
    }

    /* Get the order of inorder explore */
    std::vector<T> get_inorder() {
      std::vector<T> order;

      this->inorder_explorer(order, this->root);

      return order;
    }
};

int main() {
  int64_t N;
  std::cin >> N;

  BinarySearchTree<int64_t> tree;

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
      if (tree.find(value) != nullptr) std::cout << "yes" << std::endl;
      else std::cout << "no" << std::endl;
    } else if (command == "delete") {
      tree.erase(value);
    } else if (command == "print") {
      auto inorder = tree.get_inorder();
      for (auto p : inorder) std::cout << " " << p;
      std::cout << std::endl;

      auto preorder = tree.get_preorder();
      for (auto p : preorder) std::cout << " " << p;
      std::cout << std::endl;
    }
  }
}
