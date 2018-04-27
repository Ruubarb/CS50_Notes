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

    for (i = 1; i <= 10; i++)
    {
        content = malloc(sizeof(node));
        content->value = i;
        head = content;
        content->next = head;
    }
    printf("\n");

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}