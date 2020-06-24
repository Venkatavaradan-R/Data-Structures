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
void delete_back(LL *);
void delete_front(LL *);
void delete_key(LL *, int);
void delete_pos(LL *, int);
int search(LL *, int);
/*
duplicate
sort 
merge (into sorted)
*/

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

    printf("found 6 at pos %d\n", search(list1, 6));
    printf("found 1 at pos %d\n", search(list1, 1));
    printf("found 13 at pos %d\n", search(list1, 13));

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
    printf("\n\n");
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
    p = NULL;

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
        q = p;
        p = p->link;
    }

    q->link = temp;
    temp->link = p;
    p = NULL;
    q = NULL;
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
    p = NULL;
    q = NULL;
}

void delete_back(LL *list)
{
    if (list->non == 0)
        return;
    if (list->non == 1)
    {
        free(list->head);
        list->head = NULL;
        list->non--;
        return;
    }
    node *p = list->head->link, *q = list->head;
    while (p->link != NULL)
    {
        q = p;
        p = p->link;
    }
    free(p);
    q->link = NULL;
    p = NULL;
    q = NULL;
    list->non--;
}

void delete_front(LL *list)
{
    if (list->non == 0)
        return;

    if (list->non == 1)
    {
        delete_back(list);
        return;
    }

    node *p = list->head;
    list->head = list->head->link;
    free(p);
    list->non--;
    p->link = NULL;
}

void delete_key(LL *list, int key)
{
    if (list->non == 0)
        return;
    if (list->non == 1)
    {
        if (list->head->data == key)
            delete_back(list);
        else
            return;
    }

    node *p = list->head->link, *q = list->head;

    if (q->data == key)
    {
        delete_front(list);
        return;
    }

    while (p->data != key && p != NULL)
    {
        q = p;
        p = p->link;
    }
    printf("HELOOOOOOOOOOO!!!\n");

    if (p == NULL)
    {
        printf("key not found in list\n");
        return;
    }
    q->link = p->link;
    free(p);
    q = NULL;
    p = NULL;
    list->non--;
}

void delete_pos(LL *list, int pos)
{
    if (list->non == 0)
    {
        return;
    }

    if (pos == 1)
    {
        delete_front(list);
        return;
    }

    node *p = list->head, *q = NULL;
    int count = 1;
    while (count != pos && p != NULL)
    {
        q = p;
        p = p->link;
        count++;
    }

    if (p == NULL)
    {
        printf("pos %d doesnt exist", pos);
        return;
    }

    q->link = p->link;
    free(p);
    list->non--;
    q = NULL;
    p = NULL;
}

int search(LL *list, int info)
{
    if (list->non == 0)
    {
        return -1;
    }

    node *p = list->head, *q = NULL;
    int count = 1;
    while (p->data != info && p != NULL)
    {
        q = p;
        p = p->link;
        count++;
    }

    if (p == NULL)
    {
        return -1;
    }

    else
        return count;

    p = NULL;
    q = NULL;
}