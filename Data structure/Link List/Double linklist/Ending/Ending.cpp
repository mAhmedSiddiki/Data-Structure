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
    temp->right=NULL;
    temp->left=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node* temp1;
        temp1=head;
        while(temp1->right!=NULL)
        {
            temp1=temp1->right;
        }
        temp1->right=temp;
        temp->left=temp1;
    }
}

void print()
{
    struct node* temp;
    temp=head;
    printf("Head => ");
    while(temp!=NULL)
    {
        printf("%d => ",temp->data);
        temp=temp->right;
    }
    printf("End\n");
}

int main()
{
    int i,j,x;
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
