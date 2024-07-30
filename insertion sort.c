#include<stdio.h>
int main()
{
    int a[100],n,i,j,small,temp,pos,k,l,m;
    printf("enter no of elements:\n");
    scanf("%d", &n);
    printf("enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j>0 && a[j]<a[j-1];j--)
        {


                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;

        }
    }
    printf("the sorted array is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
}
