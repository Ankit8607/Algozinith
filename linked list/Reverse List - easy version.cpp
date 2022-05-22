// https://www.learning.algozenith.com/problems/Reverse-List---easy-version-515

/*

Description

Given a singly linked list, reverse the nodes and return its head.

Complete the function

ListNode* reverseList(ListNode* head)

Constraints

0 ≤ Length of the linked list ≤ 106
0 ≤ Values stored in nodes ≤ 109


Sample Input 1

1
1

Sample Output 1

1

Sample Input 2

5
1 2 3 4 5

Sample Output 2

5 4 3 2 1

*/


ListNode* reverseList(ListNode* head) {
    ListNode* current = head;
    ListNode *next = NULL;
    head=NULL;

    while (current != NULL) {
        next = current->next;
        current->next = head;
        head = current;
        current = next;
    }
    return head;
}
