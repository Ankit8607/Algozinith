// https://www.learning.algozenith.com/problems/Remove-Duplicates-514

/*

Description

Given a sorted linked list, delete all duplicates such that each element appears only once.

Complete the function

ListNode* deleteDuplicates(ListNode* head)
head points to the beginning of the linked list.


Constraints

0 ≤ Length of the linked list ≤ 106
0 ≤ Values stored in nodes ≤ 109
It's guaranteed that the linked list is sorted.


Sample Input 1

3
1 1 2

Sample Output 1

1 2

Sample Input 2

6
1 1 1 2 3 3

Sample Output 2

1 2 3

*/


#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return NULL;
    ListNode *it=head;
	while(it->next){
		if(it->val==it->next->val){
			it->next=it->next->next;
		}
		else it=it->next;
	}
	return head;
}

ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    ListNode* head = GetList(num);

    head = deleteDuplicates(head);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
