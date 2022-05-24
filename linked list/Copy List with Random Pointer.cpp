// https://www.learning.algozenith.com/problems/Copy-List-with-Random-Pointer-521

/*

Description

Give a special singly linked list of length N with an additional random pointer that points to any node, including itself or null. Make a new linked list, which is exactly the same as the given linked list. Each node should point to the next and random pointer node in the same way as the original list. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random → Y, then for the corresponding two nodes x and y in the copied list, x.random → y.

Return the head of the copied linked list.

Complete the function

ListNode* copyRandomList(ListNode* head)


Input Format

The first line of input contains N - the number of nodes in the linked list.
Each of the next lines contains the node value and the random index in the list to which the random pointer is pointing. If the random index is -1, then the random pointer is pointing at null.

The following function parses the input

ListNode* GetList(vector<pair<int,int>> List)


Constraints

0 ≤ N ≤ 105
0 ≤ Value of the Node ≤ 109


Sample Input 1

5
1 2
6 -1
3 -1
4 1
5 3

Sample Output 1

1 3
6 -1
3 -1
4 6
5 4

*/



ListNode* copyRandomList(ListNode* head) {
    if(!head) return head;
    ListNode *newhead=head;
    ListNode *it=head;
    while(it){
        ListNode* temp = it->next;
        it->next = new ListNode(it->val);
        it->next->next = temp;
        it = temp;
    }
    it=head;
    while(it){
        it->next->random=it->random?it->random->next:it->random;
        it=it->next->next;
    }
    newhead=head->next;
    it=head;
    while(it->next){
        ListNode *tmp=it->next;
        it->next=it->next->next;
        it=tmp;
    }
    return newhead;
}
