#include <iostream>

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
    LinkedList() : return

    // LinkedList():
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