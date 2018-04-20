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
    head = malloc(sizeof(node));
    head->value = 1;
    head->next = NULL;

    while (head != NULL)
    {
        node* temp = head;
        head = head->next;
        free(temp);
    }

    /*
    node* head = malloc(sizeof(node));
    node* second = malloc(sizeof(node));
    node* third = malloc(sizeof(node));

    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = NULL;

    printf("%d\n", second->value);



    node* cursor = malloc(sizeof(node));
    cursor->value = 1;

    while(cursor != NULL)
    {
        printf("%d\n", cursor->value);
        cursor->value = cursor->value+1;
        cursor = cursor->next;
    }
    */

    return 0;
}