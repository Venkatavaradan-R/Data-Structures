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
  void insert_back(int data)
  {
    if (non == 0)
    {
      insert_front(data);
      return;
    }

    node *temp = new node(data);

    if (non == 1)
    {
      head->link = temp;
      non++;
      return;
    }

    node *p = head;

    while (p->link != NULL)
    {
      p = p->link;
    }

    p->link = temp;
    non++;
  }

  void insert_mid(int data)
  {
    if (non == 0)
    {
      insert_front(data);
      return;
    }

    if (non == 1)
    {
      if (data > head->data)
      {
        insert_back(data);
        return;
      }
      insert_front(data);
      return;
    }

    if (head->data > data)
    {
      insert_front(data);
      return;
    }

    node *temp = new node, *p = head, *q = NULL;

    while (p != NULL && data > p->data)
    {
      q = p;
      p = p->link;
    }

    if (p == NULL)
    {
      insert_back(data);
      return;
    }

    q->link = temp;
    temp->link = p;
    non++;
  }
};

// node* create_node(int);

typedef struct LinkedList LL;

int main()
{
  LL *list1 = new LL;
  list1->insert_mid(7);
  list1->insert_mid(4);
  list1->insert_mid(1);
  list1->insert_mid(100);

  list1->display();

  delete list1;
}
