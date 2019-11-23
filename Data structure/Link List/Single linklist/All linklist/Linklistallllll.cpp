#include<stdio.h>
#include<stdlib.h>
int i,j,x,s,k,position;
struct node
{
    int data;
    struct node* link;
};

struct node* head=NULL;

void beginning(int value)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->link=head;
    head=temp;
}

void ending(int value)
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
        for(i=1;i<=(position-2);i++)
        {
            temp1=temp1->link;
        }
        struct node* temp2=(struct node*)malloc(sizeof(struct node));
        temp2->data=no;
        temp2->link=temp1->link;
        temp1->link=temp2;
    }
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

void print()
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    printf("Insert Beginning is:\nHead=>");
    while(temp!=NULL)
    {
        printf("%d=>",temp->data);
        temp=temp->link;
    }
    printf("End\n");
}

void start()
{
    printf("How many number you insert: ");
                scanf("%d",&x);

                for(i=0;i<x;i++)
                {
                    scanf("%d",&j);
                    ending(j);
                }
                print();
}


int main()
{

        printf("**** Welcome to link-list ****\n");
        printf("1. Beginning.\n");
        printf("2. Ending.\n");
        printf("3. Add node.\n");
        printf("4. Deletion.\n");
        printf("5. Searching.\n");

        int listt;
        printf("\nWhat would you use..??\n");
        scanf("%d",&listt);
        system("cls");
        switch(listt)
        {
            case 1:
                    printf("How many number you insert:");
                    scanf("%d",&x);
                    printf("Enter %d number:\n",x);

                    for(i=0;i<x;i++)
                    {
                        scanf("%d",&j);
                        beginning(j);
                    }
                    print();
                    break;

            case 2:
                    start();
                    break;
            case 3:
                start();

                printf("\n\nAdd node & NO:\n");
                scanf("%d%d",&k,&s);
                addnode(k,s);

                print();
                break;
            case 4:
                start();

                printf("\n\nDelete Node:");
                scanf("%d",&position);
                deletenode(position);
                print();
                break;
            case 5:
                start();

                printf("\n\nSearch number:");
                scanf("%d",&s);
                search(s);
                break;
            default:printf("Sorry...You are wrong.\n");
            break;
        }



    return 0;
}
