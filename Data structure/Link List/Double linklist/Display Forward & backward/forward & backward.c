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
        struct node* t;
        t=head;
        while(t->right!=NULL)
        {
            t=t->right;
        }
        t->right=temp;
        temp->left=t;
    }

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

void revers()
{
    struct node* temp;
    temp=head;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }

    printf("\nBackward: Head <= ");
    while(temp!=NULL)
    {
        printf("%d <= ",temp->data);
        temp=temp->left;
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
    revers();


    return 0;
}
