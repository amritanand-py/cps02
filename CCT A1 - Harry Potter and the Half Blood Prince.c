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
LinkedListNode* reverse(LinkedListNode* head)
{
    LinkedListNode* prev = NULL;
    LinkedListNode* curr = head;
    while (curr) {
        LinkedListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// function used to reverse a linked list from position m to n

LinkedListNode* reverseSublist(LinkedListNode* head, int n, int m)
{
    if (n == m)
        return head;
    LinkedListNode *revs = NULL, *revs_prev = NULL;
    LinkedListNode *revend = NULL, *revend_next = NULL;
  
    // Find values of above pointers.
    int i = 1;
    LinkedListNode* curr = head;
    while (curr && i <= m) {
        if (i < n)
            revs_prev = curr;
        if (i == n)
            revs = curr;
        if (i == m) {
            revend = curr;
            revend_next = curr->next;
        }
        curr = curr->next;
        i++;
    }
    revend->next = NULL;
    // Reverse linked list starting with revs.
    revend = reverse(revs);
    // If starting position was not head
    if (revs_prev)
        revs_prev->next = revend;
    // If starting position was head
    else
        head = revend;
    revs->next = revend_next;
    return head;
}
int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    LinkedListNode* res;
    int head_size = 0;

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    scanf("%d\n", &head_size);
    for(int i = 0; i < head_size; i++) {
        int head_item;
        scanf("%d", &head_item);
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if(i == 0) {
            head = head_tail;
        }
    }


    int n;
    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    res = reverseSublist(head, n, m);
    while (res != NULL) {
        fprintf(f, "%d ", res->val);

        res = res->next;
    }

    fclose(f);
    return 0;
}
