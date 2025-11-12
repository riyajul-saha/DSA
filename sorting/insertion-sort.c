#include<stdio.h>

void insertion_sort(int a[],int r)
{
	int i,j,temp;
	for(i=1; i<r; i++)
	  {
	      temp=a[i];
	      for(j=i-1; j>=0; j--)
	      {
	          if(a[j]>temp)
	          {
	              a[j+1]=a[j];
	          }
	      }
	      a[j+1]=temp;
	  }
}
int main()
{
    int r, a[20],  i ; 
    printf("Enter a range : ");
    scanf("%d", &r);
    printf("Enter %d number:\n", r);
    for(i=0; i<r; i++)
    {
        scanf("%d", &a[i]);
    }
    insertion_sort(a,r);
    printf("After sorting:\n");
    for(i=0; i<r; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
