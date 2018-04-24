#include <stdio.h>
#include <stdlib.h>



struct node
{
    int data;
    struct node* next;
};
struct node* head;

void insert(int x);
void print();

int main(void)
{
    head = NULL;
    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter the Number \n");
        scanf("%d", &x);
        insert(x);
        print();
    }


    while (head != NULL)
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void insert(int x)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if(head != NULL)
    {
        temp->next = head;
    }
    head = temp;
}

void print()
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}