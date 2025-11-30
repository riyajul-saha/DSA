#include<stdio.h>
#include<stdlib.h>

void binarysearch(int list[],int size)
{
  int left,right,middle,ele;
  left = 0;
  right = size-1;
  printf("Enter element to search:");
  scanf("%d",&ele);
  while(left <= right)
  {
    middle = (left+right)/2;
    if(list[middle] == ele)
    {
      printf("[%d is found at position %d in list]",ele,middle+1);
      return;
    }
    else if(ele > list[middle])
    {
      left = middle+1;
    }
    else if(ele < list[middle])
    {
      right = middle-1;
    }
  }
  printf("[%d is not found in list.]",ele);
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
        binarysearch(list,n);
        break;
      case 2:
        exit(1);
      default:
        printf("Invaild input!");
    }
  }
  return 0;
}