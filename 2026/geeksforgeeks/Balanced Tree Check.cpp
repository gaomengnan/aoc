#include <vector>
using namespace std;
class Node {
public:
  int data;
  Node *left;
  Node *right;

  // Constructor to initialize a new node
  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class Solution {
public:
  int checkBalance(Node *node) {
    if (node == NULL) {
      return 0;
    }

    int leftHeight = checkBalance(node->left);
    if (leftHeight == -1) {
      return -1;
    }

    int rightHeight = checkBalance(node->right);

    if (rightHeight == -1) {
      return -1;
    }


    if (abs(leftHeight - rightHeight) > 1) {
      return false;
    }

    return max(leftHeight, rightHeight) + 1;
  };

public:
  bool isBalanced(Node *root) {
    return checkBalance(root) != -1;
  }
};

int main() {
  Solution sol;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->left->left->left = new Node(6);

  if (sol.isBalanced(root)) {
    printf("The tree is balanced.\n");
  } else {
    printf("The tree is not balanced.\n");
  }

  return 0;
}
