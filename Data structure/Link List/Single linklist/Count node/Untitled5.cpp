#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* head=NULL;

void print()
{
    struct node* temp;
    temp=head;
    printf("The list is:\ntemp=>");
    while(temp!=NULL)
    {
        printf(" %d=> ",temp->data);
        temp=temp->link;
    }
    printf("End\n");
}

void insert(int value)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=NULL;
    if(head==NULL)
    {
        head=temp;

    }
    else
    {
        struct node* t;
        t=head;

        while(t->link!=NULL)
        {
            t=t->link;
        }
        t->link=temp;
    }
}


int nodecount()
{
    int c=0;
    struct node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->link;
        c++;
    }
    return c;
}


int main()
{
    int i,x,j;
    printf("How many number you insert: ");
    scanf("%d",&x);

    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }
    print();
    int haha=nodecount();
    printf("\nTotal Node: %d\n",haha);

    return 0;
}
