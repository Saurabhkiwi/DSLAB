#include<stdio.h>
int main()
{
    int a[100],n,i,j,temp;
    printf("enter number of elements:\n");
    scanf("%d", &n);
    printf("enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("the sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d", a[i]);
    }
}
