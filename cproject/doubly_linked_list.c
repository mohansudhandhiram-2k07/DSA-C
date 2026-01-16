#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node* create_list();
struct node* insert_node(struct node *head);
struct node* get_new_node(int value); 
int get_data();
void print_node(struct node* head);
struct node * del_node(struct node *head);
int node_length(struct node *head);
struct node* search(struct node* head,int value);
void modify_linked_list(struct node* head);
void create_loop(struct node* head);
void floyd_cycle(struct node* head);

int main()
{
    struct node* head = NULL;
    int choice;
    
    printf("\n--- DOUBLY LINKED LIST PROGRAM ---\n");

    while(1)
    {
        
        printf("\n\n***************************\n");
        printf("1. Create New List \n");
        printf("2. Insert Node at Specific Position\n");
        printf("3. Delete Node at specific position\n");
        printf("4. Display linked List\n");
        printf("5. Get Length\n");
        printf("6. Search\n");
        printf("7. modify linked list\n");
        printf("8. create loop to test floyd logic\n");
        printf("9. check for loop\n");
        printf("10. Exit\n");
        printf("***************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                
                if(head != NULL) 
                    printf("List already exists!\n");
                else 
                    head = create_list();
                break;

            case 2:
                head = insert_node(head);
                break;

            case 3:
                head = del_node(head);
                break;

            case 4:
                print_node(head);
                break;
            
            case 5:
                printf("\nCurrent Length: %d\n", node_length(head));
                break;
            case 6:
                int val;
                printf("Enter value to search: ");
                scanf("%d", &val);
                struct node* result = search(head, val);
    
                if(result != NULL) 
                {
                    printf("Data found at address: %p\n", (void*)result);
                } 
                else 
                {
                    printf("Data not found.\n");
                }   
                break;



            case 7:
                modify_linked_list(head);
                break;

            case 8:
                create_loop(head);
                break;


            case 9:
                floyd_cycle(head);
                break;

            case 10:
                printf("Exiting... \n");
                exit(0); 
                break;

            default:
                printf("Invalid Choice! Try 1-6.\n");
        }
    }
    return 0;
}


struct node* get_new_node(int value) {
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
struct node* create_list()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int choice = 1;
    
    do {
        
        int val = get_data();
        struct node *newnode = get_new_node(val);

        if(head == NULL) {
            head = newnode;
            temp = head;
        } 
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        
        printf(" DO YOU WANT TO ADD ANOTHER NODE? (0/1): ");
        scanf("%d", &choice);
    } while(choice);
    
    return head;
}


struct node* insert_node(struct node *head)
{
    int pos;
    printf("\nWHERE DO YOU WANT TO INSERT THE NODE (Position): ");
    scanf("%d", &pos);
    if(pos<0 || pos>node_length(head))
    {
        printf("!!INVALID POSITION!!");
        return head;
    }
    printf("ENTER DATA FOR NEW NODE: ");
    int val;
    scanf("%d", &val);
    struct node *newnode = get_new_node(val); 
    if(pos == 1) 
    {
        newnode->next = head;
        if(head != NULL) 
        {
            head->prev = newnode;
        }
        head = newnode; 
        return head;    
    }

    struct node* temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++) 
    {
        temp = temp->next;
    }
    if(temp == NULL) 
    {
        printf("INVALID POSITION!\n");
        return head;
    }
    newnode->next = temp->next; 
    newnode->prev = temp;       
    
    if(temp->next != NULL) 
    {    
        temp->next->prev = newnode;
    }
    temp->next = newnode;       

    return head;
}

int get_data()
{
    int data;
    printf("ENTER DATA: ");
    scanf("%d", &data);
    return data;
}

void print_node(struct node* head)
{
    struct node* temp = head;
    int i = 1;
    printf("\nList: NULL <-> ");
    while(temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
        i++;
    }
    printf("NULL\n");
}

struct node * del_node(struct node *head)
{
    struct node * temp = head;
    int pos;
    printf("\nENTER THE NODE YOU WANT TO DELETE: ");
    scanf("%d",&pos);
    if(pos< 1 || pos> node_length(head) )
    {
        printf("!!INVALID POSITION!!");
        return head;
    }
    if(pos==1)
    {
        if(head!=NULL)
        {
            head = head->next;
            if(head!=NULL)
            {
                head->prev = NULL;
            }
        }
        free(temp);
    }
    else
    {
        for(int i=1;i<pos-1;i++)
        {
            temp = temp->next;
        }
        struct node * to_del = temp->next;
        if(to_del!=NULL)
        {
            struct node * connec_node = to_del->next;
            temp->next = connec_node;
            if(connec_node!=NULL)
            {
                connec_node->prev = temp;
            }
        }
    free(to_del);
    }
    return head;
     

}

int node_length(struct node *head)
{
    int i = 0;
    struct node *temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        i++;
    }
    return i;
}

struct node *search(struct node* head, int value)
{
    if(head != NULL)
    {
        
        
        struct node*temp = head;
        do
        {
            if(temp->data == value)
            {
                
                return temp;
            }
            temp = temp->next;

        }while(temp != NULL);
        
        return NULL;
    }
    else
    {
        printf("NO LINKED LIST FOUND!\nPRESS '1' TO CREATE A LINKED LIST");
    }
    return 0;
}

void modify_linked_list(struct node* head)
{
    if(head == NULL)
    {
        printf("NO LINKED LIST FOUND.\n CREATE ONE!");
        return;
    }
    int old_data,new_data;
    printf("\nENTER DATA TO BE CHANGED(old): ");
    scanf("%d",&old_data);
    struct node* add_old_data = search(head,old_data);
    if(add_old_data == NULL)
    {
        printf("\nDATA NOT FOUND!");
        return;
    }
    printf("\nENTER DATA (new): ");
    scanf("%d",&new_data);
    add_old_data->data = new_data;
    printf("MODIFICATION SUCCESFUL!!");
}

void create_loop(struct node* head)
{
    if(head==NULL)
    {
        printf("NO LINKED LIST FOUND!");
        return;
    }
    if(head->next == NULL)
    {
        printf("ONLY ONE NODE FOUND!");
        return;
    }
    int len = node_length(head);
    int random_position = (rand()%len)+1;
    struct node* loop_start = head;
    for(int i=1;i<random_position;i++)
    {
        loop_start = loop_start->next;

    }
    struct node* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = loop_start;
    printf("LOOP IS CREATED!!\nDO NOT PRINT/DISPLAY ");
}

void floyd_cycle(struct node* head)
{
    struct node* fast = head;
    struct node* slow = head;
    while(fast != NULL && fast->next !=NULL)
        {
            
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                slow = head;
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;

                }
                printf("loop detected at: %d ",fast->data);
                return;
            }

        }
    printf("NO LOOP DETECTED!");
    return;    

}