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


void deleteno(int no)
{

    int n=1,c,i;
    struct node* temp;
    temp=head;
    while(temp->link!=NULL)
    {
        if(temp->data==no)
        {
            c=n;
            break;
        }
        else
        {
            n++;
        }
        temp=temp->link;
    }
    if(n==c)
    {
        struct node* t;
        t=head;
        for(i=1;i<=(n-2);i++)
        {
            t=t->link;
        }
        t->link=temp->link;
    }
    else
    {
        printf("Wrong");
    }

}

int main()
{
    head=NULL;
    int i,j,x,no;
    printf("How many number you insert:");
    scanf("%d",&x);
    printf("Enter %d number:\n",x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }

    print();

    printf("\n\nDelete No:");
    scanf("%d",&no);
    deleteno(no);
    print();

    return 0;
}
