#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    char name[50];
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
        printf(" %d=> \t\t %s ",temp->data,temp->name[50]);
        temp=temp->link;
    }
    printf("End\n");
}

void insert(int value,char name[])
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->name[50]=name[50];
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


int main()
{
    insert(1,marjuk);
    insert(2,marjuk);
    insert(3,marjuk);
    insert(4,marjuk);
    insert(5,marjuk);
    print();

    return 0;
}
