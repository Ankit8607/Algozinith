// https://www.learning.algozenith.com/problems/Reverse-List---hard-version-516

/*

Description

Given a singly linked list and an integer K, reverse the nodes of the list K at a time and returns its head.

It's guaranteed that the K is divisible by the length of the linked list.

Complete the function

ListNode* reverseList(ListNode* head, int K)

Input Format

The first line of input contains N - the length of the linked list.
The second line contains N space-separated integers denoting the sequence of elements in the linked list.
The third line contains an integer K.

The following functions read the input

ListNode* GetList(vector<int> &num)

Constraints

1 ≤ N ≤ 106
1 ≤ K ≤ N
0 ≤ Values stored in nodes ≤ 109
It's guaranteed that the N is divisible by K.


Sample Input 1

6
1 2 3 4 5 6
3

Sample Output 1

3 2 1 6 5 4

Sample Input 2

3
1 3 2
3

Sample Output 2

2 3 1


*/



ListNode* reverseList(ListNode* head, int K) {
    if(!head || K==1) return head;
    ListNode *cur=head,*start=head;
    int t=K;
    head=NULL;
    while(t--){
        ListNode *tmp=cur->next;
        cur->next=head;
        head=cur;
        cur=tmp;
    }
    start->next=reverseList(cur,K);
    return head;
}
