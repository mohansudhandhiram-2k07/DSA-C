#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 6

typedef enum{
    success = 0,
     full ,
     empty
}status;



typedef struct 
{
    int items[MAX];
    int top;
}stack;
status push(stack *s,int data);
status display(stack *s);
status initialize_stack(stack *s);
bool is_empty(stack *s);
bool is_full(stack *s);
status peek(stack *s);
status pop(stack *s);

int main()
{
    stack stack1;
    initialize_stack(&stack1);
    int choice, data;
    
    while(1)
    {
        printf("--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                if(push(&stack1, data) == success)
                    printf("Pushed successfully\n");
                else
                    printf("Stack is full\n");
                break;
                
            case 2:
                if(pop(&stack1) == success)
                    printf("Popped successfully\n");
                else
                    printf("Stack is empty\n");
                break;
                
            case 3:
                if(peek(&stack1) == empty)
                    printf("Stack is empty\n");
                else
                    printf("\n");
                break;
                
            case 4:
                if(display(&stack1) == empty)
                    printf("Stack is empty\n");
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

status initialize_stack(stack *s)
{
    s->top = -1;
    return success;
}

status push(stack *s,int data)
{
    if(is_full(s))
    {
        return full;
    }
    s->top++;
    s->items[s->top] = data;
    return success;
}
status display(stack *s)
{
    
    if(is_empty(s))
    {
        return empty;
    }
    for (int i = s->top; i >= 0; i--) 
    {
        printf("%d\n", s->items[i]);
    }
    return success;
}

status pop(stack *s)
{
    if(is_empty(s))
    {
        return empty;
    }
    (s->top)--;
    return success;

}

bool is_empty(stack *s) 
{
    return s->top == -1;
}

bool is_full(stack *s) 
{
    return s->top == MAX - 1;
}

status peek(stack *s)
{
    if(is_empty(s))
    {
        return empty;
    }
    printf("%d",s->items[s->top]);
    return success;
}