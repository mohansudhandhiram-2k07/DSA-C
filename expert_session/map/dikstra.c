#include<stdio.h>
#include"stdlib.h"
#include"stdbool.h"
#include"limits.h"
#define SIZE 5

typedef struct node
{
    int vertex;
    int weights;
    struct node* next;
    
}node;

node *create_node(int data,int weight)
{
    node *newnode = (node*)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->vertex = data;
    newnode->weights = weight;
    return newnode;
}

void addEdge(node *adj[], int src, int dest,int weight)
{
    node *newnode = create_node(dest,weight);
    newnode->next = adj[src];
    
    adj[src] = newnode; 
    
    newnode = create_node(src,weight);
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
    int stack[SIZE];
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
    int rear = 0,front = 0, queue[SIZE];
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

void diji(node* arr[],int src)
{
    bool visited[SIZE];
    int dis[SIZE];
    for(int i = 0;i<SIZE;i++)
    {
        visited[i] = false;
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
    for(int i =0 ;i<SIZE;i++)
    {
        int min = INT_MAX,u = -1;
        for(int i = 0;i<SIZE;i++)
        {
            if(visited[i] == false && dis[i] <= min)
            {
                min = dis[i];
                u = i;
            }
        }
        if(u == -1) break;
        visited[u] = true;
        node * temp = arr[u];
        while(temp != NULL)
        {
            int v = temp->vertex, w = temp->weights;
            if(visited[v] == false && dis[u] != INT_MAX && dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
            }
            temp = temp->next;
        }
    } 
    printf("Vertex \t Distance from Source %d\n", src);
    for (int i = 0; i < SIZE; i++) {
        printf("%d \t\t %d\n", i, dis[i]);
    }
    
}

int main()
{
    node *arr[SIZE];
    int visited[SIZE] = {0};
    for(int i = 0;i < SIZE;i++) arr[i] = NULL;
    addEdge(arr, 0, 1, 3); 
    addEdge(arr, 0, 2, 1); 
    addEdge(arr, 1, 3, 1); 
    addEdge(arr, 1, 4, 1);
    addEdge(arr, 2, 3, 3);
    addEdge(arr, 3, 4, 3);
    addEdge(arr, 1, 3, 1);
    printf("using: recursion\n");
    dfs_recursion(arr,visited,1);
    printf("\n");
    printf("using: stack\n");
    int visit[SIZE] = {0};
    stack_dfs(arr,visit,1);
    printf("\n");
    int visi[SIZE] = {0};
    printf("bfs: \n");
    bfs(arr,visi,0);
    printf("\n");
    diji(arr,1);
    
}
