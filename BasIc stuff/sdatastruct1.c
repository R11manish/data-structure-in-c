#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode;
struct node *start=NULL;
struct node *last=NULL;
void create();
void traverse();
void insert_beg();
void insert_spec();
void insert_end();
void del_beg();
void del_end();
void del_spec();
int main()
{
    int ch,c1,c2;
    while(1)
    {
        system("cls");
        printf("\n--------Circular-Link-List---------");
        printf("\n1.Create");
        printf("\n2.traverse");
        printf("\n3.insertion");
        printf("\n4.deletation");
        printf("\n5.Exit");
        printf("\nEnter your choice Here:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            create();
            system("pause");
            break;
            case 2:
            traverse();
            system("pause");
            break;
            case 3:
            system("cls");
            printf("\n1.insertion at begning");
            printf("\n2.insertion at specific position");
            printf("\n3.insertion at last postion");
            printf("\nEnter your choice Here:");
            scanf("%d",&c1);
            switch(c1)
            {
                case 1:
                insert_beg();
                system("pause");
                break;
                case 2:
                insert_spec();
                system("pause");
                break;
                case 3:
                insert_end();
                system("pause");
                break;
                default:
                printf("\nplease enter correct value Here");
            }
            break;
            case 4:
            system("cls");
            printf("\n1.deletation at begning");
            printf("\n2.deletation at specific position");
            printf("\n3.deletation at last postion");
            printf("\n4.Enter your choice Here:");
            scanf("%d",&c2);
            switch(c2)
            {
                case 1:
                del_beg();
                system("pause");
                break;
                case 2:
                del_spec();
                system("pause");
                break;
                case 3:
                del_end();
                system("pause");
                break;
                default:
                printf("\nplease enter correct value Here");
            }
            break;
            case 5:
            exit(0);
        }
    }
    return 0;
}

void create()
{
    int item;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    printf("No Memory Allocated Here");
    else
    {
        printf("\n Enter the item :");
        scanf("%d",&item);
        newnode->data=item;
        if(start==NULL)
        {
            start=newnode;
            last=newnode;
            last->next=start;
            printf("\nElement is inserted successfully:%d",newnode->data);
        }
        else
        {
            last->next=newnode;
            last=newnode;
            last->next=start;
            printf("\nElement is inserted successfully:%d",newnode->data);
        }
        
    }
    
}

void insert_beg()
{
    int item;
    if(start==NULL)
    printf("\nNo Node is created Here");
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("No memory allocated Here:");
        else
        {
            printf("\nEnter the item");
            scanf("%d",&item);
            newnode->data=item;
            newnode->next=start;
            start=newnode;
            last->next=start;/*there is fourth line*/
        }
        
    }
    printf("\nElement inserted :%d",newnode->data);
}

void insert_end()
{
    int item;
    if(start==NULL)
    printf("\nNo Node is Created");
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("\nNo memory allocated");
        else
        {
            printf("\nEnter the item:");
            scanf("%d",&item);
            newnode->data=item;
            last->next=newnode;
            last=newnode;
            last->next=start;

        }
        
    }
    printf("\nElement inserted here:%d",newnode->data);
}


void insert_spec()
{
    int item,pos,i;
    if(start==NULL)
    printf("\n No node is created here");
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("\n No memory allocated");
        else
        {
            struct node *temp;
            temp=start;
            printf("\nEnter the item:");
            scanf("%d",&item);
            newnode->data=item;
            printf("\nEnter the pos of insertion:");
            scanf("%d",&pos);
            --pos;
            for(i=1;i<pos;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;

        }
        
    }
    printf("\nElement inserted :%d",newnode->data);
}

void del_beg()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {
        start=temp->next;
        last->next=start;
        printf("\nElement deleted:%d",temp->data);
        free(temp);
    }
}

void del_end()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {
        while(temp->next->next!=start)
        {
            temp=temp->next;
        }
        printf("\nElement deleted:%d",last->data);
        free(last);
        last=temp;
        last->next=start;
    }
}

void del_spec()
{
    int pos,i;
    struct node *temp;
    struct node *pre;
    temp=start;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {
        printf("\nEnter the pos of de element:");
        scanf("%d",&pos);
        for(i=1;i<pos;i++)
        {
            pre=temp;
            temp=temp->next;
        }
        pre->next=temp->next;
        printf("\n Element deleted :%d",temp->data);
        free(temp);
    }
}

void traverse()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {   printf("\nelements are:\n");
        printf("%d->",temp->data);
        temp=temp->next;
        while(temp!=start)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
    printf("\n");
    
}
