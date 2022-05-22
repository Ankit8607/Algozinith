// https://www.learning.algozenith.com/problems/Intersection-of-Two-Lists-518

/*

Description

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return NULL.

Complete the function 

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)

Input Format

The first line of input contains N - the number of nodes in the first linked list.
The second line contains N space-separated numbers denoting the elements of the linked list.
The third line contains M - the number of nodes in the second linked list.
The fourth line contains M space-separated numbers denoting the elements of the linked list.
The last line of input contains skipA and skipB. If skipA = skipB = -1, then there is no intersection of two lists. Otherwise listA[skipA + i] == listB[skipB + i] for i = 1 to N - skipA. It's guaranteed that when skipA ≠ -1 and skipB ≠ -1, then N - skipA == M - skipB.

The following function parses the input

pair<ListNode*, ListNode*> GetList(vector<int> listA, vector<int> listB, int skipA, int skipB)

Constraints

1 ≤ N, M ≤ 105
-1 ≤ skipA < N
-1 ≤ skipB < M
0 ≤ Value of the node ≤ 109
It's guaranteed that the input is valid.


Sample Input 1

5
2 3 1 4 5
6
9 6 8 1 4 5
2 3

Sample Output 1

1

Sample Input 2

4
1 2 5 3
3
6 5 3
2 1

Sample Output 2

5


*/



ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a=headA,*b=headB;
    while(a && b){
        a=a->next;
        b=b->next;
    }
    if(b) swap(a,b),swap(headA,headB);
    while(a){
        a=a->next;
        headA=headA->next;
    }
    while(headA and headB){
        if(headA==headB) return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return headA;
}
