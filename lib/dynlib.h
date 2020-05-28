#ifndef dynlibH
#define dynlibH

#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    char *data;
    struct Node *next;
};

struct Node *head;
struct Node *current;

int count;

extern void printList();

void push(char *x);

// struct node* deleteFirst();
bool isEmpty();
int length();

#endif