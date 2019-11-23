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

void addnode(int position,int no)
{
    int i;
    if(position==1)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=no;
        temp->link=head;
        head=temp;

    }
    else
    {
        struct node* temp1;
        temp1=head;
        for(i=1;i<=(position-1);i++)
        {
            temp1=temp1->link;
        }
        struct node* temp2=(struct node*)malloc(sizeof(struct node));
        temp2->data=no;
        temp2->link=temp1->link;
        temp1->link=temp2;
    }
}



void print()
{
    struct node* temp;
    temp=head;
    printf("Head=>");
    while(temp!=NULL)
    {
        printf("%d=>",temp->data);
        temp=temp->link;
    }
    printf("End");
}

int main()
{
    head=NULL;

    int i,j,x,k,s;
    printf("How many number you insert:");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }
    print();

    printf("\n\nAdd node & NO:\n");
    scanf("%d%d",&k,&s);
    addnode(k,s);

    print();

    return 0;
}
