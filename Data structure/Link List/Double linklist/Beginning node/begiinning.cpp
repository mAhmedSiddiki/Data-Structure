#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* right;
    struct node* left;
};

struct node* head=NULL;

void insert(int value)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->right=head;
    temp->left=head;
    head=temp;

}

void print()
{
    struct node* temp;
    temp=head;
    printf("Forward: Head => ");
    while(temp!=NULL)
    {
        printf("%d => ",temp->data);
        temp=temp->right;
    }
    printf("End\n");
}


int main()
{
    int i,j,x,a,n;
    printf("How many number you insert:");
    scanf("%d",&x);
    printf("Enter %d number:\n",x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }
    print();


    return 0;
}
