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


struct LinkedListNode *addToEmpty(LinkedListNode *last, int data) 
{ 
    if (last != NULL) 
      return last; 
    struct LinkedListNode *l = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode)); 
    l -> val = data; 
    l -> next = l; 

    return l; 
}

LinkedListNode* insertAtBeginning(LinkedListNode* last, int data) {
    if (last == NULL) 
    return addToEmpty(last, data); 

    struct LinkedListNode *temp = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode)); 
    temp -> val = data; 
    temp -> next = last -> next; 
    last -> next = temp; 

    return last; 

}
LinkedListNode* insertAtEnd(LinkedListNode* last, int data) {

    if (last == NULL) 
        return addToEmpty(last, data); 
    struct LinkedListNode *temp = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode)); 

    temp -> val = data; 
    temp -> next = last -> next; 
    last -> next = temp; 
    last=temp;

    return last; 
}
LinkedListNode* deleteAtBeginning(LinkedListNode* tail) {
    if(tail==NULL)
        return NULL;
    struct LinkedListNode *t;
    if(tail==tail->next)
        tail=NULL;
    else
    {    t=tail->next;
    tail->next=tail->next->next;
    free(t);}
    return tail;

}
LinkedListNode* deleteAtEnd(LinkedListNode* tail) {
    if(tail==NULL)
        return NULL;
    struct LinkedListNode *t;
    if(tail==tail->next)
        tail=NULL;
    else
    {    t=tail->next;
    while(t->next!=tail)
        t=t->next;
     t->next=t->next->next;
    free(tail);
     tail=t;
    }
    return tail;

}


//-------------------- tail of the code ------------------------

void printForward(LinkedListNode* head) {
    if (head == NULL) return;
    printf("%d ", head->val);
    printForward(head->next);
}
void printBackward(LinkedListNode* head) {
    if (head == NULL) return;
    printBackward(head->next);
    printf("%d ", head->val);
}
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
int check(LinkedListNode* tail) {
    if (tail == NULL && sz == 0) return 1;
    if (tail == NULL || sz == 0) return 0;
    if (tail->val != a[sz]) return 0;
    LinkedListNode* ii = tail->next;
    for (int i = 1; i < sz; i++) {
        if (ii == NULL) return 0;
        if (a[i] != ii->val) return 0;
        ii = ii->next;
    }
    return 1;
}
int main() {
    srand(time(NULL));
    int t, n; in(t); in(n);
    while (t--) {
        LinkedListNode* head = NULL;
        sz = 0;
        for (int i = 0; i < n; i++) {
            int type = rng(4);
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
                head = deleteAtBeginning(head);
                erasee(1);
                if (!check(head)) {
                    printf("incorrect deleteAtBeginning");
                    return 0;
                }
            }

            if (type == 3) {
                head = deleteAtEnd(head);
                erasee(sz);
                if (!check(head)) {
                    printf("incorrect deleteAtEnd");
                    return 0;
                }
            }
        }
    }
    printf("correct");
}