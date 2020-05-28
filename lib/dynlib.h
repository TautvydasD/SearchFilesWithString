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

extern void push(char *x);

extern bool isEmpty();
extern int length();

#endif