#include<stdio.h>
#include<stdlib.h>

void linearsearch(int list[],int size)
{
  int ele,i;
  printf("Enter element to Search :");
  scanf("%d",&ele);
  for(i=0;i<size;i++)
  {
    if(list[i] == ele)
    {
      printf("[%d is found at position %d in list.]\n",ele,i+1);
      return;
    }
  }
  printf("[%d is not found in list.]\n",ele);
}

int main()
{
  int n,i,ch;
  printf("Enter the size of list:");
  scanf("%d",&n);
  int list[n];
  for(i=0;i<n;i++)
  {
    printf("\nEnter value of position %d:",i+1);
    scanf("%d",&list[i]);
  }
  while(1)
  {
    printf("\n===Serching===");
    printf("\n\n1. Search a element.");
    printf("\n2.Exit");
    printf("\n\n>>Enter choice:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
        linearsearch(list,n);
        break;
      case 2:
        exit(1);
      default:
        printf("Invaild input!");
    }
  }
  return 0;
}