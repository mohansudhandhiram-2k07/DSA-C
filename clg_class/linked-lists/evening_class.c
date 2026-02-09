#include<stdio.h>
#include<stdlib.h>

struct node{
    int seats;
    struct node *next;
};

void create_coaches(struct node **head,int coaches,int seats);
struct node* get_new_node(int value);
void display(struct node *head);
void insert_coach_at_middle(struct node **head,int seats);

int main()
{
    struct node *head = NULL;
    int choice, coaches, seats;
    
    while(1)
    {
        printf("\n=== COACH MANAGEMENT SYSTEM ===\n");
        printf("1. Create Coaches\n");
        printf("2. Display Coaches\n");
        printf("3. Insert Coach at Middle\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter number of coaches: ");
                scanf("%d", &coaches);
                printf("Enter number of seats per coach: ");
                scanf("%d", &seats);
                create_coaches(&head, coaches, seats);
                printf("Coaches created successfully!\n");
                break;
                
            case 2:
                display(head);
                break;
                
            case 3:
                printf("Enter seats for new coach: ");
                scanf("%d", &seats);
                insert_coach_at_middle(&head, seats);
                printf("Coach inserted at middle!\n");
                break;
                
            case 4:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void create_coaches(struct node **head,int coaches,int seats)
{
    struct node *temp = NULL;
    for(int i = coaches;i>=0;i--)
    {
    struct node *newnode = get_new_node(seats);
    if(*head == NULL)
    {
        *head = newnode;
        temp = *head;
    }
    else
    {
        temp->next = newnode;
        temp = temp->next;
    }
    }

}

struct node* get_new_node(int value)
{
    struct node *newnode = malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("NO MEMORY ALLOCATED!\n");
        return NULL;
    }
    newnode->seats = value;
    newnode->next = NULL;
    return newnode;
}

void display(struct node *head)
{
    if(head == NULL)
    {
        printf("NO COACHES!\n");
        return;
    }
    int i = 1;
    while(head->next != NULL)
    {
        printf("The coach %d has %d number of seats\n",i,head->seats);
        i++;
        head = head->next;
    }
    
}

void insert_coach_at_middle(struct node **head,int seats)
{
    struct node *fast = *head;
    struct node *slow = *head;
   while(fast != NULL && fast->next != NULL)
   {
        slow = slow->next;
        fast = fast->next->next;
   }
   struct node *newnode = get_new_node(seats);
   newnode->next = slow->next;
   slow->next = newnode;

}