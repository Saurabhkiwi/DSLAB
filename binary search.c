#include<stdio.h>
int main()
{
    int a[100],n,i,key,mid,low,high,pos;
    printf("enter no of elements\n");
    scanf("%d",&n );
    printf("enter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter element to be found:\n");
    scanf("%d", &key);
    low=0;
    high=n-1;
    do
    {
        mid=(low+high)/2;
        if(a[mid]>a[low])
        {
            low=mid+1;
        }
        else if(a[mid]<a[high])
        {
            high=mid-1;
        }
    }while(a[mid]!=key && low<=high);
    if(a[mid]==key)
    {
        pos=mid+1;
        printf("%d is found at place %d", key,pos);
    }
    else{
        printf("%d not found", key);
    }
}
