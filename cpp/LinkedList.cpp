#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

struct LinkedList
{
    int non;
    node *head;
};

typedef struct LinkedList LL;

int main()
{
    LL list1 = new LL;
    list1->non = 100;
    cout << list1->non << endl;
}