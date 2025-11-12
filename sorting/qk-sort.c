#include<stdio.h>

int quick(int array[],int beg,int end)
{
	int lock = beg;
	int left = beg;
	int right = end;
	int temp;
begging:
	while(array[lock]<array[right] && right != lock)
	{
		right--;
	}
	if(lock == right)
	{
		return lock;
	}
	if(array[lock] > array[right])
	{
		temp = array[lock];
		array[lock]=array[right];
		array[right]=temp;
		lock = right;
	}
	while(array[lock]>array[left] && lock != left)
	{
		left++;
	}
	if(left == lock)
	{
		return lock;
	}
	if(array[lock] < array[left])
	{
		temp = array[lock];
		array[lock] = array[left];
		array[left] = temp;
		lock = left; 
	}
	goto begging;
}

void quick_sort(int a[],int beg,int end)
{
	if(beg < end)
	{
		int lock = quick(a,beg,end);
		quick_sort(a,beg,lock-1);
		quick_sort(a,lock+1,end);
	}
}

int main()
{
	int n,i;
	printf("\nEnter Size of array:");
	scanf("%d",&n);
	int array[n];
	for(i=0;i<n;i++)
	{
		printf("Enter Value of position %d :",i+1);
		scanf("%d",&array[i]);	
	}
	quick_sort(array,0,n-1);
	printf("\nSorted Array :[");
	for(i=0;i<n;i++)
	{
		printf("%d,",array[i]);	
	}
	printf("]\n");
	return 0;
}
