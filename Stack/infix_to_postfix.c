#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 15

char stack[SIZE];
char output[100];
int top = -1;
int idx=0;

int isoperator(char ele)
{
  if(ele == '+' || ele == '-' || ele == '*' || ele == '/' || ele == '(' || ele == ')' || ele == '^' || ele == '%')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int is_empty_stack()
{
  if(top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int is_full_stack()
{
  if(top == SIZE-1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void push_in_stack(char op)
{
  if(!is_full_stack())
  {
    top++;
    stack[top] = op;
  }
  else
  {
    printf("\a[!] Stack Full");
  }
}

int preference_of(char element)
{
  if(element == '^')
  {
    return 3;
  }
  else if(element == '*' || element == '/' || element == '%')
  {
    return 2;
  }
  else if(element == '+' || element == '-')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

char pop_from_stack()
{
  char data = stack[top];
  top--;
  return data;
}

void convert_to_postfix(char expression[100])
{
  int i = 0;
  char ele,op;
  while(expression[i] != '\0')
  {
    ele = expression[i];
    if(isoperator(ele))
    {
      if(!is_empty_stack())
      {
        if(ele == ')' || ele == '(')
        {
          if(ele == '(')
          {
            push_in_stack(ele);
            i++;
            continue;
          }
          while(stack[top] != '(')
          {
            op = pop_from_stack();
            output[idx] = op;
            idx++;
          }
          op=pop_from_stack();
        }
        else if(preference_of(stack[top]) >= preference_of(ele))
        {
          if(ele == '^' && stack[top] == '^')
          {
            push_in_stack(ele);
            i++;
            continue;
          }
          while(preference_of(stack[top]) >= preference_of(ele)  && stack[top] != '(' && top != -1)
          {
            op = pop_from_stack();
            output[idx] = op;
            idx++;
          }
          push_in_stack(ele);
        }
        else
        {
          push_in_stack(ele);
        }
      }
      else
      {
        push_in_stack(ele);
      }
      i++;
    }
    else
    {
      output[idx] = ele;
      idx++;
      i++;
    }
  }
  while(top != -1)
  {
    output[idx] = pop_from_stack();
    idx++;
  }
  output[idx] = '\0';
}

int main()
{
  char expression[100];
  printf("\nEnter Infix expression:");
  scanf("%s",expression);
  convert_to_postfix(expression);
  printf("\nPostfix format : %s\n",output);
  return 0;
}