// https://www.learning.algozenith.com/problems/Add-Two-Numbers-507

/*

Description

A number is represented in the form of a linked list, by storing its digit in the reverse order. Each node of the linked list stores one digit. The head of the linked list is pointed towards the least significant digit of the number.

Given two non-empty linked list representing two numbers, your task is to add them and return the sum as a linked list.

Complete the function

ListNode* addTwoNumbers(ListNode* n1, ListNode* n2)
n1 and n2 are head of the two numbers' linked lists. And the function returns the head of the linked list of the sum.


Constraints

Size of the linked list ≤ 105
Each node in the linked list stores values between 0 to 9.
It is guaranteed that the list represents a number that does not have leading zeros.


Sample Input 1

200
13421

Sample Output 1

13621

Sample Input 2

12
0

Sample Output 2

12

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

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    int carry=0;
    ListNode *a=A,*b=B;
    while(a && b){
        carry+=a->val+b->val;
        a->val=carry%10;
        b->val=carry%10;
        carry/=10;
        a=a->next;
        b=b->next;
    }
    while(a){
        carry+=a->val;
        a->val=carry%10;
        carry/=10;
        if(!a->next){
            if(carry){
                a->next=new ListNode(carry);
            }
            return A;
        }
        a=a->next;
    }
    while(b){
        carry+=b->val;
        b->val=carry%10;
        carry/=10;
        if(!b->next){
            if(carry){
                b->next=new ListNode(carry);
            }
            return B;
        }
        b=b->next;
    }
    ListNode *it=A;
    while(it){
        if(it->next==NULL){
            if(carry) it->next=new ListNode(carry);
            return A;
        }
				it=it->next;
    }
}

ListNode* GetList(string &num) {
    ListNode* n1 = nullptr;
    ListNode* head = nullptr;
    for(int i = (int)num.length() - 1; i >= 0; i--) {
        ListNode* temp = new ListNode(num[i] - '0');
        if(n1) {
            n1->next = temp;
            n1 = temp;
        }
        else {
            n1 = temp;
            head = n1;
        }
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string num1, num2;
    cin >> num1;
    cin >> num2;

    ListNode* n1 = GetList(num1);
    ListNode* n2 = GetList(num2);

    ListNode* sum = addTwoNumbers(n1, n2);

    string ans = "";
    while(sum) {
        ans += ('0' + sum->val);
        sum = sum->next;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}
