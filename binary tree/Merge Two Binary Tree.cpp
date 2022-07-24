// https://www.learning.algozenith.com/problems/Merge-Two-Binary-Tree-659

/*

Description

Given two binary trees. We need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the non-null node will be used as the node of new tree.


Input Format

The first line contains an integer T, (1 ≤ T ≤ 10^5), the number of test cases.

The first line of each test case contains an integer N, the length of the array representing the serialized representation of a tree1.

The next line contains N-space-separated distinct integers. 

The next line contains an integer M, the length of the array representing the serialized representation of a tree2.

The next line contains M-space-separated distinct integers. 

The input is given as a serialized representation of a tree.

The following function parses the input:

Node* getBinaryTree(vector<int> &num, int*ind)

Sum of N across all test cases ≤ 10^7.


Output Format

For each test case return the new merged tree root node. 


Sample Input 1

1
11
1496 5959 -1 -1 5566 1754 -1 -1 8678 -1 -1 
9
1358 5601 8697 -1 -1 8984 -1 -1 -1 

Sample Output 1

2854 11560 8697 -1 -1 8984 -1 -1 5566 1754 -1 -1 8678 -1 -1 

*/


struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};

Node *getMergedTree(Node * t1, Node * t2)
{
    if(t1==NULL) return t2;
    if(t2==NULL) return t1;
    Node *root=new Node(t1->val+t2->val);
    root->left=getMergedTree(t1->left, t2->left);
    root->right=getMergedTree(t1->right, t2->right);
    return root;
}
