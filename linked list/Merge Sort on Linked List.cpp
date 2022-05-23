// https://www.learning.algozenith.com/problems/Merge-Sort-on-Linked-List-513

/*

Description

Sort a singly linked list in O(NlogN) using merge sort. Here, N is the length of the linked list.

Complete the function

ListNode* mergesort(ListNode* head)
head is the pointer to the beginning of the list.


Constraints

0 ≤ N ≤ 105
0 ≤ Values stored in nodes ≤ 109


Sample Input 1

1
2

Sample Output 1

2

Sample Input 2

5
1 3 6 1 7

Sample Output 2

1 1 3 6 7

*/


ListNode* merge(ListNode* A, ListNode* B){
    if(A == NULL){
        return B;
    }
    if(B == NULL){
        return A;
    }
    
    ListNode* head = NULL;
    
    if(A->val < B->val){
        head = A;
        A = A->next;
    }
    else{
        head = B;
        B = B->next;
    }
    
    ListNode* temp = head;
    
    while(A != NULL && B != NULL){
        if(A->val < B->val){
            temp->next = A;
            A = A->next;
        }
        else{
            temp->next = B;
            B = B->next;
        }
        temp = temp->next;
    }
    
    if(A != NULL){
        temp->next = A;
    }
    else{
        temp->next = B;
    }
    
    return head;
} 

ListNode* mergesort(ListNode* A) {
    ListNode *head=A;
    if(!head || head->next==NULL) return head;

    ListNode* start = A;
    ListNode* end = A->next;
    
    while(end != NULL && end->next != NULL){
        start = start->next;
        end = (end->next)->next;
    }
    
    end = start->next;
    start->next = NULL;
    
    return merge(mergesort(head),mergesort(end));
}
