#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define V 5
struct node{
	int vertex;
	struct node * next;
};

struct node* create_node(int d){
	struct node* nnp=(struct node *)malloc(sizeof(struct node));
	nnp->vertex=d;
	nnp->next=NULL;
	return nnp;
}
void addedge(struct node * adj[],int src,int dest){
	struct node * nnp=create_node(dest);
	nnp->next=adj[src];
	adj[src]=nnp;
}

void display(struct node *head){
	while(head){
		printf("%d -> ",head->vertex);
		head=head->next;
	}
	printf("NULL\n");
}

#define MAX 20
struct queue{
	int item[V];
	int front;
	int rear;
}q;

void enqueue(struct queue * q,int d){
	if(q->front==-1){
		(q->front)++;
	}
	q->item[++(q->rear)]=d;
	
	
}
void initialize_queue(struct queue * q){
	q->front =-1;
	q->rear=-1;
}

int dequeue(struct queue *q){
	int data=q->item[q->front];
	if(q->front==q->rear){
		q->front=-1;
		q->rear=-1;
	}
	else{
	
	q->item[q->front]=0;
	q->front+=1;
}
	return data;
}
int isempty(struct queue* q){
	return q->front==-1;
}



void topological_sort(struct node * adj[]){
	int indegree[V]={0},curr;
	struct node* temp;
	initialize_queue(&q);
	for(int i=0;i<V;i++){
		temp=adj[i];
		while(temp){
			indegree[temp->vertex]++;
			temp=temp->next;
		}
		}
		
		for(int i=0;i<V;i++){
			if(indegree[i]==0){
				enqueue(&q,i);
			}
		}
		while(!isempty(&q)){
			curr=dequeue(&q);
			printf("%d  ",curr);
			temp=adj[curr];
			while(temp){
				indegree[temp->vertex]--;
				if(indegree[temp->vertex]==0){
					enqueue(&q,temp->vertex);
				}
				temp=temp->next;
			}
		}
	
}
int main(){
	struct node* adj[V];
	for(int i=0;i<V;i++){
		adj[i]=NULL;
	}
	addedge(adj,0,1);
	addedge(adj,0,3);
	addedge(adj,1,4);
	addedge(adj,1,2);
	addedge(adj,3,1);
	addedge(adj,3,4);
	for(int i=0;i<V;i++)
	{
		printf("[%d] ===>  ",i);
		display(adj[i]);
	}
	printf("\n\n");
	topological_sort(adj);
}