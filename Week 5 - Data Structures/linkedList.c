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

    //int i;

    content = malloc(sizeof(node));
    content->value = 1;
    content->next = NULL;
    head = content;
    printf("%i\n", content->value);

    content = malloc(sizeof(node));
    content->value = 2;
    content->next = content;
    head = content;
    printf("%i\n", content->value);

    content = malloc(sizeof(node));
    content->value = 3;
    content->next = content;
    head = content;
    printf("%i\n", content->value);

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}