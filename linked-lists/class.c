#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void create_list(struct node **head,struct node **tail);
struct node *create_node();
int get_data();
void display_list(struct node *head);
void insert_at_pos(struct node **head,struct node **tail);
void delete_at_position(struct node **head, struct node **tail);

int main()
{
    struct node* head = NULL;
    struct node* tail = NULL;

    int choice;
    while(1)
    {
        printf("\n1. Create List\n2. Display List\n3. Insert at Position\n4. Delete at Position\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                create_list(&head, &tail);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                insert_at_pos(&head, &tail);
                break;
            case 4:
                delete_at_position(&head, &tail);
                break;
            case 5:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void create_list(struct node ** head, struct node** tail)
{
    
    struct node *newnode = NULL;
    int choice = 1;
    do
    {
        newnode = create_node();
        if(*head == NULL)
        {
            newnode->prev = (*head);
            *head = newnode;
            *tail = newnode;
            

        }
        else
        {
            newnode->prev = *tail;
            (*tail)->next = newnode;
            *tail = (*tail)->next;
        }
        printf("\nDO YOU WANT TO ADD ANOTHER NODE(0/1): ");
        scanf("%d",&choice);
        
    }while(choice);
    
        
    

}

struct node *create_node()
{

    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("MEMORY FULL!!");
        exit(EXIT_FAILURE);
    }
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = get_data();
    return newnode;

}

int get_data()
{
    int data;
    printf("ENTER DATA FOR NODE: ");
    scanf("%d",&data);
    return data;
}

void display_list(struct node *head)

{
    if(head == NULL)
    {
        printf("NO LINKED LIST FOUND !!\n");
        exit(EXIT_FAILURE);
    }
    printf("NULL<->");
    while(head != NULL)
    {
        printf("%d<->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void insert_at_pos(struct node **head,struct node **tail)
{
    if(*head == NULL)
    {
        printf("NO LINKED LIST FOUND!!\nMAKE ONE!");
        return;
    }
    struct node *newnode;
    struct node *temp = *head;
    int pos;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    if(pos<=0)
    {
        printf("INVALID POSITION!");
        return;
    }
    newnode = create_node();
    if(pos == 1)
    {
        
        newnode->next = temp;
        *head = newnode;
    }
    for(int i=1; i<pos-1;i++)
    {
        if(temp->next == NULL)
        {
                printf("INVALID POSITION!!");
                return;
        }
        temp = temp->next;        
    }
    
    if(temp->next == NULL)
    {
        temp->next = newnode;
        *tail = newnode;
        return;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    temp->next = newnode;
    
    
    

}

void delete_at_position(struct node **head, struct node **tail)
{
    if(*head == NULL)
    {
        printf("NO LINKED LIST FOUND!!\nMAKE ONE!");
        return;
    }
    struct node *temp = *head;
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if(pos<=0)
    {
        printf("INVALID POSITION!");
        return;
    }
    if(pos==1)
    {
        struct node *to_del = *head;
        *head = (*head)->next;
        if(head!=NULL)
        {
            (*head)->prev = NULL;
        }
        free(to_del);
        return;
    }
    for(int i=1; i<pos-1;i++)
    {
        if(temp->next == NULL)
        {
                printf("INVALID POSITION!!");
                return;
        }
        temp = temp->next;        
    }
    if(temp->next->next == NULL)
    {
        struct node *to_del = temp->next;
        temp->next = NULL;
        free(to_del);
        return;
    }
    struct node *to_del = temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    
    free(to_del);

}
