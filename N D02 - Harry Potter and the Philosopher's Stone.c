#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    char val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, char val) {
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
    char val;
    LinkedListNode *next;
};
*/
void reverse(LinkedListNode**);
bool compareLists(LinkedListNode*,LinkedListNode*);

// Function to check if given linked
// list is palindrome or not
// bool isPalindrome(struct Node* head)
bool isPalindrome(LinkedListNode* head)
{
    LinkedListNode *slow_ptr = head,
                *fast_ptr = head;
    LinkedListNode *second_half,
                *prev_of_slow_ptr = head;

    // To handle odd size list 
    LinkedListNode* midnode = NULL;

    // Initialize result
    bool res = true;

    if (head != NULL &&
        head->next != NULL)
    {
        // Get the middle of the list.
        // Move slow_ptr by 1 and
        // fast_ptrr by 2, slow_ptr
        // will have the middle node
        while (fast_ptr != NULL &&
               fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;

            // We need previous of the slow_ptr for
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        /* fast_ptr would become NULL when there
           are even elements in list. And not NULL
           for odd elements. We need to skip the
           middle node for odd case and store it
           somewhere so that we can restore the
           original list*/
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // Now reverse the second half and
        // compare it with first half
        second_half = slow_ptr;

        // NULL terminate first half
        prev_of_slow_ptr->next = NULL;

        // Reverse the second half
        reverse(&second_half);

        // Compare
        res = compareLists(head, second_half);

        // Construct the original list back
        // Reverse the second half again
        reverse(&second_half);

        // If there was a mid node (odd size
        // case) which was not part of either
        // first half or second half.
        if (midnode != NULL)
        {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return res;
}

// Function to reverse the linked list
// Note that this function may change
// the head
void reverse(LinkedListNode** head_ref)
{
    LinkedListNode* prev = NULL;
    LinkedListNode *current = *head_ref;
    LinkedListNode *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Function to check if two input
// lists have same data
bool compareLists(LinkedListNode* head1,LinkedListNode* head2)
{
    LinkedListNode* temp1 = head1;
    LinkedListNode* temp2 = head2;

    while (temp1 && temp2)
    {
        if (temp1->val == temp2->val)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }

    // Both are empty return 1
    if (temp1 == NULL && temp2 == NULL)
        return 1;

    // Will reach here when one is NULL
    // and other is not
    return 0;
}

// Push a node to linked list.
// Note that this function
// changes the head
// void push(LinkedListNode** head_ref,
//           char new_data)
// {
//     // allocate node
//     LinkedListNode* new_node =
//            (struct Node*)malloc(sizeof(struct Node));

//     // Put in the data
//     new_node->data = new_data;

//     // Link the old list off the new node
//     new_node->next = (*head_ref);

//     // Move the head to point to the new node
//     (*head_ref) = new_node;
// }


int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    bool res;
    int head_size = 0;

    LinkedListNode* head = NULL;
    LinkedListNode* head_tail = NULL;

    scanf("%d", &head_size);
 	char s[10005];
  	scanf(" %s", s);
    for(int i = 0; i < head_size; i++) {
        char head_item = s[i];
        head_tail = _insert_node_into_singlylinkedlist(head, head_tail, head_item);

        if(i == 0) {
            head = head_tail;
        }
    }


    res = isPalindrome(head);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}
