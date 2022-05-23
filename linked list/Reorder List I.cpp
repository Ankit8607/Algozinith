// https://www.learning.algozenith.com/problems/Reorder-List-I-510

/*

Description

Given the head of the singly connected linked list, your task is to reorder it as follows.

Original list:

L1 -> L2 -> L3 -> ...... -> Ln-2 -> Ln-1 -> Ln
Reorder list:

L1 -> Ln -> L2 -> Ln-1 -> L3 -> Ln-2 -> .....
Complete the function

void reorderList(ListNode* head)
head is the pointer to the beginning of the linked list.

You may not modify the values in the list's nodes. Only nodes themselves may be changed.


Constraints

0 ≤ Length of the linked list ≤ 106
0 ≤ Value stored in the node ≤ 109


Sample Input 1

1
3

Sample Output 1

3

Sample Input 2

5
1 2 3 4 5

Sample Output 2

1 5 2 4 3

Sample Input 3

4
1 2 3 4

Sample Output 3

1 4 2 3

*/


void fun(ListNode *(&head),ListNode *it){
    if(!it) return;
    fun(head,it->next);
    it->next=head->next;
    head->next=it;
    head=it->next;
}

void reorderList(ListNode* head) {
  	if(!head || head->next==NULL) return;
  	ListNode* slow=head,*fast=head;
      while(fast and fast->next){
          slow=slow->next;
          fast=fast->next->next;
      }
    fast=slow;
    slow=slow->next;
    fast->next=NULL;
    fast=head;
    fun(fast,slow);
}
