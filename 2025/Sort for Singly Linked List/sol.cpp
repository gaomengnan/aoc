#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
class Solution {
public:
  Node *insertionSort(struct Node *head_ref) {
    vector<int> mat;

    while (head_ref) {
      mat.push_back(head_ref->data);
      head_ref = head_ref->next;
    }
    sort(mat.begin(), mat.end());

    struct Node *head = NULL;

    for (int i = 0; i < mat.size(); i++) {
      struct Node *newNode = new Node(mat[i]);
      if (head == NULL) {
        head = newNode;
      } else {
        struct Node *temp = head;
        while (temp->next) {
          temp = temp->next;
        }
        temp->next = newNode;
      }
    }
    return head;
  }
};

int main() {
  Solution sol;

  return 0;
}
