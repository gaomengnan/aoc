// Given the root of a binary tree, your task is to find the maximum depth of
// the tree. Note: The maximum depth or height of the tree is the number of
// edges in the tree from the root to the deepest node.
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = NULL;
  }
};

class Solution {
public:
  int height(Node *root) {
    if (root == nullptr) {
      return -1;
    }
    queue<pair<int, Node *>> qs;
    // set<int> s;
    qs.push({0, root});

    int maxLevel = 0;
    while (!qs.empty()) {
      auto [level, cur] = qs.front();
      maxLevel = max(maxLevel, level);
      if (cur->left) {
        qs.push({
            level + 1,
            cur->left,
        });
      }
      if (cur->right) {
        qs.push({
            level + 1,
            cur->right,
        });
      }
      qs.pop();
    }
    return s.size() - 1;
  }
};

int main() {
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->right->right = new Node(5);

  Solution solution;
  std::cout << "Height: " << solution.height(root) << std::endl;
  return 0;
}
