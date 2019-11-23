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

void deletenode(int position,int x)
{
    int i;
    if(position==1)
    {
        struct node* temp;
        temp=head;
        head=temp->right;
        free(temp);
    }
    else if(position==x)
    {
        struct node* temp1;
        temp1=head;
        for(i=1;i<=(position-2);i++)
        {
            temp1=temp1->right;
        }
        struct node* temp2;
        temp2=temp1->right;
        temp1->right=NULL;
        temp2->right=NULL;
        temp2->left=NULL;
        free(temp2);
    }
    else
    {
        int i;
        struct node* temp1;
        temp1=head;
        for(i=1;i<=(position-2);i++)
        {
            temp1=temp1->right;
        }
        struct node* temp2;
        temp2=temp1->right;
        temp1->right=temp2->right;
        struct node* temp3;
        temp3=temp2->right;
        temp3->left=temp2->left;
        free(temp2);
    }
}

int main()
{
    int i,j,x,a;
    printf("How many number you insert:");
    scanf("%d",&x);
    printf("Enter %d number:\n",x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }
    print();
    printf("Delete node: ");
    scanf("%d",&a);
    deletenode(a,x);
    print();


    return 0;
}
