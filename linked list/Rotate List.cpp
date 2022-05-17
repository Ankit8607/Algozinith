// https://www.learning.algozenith.com/problems/Rotate-List-511

/*

Description

Given a singly linked list, rotate the list to the right by K places.

Complete the function

ListNode* rotateList(ListNode* head, int K)
head points to the beginning of the list.


Input Format

The first line of input contains n - the length of the linked list.
The second line contains n space-separated integers denoting the sequence of values stored in nodes of the linked list.
The last of the input contains K.

The following function creates the linked list from the input

ListNode* GetList(vector<int> &num)

Constraints

0 ≤ Length of the linked list ≤ 106
0 ≤ K ≤ 109
0 ≤ Value stored in node ≤ 109


Sample Input 1

3
1 2 3
0

Sample Output 1

1 2 3

Sample Input 2

3
1 2 3
1

Sample Output 2

3 1 2

Sample Input 3

3
1 2 3
6

Sample Output 3

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

ListNode* rotateList(ListNode* head, int K) {
   if(!head || head->next==NULL) return head;
    if(!K) return head;

    int n = 0;
    ListNode *cur = head;
    ListNode *last = head;

    while(cur) {
        n++;
        last = cur;
        cur = cur->next;
    }

    K %= n;

    cur = head;

    for(int i = 0; i < n - K - 1; i++)
        cur = cur->next;

    last->next = head;

    ListNode *temp = cur->next;
    cur->next = NULL;

    return temp;
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

    int K;
    cin >> K;

    ListNode* head = GetList(num);

    head = rotateList(head, K);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
