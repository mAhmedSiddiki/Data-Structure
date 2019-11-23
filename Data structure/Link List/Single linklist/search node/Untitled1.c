#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* head=NULL;

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
        printf("%d=>",temp->data);
        temp=temp->link;
    }
    printf("End");
}

int search(int no)
{
    int count=1,n;
    struct node* temp;

	temp=head;

	while(temp->link!=NULL)
	{
		if(temp->data==no)
        {
            n=count;
            break;
        }
		else
        {
            count++;
        }
			temp=temp->link;
	}
	if(count==n)
    {
        printf("Your item is at node: %d\n",count);
    }
    else
    {
        printf("Sorry! your item is not in linked list.\n");
    }
}

int main()
{
    int x,i,j,s;
    printf("How many number you insert:");
    scanf("%d",&x);
    for(i=0;i<x;i++)
    {
        scanf("%d",&j);
        insert(j);
    }
    print();

    printf("\n\nSearch number:");
    scanf("%d",&s);
    search(s);



    return 0;
}
