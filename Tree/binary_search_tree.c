#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *create_node(int data)
{
  struct node *ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data = data;
  ptr-> left = NULL;
  ptr-> right = NULL;
  return ptr;
}

static int idx=-1;
struct node *buildTree(int preorder[])
{
  idx++;
  if(preorder[idx] == -1)
  {
    return NULL;
  }
  struct node *root = create_node(preorder[idx]);
  root->left = buildTree(preorder);
  root->right = buildTree(preorder);
  return root;
}

int main()
{
  int preorder[]={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  struct node *root = buildTree(preorder);
  printf("root->data= %d\n",root->data);
  printf("root->left->data= %d\n",root->left->data);
  printf("root->right->data= %d\n",root->right->data);
  printf("root->right->left->data= %d\n",root->right->left->data);
  printf("root->right->right->data= %d\n",root->right->right->data);
  return 0;
}