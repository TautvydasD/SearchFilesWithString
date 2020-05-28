#include "dynlib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Node *head = NULL;
struct Node *current = NULL;

int count = 0;

void printList() 
{
    struct Node *ptr = head;

    while(ptr != NULL) 
    {
        printf("%s\n",ptr->data);
        ptr = ptr->next;
    }
}


void push(char * x)
{
    struct Node *t, *temp;

    t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    count++;

    if (head == NULL)
    {
        head = t;
        head->next = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = t;
    t->next   = NULL;
}
//delete first item
// struct Node* deleteFirst()
// {
//     //save reference to first link
//     struct Node *tempLink = head;

//     //mark next to first link as first 
//     head = head->next;

//     //return the deleted link
//     return tempLink;
// }

//is list empty
bool isEmpty()
{
    return head == NULL;
}

int length()
{
    int length = 0;
    struct Node *current;

    for(current = head; current != NULL; current = current->next)
    {
        length++;
    }

    return length;
}