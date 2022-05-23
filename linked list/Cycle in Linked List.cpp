// https://www.learning.algozenith.com/problems/Cycle-in-Linked-List-509

/*

Description

Given a non-empty linked list, your task is to find the cycle in the linked list. Return starting node of the cycle and length of the cycle. If there is no cycle, then return null as node and -1 as length.

Complete the function

pair<ListNode*,int> cycleInLinkedList(ListNode* head)
head is the pointer to the beginning node of the linked list.


Input Format

The first line contains n - the length of the linked list.
The second line contains the sequence of elements in linked list nodes.
The third line contains an integer LastLink - denoting to which node from the starting position the last node connects. If it is 0, then there is no cycle.

The following function translates the input.

ListNode* GetList(int n, vector<int> &num, int lastLink)
 


Constraints

1 ≤ Length of the linked list ≤ 1000000
0 ≤ Value in node ≤ 109
1 ≤ LastLink ≤ Length of the linked list -1


Sample Input 1

3
1 2 3
2

Sample Output 1

2 2

Sample Input 2

2
1 2
1

Sample Output 2

1 2

Sample Input 3

3
1 2 3
0

Sample Output 3

-1 -1

Note

Explanation 1:

1 -----> 2 -----> 3
         ^        |
         |        |
         ----------
Explanation 2:

1 -------> 2
^          |
|          |
------------
Explanation 3:

1 -------> 2 ------> 3

*/



pair<ListNode*,int> cycleInLinkedList(ListNode* head) {
    if(head->next==NULL) return {NULL,-1};
    ListNode *slow=head,*fast=head;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    
    if(slow!=fast) return {NULL,-1};

    while(head!=slow){
        slow=slow->next;
        head=head->next;
    }
    int n=1; slow=slow->next;
    while(slow!=head){
        n++; 
        slow=slow->next;
    }
    return {head,n};
}
