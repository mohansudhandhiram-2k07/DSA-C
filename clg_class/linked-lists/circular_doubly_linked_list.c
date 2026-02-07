#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *get_node();
void create_node(struct node **head);
void display(struct node *head);
void insert_at_position(struct node **head);


int main()
{
    struct node *head = NULL;
    create_node(&head);
    display(head);
    insert_at_position(&head);

}

void create_node(struct node **head)
{
    int choice;
    struct node *newnode = NULL;
    struct node *temp = NULL;
    do
    {
        newnode = get_node();
        if(*head == NULL)
        {
            (*head) = newnode;
            newnode->next = *head;
            newnode->prev = *head;
            temp = *head;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = *head;
            
            temp = temp->next;
        }
        printf("DO YOU WANT TO ADD ANOTHER NODE(0/1): ");
        scanf("%d",&choice);
    }while(choice);
    printf("LINKED LIST CREATED!!\n");
}

void insert_at_position(struct node **head)
{
    struct node *newnode = get_node();
    if(*head == NULL)
    {
        printf("NO LINKED LIST FOUND!!\n");
        return 0;
    }
    



}

struct node *get_node()
{
    int data1;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("no memory allocated!\n");
        return 0;
    }
    printf("ENTER DATA: ");
    scanf("%d",&data1);
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = data1;
    return newnode;

}

void display(struct node *head)
{
    struct node *temp = head;
    do
    {
        printf("%d\n",temp->data);
        temp = temp->next;
    }while(head != temp);
}