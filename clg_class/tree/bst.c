#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left,*right;
};

void display_inorder(struct tree *root);
struct tree* create_node(int data);
struct tree *create_tree(struct tree *root,int data);
void display_preorder(struct tree *root);
void display_post_order(struct tree *root);

int main()
{   struct tree *root = NULL;

    root = create_tree(root ,33);
    root = create_tree(root ,22);
    root = create_tree(root ,44);
    display_inorder(root);
    printf("\n");
    display_preorder(root);
    display_post_order(root);

    return 0;
}

struct tree* create_node(int data)
{
    struct tree* newnode = (struct tree*)malloc(sizeof(struct tree));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct tree *create_tree(struct tree *root,int data)
{
    if(root == NULL)
    {
        return create_node(data);
    }
    if(data<root->data)
    {
        root->left = create_tree(root->left,data);
    }
    else
    {
        root->right = create_tree(root->right,data);
    }
    return root;

}

void display_inorder(struct tree *root)
{
    if(root == NULL)
    {
        return;
    }
    display_inorder(root->left);
    printf("%d ",root->data);
    display_inorder(root->right);
    
    return;
}

void display_preorder(struct tree *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ",root->data);
    display_preorder(root->left);
    display_preorder(root->right);
    
    return;
}
 void display_post_order(struct tree *root)
 {
    if(root==NULL)
    {
        return;
    }
    display_post_order(root->left);
    display_post_order(root->right);
    printf("%d ",root->data);
 }