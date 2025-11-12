#include<stdio.h>
#include<stdlib.h>
void selection_sort(int a[],int r)
{
	int i,j,min,temp,index;
	for(i=0; i<r-1; i++)
	    {
	        min=a[i];
	        index=i;
	        for(j=i+1; j<r; j++)
	        {
	            if(min>a[j])
	            {
	                min=a[j];
	                index=j;
	            }
	        }
	        temp=a[i];
	        a[i]=a[index];
	        a[index]=temp;
	    }
}
int main()
{
    int r, a[20],  i; 
    printf("Enter a range : ");
    scanf("%d", &r);
    printf("Enter %d number:\n", r);
    for(i=0; i<r; i++)
    {
        scanf("%d", &a[i]);
    }
    selection_sort(a,r);
    printf("After sorting:\n");
    for(i=0; i<r; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
