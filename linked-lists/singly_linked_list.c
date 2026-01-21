// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
}

struct node* create_list();
struct node* create_node();
int get_data();
void print_node();
struct node* insert_node();
struct node* del_node();


int main()
{
    struct node* head;
    head = create_list();

}

struct node* create_list()
{
    struct node* head = NULL;
    struct node* temp = NULL;
    int choice;
    do
    {
        struct node* new_node = create_node(head);
        if(head == NULL)
        {
            head = new_node;
            temp = head;
        }
        else
        {
            temp->next = new_node;
            temp = temp->next;
        }
        printf("\nDO YOU WANT TO ADD ANOTHER NODE: (0/1)");
        scanf("%d",&choice);
    
    }while(choice);

    return head;
}

struct node* create_node()
{
    struct node* new_node = (struct node)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = get_data();
    return new_node;
    
}

int get_data()
{
    int data;
    printf("ENTER THE DATA FOR NODE");
    scanf("%d",&data);
    return data;
}