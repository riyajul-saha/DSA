#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int peek = -1;

void push()
{
  int data;
  if(peek == MAX)
  {
    printf("\n[!] Stack overflow ! No more space aviable to push");
    return;
  }
  printf("Enter data:");
  scanf("%d",&data);
  peek++;
  stack[peek] = data;
  printf("\n[*] %d Successfully pushed at stack",data);
}

void pop()
{
  int data;
  if(peek == -1)
  {
    printf("\n[!] Stack downflow ! No data aviable to pop.");
    return;
  }
  data = stack[peek];
  peek--;
  printf("\n[*] %d Successfully poped from stack.",data);
}

void display()
{
  int i;
  printf("[");
  for(i=peek;i>=0;i--)
  {
    printf("%d ",stack[i]);
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
    printf("\n>>Enter a choice:");
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
        printf("!!!!!Invaild input!!!!!");
    }
  }
  return 0;
}