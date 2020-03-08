#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode;
struct node *last=NULL;
void create();
void push();
void pop();
void traverse();
int main()
{
    int ch;
    while(1)
    {
    system("cls");
    printf("\n-------S-T-A-C-K---------");
    printf("\n1.create");
    printf("\n2.push");
    printf("\n3.pop");
    printf("\n4.traverse");
    printf("\n5.exit");
    printf("\nEnter your choice Here:");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            create();
            system("pause");
            break;
            case 2:
            push();
            system("pause");
            break;
            case 3:
            pop();
            system("pause");
            break;
            case 4:
            traverse();
            system("pause");
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("\nYou Have Inserted Wrong Value Here");
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
    printf("\nMemory not allocated");
    else
    {   if(last==NULL)
        {
            printf("\nEnter the item Here:");
            scanf("%d",&item);
            newnode->data=item;
            last=newnode;
            last->next=NULL;
        }
        else
        {
            printf("\nNode is already created");
        }
    }
    
}

void push()
{
    int item;
    newnode=(struct node *)malloc(sizeof(struct node));
    if(last==NULL)
    printf("\nNo node is created");
    else
    {
        printf("\nEnter the item Here:");
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=last;
        last=newnode;
        printf("\nElement inserted :%d",newnode->data);
    }
    
}

void pop()
{
    struct node *temp;
    if(last==NULL)
    printf("\nNo node is created");
    else
    {
    temp=last;
    last=temp->next;
    free(temp);
    }
}

void traverse()
{
    struct node *temp;
    temp=last;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
}