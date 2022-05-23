// https://www.learning.algozenith.com/problems/Reorder-List-II-519

/*

Description

Given the head of the singly connected linked list, your task is to reorder it as follows.

Original list:

L1 -> L2 -> L3 -> ...... -> Ln-2 -> Ln-1 -> Ln
Reorder list:

L1 -> L3 -> L5 -> ..... -> L6 -> L4 -> L2
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

1 3 5 4 2

*/


void reorderList(ListNode* head) {
    if(!head || head->next==NULL) return;
    ListNode *even=NULL,*it=head,*prev=head;
    while(it and it->next) {
        ListNode *y=it->next;
        it->next=y->next;
        it=y;
        if(!even){
            even=y;
        }
    }
    it=even;
    prev=NULL;
    while(it){
        even=it;
        it=it->next;
        even->next=prev;
        prev=even;
    }
    it=head;
    while(it->next) it=it->next;
    it->next=even;    
}
