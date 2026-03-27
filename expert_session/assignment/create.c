#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node * create_node()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = 0;
    return newnode;
}



int main()
{
    struct node *head = create_node();
    head->next = create_node();
    printf("%d",head->data);
    printf("%d",head->next->data);
}

