#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define CAP 4

int queue[CAP];
int size = 0;
int front = 0;
int rare = -1;

int front_element()
{
  return queue[front];
}

void push(int data)
{
  if(size == CAP)
  {
    printf("\n\a[!] Queue is Full..");
    return;
  }
  rare = (rare+1)%CAP;
  queue[rare] = data;
  size++;
  if(rare == 0)
  {
    front = 0;
  }
  printf("\n[~] %d successfully pushed.",data);
}

int pop()
{
  int data;
  if(size == 0)
  {
    printf("\n\a[!] Empty queue.");
    return 0;
  }
  data = front_element();
  front = (front+1)%CAP;
  size--;
  return data;
}

int search(int data)
{
  int i;
  for(i=0;i<CAP;i++)
  {
    if(queue[i] == data)
    {
      return i+1;
    }
  }
  return -1;
}

int main()
{
  int i,ch,ele,idx;
  while(1)
  {
    printf("\n===Cirlular Queue===");
    printf("\n1. Push.");
    printf("\n2. Pop");
    printf("\n3. Search");
    printf("\n4. Display all.");
    printf("\n5. Exit.");
    printf("\n---------------------");
    printf("\n (>>) Choose option :");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        printf("\n{>>} Enter Element:");
        scanf("%d",&ele);
        push(ele);
        break;
      case 2:
        ele = pop();
        if(ele != 0)
        {
          printf("\n[~] %d successfully poped.",ele);
        }
        break;
      case 3:
        printf("\n{>>} Enter searched element:");
        scanf("%d",&ele);
        idx=search(ele);
        if(idx != -1)
        {
          printf("\n[@] %d is founded at %d position.",ele,idx);
        }
        else
        {
          printf("[!!] Cannot found %d at queue.",ele);
        }
        break;
      case 4:
        printf("\nAll elements of queue are : ");
        for(i=0;i<size;i++)
        {
          printf("%d ",queue[i]);
        }
        break;
      case 5:
        exit(1);
      default:
        printf("\n\a[!] Invaild input..");
    }
  }
  return 0;
}