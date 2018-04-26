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
        content = malloc(sizeof(head));
        content->value = i;
        content->next = head;
        head = content;
        while (content->next != NULL)
        {
            printf("%i ", content->value);
            content = content->next;
        }
    }
    printf("\n");

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    /*
    node* head = NULL;
    head = malloc(sizeof(node));

    node* cursor = malloc(sizeof(node));

    head->next = cursor; //head node points cursor


    cursor->value = 2;
    cursor->next = NULL;
    cursor->value = 4;
    cursor->next = NULL;
    cursor->value = 6;
    cursor->next = NULL;

    //creating cursor1 node and while loop allows us to traverse list until reaching final value
    node* cursor1 = head;
    while (cursor1->next != NULL)
    {
        cursor1 = cursor1->next;
        printf("%i\n", cursor1->value);
    }


    for (int i = 1; i <= 10; i++)
    {
        cursor->value = i;
        cursor->next = NULL;
        printf("%i\n", cursor->value);
    }
    */


    return 0;
}