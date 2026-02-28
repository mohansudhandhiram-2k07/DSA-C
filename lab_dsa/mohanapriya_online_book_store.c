#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
   int id;
   char title[50];
   char author[50];
   float price;`
   struct node *left;
   struct node *right;
};
struct node *insert(struct node *root,int id,char *title,char *author,float price);
struct node *create(int id,char *title,char *author,float price);
void inorder(struct node *root);
struct node *search(struct node *root,int id);
void recommend(struct node *root,float price);
int main(){
    struct node *root=NULL;
    root=insert(root,1,"The Mass","SK",400);
    root=insert(root,2,"The Universe","Rk",350);
    root=insert(root,3,"The King of Forest","MS",650);
    root=insert(root,4,"Science without myth","LLM",820);
    root=insert(root,5,"Programming in c","Cormen",900);
    inorder(root);
    int id=2;
    struct node *f=search(root,id);
    if(f){
       printf("Book is found!!!\n");
       printf("ID:%d|Title:%s|Author:%s|Price:%.2f\n",root->id,root->title,root->author,root->price);
    }
    else
       printf("Book is not found\n");
    printf("Recommend books(price<=800):\n");
    recommend(root,800);

}
struct node *create(int id,char *title,char *author,float price){
     struct node *nnp=(struct node *)malloc(sizeof(struct node));
     nnp->id =id;
     strcpy(nnp->title,title);
     strcpy(nnp->author,author);
     nnp->price=price;
     nnp->left=nnp->right=NULL;
     return nnp;
}
struct node *insert(struct node *root,int id,char *title,char *author,float price){
   if (root == NULL)
      return create(id,title,author,price);
   if(id<root->id)
      root->left=insert(root->left,id,title,author,price);
   else
      root->right=insert(root->right,id,title,author,price);
   return root;
}
void inorder(struct node *root){
  if(root==NULL)
    return ;
  inorder(root->left);
  printf("ID:%d|Title:%s|Author:%s|Price:%.2f\n",root->id,root->title,root->author,root->price);
  inorder(root->right);
}
struct node *search(struct node *root,int id){
   if(root == NULL)
      return NULL;
   if(id== root->id){
       return root;
   }
   else if(id<root->id){
      return search(root->left,id);
   }
   else
      return search(root->right,id);
}
void recommend(struct node *root,float price){
      if (root == NULL)
         return;
      recommend(root->left,price);
      if(root->price <= price)
           printf("ID:%d|Title:%s|Author:%s|Price:%.2f\n",root->id,root->title,root->author,root->price);
      recommend(root->right,price);
}