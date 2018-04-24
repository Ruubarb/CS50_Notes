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

    //creates nodes for head, tmp, content
    node* head = NULL;
    node* tmp = NULL;
    node* content = NULL;

    head->next = content; //head node points to content

    for (int i = 1; i <= 10; i++)
    {
        content = malloc(sizeof(node)); //creates new node
        content->value = i; //node value is i
        tmp->next = content; //tmp node points to content node
        tmp = tmp->next; //tmp node b
        content->next = NULL; //content node points to null

        printf("%i ", content->value); //see node value
    }

    while (head != NULL)
    {
        node* temp = head;
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