#include<stdio.h>
#include<stdlib.h>
#define MAX 6

typedef enum{
    success = 0,
     full ,
     empty
}status;

int stack[MAX];
int top = -1;

status push(int data);
status pop();
status peek();
status display();

int main()
{
    
    int choice,add;
    
    while(1) 
    {
        printf("0.exit\n1.create stack\n2.remove from stack\n3.peek at stack\n4.display stack\n");
        scanf("%d",&choice);
        switch(choice)
    {
        case 1:
            
            do
            {
                int data;
                printf("\nENTER DATA TO ADD TO STACK: ");
                scanf("%d",&data);
                
                if(push(data) == full)
                {
                    printf("STACK FULL!!\n");
                    break;
                }
                printf("\n--DATA ADDED!--\n");
                printf("Do you want to add to the stack? (0/1)\n");
                scanf("%d",&add);
            }while(add);
            break;
        case 2:
            
            do
            {
               
                if(pop() == empty)
                {
                    printf("STACK EMPTY!!\n");
                    break;
                }
                printf("\n---Data removed---");
                printf("\nDo you want to delete another data? (0/1)\n");
                scanf("%d",&add);
            }while(add);
            break;
        case 3:
            
            if(peek() == empty)
            {
                printf("STACK EMPTY!!\n");
                break;
            }
            break;
        case 4:
            printf("\n---STACK---\n\n");
            
            if(display() == empty)
            {
                printf("\nSTACK EMPTY!!\n");
                break;
            }
            break;
        case 0:
            return 0;
    }
    }
    return 0;

}

status push(int data)
{
    if(top == MAX-1)
    {
        return full;
    }
    top++;
    stack[top] = data;
    return 0;
}

status display()
{

    if(top == -1)
    {
        return empty;
    }
    for(int i = top;i>=0;i--)
    {
        printf("%d \n",stack[i]);

    }
    return 0;
}
status pop()
{
    if(top == -1)
    {
        return empty;
    }
    top--;
    return 0;
}
status peek()
{
    if(top == -1)
    {
        return empty;
    }
    printf("%d",stack[top]);
    return 0;
}