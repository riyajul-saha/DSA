#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct stack
{
  int top;
  int *array;
};
struct stack *stk;

void push()
{
  int data;
  if(stk->top == MAX-1)
  {
    printf("Stack Overflow !!!");
    return;
  }
  else
  {
    stk->top ++;
    printf("\nEnter data :");
    scanf("%d",&data);
    stk->array[stk->top] = data;
    printf("\n%d Succesfully Pushed.",data);
  }
}

void pop()
{
  int data;
  if(stk->top == -1)
  {
    printf("Stack Underflow !!!");
    return;
  }
  else
  {
    data = stk->array[stk->top];
    stk->top--;
    printf("\n%d Succesfully Deleted.",data);
  }
}

void display()
{
  int i;
  if(stk->top == -1)
  {
    printf("Data not found !");
    return;
  }
  else
  {
    printf("\n[");
    for(i=0;i<=stk->top;i++)
    {
      printf("%d ",stk->array[i]);
    }
    printf("]");
  }
}

int main()
{
  int ch;
  stk = (struct stack *)malloc(sizeof(struct stack));
  stk->top = -1;
  stk->array = (int *)calloc(MAX,sizeof(int));
  
  printf("\n1. Push");
  printf("\n2. Pop");
  printf("\n3. Display");
  printf("\n4. Exit");
  while(1)
  {
    printf("\n\nEnter your choice :");
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
        printf("\n Wrong input.");
    }
  }
  return 0;
}