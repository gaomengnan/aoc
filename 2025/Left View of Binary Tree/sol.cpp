#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Node {
public:
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

class Solution {
public:
  void dfs(Node *root, int level, vector<int> &visited) {
    if (root == nullptr)
      return;
    if (level == visited.size()) {
      visited.push_back(root->data);
    }
    dfs(root->left, level + 1, visited);
    dfs(root->right, level + 1, visited);
  };

public:
  vector<int> leftView(Node *root) {
    vector<int> visited;
    dfs(root, 0, visited);
    return visited;
  };
};

int main() {
  Solution sol;
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->right = new Node(6);
  vector<int> result = sol.leftView(root);
  for (int val : result) {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
