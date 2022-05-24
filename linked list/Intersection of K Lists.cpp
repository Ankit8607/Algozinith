// https://www.learning.algozenith.com/problems/Intersection-of-K-Lists-520

/*

Description

Given the heads of K singly-linked lists, return their common intersection node. If the linked lists don’t intersect, return null. It is guaranteed that this structure does not have any cycles.

Complete the function

ListNode* getKIntersectionNode(vector<ListNode*> head)


Input Format

The first line of input contains K - the number of linked lists.
The 2ith line contains Ni - the number of nodes in ith linked list.
The (2i + 1)th line contains Ni space-separated integers denoting the nodes in the ith linked list.
Each unique node has a unique value, and vice-versa. No two different nodes have the same value.

The following function parses the input

vector<ListNode*> GetList(vector<vector<int>> num, int K)


Constraints

1 ≤ K ≤ 100
0 ≤ Ni ≤ 1000


Sample Input 1

3
7
1 2 3 5 6 8 9
6
4 3 5 6 8 9
4
7 6 8 9

Sample Output 1

6

Note

Node 6 is a common intersection of all linked lists.

*/


// My approach

ListNode * intersection(int i, int j,vector<ListNode *>&lists) {
    ListNode* it1=lists[i],*it2=lists[j];
    while(it1 and it2){
        it1=it1->next; 
        it2=it2->next;
    }
    ListNode* inter;
    if(it1){
        inter=lists[i];
        while(it1){
            it1=it1->next;
            inter=inter->next;
        }
        it2=lists[j];
        while(inter!=it2){
            inter=inter->next;
            it2=it2->next;
        }
    }
    else{
        inter=lists[j];
        while(it2){
            it2=it2->next;
            inter=inter->next;
        }
        it1=lists[i];
        while(inter!=it1){
            inter=inter->next;
            it1=it1->next;
        }
    }
    return inter;
}

ListNode* getKIntersectionNode(vector<ListNode*>& lists) {
    if(lists.size()<2) return lists.front();
    ListNode* ans;
    for(int i=1;i<lists.size(); i++){
        ans=intersection(i-1,i,lists);
        lists[i]=ans;
    }
    return ans;
}



// Smart approach

ListNode *getTwoIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* l1 = headA, *l2 = headB;
    while(l1 != l2) {
        l1 = (l1 == NULL) ? headB : l1->next;
        l2 = (l2 == NULL) ? headA : l2->next;
    }
    return l1;
}

ListNode* mergeLists(vector<ListNode*>& lists, int l, int r) {
    if (l == r) {
        return lists[l];
    }

    int mid = (l + r) / 2;

    ListNode* head1 = mergeLists(lists, l, mid);
    ListNode* head2 = mergeLists(lists, mid + 1, r);

    return getTwoIntersectionNode(head1, head2);
}

ListNode* getKIntersectionNode(vector<ListNode*>& lists) {
    if(lists.empty()) {
        return NULL;
    }

    return mergeLists(lists, 0, (int)lists.size() - 1);
}
