#include <iostream>
using namespace std;
class Node {
public:
  int data;
  Node *next;
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

void insertAtHead(
    Node *&head,
    int data) { // Sending as reference cause we don't want to make another
                // copy. We want to change in main Linked List
  Node *temp = new Node(data);

  temp->next = head;
  head = temp;
}

void insertAtTail(Node *&tail, int data) {
  Node *temp = new Node(data);

  tail->next = temp;
  tail = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position) {
  if (position == 1) {
    insertAtHead(head, data);
    return;
  }
  position -= 2; // Initially at position 1
  Node *temp = head;
  Node *newNode = new Node(data);
  while (position--)
    temp = temp->next;
  // Insert at end
  if (temp->next == NULL) {
    insertAtTail(tail, data);
    return;
  }

  // Inserting at any position
  newNode->next = temp->next;
  temp->next = newNode;
}

void printLL(Node *&head) {
  Node *cur = head;
  while (cur) {
    cout << cur->data << " ";
    cur = cur->next;
  }
  cout << endl;
}

int main() {
  Node *node1 = new Node(5);
  Node *head = node1;
  Node *tail = node1;

  printLL(head);

  insertAtHead(head, 10);
  printLL(head);

  insertAtTail(tail, 15);
  printLL(head);

  insertAtPosition(head, tail, 20, 2);
  printLL(head);
}
