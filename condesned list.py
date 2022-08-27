#!/bin/python3

import math
import os
import random
import re
import sys

class SinglyLinkedListNode:
    def __init__(self, node_data):
        self.data = node_data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert_node(self, node_data):
        node = SinglyLinkedListNode(node_data)

        if not self.head:
            self.head = node
        else:
            self.tail.next = node

        self.tail = node

def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.next

        if node:
            fptr.write(sep)



#
# Complete the 'condense' function below.
#
# The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
# The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
#

#
# For your reference:
#
# SinglyLinkedListNode:
#     int data
#     SinglyLinkedListNode next
#
#

def condense(head):
  # Write your code here
  ans=None
  s=set()
  ansl=SinglyLinkedList()
  while head:
    if head.data not in s:
      s.add(head.data)
      ansl.insert_node(head.data)
      head=head.next
    else:
      head=head.next
  return ansl.head
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    head_count = int(input().strip())

    head = SinglyLinkedList()

    for _ in range(head_count):
        head_item = int(input().strip())
        head.insert_node(head_item)

    result = condense(head.head)

    print_singly_linked_list(result, '\n', fptr)
    fptr.write('\n')

    fptr.close()
