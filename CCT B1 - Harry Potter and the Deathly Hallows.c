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
void deleteNode(LinkedListNode* x) {
    if (x->next==NULL)
    {
        return;
    }
    x->val=x->next->val;
    LinkedListNode *temp;
    temp = x->next;
    x->next=x->next->next;
    free(temp);
}

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    LinkedListNode* res;
    int x_size = 0;

    LinkedListNode* x = NULL;
    LinkedListNode* x_tail = NULL;

    scanf("%d\n", &x_size);
    for(int i = 0; i < x_size; i++) {
        int x_item;
        scanf("%d", &x_item);
        x_tail = _insert_node_into_singlylinkedlist(x, x_tail, x_item);

        if(i == 0) {
            x = x_tail;
        }
    }

	int p; scanf("%d", &p);
  	p--;
  	LinkedListNode* ptr = x;
  	while(p--) ptr = ptr->next;
    deleteNode(ptr);
    res = x;
  	while (res != NULL) {
        fprintf(f, "%d\n", res->val);

        res = res->next;
    }

    fclose(f);
    return 0;
}
