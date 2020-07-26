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
    // Not needed because of constructor

    // node* create_node(int data)
    // {
    //   node *temp = new node;
    //   temp->data  = data;
    //   temp->link = NULL;
    //   return temp;
    // }
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
      temp = new node(data);

      if (non == 0)
      {
        head = temp;
        non++;
        return;
      }

      if (non==1)
      {
        temp->link = head;
        head = temp;
        non++;
        return;
      }

      // if 


    }
};

// node* create_node(int);

typedef struct LinkedList LL;

int main()
{
    LL *list1 = new LL;
    node *n1 = new node(100);
    node *n2 = new node(NULL, n1);
    cout << "node1: " << n1->data << "  " << n1->link << endl;
    cout << "node2: " << n2->data << "  " << n2->link << endl;

    delete list1;
}
