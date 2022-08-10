#include <iostream>
using namespace std;

class Node
{

public:
  int data;
  Node *prev;
  Node *next;

  //constructor
  Node(int d)
  {
    this->data = d;
    this->prev = NULL;
    this->next = NULL;
  }
};

// traversing a linked list
void print(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

// gives length of linked list
int getLength(Node *head)
{
  Node *temp = head;
  int len = 0;
  while (temp != NULL)
  {
    len++;
    temp = temp->next;
  }
  return len;
}

//insertAtHead
void insertAtHead(Node *&head, int d)
{
  Node *temp = new Node(d);
  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    temp->next = head;
    head->prev = temp;
    head = temp;
  }
}

//insertAtTail
void insertAtTail(Node *&tail, int d)
{
  //new node creation
  Node *temp = new Node(d);

  if (tail == NULL)
  {
    tail = temp;
  }
  else
  {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
  // insert at starting
  if (position == 1)
  {
    insertAtHead(head, d);
    return; // ye likhne se nikhe kuchh v nhi chalega
  }

  Node *temp = head;
  int cnt = 1;
  while (cnt < position - 1)
  {
    temp = temp->next;
    cnt++;
  }

  // // the modification required
  // Node *temp2 = temp;
  // temp2 = temp2->next;

  //inserting at Last Position
  if (temp->next == NULL)
  {
    insertAtTail(tail, d);
    return; // ye likhne se nikhe kuchh v nhi chalega
  }

  // (ye wala v chlega bas temp2 ko uncoment kar)
  // // creating a node for d
  // Node *nodeToInsert = new Node(d);
  // nodeToInsert->next = temp2;
  // temp->next = nodeToInsert;
  // nodeToInsert->prev = temp;
  // temp2->prev = nodeToInsert;

  // creating a node for d
  Node *nodeToInsert = new Node(d);

  nodeToInsert->next = temp->next;
  temp->next->prev = nodeToInsert;
  temp->next = nodeToInsert;
  nodeToInsert->prev = temp;
}

int main()
{

  // Node *node1 = new Node(10);
  // Node *head = node1;
  // Node *tail = node1;

  Node *head = NULL;
  Node *tail = NULL;

  print(head);
  // cout << getLength(head)<<endl;

  insertAtHead(head, 11);
  print(head);

  insertAtHead(head, 13);
  print(head);

  insertAtHead(head, 8);
  print(head);

  insertAtTail(tail, 25);
  print(head);

  // insertAtTail(tail, 30);
  // print(head);

  insertAtPosition(tail, head, 2, 100);
  print(head);

  insertAtPosition(tail, head, 1, 101);
  print(head);

  insertAtPosition(tail, head, 8, 102);
  print(head);

  cout << getLength(head) << endl;

  return 0;
}