#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

int hash_table[SIZE];

int key(int data)
{
  return data%10;
}

void Insert(int data)
{
  int k;
  k = key(data);
  hash_table[k] = data;
}

void Delete(int data)
{
  int k = key(data);
  hash_table[k] = 0;
}

int Search(int data)
{
  int k = key(data);
  if(hash_table[k] == data)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int ch,data;
  while(1)
  {
    printf("\n==Hash Operation==\n");
    printf("1. Insert Data.\n");
    printf("2. Delete Data.\n");
    printf("3. Search Data.\n");
    printf("4. Display Table.\n"); //This is extra operation.
    printf("5. Exit.\n");
    printf("\nEnter Choice:");
    scanf("%d",&ch);
    
    switch(ch)
    {
      case 1:
        printf("\n[>>] Enter data to insert:");
        scanf("%d",&data); 
        Insert(data);
        printf("[~] %d inserted Succesfully.",data);
        break;
      case 2:
        printf("\n[>>] Enter data to delete:");
        scanf("%d",&data);
        Delete(data);
        printf("[^] %d deleted succesfully",data);
        break;
      case 3:
        printf("\n[>>] Enter data to search:");
        scanf("%d",&data);
        if(Search(data))
        {
          printf("\n[~] %d is present in table",data);
        }
        else
        {
          printf("\n[^] %d is not present in table.",data);
        }
        break;
      case 4:
        //display();
        break;
      case 5:
        exit(0);
      default:
        printf("\n[!] Invaild input");
        
        
    }
  }
	return 0;
}
