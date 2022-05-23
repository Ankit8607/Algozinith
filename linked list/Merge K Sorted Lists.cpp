// https://www.learning.algozenith.com/problems/Merge-K-Sorted-Lists-517

/*

Description

You are given an array of K singly linked lists. head[i] is the head of ith linked list. Each linked list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Complete the function

ListNode* mergeKLists(vector<ListNode*> head)
Do it in O(1) extra space.


Input Format

The first line of input contains K - the number of linked lists.
2ith line contains Ni - the number of nodes in ith linked list.
(2i + 1)th line contains Ni space-separated integers denoting the nodes in the ith linked list in ascending order.

The following function parses the input

vector<ListNode*> GetList(int K, vector<vector<int>> &num)

Constraints

1 ≤ K ≤ 102
0 ≤ Ni ≤ 103
0 ≤ Values of the node ≤ 109
It's guaranteed that each linked list is sorted.


Sample Input 1

3
3
3 5 6
3
1 2 9
3
4 7 8

Sample Output 1

1 2 3 4 5 6 7 8 9

Sample Input 2

3
2
1 5
0

1
4
 

Sample Output 2

1 4 5

*/


ListNode* res=NULL,*prev;
    while(1){
        int t=1e9+10;
        int tmp;
        for(int j=0;j<head.size();j++){
            if(head[j]!=NULL and head[j]->val<t){
                tmp=j;
                t=head[j]->val;
            }
        }
        if(t==1e9+10) break;
        if(!res){
            res=head[tmp];
            prev=res;
            head[tmp]=head[tmp]->next;
        }
        else{
            prev->next=head[tmp];
            prev=head[tmp];
            // prev->next=NULL;
            head[tmp]=head[tmp]->next;
        }
    }
    return res;
