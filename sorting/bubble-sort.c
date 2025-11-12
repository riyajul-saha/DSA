#include<stdio.h>

void bubble_sort(int a[],int r)
{
	int i,j,temp;
	 for(i=0; i<r; i++)
    {
        for(j=0; j<(r-1) ; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }

}
int main()
{
    int i, r, a[20];
    printf("Enter a range: ");
    scanf("%d",&r);
    printf("Enter %d numbers: \n",r);
    for(i=0; i<r; i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,r);
    
    printf("After sorting(Assending order):\n");
    for(i=0; i<r; i++)
    {
        printf("%d \n",a[i]);
    }
}
