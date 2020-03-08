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
        printf("\n------circular--Double-Link-List---------");
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
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    printf("\nNo memory allocated");
    else
    {
        printf("\nEnter the item Here:");
        scanf("%d",&item);
        newnode->data=item;
        if(start==NULL)
        {
            start=newnode;
            last=newnode;
            start->next=last;
            start->pre=last;
            last->next=start;
            last->pre=start;
        }
        else
        {
            last->next=newnode;
            newnode->pre=last;
            last=newnode;
            last->next=start;
            start->pre=last;
        }
        printf("\nelement inserted :%d",newnode->data);    
    }

}

void insert_beg()
{
    int item;
    if(start==NULL)
    printf("\nNo Node is created");
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        printf("\nNo memory Allocated");
        else
        {
            printf("\nEnter the item Here:");
            scanf("%d",&item);
            newnode->data=item;
            newnode->next=start;
            start->pre=newnode;
            start=newnode;
            start->pre=last;
            last->next=start;
            printf("\nElement inserted:%d",newnode->data);

        }
        
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
        printf("\nNo memory Allocated");
        else
        {
            printf("\nEnter the position Here:");
            scanf("%d",&pos);
            --pos;
            printf("\nEnter the Item Here:");
            scanf("%d",&item);
            newnode->data=item;
            for(i=1;i<pos;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next->pre=newnode;
            temp->next=newnode;
            newnode->pre=temp;
            printf("Element Inserted Here:%d",newnode->data);
        }
        
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
        printf("\nNo memory Allocated");
        else
        {
            printf("\nEnter the item Here:");
            scanf("%d",&item);
            newnode->data=item;
            last->next=newnode;
            newnode->pre=last;
            last=newnode;
            last->next=start;
            start->pre=last;
        }
        printf("\nElement Inserted :%d",newnode->data);
    }
    
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
        start->pre=last;
        last->next=start;
        printf("\nElement deleted: %d",temp->data);
        free(temp);
    }
    
}

void del_spec()
{
    int pos,i;
    struct node *temp;
    temp=start;
    if(start==NULL)
    printf("\nNo node is created Here");
    else
    {
        printf("\nenter the position here:");
        scanf("%d",&pos);
        for(i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;
        printf("\nElement deleted :%d",temp->data);
        free(temp);
    }
    
}

void del_end()
{
    struct node *temp;
    if(start==NULL)
    printf("\nNo node is created Here");
    else
    {
        temp=last;
        last=temp->pre;
        last->next=start;
        start->pre=last;
        printf("\nElement deleted:%d",temp->data);
        free(temp);
    }
    
}

void traverse()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    printf("No node is created ");
    else
    {
        printf("%d->",temp->data);
        temp=temp->next;
        while (temp!=start)
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
    printf("\nNo node is created");
    else
    {
        printf("%d->",temp->data);
        temp=temp->pre;
        while (temp!=last)
        {
            
            printf("%d->",temp->data);
            temp=temp->pre;
        }
        
    }
    
}