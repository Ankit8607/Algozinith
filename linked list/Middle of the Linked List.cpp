// https://www.learning.algozenith.com/problems/Middle-of-the-Linked-List-508

/*

Description

Given a non-empty singly linked list, find a middle node of the linked list.

Complete the function

ListNode* middleNode(ListNode* head)
head is the pointer to the beginning of the linked list.

If there are even nodes, then there would be two middle nodes, find the second middle element.


Constraints

Size of linked list ≤ 100000
Each node in the linked list stores values between 0 to 109.


Sample Input 1

1
5

Sample Output 1

5

Sample Input 2

2
1 8

Sample Output 2

8

*/


ListNode* middleNode(ListNode* head) {
    if(!head || !head->next) return head;
    ListNode *slow=head,*fast=head;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
