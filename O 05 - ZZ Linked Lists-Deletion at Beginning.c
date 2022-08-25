#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
void insert(struct node** headref, int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    struct node* temp= *headref;
    if(*headref==NULL)
    {
        *headref=newnode;
        newnode->next=NULL;
        return;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}
void deletebefore(struct node** headref)
{
    struct node *ptr;
    ptr=*headref;
    int temp;
    if(*headref==NULL)
        return;
    else
    {
        *headref = ptr -> next;
        free(ptr);
    }
}
void displayList(struct node** headref)
{
    struct node* temp=*headref;
    if(*headref == NULL)
    {
        return;
    }
    else
    {
        while(temp->next != NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
int main() {
    struct node* head = NULL;
    int size;
    scanf("%d",&size);
    int i;
    for(i=0;i<size;i++)
    {
        int val;
        scanf("%d",&val);
        insert(&head,val);
    }
    int k;
    scanf("%d",&k);
    for(i=0;i<k;i++)
    {
        deletebefore(&head);
    }
    displayList(&head);
    return 0;
}