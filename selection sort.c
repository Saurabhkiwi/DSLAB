#include<stdio.h>
int main()
{
    int a[100],n,i,j,pos,small,temp;
    printf("enter number of elements:\n");
    scanf("%d", &n);
    printf("enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0;i<n;i++)
    {
        small=a[i];
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<small)
            {
                small=a[j];
                pos=j;
            }
        }
        temp=a[i];
        a[i]=small;
        a[pos]=temp;
    }
    for(i=0;i<n;i++)
    {
        printf("%d", a[i]);

    }
}
