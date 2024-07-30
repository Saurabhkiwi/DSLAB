#include<stdio.h>
int main()
{
    int a[100],i,j,key,found=0,pos,n;
    printf("enter the number of elements in the array:\n");
    scanf("%d", &n);
    printf("\nenter array elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the element to be found:\n");
    scanf("%d", &key);
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            found=1;
            pos=i+1;
        }
    }
    if(found==1)
    {
        printf("%d is found at place %d", key,pos);
    }
    else{
        printf("%d not found", key);
    }


}
