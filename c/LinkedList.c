#include <stdio.h>
#include <stdlib.h>

//?structs
struct node
{
    int data;
    struct node *link;
};

typedef struct node node;

struct LinkedList
{
    int non;
    struct node *head;
};

typedef struct LinkedList LL;

//?prototypes
void display(LL *);
node *create_node(int);
void insert_front(LL *, int);
void insert_back(LL *, int);
void destroy(LL *);
void insert_mid(LL *, int);

//!main
int main()
{

    LL *list1 = malloc(sizeof(LL));
    list1->head = NULL;
    list1->non = 0;

    insert_front(list1, 10);
    insert_front(list1, 9);
    insert_front(list1, 8);
    insert_back(list1, 11);
    insert_back(list1, 12);
    insert_back(list1, 13);

    insert_mid(list1, 4);
    insert_mid(list1, 1);
    insert_mid(list1, 6);
    insert_mid(list1, 3);
    insert_mid(list1, 12);

    display(list1);

    destroy(list1);
    free(list1);
}

//? fn defs

void display(LL *list)
{
    printf("List Length:\t%d\n", list->non);

    if (list->head == NULL)
    {
        printf("Empty!");
        return;
    }
    node *p = list->head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->link;
    }
}

node *create_node(int data)
{
    node *temp = malloc(sizeof(node));
    temp->link = NULL;
    temp->data = data;
    return temp;
}

void insert_front(LL *list, int data)
{

    node *temp = create_node(data);
    temp->link = list->head;
    list->head = temp;
    list->non++;
}

void insert_back(LL *list, int data)
{
    node *temp = create_node(data);

    node *p = list->head;
    while (p->link != NULL)
    {
        p = p->link;
    }

    p->link = temp;
    list->non++;
}

void insert_mid(LL *list, int data)
{

    if (list->non == 0)
    {
        insert_front(list, data);
        return;
    }

    if (list->non == 1)
    {
        if (list->head->data > data)
        {
            insert_front(list, data);
            return;
        }
        else
        {
            insert_back(list, data);
            return;
        }
    }

    node *p = list->head->link, *q = list->head;

    if (data < q->data)
    {
        insert_front(list, data);
        return;
    }

    node *temp = create_node(data);

    while (temp->data > p->data && p != NULL)
    {

        printf("HELLO!!!!!!\n");

        q = p;
        p = p->link;
    }

    q->link = temp;
    temp->link = p;
    list->non++;
}

void destroy(LL *list)
{
    if (list->non == 0)
        return;
    node *p = list->head->link, *q = list->head;
    while (p != NULL)
    {
        free(q);
        q = p;
        p = p->link;
    }
    free(q);
}