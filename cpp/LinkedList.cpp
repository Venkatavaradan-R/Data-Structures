#include <iostream>

// void display(LL *);
// node *create_node(int);
// void insert_front(LL *, int);
// void insert_back(LL *, int);
// void destroy(LL *);
// void insert_mid(LL *, int);
// void delete_back(LL *);
// void delete_front(LL *);
// void delete_key(LL *, int);
// void delete_pos(LL *, int);
// int search(LL *, int);
// LL *duplicate(LL *);
/*
sort
merge (into sorted)
*/

using namespace std;

class node
{
public:
  int data;
  struct node *link;
  node(int x = 0, struct node *y = NULL)
  {
    data = x;
    link = y;
  }
};

typedef struct node node;

class LinkedList
{
public:
  int non;
  node *head;

  LinkedList()
  {
    non = 0;
    head = NULL;
  }

  void insert_front(int data)
  {
    node *temp = new node(data);

    if (non == 0)
    {
      head = temp;
      non++;
      return;
    }

    temp->link = head;
    head = temp;
    non++;
    return;
  }
  void display()
  {
    if (non == 0)
    {
      cout << "Empty!";
      return;
    }

    if (non == 1)
    {
      cout << head->data << " " << endl;
      return;
    }

    node *p = head, *q = NULL;

    while (p != NULL)
    {
      cout << p->data << " ";
      p = p->link;
    }
    cout << endl;
  }
};

// node* create_node(int);

typedef struct LinkedList LL;

int main()
{
  LL *list1 = new LL;
  // node *n1 = new node(100);
  // node *n2 = new node(NULL, n1);
  // cout << "node1: " << n1->data << "  " << n1->link << endl;
  // cout << "node2: " << n2->data << "  " << n2->link << endl;

  list1->insert_front(10);
  list1->insert_front(9);
  list1->insert_front(8);
  list1->insert_front(7);
  list1->display();
  // cout << list1->head->link;

  delete list1;
}
