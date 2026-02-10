#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void push(int data);
struct node * top = NULL;
struct node* create_node(int data);
void display();
void pop();
void peep();


int main()
{
    int choice, data;
    
    while(1)
    {
        printf("\n=== Linked List Stack Menu ===\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peep\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                printf("Pushed %d successfully\n", data);
                break;
                
            case 2:
                pop();
                printf("Popped successfully\n");
                break;
                
            case 3:
                printf("Top element: ");
                peep();
                break;
                
            case 4:
                printf("Stack: ");
                display();
                break;
                
            case 5:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}

void push(int data)
{
    
    struct node *temp = top;
    struct node *newnode = create_node(data);
    if(top == NULL)
    {
        top = temp = newnode;
    }
    else 
    {
        newnode->next = temp;
        top = newnode;
        
    }

}

struct node* create_node(int data)
{
    struct node* new_node = (struct node *)malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
    
}

void display()
{
	struct node *temp = top;
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp = temp->next;
		
	}
	printf("NULL\n");
}

void pop()
{
    if(top == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    struct node *temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
    

}

void peep()
{
    if(top == NULL)
    {
        printf("stack empty\n");
        return;
    }
    printf("%d\n",top->data);
    return;
}