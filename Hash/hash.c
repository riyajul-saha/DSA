#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *addr;
};

int main()
{
	struct node *ptr;
	ptr =(struct node *)calloc(10,sizeof(struct node));
	ptr[0].data = 5;
	printf("Data = %d",ptr[0].data);
	return 0;
}
