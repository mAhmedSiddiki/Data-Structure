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

void addnode(int position,int no,int x)
{
    int i;
    if(position==1)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=no;
        struct node* t;
        t=head;
        temp->right=t->right;
        struct node* t2;
        t2=t->right;
        t2->left=temp;
        t->right=temp;
        temp->left=t;
    }
    else if(position==x)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp->data=no;
        temp->right=NULL;
        struct node* t;
        t=head;
        while(t->right!=NULL)
        {
            t=t->right;
        }
        temp->left=t;
        t->right=temp;
    }
    else
    {
        struct node* temp1;
        temp1=head;
        for(i=1;i<=(position-1);i++)
        {
            temp1=temp1->right;
        }
        struct node* temp2=(struct node*)malloc(sizeof(struct node));
        temp2->data=no;
        temp2->right=temp1->right;
        temp2->left=temp1;
        temp1->right=temp2;
        struct node* temp3;
        temp3=temp2->right;
        temp3->left=temp2;
    }
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
    printf("Insertion:\nAdd node: ");
    scanf("%d",&a);
    printf("Insert number: ");
    scanf("%d",&n);
    addnode(a,n,x);
    print();

    return 0;
}
