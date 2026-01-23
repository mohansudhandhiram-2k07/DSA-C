#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

void insert(struct node** head,struct node** tail);
struct node* node();
int get_data();
void display(struct node* head);
void pos(struct node** head,struct node** tail);
void del(struct node** head,struct node** tail);
void reverse(struct node** head,struct node** tail);

int main()
{
	struct node *head = NULL;
	struct node *tail = NULL;
		insert(&head,&tail);
		display(head);
		reverse(&head,&tail);
		display(head);
		pos(&head,&tail);
		display(head);
		/*del(&head,&tail);
		display(head);*/ 
		return 0;
}

void insert(struct node** head,struct node** tail)
{
	int choice = 1;
	
	struct node * newnode ;
	do
	{
		newnode = node();
		if(*tail == NULL)
		{
			
			*tail = newnode;
			*head = *tail;
		}
		else
		{
			(*tail)->next = newnode;
			*tail = (*tail)->next;
		}
		printf("\ndo you want to add another node?(0/1): ");
		scanf("%d",&choice);
	}while(choice);
	
	
}

struct node* node()
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	newnode->next = NULL;
	newnode->data = get_data();
	return newnode;
}

int get_data()
{
	int data;
	printf("\nENTER DATA FOR NODE: ");
	scanf("%d",&data);
	return data;
}

void display(struct node* head)
{
	
	while(head != NULL)
	{
		printf("%d->",head->data);
		head = head->next;
		
	}
	printf("NULL\n");
}

void pos(struct node** head,struct node** tail)
{
	struct node* temp = *head;
	int pos;
	
	printf("\nenter the position to insert: ");
	scanf("%d",&pos);
	
	if(pos<=0)
	{
		printf("INVALID POSITION!\n");
		exit(EXIT_FAILURE);
	}
	for(int i = 1;i<pos-1;i++)
	{
		
	
		if(temp->next == NULL)
		{
			printf("invalid position\n");
			exit(EXIT_FAILURE);
		}
		temp = temp->next;	
	}
		struct node* newnode = node();
		if(pos == 1)
		{
			newnode->next = *head;
			*head = newnode;
			return;
			
		}
		if(temp->next != NULL)
		{
			newnode->next = temp->next;
		}
		temp->next = newnode;
		if(newnode->next==NULL)
		{
			*tail = newnode;
		}
	
}

void del(struct node** head,struct node** tail)
{
	struct node* temp = *head;
	int pos;
	if(*head == NULL)
	{
		printf("NO LINKED LIST FOUND!\n");
		exit(EXIT_FAILURE);
	}
	printf("\nenter the position to delete: ");
	scanf("%d",&pos);
    if(pos<=0)
	{
		printf("INVALID POSITION!\n");
		exit(EXIT_FAILURE);
	}
	for(int i = 1;i<pos-1;i++)
	{
		
	
		if(temp->next == NULL)
		{
			printf("invalid position\n");
			return;
		}
		temp = temp->next;	
	}
	if(pos == 1)
	{
		temp = temp->next;
		*head = temp;
		return;
	}
	if(temp->next == NULL)
	{
		struct node * A = temp;
		temp = NULL;
		free(A);
		
		return;
	}
	if(temp->next->next == NULL)
	{
		struct node* A = temp->next;
		temp->next = NULL;
		free(A);
		return;
	}
	if(temp->next->next != NULL)
	{
	
		struct node* A = temp->next;
		temp->next = temp->next->next;
		free(A);
	}
	if(temp->next == NULL)
	{
		*tail = temp->next;
	}
	
	
}

void reverse(struct node** head,struct node** tail)
{
	struct node *prev = NULL;
	struct node *nxt = *head;
	struct node *current = *head;
	*tail = *head;

	while(current != NULL)
	{
		nxt = current->next;
		current->next = prev;
		prev = current;
		current = nxt;

	}
	*head = prev;
	


}