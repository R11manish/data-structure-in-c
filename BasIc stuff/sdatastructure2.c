#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
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
void traverse1();
int main()
{
    int ch,c1,c2;
    while(1)
    {
        system("cls");
        printf("\n--------Double-Link-List---------");
        printf("\n1.Create");
        printf("\n2.traverse");
        printf("\n3.insertion");
        printf("\n4.deletation");
        printf("\n5.back traverse");
        printf("\n6.Exit");
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
            traverse1();
            system("pause");
            break;
            case 6:
            exit(0);
            break;
        }
    }
    return 0;
}
void create()
{
    int item;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory not allocated");
    }
    else
    {
        printf("\nenter the item:");
        scanf("%d",&item);
        newnode->data=item;
        if(start==NULL)
        {
            start=newnode;
            start->next=NULL;
            start->pre=NULL;
            last=newnode;
        }
        else
        {
            last->next=newnode;
            newnode->pre=last;
            last=newnode;
            last->next=NULL;
        }
    printf("element inserted:%d",newnode->data);   
    }
}

void insert_beg()
{
    int item;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("\nMemory Not Allocated");
        else
        {
            printf("\nEnter the item:");
            scanf("%d",&item);
            newnode->data=item;
            start->pre=newnode;
            newnode->next=start;
            start=newnode;
            start->pre=NULL;
        }
    printf("\nelement inserted at begining:%d",newnode->data);    
    }
    
}

void insert_spec()
{
    int item,pos,i;
    struct node *temp;
    temp=start;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("\nMemory not allocated");
        else
        {
            printf("\nenter the position here:");
            scanf("%d",&pos);
            printf("\nenter the item here:");
            scanf("%d",&item);
            newnode->data=item;
            --pos;
            for(i=1;i<pos;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next->pre=newnode;
            temp->next=newnode;
            newnode->pre=temp;
        }
    printf("\nElement inserted:%d",newnode->data);
    }
    
}


void insert_end()
{
    int item;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("\nNo memory is allocated");
        else
        {
            printf("\nEnter the item Here:");
            scanf("%d",&item);
            newnode->data=item;
            last->next=newnode;
            newnode->pre=last;
            last=newnode;
            last->next=NULL;
        }
        
    }
    printf("\nElement insered:%d",newnode->data);
}

void del_beg()
{
    struct node *temp;
    if(start==NULL)
    printf("\nNo node is created");
    else
    {
        temp=start;
        start=temp->next;
        start->pre=NULL;
        printf("\nElement is deleted :%d",temp->data);
        free(temp);
    }
}

void del_spec()
{
    int pos,i;
    struct node *prei;
    struct node *temp;
    struct node *temp1;
    temp=start;
    if(start==NULL)
    printf("\nNo node is creaed");    
    else
    {
        printf("\nEnter the position of element:");
        scanf("%d",&pos);
        for(i=1;i<pos;i++)
        {
            prei=temp;
            temp=temp->next;
        }
        prei->next=temp->next;
        temp->next->pre=prei;
        printf("\nElement is deleted:%d",temp->data);
        free(temp);
    }
    
}

void del_end()
{
    struct node *temp;
    if(start==NULL)
    printf("\nNode is Empty");
    else
    {
        temp=last;
        last=temp->pre;
        last->next=NULL;
        printf("\neElement is deleted:%d",temp->data);
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
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
    }
    
}

void traverse1()
{
    struct node *temp;
    temp=last;
    if(start==NULL)
    printf("\nNo node is created ");
    else
    {
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->pre;
        }
    }
}