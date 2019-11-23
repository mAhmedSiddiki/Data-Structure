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

void print()
{
    struct node* temp;
    temp=head;
    printf("Head=>");
    while(temp!=NULL)
    {
        printf(" %d => ",temp->data);
        temp=temp->link;
    }
    printf("End\n");
}


void deletenode(int position)
{
    if(position==1)
    {
        struct node* temp;
        temp=head;
        head=temp->link;
        free(temp);
    }
    else
    {
        int i;
        struct node* temp1;
        temp1=head;
        for(i=1;i<=(position-2);i++)
        {
            temp1=temp1->link;
        }
        struct node* temp2;
        temp2=temp1->link;
        temp1->link=temp2->link;
        free(temp2);
    }
}


int main()
{
    head=NULL;
    int i,j,x,position;
    printf("How many number you insert:");
    scanf("%d",&x);
    printf("Enter %d number:\n",x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }

    print();

    printf("\n\nDelete Node:");
    scanf("%d",&position);
    deletenode(position);

    print();

    return 0;
}
