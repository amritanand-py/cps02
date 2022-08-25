#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define in(x) scanf(" %d", &x);
#define LinkedListNode LinkedListNode
typedef struct LinkedListNode LinkedListNode;
struct LinkedListNode {
    int val;
    struct LinkedListNode* next;
};


//-------------------- body of the code ------------------------


LinkedListNode* insertAtBeginning(LinkedListNode* head, int val) {

    LinkedListNode *f = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    f->val = val;
    f->next = NULL;

    if(head == NULL)
        return f;
    else{
        LinkedListNode *a = head;
        f->next = head;
        head = f;
        return head;
    }

}
LinkedListNode* insertAtEnd(LinkedListNode* head, int val) {

    LinkedListNode *f = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    f->val = val;
    f->next = NULL;

    if(head == NULL)
        return f;
    else{
        LinkedListNode *a = head;
        while(a->next!=NULL)
        {
            a = a->next;
        }
        a->next = f;
        return head;
    }

}
LinkedListNode* insertAtPosition(LinkedListNode* head, int val, int pos) {

    if(pos==1)
    {
        LinkedListNode *o = insertAtBeginning(head, val);
        return o;
    }
    else{
        LinkedListNode *f = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        f->val = val;
        f->next = NULL;
        int i = pos-2;
        LinkedListNode *cptr = head, *nextPtr = head->next;
        while(i--) {
            cptr = cptr->next;
            nextPtr = nextPtr->next;
        }

        f->next = nextPtr;
        cptr->next = f;
        return head;
    }

}
LinkedListNode* deleteAtBeginning(LinkedListNode* head) {

    LinkedListNode *toDelete;

    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        toDelete = head;
        head = head->next;
        return head;
    }

}
LinkedListNode* deleteAtEnd(LinkedListNode* head) {

    LinkedListNode *toDelete, *secondLastNode;

    if(head == NULL)
    {
        return NULL;
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        while(toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }
        if(toDelete == head)
        {
            head = NULL;
        }
        else
        {
            secondLastNode->next = NULL;
        }
        free(toDelete);

        return head;
    }

}
LinkedListNode* deleteAtPosition(LinkedListNode* head, int pos) {

    if(pos < 1)
        return head;

   if (head == NULL) 
      return NULL; 

   LinkedListNode* temp = head; 

    if (pos == 1) 
    { 
        head = temp->next;    
        free(temp);                
        return head; 
    } 

    int i;
    for (i=0; temp!=NULL && i<pos-2; i++) 
         temp = temp->next; 

    if (temp == NULL || temp->next == NULL) 
         return head; 

    LinkedListNode *next = temp->next->next; 

    free(temp->next);  

    temp->next = next;
    return head;

}

//-------------------- tail of the code ------------------------


int rng(int lim) {
    if (lim == 0) return 0;
    return rand()%lim;
}
int a[1005], sz = 0;
void insertt(int val, int pos) {
    if (pos < 0) return;
    if (pos > sz + 1) return;
    sz += 1;
    for (int i = sz; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = val;
}
void erasee(int pos) {
    if (pos > sz) return;
    if (pos < 1) return;
    sz--;
    for (int i = pos; i <= sz; i++)
        a[i] = a[i + 1];
}
int check(LinkedListNode* head) {
    for (int i = 1; i <= sz; i++) {
        if (head == NULL) return 0;
        if (head->val != a[i]) return 0;
        head = head->next;
    }    
    if (head != NULL) return 0;
    return 1;
}
int main() {
    srand(time(NULL));
    int t, n; in(t); in(n);
    while (t--) {
        LinkedListNode* head = NULL;
        sz = 0;
        for (int i = 0; i < n; i++) {
            int type = rng(6);
            if (type == 0) {
                int val = rng(1000);
                head = insertAtBeginning(head, val);
                insertt(val, 1);
                if (!check(head)) {
                    printf("incorrect insertAtBeginning");
                    return 0;
                }
            }

            if (type == 1) {
                int val = rng(1000);
                head = insertAtEnd(head, val);
                insertt(val, sz + 1);
                if (!check(head)) {
                    printf("incorrect insertAtEnd");
                    return 0;
                }
            }

            if (type == 2) {
                int val = rng(1000);
                int pos = rng(sz + 1) + 1;
                head = insertAtPosition(head, val, pos);
                insertt(val, pos);
                if (!check(head)) {
                    printf("incorrect insertAtPosition");
                    return 0;
                }
            }

            if (type == 3) {
                head = deleteAtBeginning(head);
                erasee(1);
                if (!check(head)) {
                    printf("incorrect deleteAtBeginning");
                    return 0;
                }
            }

            if (type == 4) {
                head = deleteAtEnd(head);
                erasee(sz);
                if (!check(head)) {
                    printf("incorrect deleteAtEnd");
                    return 0;
                }
            }

            if (type == 5) {
                int pos = rng(sz)+1;
                head = deleteAtPosition(head, pos);
                erasee(pos);
                if (!check(head)) {
                    printf("incorrect deleteAtPosition");
                    return 0;
                }
            }
        }
    }
    printf("correct");
}