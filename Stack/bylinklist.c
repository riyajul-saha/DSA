#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
struct node *create_node()
{
  struct node *cn;
  cn = (struct node *)malloc(sizeof(struct node));
  printf("Enter data:");
  scanf("%d",&cn->data);
  cn->next = 0;
  return cn;
}

struct node *peek=0;

void push()
{
  struct node *p;
  p = create_node();
  if(peek == 0)
  {
    peek = p;
  }
  else
  {
    p->next = peek;
    peek = p;
  }
  printf("\n[*] %d succesfully pushed at stack.",peek->data);
}

void pop()
{
  if(peek == 0)
  {
    printf("[!] Stack downflow ! No element found to pop.");
    return;
  }
  struct node *p;
  p = peek;
  peek = peek->next;
  p->next = 0;
  printf("[*] %d succesfully popped",p->data);
  free(p);
}

void display()
{
  if(peek==0)
  {
    printf("\n[!] No element found to delete.");
    return;
  }
  struct node *d;
  d=peek;
  printf("\n[~] Stack elements are :[");
  while(d !=0)
  {
    printf("%d ",d->data);
    d = d->next;
  }
  printf("\b]");
}

int main()
{
  int ch;
  while(1)
  {
    printf("\n\n\n");
    printf("1. Push.\n");
    printf("2. Pop.\n");
    printf("3. Display.\n");
    printf("4. Exit.\n");
    printf("\n>>Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        push();
        break;
      case 2:
        pop();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
      default:
        printf("Invaild input");
      
    } 
      
  }
  return 0;
}