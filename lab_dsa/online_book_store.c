#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
    int id,stock;
    char title[50],author[50];
    float price;
    struct tree *left, *right;

    
}tree;

void display_inorder(struct tree *root);
tree* create_node(int data, int stock,  char *title,  char *author, float price);
tree* create_tree(struct tree *root, int data, int stock,  char *title,  char *author, float price);

int main()
{
    tree *root = NULL;
    root = create_tree(root, 101, 15, "The C Programming Language", "Dennis Ritchie", 45.00);
    root = create_tree(root, 56, 5, "Embedded Systems", "naveen", 50.50);
    root = create_tree(root, 105, 8, "binary", "kumaar", 40.00);
    root = create_tree(root, 58, 12, "edgw ai", "mohan", 60.00);
    display_inorder(root);
    recommend(root,104);

}


tree* create_tree(struct tree *root, int data, int stock,  char *title,  char *author, float price)
{
    if(root == NULL)
    {
        return create_node(data,stock,title,author,price);
    }
    if(data<root->id)
    {
        root->left = create_tree(root->left,data,stock,title,author,price);
    }
    else
    {
        root->right = create_tree(root->right,data,stock,title,author,price);
    }
    return root;

}

tree* create_node(int data, int stock,  char *title,  char *author, float price)
{
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->id = data;
    strcpy(newnode->title , title);
    strcpy(newnode->author , author);
    newnode->price = price;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->stock = stock;
    return newnode;
}

void display_inorder(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    display_inorder(root->left);
    printf("%d \n",root->id);
    display_inorder(root->right);
    
    return;
}
