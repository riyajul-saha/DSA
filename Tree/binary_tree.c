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

void preorder_traversal(struct node *tree)
{
  if(tree == NULL)
  {
    return;
  }
  printf("%d ",tree->data);
  preorder_traversal(tree->left);
  preorder_traversal(tree->right);
}

void inorder_traversal(struct node *root)
{
  if(root == NULL)
  {
    return;
  }
  inorder_traversal(root->left);
  printf("%d ",root->data);
  inorder_traversal(root->right);
}

void postorder_traversal(struct node *root)
{
  if(root == NULL)
  {
    return;
  }
  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ",root->data);
}

int main()
{
  int preorder[]={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
  struct node *root = buildTree(preorder);
  printf("Check tree building........................\n");
  printf("root->data= %d\n",root->data);
  printf("root->left->data= %d\n",root->left->data);
  printf("root->right->data= %d\n",root->right->data);
  printf("root->right->left->data= %d\n",root->right->left->data);
  printf("root->right->right->data= %d\n",root->right->right->data);
  
  printf("\nCheck preorder tree traversal.................\n");
  preorder_traversal(root);
  
  printf("\nCheck Inorder tree traversal.................\n");
  inorder_traversal(root);

  printf("\nCheck Post order tree traversal.................\n");
  postorder_traversal(root);
  printf("\n");
  return 0;
}