//Scratch implimentation of queue

#include<stdio.h>
#include<stdlib.h>

struct node 
{
  int data;
  struct node *next;
};

struct node *createnode()
{
  int data;
  printf("\nEnter data:");
  scanf("%d",&data);
  
  struct node *cn;
  cn = (struct node *)malloc(sizeof(struct node));
  cn->data = data;
  cn->next = NULL;
  return cn;
}

struct node *head = NULL;
struct node *tail = NULL;

int empty()
{
  return head == NULL;
}

void enqueue()
{
  struct node *eq;
  eq = createnode();
  if(empty())
  {
    head = eq;
    tail = eq;
  }
  else
  {
    tail->next = eq;
    tail = eq;
  }
  printf("\n[~] Succesfully added %d",eq->data);
}

void dequeue()
{
  if(empty())
  {
    printf("\n[!] No data found to delete.");
  }
  else
  {
    struct node *temp;
    int data;
    temp = head;
    head = head->next;
    temp->next = NULL;
    data = temp->data;
    free(temp);
    printf("\n[~] Succesfully deleted %d",data);
  }
}

void front()
{
  printf("Front data is :%d",head->data);
}

void display()
{
  if(empty())
  {
    printf("\n[!] No data found to display.");
    return;
  }
  struct node *d;
  d = head;
  printf("\n[");
  while(d != NULL)
  {
    printf("%d ",d->data);
    d=d->next;
  }
  printf("\b]");
}

int main()
{
  int ch;
  while(1)
  {
    printf("\n== QUEUE ==");
    printf("\n\n1. Enqueue.");
    printf("\n2. Dequeue.");
    printf("\n3. Front.");
    printf("\n4. Display.");
    printf("\n5. Exit.");
    printf("\n\nEnter your choice:");
    scanf("%d",&ch);
    
    switch(ch)
    {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        front();
        break;
      case 4:
        display();
        break;
      case 5:
        exit(1);
      default:
        printf("\nInvaild input!!!");
    }
  }
  return 0;
}