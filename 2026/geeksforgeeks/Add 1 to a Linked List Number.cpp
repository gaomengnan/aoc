// You are given a linked list where each element in the list is a node and have
// an integer data. You need to add 1 to the number formed by concatinating all
// the list node numbers together and return the head of the modified linked
// list.
//
// Note: The head represents the first element of the given array.
// 先反转之后 在进行+1 操作
#include <iostream>
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
  Node *reserve_node(Node *head) {
    Node *prev = NULL;
    Node *current = head;

    while (current != NULL) {
      Node *next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    return prev;
  };

  // Helper function to add 1 to the reversed list
  bool addOneUtil(Node *head) {
    Node *current = head;
    int carry = 1;

    while (current != NULL) {
      int sum = current->data + carry;
      carry = sum / 10;
      current->data = sum % 10;
      current = current->next;
    }
    return carry ? true : false;
  }

public:
  Node *addOne(Node *head) {
    // Reverse the linked list
    Node *reversed = reserve_node(head);

    // Add 1 to the reversed list
    bool carry = addOneUtil(reversed);

    // If there's still a carry, add a new node at the end
    if (carry) {
      Node *newNode = new Node(carry);
      Node *current = reversed;
      while (current->next != NULL) {
        current = current->next;
      }
      current->next = newNode;
    }

    // Reverse again to get the original order
    return reserve_node(reversed);
  }
};

// Helper function to print the linked list
void printList(Node *head) {
  Node *current = head;
  while (current != NULL) {
    cout << current->data;
    if (current->next != NULL) {
      cout << " -> ";
    }
    current = current->next;
  }
  cout << endl;
}

// Helper function to create a linked list from a vector
Node *createList(const vector<int> &arr) {
  if (arr.empty())
    return NULL;

  Node *head = new Node(arr[0]);
  Node *current = head;
  for (size_t i = 1; i < arr.size(); i++) {
    current->next = new Node(arr[i]);
    current = current->next;
  }
  return head;
}

int main() {
  // Test case 1: 123 -> 124
  vector<int> arr1 = {1, 2, 3};
  Node *head1 = createList(arr1);
  cout << "Test 1: ";
  printList(head1);

  Solution sol1;
  head1 = sol1.addOne(head1);
  cout << "After add 1: ";
  printList(head1);
  cout << endl;

  // Test case 2: 999 -> 1000
  vector<int> arr2 = {9, 9, 9};
  Node *head2 = createList(arr2);
  cout << "Test 2: ";
  printList(head2);

  Solution sol2;
  head2 = sol2.addOne(head2);
  cout << "After add 1: ";
  printList(head2);
  cout << endl;

  // Test case 3: 5 -> 6
  vector<int> arr3 = {5};
  Node *head3 = createList(arr3);
  cout << "Test 3: ";
  printList(head3);

  Solution sol3;
  head3 = sol3.addOne(head3);
  cout << "After add 1: ";
  printList(head3);
  cout << endl;

  // Test case 4: 1999 -> 2000
  vector<int> arr4 = {1, 9, 9, 9};
  Node *head4 = createList(arr4);
  cout << "Test 4: ";
  printList(head4);

  Solution sol4;
  head4 = sol4.addOne(head4);
  cout << "After add 1: ";
  printList(head4);
  cout << endl;

  // Test case 5: 0 -> 1
  vector<int> arr5 = {0};
  Node *head5 = createList(arr5);
  cout << "Test 5: ";
  printList(head5);

  Solution sol5;
  head5 = sol5.addOne(head5);
  cout << "After add 1: ";
  printList(head5);

  return 0;
}
