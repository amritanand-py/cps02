#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long int t;
    int i,val;
    scanf("%ld",&t);
    struct node* head;
    for(i=0;i<t;i++)
    {
        scanf("%d",&val);
        struct node* temp1=(struct node *)malloc(sizeof(struct node*));
        temp1->data=val;
        temp1->next=NULL;
        if(i==0)
        {
            head=temp1;
        }
        else 
        {
            struct node* temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=temp1;
        }
    }
    scanf("%d",&val);
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            printf("yes");
            return 0;
        }
        temp=temp->next;
    }
    printf("no");
    return 0;
}