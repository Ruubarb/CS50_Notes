#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    typedef struct node
    {
        int value;
        struct node* next;
    }
    node;

    node* head = NULL;
    node* temp = NULL;
    node* content = NULL;

    int i;

    /*
    code from https://stackoverflow.com/a/50012170/7217977, written by Srini
    */

    for (i = 1; i <= 10; i++)
    {
        if (head == NULL)
        {
            // The list is empty when this condition triigers
            // we initialize the first node and assign head to point to it
            head = (node*)malloc(sizeof(node)); // allocate memory to the pointer. Also make sure the memory pointed to is of a node type
                                                // This is important because it will allow us use -> operator to assign values to the pointed
                                                // at memory
            head -> value = i; // assign the value i to the value field of the pointed to memory
            head -> next = NULL; // assign the next pointer of the pointed to memory to NULL
        }
        else
        {
            // iterate over the list till we reach the end.
            // Once we do, assign more memory at the end, assign the memory a value and make it's next pointer be NULL
            content = head;
            while (content -> next != NULL)
            {
                content = content -> next;
            }
            content -> next = (node*)malloc(sizeof(node));
            content -> next -> value = i;
        }

    }

    while (head != NULL)
    {
        temp = head;
        printf("Node data: %d\n", temp -> value);
        head = head->next;
        free(temp);
    }

    return 0;
}