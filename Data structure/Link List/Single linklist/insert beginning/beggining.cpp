#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* head;

void insert(int value)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=head;
    head=temp;
}

void print()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    printf("Insert Beginning is:\nHead=>");
    while(temp!=NULL)
    {
        printf("%d=>",temp->data);
        temp=temp->link;
    }
    printf("End\n");
}

int main()
{
    head=NULL;
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
