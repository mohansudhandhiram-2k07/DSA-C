// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void print_node();
void create_node();
int get_data(int n);
struct node{
    int data;
    struct node* next;
}*head;

int main() {
    
    int choice;
    create_node();

    return 0;
}

void create_node()
{
    int choice;
    struct node *newnode,*temp;
    head = NULL;
    int n=1;
    do
    {
        
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = get_data(n);
        newnode->next = NULL;
        n++;
        if(head == NULL)
        
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            temp->next = head;
        }
        printf("ADD ANOTHER NODE? (0/1): ");
        scanf("%d",&choice);
        
        
    }while(choice);
    print_node();
    printf("lol\n");
}
int get_data(int n)
{
    int data;
    printf("ENTER DATA FOR %d:  ",n);
    scanf("%d",&data);
    return data;
}
void print_node()
{
    int i=1;
    struct node* temp = head;
    do
    {
        printf("data at the node %d is %d \n",i,temp->data);
        temp = temp->next;
        i++;
    }while (temp!=head);
}


