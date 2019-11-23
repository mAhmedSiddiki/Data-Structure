#include<stdio.h>
int main()
{
    int ara[100],x,i,n,j,z=0;
    printf("Enter array number:");
    scanf("%d",&x);

    printf("Enter %d number:\n",x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&ara[i]);
    }

    printf("Enter find number:");
    scanf("%d",&n);


    for(j=0;j<x;j++)
    {
        if(ara[j]==n)
        {
            printf("%d no index in your data of array.\n",j+1);
            break;
        }
    }

    if(j==x)
    {
        printf("Item is not in the array.\n");
    }



    return 0;
}
