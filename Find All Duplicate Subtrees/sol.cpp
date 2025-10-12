#include <algorithm>
#include <iostream>
#include <print>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
  int data;    // 节点存储的值
  Node *left;  // 左子节点指针
  Node *right; // 右子节点指针

  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

unordered_map<string, int> mp;
vector<Node *> res;

class Solution {
public:
  string dfs(Node *root) {
    if (!root)
      return "#";

    string serial =
        to_string(root->data) + "," + dfs(root->left) + "," + dfs(root->right);

    if (++mp[serial] == 2) {
      res.push_back(root);
    }
    return serial;
  };

  vector<Node *> printAllDups(Node *root) {
    mp.clear();
    res.clear();
    dfs(root);
    return res;
  }
};

int main() {
  // 创建一个示例二叉树
  Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(2); // 重复子树的根节点
  root->right->left->left = new Node(4);
  root->right->left->right = new Node(5);

  Solution sol;
  vector<Node *> duplicates = sol.printAllDups(root);

  // 输出重复子树的根节点值
  cout << "Duplicate Subtree Roots: ";
  for (Node *dupRoot : duplicates) {
    cout << dupRoot->data << " ";
  }
  cout << endl;

  // 清理内存（删除树节点）
  // 注意：这里没有实现完整的内存清理代码，实际使用中应确保释放所有分配的内存。
  delete root->left->left;
  delete root->left->right;
  delete root->left;
  delete root->right->left->left;
  delete root->right->left->right;
  delete root->right->left;
  delete root->right;
  delete root;

  return 0;
}
