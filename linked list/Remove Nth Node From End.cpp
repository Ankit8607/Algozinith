// https://www.learning.algozenith.com/problems/Remove-Nth-Node-From-End-512

/*

Description

Given a non-empty singly linked list, remove the Nth node from the end and returns its head. 

Try to do it in one pass.

Complete the function

ListNode* removeNthFromEnd(ListNode* head, int N)
head points to the beginning of the linked list.


Constraints

1 ≤ Length of the linked list ≤ 106
1 ≤ N ≤ Length of the linked list
0 ≤ Value stored in nodes ≤ 109


Sample Input 1

3
1 2 3
1

Sample Output 1

1 2

Sample Input 2

4
1 2 3 4
3

Sample Output 2

1 3 4

Sample Input 3

4
1 2 3 4
4

Sample Output 3

2 3 4

*/


ListNode* removeNthFromEnd(ListNode* head, int N) {
    if(!head) return head;

    ListNode *prev = NULL, *cur = head;

    for(int i = 0; i < N; i++) 
        cur = cur->next;

    if(!cur) return head->next;

    while(cur) {
        cur = cur->next;
        if(prev) prev = prev->next;
        else prev = head;
    }

    prev->next = prev->next->next;

    return head;
}
