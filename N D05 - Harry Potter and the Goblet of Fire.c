#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if(head == NULL) {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}


/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
int length(LinkedListNode* head)
{
    int l=0;
    LinkedListNode* temp=head;
    while(temp)
    {
        temp=temp->next;
        l++;
    }
    return l;
}
bool findIntersection(LinkedListNode* head1, LinkedListNode* head2) {
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    LinkedListNode* ptr1;
    LinkedListNode* ptr2;
    if(l1>l2)
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else
    {
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d)
    {
        ptr1=ptr1->next;
        if(ptr1==NULL)
        {
            return 0;
        }
        d--;
    }
    while(ptr1!=NULL &&ptr2!=NULL)
    {
        if(ptr1==ptr2)
        {
            return 1;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return 0;
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    bool res;
    int head1_size = 0;

    LinkedListNode* head1 = NULL;
    LinkedListNode* head1_tail = NULL;

    scanf("%d", &head1_size);
    for(int i = 0; i < head1_size; i++) {
        int head1_item;
        scanf("%d", &head1_item);
        head1_tail = _insert_node_into_singlylinkedlist(head1, head1_tail, head1_item);

        if(i == 0) {
            head1 = head1_tail;
        }
    }


    int head2_size = 0;

    LinkedListNode* head2 = NULL;
    LinkedListNode* head2_tail = NULL;

    scanf("%d", &head2_size);
    for(int i = 0; i < head2_size; i++) {
        int head2_item;
        scanf("%d", &head2_item);
        head2_tail = _insert_node_into_singlylinkedlist(head2, head2_tail, head2_item);

        if(i == 0) {
            head2 = head2_tail;
        }
    }

    int token;
    scanf("%d", &token);
    if (token != 0){
        token--;
        LinkedListNode* ptr = head1;
        while(token--){
            ptr = ptr->next;
        }
      	if (head2 == NULL) head2 = ptr;
        else head2_tail->next = ptr;
    }

    res = findIntersection(head1, head2);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}
