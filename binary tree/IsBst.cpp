// https://www.learning.algozenith.com/problems/IsBst-655

/*

Description

Check if a binary tree is BST or not.

A binary search tree (BST) is a node based binary tree data structure which has the following properties. 
• The left subtree of a node contains only nodes with keys less than the node’s key. 
• The right subtree of a node contains only nodes with keys greater than the node’s key. 
• Both the left and right subtrees must also be binary search trees.
From the above properties it naturally follows that: 
• Each node (item in the tree) has a distinct key.


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N the length of the array representing the serialized representation of a tree.

The next line contains N-space-separated integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

Return true/false.


Sample Input 1

6
17
113169 111387 -1 -1 209114 -1 957726 786099 643981 -1 -1 821914 -1 -1 990181 -1 -1 
7
566098 413153 -1 -1 797870 -1 -1 
3
964901 -1 -1 
19
14136 -1 35825 -1 37940 -1 264128 -1 370052 -1 545817 -1 659383 -1 678544 -1 682492 -1 -1 
13
7813 6718 -1 5816 -1 -1 5249 -1 3912 8623 -1 -1 -1 
15
8359 8305 9109 6276 -1 -1 6626 -1 -1 2942 -1 -1 8575 -1 -1 

Sample Output 1

yes
yes
yes
yes
no
no

*/


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
pair<int,int> fun(Node *root,bool &bst){
    if(root == NULL) return {1e9,-1e9};
    pair<int,int> l=fun(root->left,bst);
    pair<int,int> r=fun(root->right,bst);
    if(root->val<=l.second) bst=false;
    if(root->val>=r.first) bst=0;
    return {min(root->val,l.first),max(root->val,r.second)};
}

bool isBst(Node* root) {
    bool bst=1;
    fun(root,bst);
    return bst;
}
