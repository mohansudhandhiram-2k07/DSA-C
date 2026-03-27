#include<stdio.h>
#include"stdlib.h"

typedef struct node
{
    int vertex;
    struct node* next;

}node;

node *create_node(int data)
{
    node *newnode = ( node*)malloc(sizeof( node));
    newnode->next = NULL;
    newnode->vertex = data;
    return newnode;
}

void addEdge(node *adj[], int src, int dest)
{
    node *newnode = create_node(dest);
    newnode->next = adj[src];
    adj[src] = newnode;

    newnode = create_node(src);
    newnode->next = adj[dest];
    adj[dest] = newnode;
}

void dfs_recursion(node *arr[],int visited[],int current)
{
    visited[current] = 1;
    printf("%d ",current);

    node *temp = arr[current];
    while(temp != NULL)
    {
        int n = temp->vertex;
        if(visited[n] == 0)
        {
            dfs_recursion(arr,visited,n);

        }
        temp = temp->next;
    }


}

void stack_dfs(node *arr[],int visited[],int start)
{
    int stack[7];
    int top = -1;
    stack[++top] = start;
    while(top >= 0)
    {
        int curr = stack[top--];
        if(visited[curr] == 0)
        {
            visited[curr] = 1;
            printf("%d ",curr);
        }
        node *list = arr[curr];
        while(list != NULL)
        {
            int n = list->vertex;
            if(visited[n] == 0)
            {
                stack[++top] = n;
            }
            
            list = list->next;
        }
    }

}

void bfs(node *arr[],int *visited,int start)
{
    int rear = 0,front = 0, queue[7];
    visited[start] = 1;
    queue[front++] = start;
    while(rear < front)
    {
        int curr = queue[rear++];
        printf("%d ", curr);

        node *list = arr[curr];
        while(list != NULL)
        {
            int n = list->vertex;

            if(visited[n] == 0)
            {
                visited[n] = 1;
                queue[front++] = n;
            }

            list = list->next;
        }
    }
}

int main()
{
    node *arr[7];
    int visited[7] = {0};
    for(int i = 0;i < 7;i++) arr[i] = NULL;
    addEdge(arr, 1, 2); 
    addEdge(arr, 1, 3); 
    addEdge(arr, 2, 0); 
    addEdge(arr, 3, 4);
    addEdge(arr, 3, 6);
    printf("using: recursion\n");
    dfs_recursion(arr,visited,0);
    printf("\n");
    printf("using: stack\n");
    int visit[7] = {0};
    stack_dfs(arr,visit,0);
    printf("\n");
    int visi[7] = {0};
    printf("bfs: \n");
    bfs(arr,visi,0);

}
