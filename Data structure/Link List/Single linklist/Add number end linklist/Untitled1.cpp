#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;

void insert(int value)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node* temp1;
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
}

void addno(int no)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=no;
    temp->next=NULL;
    struct node* temp1;
    temp1=head;
    printf("Add %d end of list:\n",no);
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
}

void print()
{
    struct node* temp;
    temp=head;
    printf("Head => ");
    while(temp!=NULL)
    {
        printf("%d => ",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main()
{
    int j,x,i,a;
    printf("How many number you input:");
    scanf("%d",&x);
    printf("Enter %d number:\n",x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }
    print();
    printf("\n\nAdd any number: ");
    scanf("%d",&a);
    addno(a);
    print();


    return 0;
}
