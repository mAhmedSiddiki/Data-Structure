#include<stdio.h>
int main()
{
    int ara[100],i,n,x,first,last,mid;
    printf("Enter array size:");
    scanf("%d",&x);

    printf("Enter array number:\n");
    for(i=1;i<=x;i++)
    {
        scanf("%d",&ara[i]);
    }

    printf("Enter find number:");
    scanf("%d",&n);

    first=1;
    last=x-1;
    mid=(first+last)/2;

    while(first<=last)
    {
        if(ara[mid]==n)
        {
            printf("yaaa...!!!\n");
            break;
        }

        else if(ara[mid]<n)
        {
            first=mid+1;
            mid=(first+last)/2;
        }

        else
        {
            last=mid-1;
            mid=(first+last)/2;
        }
    }

    if(first>last)
    {
        printf("Nooo...!!!\n");
    }

    return 0;
}